#ifndef CLOCK_HPP
#define CLOCK_HPP

#include "hwlib.hpp"
#include "hwmath.hpp"
#include "lookup.hpp"

namespace drawable {
 
// can't seem to compile this without instantiating it :(
//template<typename T = void>
class clock {
private:
    hwlib::window& display;
    hwlib::pin_in& mins_button;
    hwlib::pin_in& hours_button;
    int_fast8_t seconds;
    int_fast8_t minutes;
    int_fast8_t hours;
public:
    clock(
        hwlib::window& display,
        hwlib::pin_in& mins_button,
        hwlib::pin_in& hours_button
    ):
        display{display},
        mins_button{mins_button},
        hours_button{hours_button},
        seconds{},
        minutes{},
        hours{}
    {}

    void HWLIB_NORETURN run() {
        display.clear();
        draw_dials();
 
        for (auto time{hwlib::now_us()}, now{time};; now = hwlib::now_us()) {
            constexpr auto second_us{1'000'000};

            if (now > time + second_us) {
                render_all_hands(render::erase);
                set_clock_on_interaction();
                update_clock();
                render_all_hands();
                display.flush();
                time = now;
            }
        }
    }
private:
    static constexpr auto window_size{hwlib::xy{128, 64}};
    static constexpr auto window_center{window_size / 2};
    static constexpr auto font_size{8};
    static constexpr auto max_hours{12};
    static constexpr auto max_time_units{60};

    static constexpr auto max_radius(
        auto offset = 0,
        hwlib::xy size = window_center
    ) {
        return (size.x > size.y ? size.y : size.x) - offset;
    }

    template<auto O = font_size / 2, auto R = max_radius(O)> 
    static constexpr hwlib::xy coord_from_degree(int_fast8_t degree) {
        return window_center + hwlib::xy{
            static_cast<decltype(hwlib::xy::x)>(
                R * hwmath::sin(hwmath::radian_from_degree(degree))
            ), 
            static_cast<decltype(hwlib::xy::y)>(
                -R * hwmath::cos(hwmath::radian_from_degree(degree)))};
    }

    static constexpr cache::lookup<hwlib::xy, max_hours> dial_coords(
        coord_from_degree
    );
    static constexpr cache::lookup<hwlib::xy, max_time_units> min_coords(
        coord_from_degree<font_size>
    );
    static constexpr cache::lookup<hwlib::xy, max_time_units> hour_coords(
        coord_from_degree<font_size * 2>
    );

    enum class render : bool {
        draw = true,
        erase = false
    };

    void set_clock_on_interaction() {
        if (not mins_button.read()) {
            update_mins_hours();
        } else if (not hours_button.read()) {
            for (auto mins = 0; mins < max_time_units / max_hours; ++mins) {
                update_time(hours, max_time_units);
            }
        }
    }

    void update_clock() {
        update_time(
            seconds,
            max_time_units,
            [=]{return this->update_mins_hours();});
    }

    void update_mins_hours() {
        update_time(minutes, max_time_units);

        if (minutes % max_hours == 0) {
            update_time(hours, max_time_units);
        }
    }

    template<typename F = void (*)()>
    void update_time(
        auto& unit,
        auto limit,
        F update = []{}
    ) {
        if (++unit == limit) {
            update();
            unit = 0;
        }
    }

    void render_all_hands(
        render action = render::draw
    ) const {
        render_hand(min_coords[seconds], action);
        render_hand(min_coords[minutes], action);
        render_hand(hour_coords[hours], action);
    }

    void render_hand(
        hwlib::xy end,
        render action
    ) const {
        hwlib::line{
            window_center,
            end,
            action == render::draw
                ? hwlib::white
                : hwlib::black
        }.draw(display);
    }

    void draw_dials() const {
        auto const font{hwlib::font_default_8x8()};
        auto const offset{
            hwlib::xy{font_size, font_size} / 2
        };
        for (auto index = 1u; index < dial_coords.size() - 2; ++index) {
            display.write(
                dial_coords[index] - offset,
                invert(font[index + '0']));
        }
        draw_dial_10(dial_coords[10] - offset, font);
        draw_dial_11(dial_coords[11] - offset, font);
        draw_dial_12(dial_coords[0] - offset, font);
    }

    void draw_dial_10(auto const& coord, auto const& font) const {
        display.write(coord - hwlib::xy{8, 0}, invert(font['1']));
        display.write(coord, invert(font['0']));
    }

    void draw_dial_11(auto const& coord, auto const& font) const {
        auto const img_one{invert(font['1'])};
        display.write(coord - hwlib::xy{8, 0}, img_one);
        display.write(coord, img_one);
    }

    void draw_dial_12(auto const& coord, auto const& font) const {
        display.write(coord - hwlib::xy{4, 0}, invert(font['1']));
        display.write(coord + hwlib::xy{4, 0}, invert(font['2']));
    }
};
}; // end of drawable namespace

#endif // CLOCK_HPP

#include "hwlib.hpp"
#include "clock.hpp"

int main() {
    namespace target = hwlib::target;
    auto sda{target::pin_oc{target::pins::d8}};
    auto scl{target::pin_oc{target::pins::d9}};
    auto hours{target::pin_in{target::pins::d10}};
    auto minutes{target::pin_in{target::pins::d11}};
    auto i2c_bus{hwlib::i2c_bus_bit_banged_scl_sda(scl, sda)};
    auto display{hwlib::glcd_oled(i2c_bus)};

    drawable::clock{display, minutes, hours}.run();
    return 0;
}

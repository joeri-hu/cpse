#ifndef SET_HPP
#define SET_HPP

#include <ostream>
#include <array>

class set {
private:
    static constexpr auto max_size{10};
	std::array<int, max_size> stuff;
    int tally;

    void shift(int start) {
        for (auto spot = start + 1; spot < max_size; ++spot) {
            stuff[spot - 1] = stuff[spot];
        }
    }
public:
    set();
    void add(int thing);
    bool contains(int thing) const;
    void remove(int thing);
    friend std::ostream& operator<<(std::ostream& lhs, set const& rhs);
};

std::ostream& operator<<(std::ostream& lhs, set const& rhs);

#endif // SET_HPP

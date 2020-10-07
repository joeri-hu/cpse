#ifndef SET_HPP
#define SET_HPP

#include <ostream>
#include <array>

template<typename T = int, size_t S = 10>
class set {
private:
	std::array<T, S> stuff;
    size_t tally;

    void shift(size_t start) {
        for (auto spot = start + 1; spot < S; ++spot) {
            stuff[spot - 1] = stuff[spot];
        }
    }
public:
    set():
        stuff{},
        tally{}
    {}

    void add(T thing) {
        if (tally < S and not contains(thing)) {
            stuff[tally++] = thing;
        }
    }

    bool contains(T thing) const {
        for (auto const item : stuff) {
            if (item == thing) {
                return true;
            }
        }
        return false;
    }

    void remove(T thing) {
        for (size_t spot = 0; spot < S; ++spot) {
            if (stuff[spot] == thing) {
                shift(spot);
                --tally;
                return;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& lhs, set const& rhs) {
        lhs << '[';
        auto delim{""};

        for (auto const item : rhs.stuff) {
            if constexpr (std::is_same_v<T, char>) {
                lhs << delim << +item;
            } else {
                lhs << delim << item;
            }
            delim = ", ";
        }
        return lhs << ']';
    }
};

#endif // SET_HPP

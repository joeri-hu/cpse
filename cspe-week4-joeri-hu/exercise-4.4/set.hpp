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
        for (auto spot = start + 1; spot < tally; ++spot) {
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
        for (size_t spot = 0; spot < tally; ++spot) {
            if (stuff[spot] == thing) {
                return true;
            }
        }
        return false;
    }

    void remove(T thing) {
        for (size_t spot = 0; spot < tally; ++spot) {
            if (stuff[spot] == thing) {
                shift(spot);
                --tally;
                return;
            }
        }
    }

    T max() const {
        auto max{stuff[0]};

        for (size_t spot = 1; spot < tally; ++spot) {
            if (stuff[spot] > max) {
                max = stuff[spot];
            }
        }
        return max;
    }

    friend bool operator> (
        T const& stuff,
        std::array<char, 3> const& other
    ) {
        for (size_t spot = 0; spot < stuff.size(); ++spot) {
            if (stuff[spot] > other[spot]) {
                return true;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(
        std::ostream& stream,
        set const& other
    ) {
        stream << '[';
        auto delim{""};

        for (size_t spot = 0; spot < other.tally; ++spot) {
            if constexpr (std::is_same_v<T, std::array<char, 3>>) {
                stream << delim << '[' << other.stuff[spot][0]
                     << ", " << other.stuff[spot][1] << ']';
            } else {
                stream << delim << other.stuff[spot];
            }
            delim = ", ";
        }
        return stream << ']';
    }
};

#endif // SET_HPP

#include "set.hpp"

set::set():
    stuff{},
    tally{}
{}

void set::add(int thing) {
    if (tally < max_size and not contains(thing)) {
        stuff[tally++] = thing;
    }
}

bool set::contains(int thing) const {
    for (auto const item : stuff) {
        if (item == thing) {
            return true;
        }
    }
    return false;
}

void set::remove(int thing) {
    for (auto spot = 0u; spot < max_size; ++spot) {
        if (stuff[spot] == thing) {
            shift(spot);
            --tally;
        }
    }
}

std::ostream& operator<<(std::ostream& lhs, set const& rhs) {
    lhs << '[';
    auto delim{""};

    for (auto const item : rhs.stuff) {
        lhs << delim << item;
        delim = ", ";
    }
    lhs << ']';
    return lhs;
}

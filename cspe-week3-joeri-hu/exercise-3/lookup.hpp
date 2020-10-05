#ifndef LOOKUP_HPP
#define LOOKUP_HPP

namespace cache {

template<typename T, auto S = 1>
class lookup {
private:
    static constexpr auto max_degrees{360};
    std::array<T, S> values{};
public:
    constexpr lookup(auto converter) {
        for (auto index = 0; index < S; ++index) {
            values[index] = converter(index * (max_degrees / S));
        }
    }

    constexpr T operator[](int index) const {
        return values[index];
    }

    constexpr auto size() const {
        return values.size();
    }
};
}; // end of cache namespace

#endif // LOOKUP_HPP

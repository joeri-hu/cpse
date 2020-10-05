#ifndef HWMATH_HPP
#define HWMATH_HPP

namespace hwmath {
    constexpr double radian_from_degree(int degrees) {
        return 2 * 3.14 * (degrees / 360.0);
    }

    constexpr double pow(double base, int exponent) {
        return exponent > 1 ? base * pow(base, exponent - 1) : base;
    }

    constexpr double fac(int n) {
        return n > 1 ? n * fac(n - 1) : 1;
    }

    constexpr double sin(double x) {
        return x
            - pow(x, 3) / fac(3)
            + pow(x, 5) / fac(5)
            - pow(x, 7) / fac(7)
            + pow(x, 9) / fac(9)
            - pow(x, 11) / fac(11)
            + pow(x, 13) / fac(13)
            - pow(x, 15) / fac(15)
            + pow(x, 17) / fac(17);
    }

    constexpr double cos(double x) {
        return 1.0
            - pow(x, 2) / fac(2)
            + pow(x, 4) / fac(4)
            - pow(x, 6) / fac(6)
            + pow(x, 8) / fac(8)
            - pow(x, 10) / fac(10)
            + pow(x, 12) / fac(12)
            - pow(x, 14) / fac(14)
            + pow(x, 16) / fac(16);
    }
}; // end of hwmath namespace

#endif // HWMATH_HPP

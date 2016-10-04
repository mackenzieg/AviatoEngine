#ifndef AVIATOENGINE_MATH_H
#define AVIATOENGINE_MATH_H

#include <cmath>
#include <cassert>

namespace AVIAT {
    const double PI = 3.141592653589793238462643383279502884197169399375105820974;
    const double TAU = 6.283185307179586476925286766559005768394338798750211641949;
    const double E = 2.718281828459045235360287471352662497757247093699959574966;

    constexpr double PITORAD = PI / 180.0;
    constexpr double PITODEG = 180.0 / PI;

    template <class T>
    inline T toRad(T a)
    {
        return a * PITORAD;
    }

    template <class T>
    inline T toDeg(T a)
    {
        return a * PITODEG;
    }

    template <typename T>
    inline T square(T value)
    {
        return value * value;
    }

    template <typename T>
    inline T cube(T value)
    {
        return value * value * value;
    }

    template <typename T>
    inline T quad(T value)
    {
        return value * value * value * value;
    }

    template <typename T>
    inline T penta(T value)
    {
        return value * value * value * value * value;
    }

    template <typename T>
    inline T Min(const T& a, const T& b)
    {
        return a <= b ? a : b;
    }

    template <typename T>
    inline T Max(const T& a, const T& b)
    {
        return a >= b ? a : b;
    }

    template <typename T>
    inline T Max(const T& a, const T& b, const T& c)
    {
        return Max(Max(a, b), c);
    }

    template <typename T>
    inline T Min(const T& a, const T& b, const T& c)
    {
        return Min(Min(a, b), c);
    }

    template <typename T>
    inline T Min(const T& a, const T& b, const T& c, const T& d)
    {
        return Min(Min(a, b), Min(c, d));
    }

    template <typename T>
    inline T Max(const T& a, const T& b, const T& c, const T& d)
    {
        return Max(Max(a, b), Max(c, d));
    }

    template <typename T>
    T map(T s, T a1, T a2, T b1, T b2)
    {
        return b1 + (s - a1) * (b2 - b1) / (a2 - a1);
    }

    template <typename T>
    inline void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    inline T abs(const T& a)
    {
        return a >= 0 ? a : -a;
    }

    template <typename T, typename U>
    inline T lerp(T a, T b, U c)
    {
        assert(a < 1);
        assert(a > 0);
        return a + (b - a) * c;
    }

    template <typename T, typename U>
    inline T cubic_lerp(const T& a, const T& b, U s)
    {
        assert(a < 1);
        assert(a > 0);
        if (s < 0.0f)
            s = 0.0f;
        else if (s > 1.0f)
            s = 1.0f;
        return (a * ((2.0f * (s * s * s)) - (3.0f * (s * s)) + 1.0f)) + (b * ((3.0f * (s * s)) - (2.0f * (s * s * s))));
    }

    template <typename T>
    inline T clamp(const T& val, const T& floor, const T& ceil)
    {
        assert(floor < ceil);
        return val <= ceil ? (val >= floor ? val : floor) : ceil;
    }

    template <typename T>
    inline T clamp_low(T value, T low)
    {
        return (value < low) ? low : value;
    }

    template <typename T>
    inline T clamp_high(T value, T high)
    {
        return (value > high) ? high : value;
    }

    template <typename T>
    inline T saturate(T value)
    {
        return (value < 0.0f) ? 0.0f : ((value > 1.0f) ? 1.0f : value);
    }

    template <typename T>
    inline bool is_within_open_range(T a, T l, T h)
    {
        return (a >= l) && (a < h);
    }
}

#endif //AVIATOENGINE_MATH_H

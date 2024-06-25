#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP

#include <cppl/field>

namespace cppl
{
    template <typename T>
    class Vector2D
    {
    public:
        Field<T> x;
        Field<T> y;

        Vector2D();
        Vector2D(const &T x, const &T y);
        Vector2D(const &Vector2D<T> vec);

        Vector2D<T> *operator-() const;
        Vector2D<T> *operator-(const &Vector<T> vec) const;
        Vector2D<T> *operator+(const &Vector<T> vec) const;
        T operator*(const &Vector<T> vec) const;
        Vector2D<T> *operator*(const &T val) const;
        Vector2D<T> *operator/(const &T val) const;
        Vector2D<T> null() const;

        ~Vector2D() = default;
    };
}

#endif
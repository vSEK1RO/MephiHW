#ifndef _IMPL_VECTOR2D_HPP
#define _IMPL_VECTOR2D_HPP

#include <cppl/vec2d>
#include <cppl/field>

namespace cppl
{
    template <typename T>
    Vector2D<T>::Vector2D()
    {
        x = Field<T>();
        y = Field<T>();
    }
    template <typename T>
    Vector2D<T>::Vector2D(const T &x, const T &y)
    {
        this->x = x;
        this->y = y;
    }
    template <typename T>
    Vector2D<T>::Vector2D(const Vector2D<T> &vec)
    {
        x = vec.x;
        y = vec.y;
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::operator=(const Vector2D<T> &vec)
    {
        x = vec.x;
        y = vec.y;
        return *this;
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::operator-() const
    {
        return Vector2D<T>(-x, -y);
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::operator-(const Vector2D<T> &vec) const
    {
        return Vector2D<T>(x - vec.x, y - vec.y);
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::operator+(const Vector2D<T> &vec) const
    {
        return Vector2D<T>(x + vec.x, y + vec.y);
    }
    template <typename T>
    T Vector2D<T>::operator*(const Vector2D<T> &vec) const
    {
        return x * vec.x + y * vec.y;
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::operator*(const T &val) const
    {
        return Vector2D<T>(x * Field<T>(val), y * Field<T>(val));
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::operator/(const T &val) const
    {
        return Vector2D<T>(x / Field<T>(val), y / Field<T>(val));
    }
    template <typename T>
    Vector2D<T> Vector2D<T>::null() const
    {
        return Vector2D<T>(0, 0);
    }
    template <typename T>
    bool Vector2D<T>::operator==(const Vector2D<T> &vec) const
    {
        return x == vec.x && y == vec.y;
    }
    template <typename T>
    bool Vector2D<T>::operator!=(const Vector2D<T> &vec) const
    {
        return x != vec.x || y != vec.y;
    }
}

#endif
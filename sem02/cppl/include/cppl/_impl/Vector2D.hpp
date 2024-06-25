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
    Vector2D<T>::Vector2D(const &T x, const &T y)
    {
        this->x = x;
        this->y = y;
    }
    template <typename T>
    Vector2D<T>::Vector2D(const &Vector2D<T> vec)
    {
        x = vec.x;
        y = vec.y;
    }
    template <typename T>
    Vector2D<T> *Vector2D<T>::operator-() const
    {
        Field<T> *newx = -x;
        Field<T> *newy = -y;
        T buffx = newx.data;
        T buffy = newy.data;
        delete newx;
        delete newy;
        return new Vector2D<T>(buffx,buffy);
    }
    template <typename T>
    Vector2D<T> *Vector2D<T>::operator-(const &Vector2D<T> vec) const
    {
        Field<T> *newx = x-vec.x;
        Field<T> *newy = y-vec.y;
        T buffx = newx.data;
        T buffy = newy.data;
        delete newx;
        delete newy;
        return new Vector2D<T>(buffx,buffy);
    }
    template <typename T>
    Vector2D<T> *Vector2D<T>::operator+(const &Vector2D<T> vec) const
    {
        Field<T> *newx = x+vec.x;
        Field<T> *newy = y+vec.y;
        T buffx = newx.data;
        T buffy = newy.data;
        delete newx;
        delete newy;
        return new Vector2D<T>(buffx,buffy);
    }
    template <typename T>
    T Vector2D<T>::operator*(const &Vector2D<T> vec) const
    {
        Field<T> *newx = x*vec.x;
        Field<T> *newy = y*vec.y;
        Field<T> *sum = *newx + *newy;
        T buff = sum.data;
        delete newx;
        delete newy;
        delete sum;
        return buff;
    }
    template <typename T>
    Vector2D<T> *Vector2D<T>::operator*(const &T val) const
    {
        Field<T> *newx = x*val;
        Field<T> *newy = y*val;
        T buffx = newx.data;
        T buffy = newy.data;
        delete newx;
        delete newy;
        return new Vector2D<T>(buffx,buffy);
    }
    template <typename T>
    Vector2D<T> *Vector2D<T>::operator/(const &T val) const
    {
        Field<T> *newx = x/val;
        Field<T> *newy = y/val;
        T buffx = newx.data;
        T buffy = newy.data;
        delete newx;
        delete newy;
        return new Vector2D<T>(buffx,buffy);
    }
    template <typename T>
    Vector2D<T> *Vector2D<T>::null() const
    {
        return new Vector2D<T>(0,0);
    }
}
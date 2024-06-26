#ifndef POLYNOM_HPP
#define POLYNOM_HPP

#include <cppl/seq>
#include <cppl/field>

namespace cppl
{
    template <typename T>
    class Polynom
    {
    public:
        Sequence<Field<T>> *coeff;

        Polynom();
        Polynom(const Sequence<Field<T>> &coeff);
        Polynom(const Polynom<T> &pol);

        Polynom<T> operator=(const Polynom<T> &pol);
        bool operator==(const Polynom<T> &pol) const;
        bool operator!=(const Polynom<T> &pol) const;
        Polynom<T> operator*(const Polynom<T> &pol) const;

        ~Polynom();
    };
}

#endif
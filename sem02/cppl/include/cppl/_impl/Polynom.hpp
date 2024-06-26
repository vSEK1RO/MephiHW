#ifndef _IMPL_POLYNOM_HPP
#define _IMPL_POLYNOM_HPP

#include <cppl/arr>
#include <cppl/polynom>

namespace cppl
{
    template <typename T>
    Polynom<T>::Polynom()
    {
        coeff = new ArraySequence<Field<T>>();
    }
    template <typename T>
    Polynom<T>::Polynom(const Sequence<Field<T>> &coeff)
    {
        this->coeff = coeff.copy();
    }
    template <typename T>
    Polynom<T>::Polynom(const Polynom<T> &pol)
    {
        coeff = pol.coeff->copy();
    }
    template <typename T>
    Polynom<T> Polynom<T>::operator=(const Polynom<T> &pol)
    {
        delete coeff;
        coeff = pol.coeff->copy();
        return *this;
    }
    template <typename T>
    bool Polynom<T>::operator==(const Polynom<T> &pol) const
    {
        return *coeff == *pol.coeff;
    }
    template <typename T>
    bool Polynom<T>::operator!=(const Polynom<T> &pol) const
    {
        return !(*coeff == *pol.coeff);
    }
    template <typename T>
    Polynom<T> Polynom<T>::operator*(const Polynom<T> &pol) const
    {
        uint64_t newLen = coeff->getLenght() + pol.coeff->getLenght() - 1;
        Polynom<T> resPol(ArraySequence<Field<T>>(newLen, Field<T>()));
        for (uint64_t i1 = 0; i1 < coeff->getLenght(); i1++)
        {
            for (uint64_t i2 = 0; i2 < pol.coeff->getLenght(); i2++)
            {
                (*resPol.coeff)[i1 + i2] =
                    (*resPol.coeff)[i1 + i2] + (*coeff)[i1] * (*pol.coeff)[i2];
            }
        }
        return resPol;
    }
    template <typename T>
    Polynom<T> Polynom<T>::operator*(const Field<T> &val) const
    {
        Polynom<T> resPol(*this);
        for (uint64_t i = 0; i < resPol.coeff->getLenght(); i++)
        {
            (*resPol.coeff)[i] = (*resPol.coeff)[i] * val;
        }
        return resPol;
    }
    template <typename T>
    Polynom<T> Polynom<T>::operator+(const Polynom<T> &pol) const
    {
        if (pol.coeff->getLenght() > coeff->getLenght())
        {
            Polynom<T> resPol(pol);
            for (uint64_t i = 0; i < coeff->getLenght(); i++)
            {
                (*resPol.coeff)[i] = (*resPol.coeff)[i] + (*coeff)[i];
            }
            return resPol;
        }
        else
        {
            Polynom<T> resPol(*this);
            for (uint64_t i = 0; i < pol.coeff->getLenght(); i++)
            {
                (*resPol.coeff)[i] = (*resPol.coeff)[i] + (*pol.coeff)[i];
            }
            return resPol;
        }
    }
    template <typename T>
    Polynom<T>::~Polynom()
    {
        delete coeff;
    }
}

#endif
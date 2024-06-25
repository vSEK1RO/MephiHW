#ifndef _IMPL_LINEAR_SPACE_2D_HPP
#define _IMPL_LINEAR_SPACE_2D_HPP

#include <cppl/arr>

#include <cppl/linsp2d>
#include <cppl/field>

namespace cppl
{
    template <typename T>
    LinearSpace2D<T>::LinearSpace2D()
    {
        _x = new ArraySequence<Field<double>>();
        _y = new ArraySequence<Field<double>>();
        size = 0;
    }
    template <typename T>
    LinearSpace2D<T>::LinearSpace2D(const Sequence<Field<double>> &x, const Sequence<Field<double>> &y)
    {
        this->_x = x.copy();
        this->_y = y.copy();
        normaliseLenght();
    }
    Sequence<Field<double>> *template <typename T>
    LinearSpace2D<T>::lagrangePolynomial() const
    {
    }
    Sequence<Field<double>> *template <typename T>
    LinearSpace2D<T>::kroneckerDelta(uint64_t index) const
    {
        Sequence<Field<double>> *k;
        ArraySequence<ArraySequence<Field<double>>> ks;
        for (uint64_t i = 0; i < size; i++)
        {
            if (i == index)
                continue;
            ArraySequence<Field<double>> buff;
            buff.append(-(*_x)[i] / ((*_x)[index] - (*_x)[i]));
            buff.append(1 / ((*_x)[index] - (*_x)[i]));
            ks.append(buff);
        }
        k = polynomialMut(ks[0], ks[1]);
        for (uint64_t i = 2; i < ks.getLenght(); i++)
        {
            ArraySequence<Field<double>> buff = *k;
            delete k;
            k = polynomialMut(ks[2], buff);
        }
        return k;
    }
    Sequence<Field<double>> *template <typename T>
    LinearSpace2D<T>::polynomialMut(const Sequence<Field<double>> &k1, const Sequence<Field<double>> &k2) const
    {
        ArraySequence<Field<double>> *k = new ArraySequence<Field<double>>(k1.getLenght() + k2.getLenght() - 2);
        for (uint64_t i1 = 0; i1 < k1.getLenght(); i1++)
        {
            for (uint64_t i2 = 0; i2 < k2.getLenght(); i2++)
            {
                (*k)[i1 + i2] += k1[i1] * k2[i2];
            }
        }
        return k;
    }
    uint64_t template <typename T>
    LinearSpace2D<T>::getSize() const
    {
        return size;
    }
    double &template <typename T>
    LinearSpace2D<T>::x(uint64_t index) const
    {
        return (*_x)[index];
    }
    double &template <typename T>
    LinearSpace2D<T>::y(uint64_t index) const
    {
        return (*_y)[index];
    }
    void template <typename T>
    LinearSpace2D<T>::normaliseLenght()
    {
        if (_x->getLenght() < _y->getLenght())
        {
            _y->resize(_x->getLenght());
            size = _x->getLenght();
        }
        else
        {
            _x->resize(_y->getLenght());
            size = _y->getLenght();
        }
    }
    template <typename T>
    LinearSpace2D<T>::~LinearSpace2D()
    {
        delete _x;
        delete _y;
    }
}

#endif
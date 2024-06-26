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
        data = new ArraySequence<Vector2D<T>>();
    }
    template <typename T>
    LinearSpace2D<T>::LinearSpace2D(const Sequence<Vector2D<T>> &vec)
    {
        data = vec.copy();
    }
    template <typename T>
    Polynom<T> LinearSpace2D<T>::lagrangePolynomial() const
    {
        Polynom<T> resPol;
        for (uint64_t i = 0; i < data->getLenght(); i++)
        {
            resPol = resPol + kroneckerDelta(i) * (*data)[i].y;
        }
        return resPol;
    }
    template <typename T>
    Polynom<T> LinearSpace2D<T>::kroneckerDelta(uint64_t index) const
    {
        if (index >= data->getLenght())
        {
            throw std::out_of_range("LinearSpace2D<T>::kroneckerDelta");
        }
        Polynom<T> resPol;
        ArraySequence<Polynom<T>> buff;
        for (uint64_t i = 0; i < data->getLenght(); i++)
        {
            if (i == index)
                continue;
            Field<T> magnitute = (*data)[index].x - (*data)[i].x;
            buff.append(Polynom<T>());
            buff.getLast().coeff->append(-(*data)[i].x / magnitute.data);
            buff.getLast().coeff->append(1.0 / magnitute.data);
        }
        resPol = buff[0] * buff[1];
        for (uint64_t i = 2; i < buff.getLenght(); i++)
        {
            resPol = buff[2] * resPol;
        }
        return resPol;
    }
    template <typename T>
    LinearSpace2D<T>::~LinearSpace2D()
    {
        delete data;
    }
}

#endif
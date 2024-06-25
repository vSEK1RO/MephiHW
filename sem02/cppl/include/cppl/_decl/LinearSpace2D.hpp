#ifndef LINEAR_SPACE_2D_HPP
#define LINEAR_SPACE_2D_HPP

#include <cppl/seq>

namespace cppl
{
    template <typename T>
    class LinearSpace2D
    {
    public:
        LinearSpace2D();
        LinearSpace2D(const Sequence<Field<T>> &x, const Sequence<Field<T>> &y);

        Sequence<Field<T>> *lagrangePolynomial() const;
        Sequence<Field<T>> *kroneckerDelta(uint64_t index) const;
        Sequence<Field<T>> *polynomialMut(const Sequence<Field<T>> &a, const Sequence<Field<T>> &b) const;

        uint64_t getSize() const;
        double &x(uint64_t index) const;
        double &y(uint64_t index) const;
        void normaliseLenght();

        ~LinearSpace2D();

    private:
        Sequence<Field<T>> *_x;
        Sequence<Field<T>> *_y;
        uint64_t size;
    };
}

#endif
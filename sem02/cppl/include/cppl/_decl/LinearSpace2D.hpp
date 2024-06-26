#ifndef LINEAR_SPACE_2D_HPP
#define LINEAR_SPACE_2D_HPP

#include <cppl/seq>
#include <cppl/vec2d>
#include <cppl/field>
#include <cppl/polynom>

namespace cppl
{
    template <typename T>
    class LinearSpace2D
    {
    public:
        Sequence<Vector2D<T>> *data;

        LinearSpace2D();
        LinearSpace2D(const Sequence<Vector2D<T>> &vec);

        Polynom<T> lagrangePolynomial() const;
        Polynom<T> kroneckerDelta(uint64_t index) const;

        ~LinearSpace2D();
    };
}

#endif
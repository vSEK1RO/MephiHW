#include <gtest/gtest.h>
#include <cstdio>

#include <cppl/linsp2d>
#include <cppl/arr>
#include <cppl/vec2d>
#include <cppl/field>
#include <cppl/fields.hpp>

using namespace cppl;

TEST(LinearSpace2D, kroneckerDelta)
{
    ArraySequence<Vector2D<double>> as;
    Vector2D<double> a(0, 2), b(1, -1), c(2, 0), d(3, -1);
    as.append(a);
    as.append(b);
    as.append(c);
    as.append(d);
    LinearSpace2D<double> linsp(as);
    Polynom<double> pol = linsp.kroneckerDelta(0);
    double arr[4] = {1.0, -11 / 6.0, 1.0, -1 / 6.0};
    EXPECT_EQ(pol.coeff->getLenght(), 4);
    for (uint64_t i = 0; i < pol.coeff->getLenght(); i++)
    {
        EXPECT_DOUBLE_EQ((*pol.coeff)[i].data, arr[i]);
    }
}
TEST(LinearSpace2D, lagrangePolynomial)
{
    ArraySequence<Vector2D<double>> as;
    Vector2D<double> a(0, 2), b(1, -1), c(2, 0), d(3, -1);
    as.append(a);
    as.append(b);
    as.append(c);
    as.append(d);
    LinearSpace2D<double> linsp(as);
    Polynom<double> pol = linsp.lagrangePolynomial();
    double arr[4] = {2.0, -7.0, 5.0, -1.0};
    EXPECT_EQ(pol.coeff->getLenght(), 4);
    for (uint64_t i = 0; i < pol.coeff->getLenght(); i++)
    {
        EXPECT_DOUBLE_EQ((*pol.coeff)[i].data, arr[i]);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
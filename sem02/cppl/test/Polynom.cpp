#include <gtest/gtest.h>
#include <cstdio>

#include <cppl/polynom>
#include <cppl/arr>
#include <cppl/field>

using namespace cppl;

TEST(Polynom, operator_mut)
{
    ArraySequence<Field<double>> a;
    for (uint64_t i = 1; i < 3; i++)
    {
        a.append(Field<double>(i));
    }
    Polynom<double> pola(a), polb(a);
    Polynom<double> pol = pola * polb;
    double arr[3] = {1, 4, 4};
    for (uint64_t i = 0; i < pol.coeff->getLenght(); i++)
    {
        EXPECT_DOUBLE_EQ((*pol.coeff)[i], arr[i]);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
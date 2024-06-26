#include <gtest/gtest.h>
#include <cstdio>

#include <cppl/polynom>
#include <cppl/arr>
#include <cppl/field>
#include <cppl/fields.hpp>

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
        EXPECT_DOUBLE_EQ((*pol.coeff)[i].data, arr[i]);
    }
}
TEST(Polynom, operator_mut_val)
{
    ArraySequence<Field<double>> a;
    for (uint64_t i = 1; i < 3; i++)
    {
        a.append(Field<double>(i));
    }
    Polynom<double> pola(a), polb(a);
    pola = pola * Field<double>(2.0);
    for (uint64_t i = 0; i < pola.coeff->getLenght(); i++)
    {
        EXPECT_DOUBLE_EQ((*pola.coeff)[i].data, 2*(*polb.coeff)[i].data);
    }
}
TEST(Polynom, operator_mut_sum)
{
    ArraySequence<Field<double>> a;
    for (uint64_t i = 1; i < 3; i++)
    {
        a.append(Field<double>(i));
    }
    Polynom<double> pola(a), polb(a);
    pola = pola * Field<double>(-1.0);
    pola = pola + polb;
    for (uint64_t i = 0; i < pola.coeff->getLenght(); i++)
    {
        EXPECT_DOUBLE_EQ((*pola.coeff)[i].data, 0.0);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
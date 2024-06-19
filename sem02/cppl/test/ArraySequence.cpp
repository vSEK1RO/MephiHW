#include <gtest/gtest.h>
#include <iostream>

#include <cppl.hpp>
using namespace cppl;

TEST(ArraySequence, Constructor)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    // EXPECT_TRUE(arr.isEqual(a, 3));
    // ArraySequence<int> brr;
    // EXPECT_TRUE(brr.isEqual(a, 0));
    // ArraySequence<int> err(1e3);
    // EXPECT_EQ(err.getSize(), 1e3);
    // int c[] = {0, 0, 0};
    // ArraySequence<int> crr(3, 0);
    // EXPECT_TRUE(crr.isEqual(c, 3));
    // ArraySequence<int> drr(arr);
    // EXPECT_EQ(arr, drr);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
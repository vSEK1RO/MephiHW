#include <gtest/gtest.h>
#include <iostream>

#include <cppl.hpp>
using namespace cppl;

TEST(DynamicArray, Constructor)
{
    int a[] = {1, 2, 3};
    DynamicArray<int> arr(a, 3);
    EXPECT_TRUE(arr.isEqual(a, 3));
    DynamicArray<int> brr;
    EXPECT_TRUE(brr.isEqual(a, 0));
    DynamicArray<int> err(1e3);
    EXPECT_EQ(err.getSize(), 1e3);
    int c[] = {0, 0, 0};
    DynamicArray<int> crr(3, 0);
    EXPECT_TRUE(crr.isEqual(c, 3));
    DynamicArray<int> drr(arr);
    EXPECT_EQ(arr, drr);
}
TEST(DynamicArray, operator_deref_by_index)
{
    int a[] = {1, 2, 3};
    DynamicArray<int> arr(a, 3);
    EXPECT_EQ(a[2], arr[2]);
}
TEST(DynamicArray, getSize)
{
    DynamicArray<int> arr(1e3, 0);
    EXPECT_EQ(arr.getSize(), 1e3);
}
TEST(DynamicArray, set)
{
    int a[] = {1, 2, 3};
    DynamicArray<int> arr(a, 3);
    arr.set(0, 3);
    EXPECT_EQ(3, arr[0]);
}
TEST(DynamicArray, resize)
{
    int a[] = {1, 2, 3};
    DynamicArray<int> arr(a, 3);
    arr.resize(2);
    EXPECT_TRUE(arr.isEqual(a, 2));
    EXPECT_EQ(arr.getSize(), 2);
}
TEST(DynamicArray, resize_1e6_pob)
{
    DynamicArray<int> arr(1e6);
    for (uint64_t i = 0; i < 1e6; i++)
    {
        arr.resize(arr.getSize() - 1);
    }
}
TEST(DynamicArray, resize_1e6_pub)
{
    DynamicArray<int> arr(0);
    for (uint64_t i = 0; i < 1e6; i++)
    {
        arr.resize(arr.getSize() + 1);
    }
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
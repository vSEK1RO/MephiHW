#include <gtest/gtest.h>
#include <cstdio>

#include <cppl/list>
using namespace cppl;

TEST(ListSequence, Constructor)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    EXPECT_TRUE(arr.isEqual(a, 3));
    ListSequence<int> brr;
    EXPECT_TRUE(brr.isEqual(a, 0));
    ListSequence<int> err(1e3);
    EXPECT_EQ(err.getLenght(), 1e3);
    int c[] = {0, 0, 0};
    ListSequence<int> crr(3, 0);
    EXPECT_TRUE(crr.isEqual(c, 3));
    ListSequence<int> drr(arr);
    EXPECT_EQ(arr, drr);
}
TEST(ListSequence, getFirst)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    EXPECT_EQ(arr.getFirst(), a[0]);
}
TEST(ListSequence, getLast)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    EXPECT_EQ(arr.getLast(), a[2]);
}
TEST(ListSequence, operator_deref_by_index)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    EXPECT_EQ(arr[1], a[1]);
}
TEST(ListSequence, getSubseq)
{
    int a[] = {1, 2, 3};
    ListSequence<int>
        arr(a, 3),
        brr(a, 2),
        crr(a + 1, 2);
    ListSequence<int> *a1 = arr.getSubseq(0, 2);
    ListSequence<int> *a2 = arr.getSubseq(1, 3);
    EXPECT_EQ(*a1, brr);
    EXPECT_EQ(*a2, crr);
    delete a1;
    delete a2;
}
TEST(ListSequence, getLenght)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    EXPECT_EQ(arr.getLenght(), 3);
}
TEST(ListSequence, append)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 2);
    arr.append(3);
    EXPECT_TRUE(arr.isEqual(a, 3));
}
TEST(ListSequence, prepend)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a + 1, 2);
    arr.prepend(1);
    EXPECT_TRUE(arr.isEqual(a, 3));
}
TEST(ListSequence, append_1e6)
{
    ListSequence<int> arr(0);
    for (uint64_t i = 0; i < 1e4; i++)
    {
        arr.append(0);
    }
}
TEST(ListSequence, preppend_1e6)
{
    ListSequence<int> arr(0);
    for (uint64_t i = 0; i < 1e6; i++)
    {
        arr.prepend(0);
    }
}
TEST(ListSequence, insertAt)
{
    int a[] = {1, 2, 3};
    int b[] = {1, 3};
    ListSequence<int> arr(b, 2);
    arr.insertAt(2, 1);
    EXPECT_TRUE(arr.isEqual(a, 3));
}
TEST(ListSequence, operator_plus)
{
    int a[] = {1, 2, 3};
    int b[] = {1, 3};
    ListSequence<int> arr(a, 3), brr(b, 2);
    int c[] = {1, 2, 3, 1, 3};
    ListSequence<int> *crr = arr + brr;
    EXPECT_TRUE(crr->isEqual(c, 3));
    delete crr;
}
TEST(ListSequence, copy)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    ListSequence<int> *brr = arr.copy();
    arr[0] = 3;
    EXPECT_FALSE(*brr == arr);
    delete brr;
}
TEST(ListSequence, resize)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a, 3);
    arr.resize(2);
    EXPECT_TRUE(arr.isEqual(a, 2));
    EXPECT_EQ(arr.getLenght(), 2);
}
int map(const int &item, uint64_t index){
    return item*2;
}
TEST(ListSequence, map)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a,3);
    ListSequence<int> *brr = arr.map(map);
    int b[] = {2, 4, 6};
    EXPECT_TRUE(brr->isEqual(b,3));
    delete brr;
}
bool where(const int &item, uint64_t index)
{
    return index%2==0?true:false;
}
TEST(ListSequence, where)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a,3);
    ListSequence<int> *brr = arr.where(where);
    int b[] = {1, 3};
    EXPECT_TRUE(brr->isEqual(b,2));
    delete brr;
}
int reduce(const int &a, const int &b)
{
    return a+b;
}
TEST(ListSequence, reduce)
{
    int a[] = {1, 2, 3};
    ListSequence<int> arr(a,3);
    EXPECT_EQ(arr.reduce(reduce,0),6);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
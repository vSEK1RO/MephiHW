#include <gtest/gtest.h>
#include <cstdio>

#include <cppl/arr>
using namespace cppl;

void print(const ArraySequence<int> &arr)
{
    for(uint64_t i=0;i<arr.getLenght();i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

TEST(ArraySequence, Constructor)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    EXPECT_TRUE(arr.isEqual(a, 3));
    ArraySequence<int> brr;
    EXPECT_TRUE(brr.isEqual(a, 0));
    ArraySequence<int> err(1e3);
    EXPECT_EQ(err.getLenght(), 1e3);
    int c[] = {0, 0, 0};
    ArraySequence<int> crr(3, 0);
    EXPECT_TRUE(crr.isEqual(c, 3));
    ArraySequence<int> drr(arr);
    EXPECT_EQ(arr, drr);
}
TEST(ArraySequence, getFirst)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    EXPECT_EQ(arr.getFirst(), a[0]);
}
TEST(ArraySequence, getLast)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    EXPECT_EQ(arr.getLast(), a[2]);
}
TEST(ArraySequence, operator_deref_by_index)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    EXPECT_EQ(arr[1], a[1]);
}
TEST(ArraySequence, getSubseq)
{
    int a[] = {1, 2, 3};
    ArraySequence<int>
        arr(a, 3),
        brr(a, 2),
        crr(a + 1, 2);
    ArraySequence<int> *a1=arr.getSubseq(0, 2);
    ArraySequence<int> *a2=arr.getSubseq(1,3);
    EXPECT_EQ(*a1, brr);
    EXPECT_EQ(*a2, crr);
    delete a1;
    delete a2;
}
TEST(ArraySequence, getLenght)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    EXPECT_EQ(arr.getLenght(), 3);
}
TEST(ArraySequence, append)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 2);
    arr.append(3);
    EXPECT_TRUE(arr.isEqual(a, 3));
}
TEST(ArraySequence, prepend)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a + 1, 2);
    arr.prepend(1);
    EXPECT_TRUE(arr.isEqual(a, 3));
}
TEST(ArraySequence, append_1e6)
{
    ArraySequence<int> arr(0);
    for (uint64_t i = 0; i < 1e6; i++)
    {
        arr.append(0);
    }
}
TEST(ArraySequence, insertAt)
{
    int a[] = {1, 2, 3};
    int b[] = {1, 3};
    ArraySequence<int> arr(b, 2);
    arr.insertAt(2,1);
    EXPECT_TRUE(arr.isEqual(a,3));
}
TEST(ArraySequence, operator_plus)
{
    int a[] = {1, 2, 3};
    int b[] = {1, 3};
    ArraySequence<int> arr(a,3), brr(b,2);
    int c[] = {1, 2, 3, 1, 3};
    ArraySequence<int> * crr = arr + brr;
    EXPECT_TRUE(crr->isEqual(c,5));
    delete crr;
}
TEST(ArraySequence, copy)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    ArraySequence<int> *brr = arr.copy();
    arr[0] = 3;
    EXPECT_FALSE(*brr == arr);
    delete brr;
}
TEST(ArraySequence, resize)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a, 3);
    arr.resize(2);
    EXPECT_TRUE(arr.isEqual(a, 2));
    EXPECT_EQ(arr.getLenght(), 2);
}
int map(const int &item, uint64_t index){
    return item*2;
}
TEST(ArraySequence, map)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a,3);
    ArraySequence<int> *brr = arr.map(map);
    int b[] = {2, 4, 6};
    EXPECT_TRUE(brr->isEqual(b,3));
    delete brr;
}
bool where(const int &item, uint64_t index)
{
    return index%2==0?true:false;
}
TEST(ArraySequence, where)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a,3);
    ArraySequence<int> *brr = arr.where(where);
    int b[] = {1, 3};
    EXPECT_TRUE(brr->isEqual(b,2));
    delete brr;
}
int reduce(const int &a, const int &b)
{
    return a+b;
}
TEST(ArraySequence, reduce)
{
    int a[] = {1, 2, 3};
    ArraySequence<int> arr(a,3);
    EXPECT_EQ(arr.reduce(reduce,0),6);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
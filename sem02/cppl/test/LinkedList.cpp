#include <gtest/gtest.h>

#include <cppl/list>
using namespace cppl;

TEST(LinkedList, Constructor)
{
    int a[] = {1, 2, 3};
    LinkedList<int> arr(a, 3);
    EXPECT_TRUE(arr.isEqual(a, 3));
    LinkedList<int> brr;
    EXPECT_TRUE(brr.isEqual(a, 0));
    LinkedList<int> err(1e3);
    EXPECT_EQ(err.getSize(), 1e3);
    int c[] = {0, 0, 0};
    LinkedList<int> crr(3, 0);
    EXPECT_TRUE(crr.isEqual(c, 3));
    LinkedList<int> drr(arr);
    EXPECT_EQ(arr, drr);
}
TEST(LinkedList, erase)
{
    int a[] = {1, 2, 3};
    LinkedList<int> arr(a, 3);
    LinkedList<int> brr(arr), crr(arr), drr(arr);
    arr.erase(0,2);
    brr.erase(1,3);
    crr.erase(1,2);
    drr.erase(0,3);
    int c[] = {1, 3};
    EXPECT_TRUE(arr.isEqual(a+2,1));
    EXPECT_TRUE(brr.isEqual(a,1));
    EXPECT_TRUE(crr.isEqual(c,2));
    EXPECT_TRUE(drr.isEqual(a,0));
}
TEST(LinkedList, insertAt)
{
    int a[] = {1, 2, 3};
    int d[] = {1, 3};
    LinkedList<int> arr(a, 3), brr(a, 2), crr(a+1, 2), drr(d, 2);
    brr.insertAt(3,2);
    crr.insertAt(1,0);
    drr.insertAt(2,1);
    EXPECT_EQ(arr,brr);
    EXPECT_EQ(arr,crr);
    EXPECT_EQ(arr,drr);
}
TEST(LinkedList, rearr)
{
    int a[] = {1, 2, 3};
    int b[] = {2, 1, 3};
    int c[] = {1, 3, 2};
    int d[] = {2, 3, 1};
    LinkedList<int> arr(a,3), brr(b, 3), crr(c, 3), drr(d, 3);
    brr.rearr(0,1);
    crr.rearr(1,2);
    drr.rearr(2,0);
    EXPECT_EQ(arr,brr);
    EXPECT_EQ(arr,crr);
    EXPECT_EQ(arr,drr);
}
TEST(LinkedList, find)
{
    int a[] = {1, 2, 2};
    LinkedList<int> arr(a,3), brr(a, 0);
    EXPECT_EQ(arr.find(2,(uint64_t)1),1);
    EXPECT_EQ(brr.find(2,(uint64_t)3),-1);
}
TEST(LinkedList, count)
{
    int a[] = {1, 2, 2};
    LinkedList<int> arr(a,3), brr(a, 0);
    EXPECT_EQ(arr.count(2),2);
    EXPECT_EQ(brr.count(2),0);
}
TEST(LinkedList, operator_deref_by_index)
{
    int a[] = {1, 2, 3};
    LinkedList<int> arr(a, 3);
    EXPECT_EQ(a[2], arr[2]);
}
TEST(LinkedList, getSize)
{
    LinkedList<int> err(1e3);
    EXPECT_EQ(err.getSize(), 1e3);
}
TEST(LinkedList, set)
{
    int a[] = {1, 2, 3};
    LinkedList<int> arr(a, 3);
    arr.set(0, 3);
    EXPECT_EQ(3, arr[0]);
}
TEST(LinkedList, resize){
    int a[] = {1, 2, 3};
    LinkedList<int> arr(a, 3);
    arr.resize(2);
    EXPECT_TRUE(arr.isEqual(a,2));
}
TEST(LinkedList, resize_1e6_pub){
    LinkedList<int> arr(0);
    for(uint64_t i=0;i<1e6;i++){
        arr.resize(arr.getSize()+1);
    }
}
TEST(LinkedList, resize_1e6_pob){
    LinkedList<int> arr(1e6);
    for(uint64_t i=0;i<1e6;i++){
        arr.resize(arr.getSize()-1);
    }
}
TEST(LinkedList, resizeRevert){
    int a[] = {1, 2, 3};
    LinkedList<int> arr(a, 3);
    arr.resizeRevert(2);
    EXPECT_TRUE(arr.isEqual(a+1,2));
}
TEST(LinkedList, resizeRevert_1e6_puf){
    LinkedList<int> arr(0);
    for(uint64_t i=0;i<1e6;i++){
        arr.resizeRevert(arr.getSize()+1);
    }
}
TEST(LinkedList, resizeRevert_1e6_pof){
    LinkedList<int> arr(1e6);
    for(uint64_t i=0;i<1e6;i++){
        arr.resizeRevert(arr.getSize()-1);
    }
}
TEST(LinkedList, operator_eq)
{
    int a[3] = {1, 2, 3};
    LinkedList<int> arr(a,3);
    LinkedList<int> brr;
    brr = arr;
    arr.resize(0);
    EXPECT_FALSE(arr==brr);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
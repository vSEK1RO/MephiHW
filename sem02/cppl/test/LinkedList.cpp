#include <gtest/gtest.h>

#include <cppl.hpp>
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

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
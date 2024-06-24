#include <gtest/gtest.h>
#include <cstdio>

#include <cppl/unip>
using namespace cppl;

TEST(UniquePointer, Constructor_Destructor)
{
    UniquePointer<int> a(new int);
    a.getData() = 10;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
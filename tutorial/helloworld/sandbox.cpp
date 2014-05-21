#include <gtest/gtest.h>
#include <iostream>
#include <string>
using namespace std;

int bitParity(int x) {
    int wd16 = x ^ (x>>16); /* Combine into 16 bits */
     int wd8  = wd16 ^ (wd16>>8); /* Combine into 8 bits */
     int wd4  = wd8 ^ (wd8>>4);
     int wd2  = wd4 ^ (wd4>>2);
     int bit  = (wd2 ^ (wd2>>1)) & 0x1;
     return bit;
}

int bitParityAnswer(int x) {
    int wd16 = x ^ (x>>16); /* Combine into 16 bits */
    int wd8  = wd16 ^ (wd16>>8); /* Combine into 8 bits */
    int wd4  = wd8 ^ (wd8>>4);
    int wd2  = wd4 ^ (wd4>>2);
    int bit  = (wd2 ^ (wd2>>1)) & 0x1;
    return bit;
}

int absVal(int x) {
    int s = x >> 31;
    return (s & (~x+1)) + (!s)&x;
}

int absValAnswer(int x) {
    return x>0?x:-x;
}

TEST(Problem7, Part2) {
    ASSERT_EQ(bitParityAnswer(0x80000000), bitParity(0x80000000));
    ASSERT_EQ(bitParityAnswer(0x7fffffff), bitParity(0x7fffffff));
    for (int i = -1024; i <= 1024; ++i) {
        ASSERT_EQ(bitParityAnswer(i), bitParity(i));
    }
}

TEST(Problem7, Part1) {
    ASSERT_EQ(absValAnswer(0x80000000), absVal(0x80000000));
    ASSERT_EQ(absValAnswer(0x7fffffff), absVal(0x7fffffff));
    for (int i = -1020004; i <= 1000204; ++i) {
        ASSERT_EQ(absValAnswer(i), absVal(i));
    }
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

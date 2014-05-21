#include <gtest/gtest.h>

int Gcd(int a, int b) {
    if (a == 0 || b == 0) {
        throw "don't do that";
    }
    int c = a % b;
    if (c == 0) return b;
    return Gcd(b, c);
}

TEST(GcdTest, HandleNoneZeroInput) {
    EXPECT_EQ(2, Gcd(4, 10));
    EXPECT_EQ(6, Gcd(30, 18));
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

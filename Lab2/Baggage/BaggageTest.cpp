#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Baggage.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 2\PPOISLab2\Baggage.cpp"

TEST(BaggageTest, Initialization) {
    Baggage baggage(20, 2);
    EXPECT_EQ(baggage.weight, 20);
    EXPECT_EQ(baggage.numberOfPieces, 2);
}

TEST(BaggageTest, ZeroWeightAndPieces) {
    Baggage baggage(0, 0);
    EXPECT_EQ(baggage.weight, 0);
    EXPECT_EQ(baggage.numberOfPieces, 0);
}

TEST(BaggageTest, LargeValues) {
    Baggage baggage(100, 10);
    EXPECT_EQ(baggage.weight, 100);
    EXPECT_EQ(baggage.numberOfPieces, 10);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


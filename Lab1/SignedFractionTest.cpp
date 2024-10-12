#include "pch.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 1\PPOISLab1\SignedFraction.h"
#include "D:\BSUIR\2 курс\ППОИС\ЛР 1\PPOISLab1\SignedFraction.cpp"

// Тесты для конструктора и методов доступа
TEST(SignedFractionTest, ConstructorAndAccessors) {
    SignedFraction frac(3, 4);
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 4);
    EXPECT_EQ(frac.getWholePart(), 0);
}

// Тесты для операторов сложения
TEST(SignedFractionTest, AdditionOperators) {
    SignedFraction frac1(1, 2);
    SignedFraction frac2(1, 3);
    SignedFraction result = frac1 + frac2;
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 6);

    frac1 += frac2;
    EXPECT_EQ(frac1.getNumerator(), 5);
    EXPECT_EQ(frac1.getDenominator(), 6);
}

// Тесты для операторов вычитания
TEST(SignedFractionTest, SubtractionOperators) {
    SignedFraction frac1(1, 2);
    SignedFraction frac2(1, 3);
    SignedFraction result = frac1 - frac2;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 6);

    frac1 -= frac2;
    EXPECT_EQ(frac1.getNumerator(), 1);
    EXPECT_EQ(frac1.getDenominator(), 6);
}

// Тесты для операторов умножения
TEST(SignedFractionTest, MultiplicationOperators) {
    SignedFraction frac1(1, 2);
    SignedFraction frac2(2, 3);
    SignedFraction result = frac1 * frac2;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 3);

    frac1 *= frac2;
    EXPECT_EQ(frac1.getNumerator(), 1);
    EXPECT_EQ(frac1.getDenominator(), 3);
}

// Тесты для операторов деления
TEST(SignedFractionTest, DivisionOperators) {
    SignedFraction frac1(1, 2);
    SignedFraction frac2(2, 3);
    SignedFraction result = frac1 / frac2;
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 4);

    frac1 /= frac2;
    EXPECT_EQ(frac1.getNumerator(), 3);
    EXPECT_EQ(frac1.getDenominator(), 4);
}

// Тесты для операторов сравнения
TEST(SignedFractionTest, ComparisonOperators) {
    SignedFraction frac1(1, 2);
    SignedFraction frac2(2, 3);
    EXPECT_TRUE(frac2 > frac1);
    EXPECT_TRUE(frac1 < frac2);
    EXPECT_TRUE(frac1 <= frac2);
    EXPECT_FALSE(frac1 >= frac2);
}

// Тесты для операторов инкремента и декремента
TEST(SignedFractionTest, IncrementDecrementOperators) {
    SignedFraction frac(1, 2);
    ++frac;
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 2);

    frac--;
    EXPECT_EQ(frac.getNumerator(), 1);
    EXPECT_EQ(frac.getDenominator(), 2);
}

// Тесты для приведения к double
TEST(SignedFractionTest, ConversionToDouble) {
    SignedFraction frac(1, 2);
    double value = static_cast<double>(frac);
    EXPECT_DOUBLE_EQ(value, 0.5);
}

// Тесты для операторов сложения с целым числом
TEST(SignedFractionTest, AdditionWithInteger) {
    SignedFraction frac(1, 2);
    SignedFraction result = frac + 2;
    EXPECT_EQ(result.getNumerator(), 5);
    EXPECT_EQ(result.getDenominator(), 2);

    frac += 2;
    EXPECT_EQ(frac.getNumerator(), 5);
    EXPECT_EQ(frac.getDenominator(), 2);
}

// Тесты для операторов вычитания с целым числом
TEST(SignedFractionTest, SubtractionWithInteger) {
    SignedFraction frac(5, 2);
    SignedFraction result = frac - 2;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);

    frac -= 2;
    EXPECT_EQ(frac.getNumerator(), 1);
    EXPECT_EQ(frac.getDenominator(), 2);
}

// Тесты для операторов умножения с целым числом
TEST(SignedFractionTest, MultiplicationWithInteger) {
    SignedFraction frac(1, 2);
    SignedFraction result = frac * 3;
    EXPECT_EQ(result.getNumerator(), 3);
    EXPECT_EQ(result.getDenominator(), 2);

    frac *= 3;
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 2);
}

// Тесты для операторов деления с целым числом
TEST(SignedFractionTest, DivisionWithInteger) {
    SignedFraction frac(3, 2);
    SignedFraction result = frac / 3;
    EXPECT_EQ(result.getNumerator(), 1);
    EXPECT_EQ(result.getDenominator(), 2);

    frac /= 3;
    EXPECT_EQ(frac.getNumerator(), 1);
    EXPECT_EQ(frac.getDenominator(), 2);
}

// Тесты для исключений в конструкторе
TEST(SignedFractionTest, ConstructorThrowsExceptionOnZeroDenominator) {
    EXPECT_THROW(SignedFraction(1, 0), std::invalid_argument);
}

// Тесты для метода reduce
TEST(SignedFractionTest, ReduceMethod) {
    SignedFraction frac(4, 8);
    EXPECT_EQ(frac.getNumerator(), 1);
    EXPECT_EQ(frac.getDenominator(), 2);
}


// Тесты для оператора <=
TEST(SignedFractionTest, LessThanOrEqualOperator) {
    SignedFraction frac1(1, 2);
    SignedFraction frac2(2, 3);
    SignedFraction frac3(1, 2);
    EXPECT_TRUE(frac1 <= frac2);
    EXPECT_TRUE(frac1 <= frac3);
    EXPECT_FALSE(frac2 <= frac1);
}

// Тесты для операторов ++ и --
TEST(SignedFractionTest, IncrementDecrementOperatorsPostfix) {
    SignedFraction frac(1, 2);
    SignedFraction temp = frac++;
    EXPECT_EQ(temp.getNumerator(), 1);
    EXPECT_EQ(temp.getDenominator(), 2);
    EXPECT_EQ(frac.getNumerator(), 3);
    EXPECT_EQ(frac.getDenominator(), 2);

    temp = frac--;
    EXPECT_EQ(temp.getNumerator(), 3);
    EXPECT_EQ(temp.getDenominator(), 2);
    EXPECT_EQ(frac.getNumerator(), 1);
    EXPECT_EQ(frac.getDenominator(), 2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 

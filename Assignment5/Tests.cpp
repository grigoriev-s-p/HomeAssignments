#include <gtest/gtest.h>

#include "Matrix.h"
#include "Rational.h"


TEST(RationalTest, ConstructorAndNormalization)
{
    Rtl a(2, 4);
    EXPECT_EQ(a.getNumerator(), 1);
    EXPECT_EQ(a.getDenominator(), 2);

    Rtl b(-2, -4);
    EXPECT_EQ(b.getNumerator(), 1);
    EXPECT_EQ(b.getDenominator(), 2);

    Rtl c(1, -3);
    EXPECT_EQ(c.getNumerator(), -1);
    EXPECT_EQ(c.getDenominator(), 3);
}

TEST(RationalTest, ZeroDenominatorThrows)
{
    EXPECT_THROW(Rtl(1, 0), std::invalid_argument);
}

TEST(RationalTest, ArithmeticOperations)
{
    Rtl a(1, 2);
    Rtl b(1, 3);

    EXPECT_EQ(a + b, Rtl(5, 6));
    EXPECT_EQ(a - b, Rtl(1, 6));
    EXPECT_EQ(a * b, Rtl(1, 6));
    EXPECT_EQ(a / b, Rtl(3, 2));
}

TEST(MatrixIntTest, CreateAndAccess)
{
    Matrix<int> m(2, 3);

    m.element(0, 0) = 1;
    m.element(1, 2) = 5;

    EXPECT_EQ(m.element(0, 0), 1);
    EXPECT_EQ(m.element(1, 2), 5);
}

TEST(MatrixIntTest, Addition)
{
    Matrix<int> a(2, 2);
    Matrix<int> b(2, 2);

    a.element(0, 0) = 1;
    a.element(1, 1) = 2;

    b.element(0, 0) = 3;
    b.element(1, 1) = 4;

    Matrix<int> c = a.add(b);

    EXPECT_EQ(c.element(0, 0), 4);
    EXPECT_EQ(c.element(1, 1), 6);
}

TEST(MatrixIntTest, ScalarMultiplication)
{
    Matrix<int> m(2, 2);
    m.element(0, 0) = 2;
    m.element(1, 1) = 3;

    Matrix<int> r = m.multiply(2);

    EXPECT_EQ(r.element(0, 0), 4);
    EXPECT_EQ(r.element(1, 1), 6);
}

TEST(MatrixIntTest, MatrixMultiplication)
{
    Matrix<int> a(2, 3);
    Matrix<int> b(3, 2);

    a.element(0, 0) = 1;
    a.element(0, 1) = 2;
    a.element(0, 2) = 3;

    b.element(0, 0) = 1;
    b.element(1, 0) = 1;
    b.element(2, 0) = 1;

    Matrix<int> c = a.multiply(b);

    EXPECT_EQ(c.rowCount(), 2);
    EXPECT_EQ(c.colCount(), 2);
    EXPECT_EQ(c.element(0, 0), 6);
}

TEST(MatrixDoubleTest, BasicOperations)
{
    Matrix<double> m(2, 2);
    m.element(0, 0) = 1.5;
    m.element(1, 1) = 2.5;

    Matrix<double> r = m.multiply(2.0);

    EXPECT_DOUBLE_EQ(r.element(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(r.element(1, 1), 5.0);
}

TEST(MatrixRationalTest, Addition)
{
    Matrix<Rtl> a(2, 2);
    Matrix<Rtl> b(2, 2);

    a.element(0, 0) = Rtl(1, 2);
    b.element(0, 0) = Rtl(1, 3);

    Matrix<Rtl> c = a.add(b);

    EXPECT_EQ(c.element(0, 0), Rtl(5, 6));
}

TEST(MatrixRationalTest, Multiplication)
{
    Matrix<Rtl> a(1, 2);
    Matrix<Rtl> b(2, 1);

    a.element(0, 0) = Rtl(1, 2);
    a.element(0, 1) = Rtl(1, 3);

    b.element(0, 0) = Rtl(2, 1);
    b.element(1, 0) = Rtl(3, 1);

    Matrix<Rtl> c = a.multiply(b);

    EXPECT_EQ(c.element(0, 0), Rtl(2, 1));
}

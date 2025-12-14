// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include <gtest/gtest.h>
#include "../src/matrix.h"
#include "../src/rational.h"

// --- Rational Tests ---
TEST(RationalTest, BasicOperations)
{
    Rational r1(1, 2);
    Rational r2(1, 4);
    
    EXPECT_EQ(r1 + r2, Rational(3, 4));
    EXPECT_EQ(r1 - r2, Rational(1, 4));
    EXPECT_EQ(r1 * r2, Rational(1, 8));
    EXPECT_EQ(r1 / r2, Rational(2, 1)); // 1/2 / 1/4 = 2
}

TEST(RationalTest, Simplification)
{
    Rational r(2, 4);
    EXPECT_EQ(r.getNum(), 1);
    EXPECT_EQ(r.getDenom(), 2);
    
    Rational r2(5, -10);
    EXPECT_EQ(r2.getNum(), -1);
    EXPECT_EQ(r2.getDenom(), 2);
}

// --- Matrix <int> Tests ---
TEST(MatrixIntTest, Addition)
{
    Matrix<int> m1(2, 2);
    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;
    
    Matrix<int> m2(2, 2);
    m2(0, 0) = 1; m2(0, 1) = 1;
    m2(1, 0) = 1; m2(1, 1) = 1;
    
    Matrix<int> sum = m1 + m2;
    EXPECT_EQ(sum(0, 0), 2);
    EXPECT_EQ(sum(1, 1), 5);
}

TEST(MatrixIntTest, Multiplication)
{
    Matrix<int> m1(2, 3);
    // 1 2 3
    // 4 5 6
    m1(0,0)=1; m1(0,1)=2; m1(0,2)=3;
    m1(1,0)=4; m1(1,1)=5; m1(1,2)=6;

    Matrix<int> m2(3, 2);
    // 7 8
    // 9 1
    // 2 3
    m2(0,0)=7; m2(0,1)=8;
    m2(1,0)=9; m2(1,1)=1;
    m2(2,0)=2; m2(2,1)=3;

    // Res:
    // 1*7+2*9+3*2=31  1*8+2*1+3*3=19
    // 4*7+5*9+6*2=85  4*8+5*1+6*3=55
    Matrix<int> res = m1 * m2;
    EXPECT_EQ(res.getRows(), 2);
    EXPECT_EQ(res.getCols(), 2);
    EXPECT_EQ(res(0, 0), 31);
    EXPECT_EQ(res(0, 1), 19);
    EXPECT_EQ(res(1, 0), 85);
    EXPECT_EQ(res(1, 1), 55);
}

TEST(MatrixIntTest, Transpose)
{
    Matrix<int> m(2, 3);
    m(0,1) = 5;
    Matrix<int> t = m.transpose();
    EXPECT_EQ(t.getRows(), 3);
    EXPECT_EQ(t.getCols(), 2);
    EXPECT_EQ(t(1, 0), 5); 
}

// --- Matrix <double> Tests ---
TEST(MatrixDoubleTest, ScalarMult)
{
    Matrix<double> m(2, 2);
    m(0, 0) = 1.5; m(0, 1) = 2.0; 
    
    Matrix<double> res = m * 2.0;
    EXPECT_DOUBLE_EQ(res(0, 0), 3.0);
    EXPECT_DOUBLE_EQ(res(0, 1), 4.0);
}

// --- Matrix <Rational> Tests ---
TEST(MatrixRationalTest, Ops)
{
    Matrix<Rational> m1(2, 2);
    m1(0, 0) = Rational(1, 2);
    m1(1, 1) = Rational(1, 3);
    
    Matrix<Rational> m2(2, 2);
    m2(0, 0) = Rational(1, 2);
    
    Matrix<Rational> sum = m1 + m2;
    EXPECT_EQ(sum(0, 0), Rational(1, 1)); // 1/2 + 1/2 = 1
    EXPECT_EQ(sum(1, 1), Rational(1, 3)); // 1/3 + 0 = 1/3
    
    // Scalar mult
    Matrix<Rational> scaled = m1 * Rational(2, 1);
    EXPECT_EQ(scaled(0, 0), Rational(1, 1)); // 1/2 * 2 = 1
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

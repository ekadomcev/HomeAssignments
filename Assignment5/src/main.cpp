// Author: Egor Kadomtsev
// Group: 25.Б81-мм
// Contact: st116930@student.spbu.ru

#include <iostream>
#include "matrix.h"
#include "rational.h"

int main()
{
    Matrix<int> m1(2, 2);
    m1(0, 0) = 1; m1(0, 1) = 2;
    m1(1, 0) = 3; m1(1, 1) = 4;

    std::cout << "Matrix<int>:" << std::endl;
    std::cout << m1 << std::endl;

    Matrix<Rational> m2(2, 2);
    m2(0, 0) = Rational(1, 2); m2(0, 1) = Rational(1, 3);
    m2(1, 0) = Rational(1, 4); m2(1, 1) = Rational(1, 5);

    std::cout << "Matrix<Rational>:" << std::endl;
    std::cout << m2 << std::endl;

    return 0;
}

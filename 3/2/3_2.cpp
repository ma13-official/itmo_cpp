#include <iostream>
#include <cmath>

double cubicRootUsingPow(double num) {
    return pow(num, 1.0/3.0);
}

double cubicRootUsingIteration(double num) {
    double epsilon = 0.0001; // точность вычисления
    double guess = num / 3.0; // начальное предположение

    while (abs(guess * guess * guess - num) >= epsilon) {
        guess = guess - (guess * guess * guess - num) / (3.0 * guess * guess);
    }

    return guess;
}

int main() {
    double number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    double result1 = cubicRootUsingPow(number);
    double result2 = cubicRootUsingIteration(number);
    
    std::cout << "1. Using pow function: Cubic root of " << number << " = " << result1 << std::endl;
    std::cout << "2. Using iteration: Cubic root of " << number << " = " << result2 << std::endl;

    return 0;
}

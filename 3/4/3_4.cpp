#include <iostream>

int sumOfSeries(int n) {
    // Базовый случай: когда n равно 1, возвращаем первый член ряда
    if (n == 1) {
        return 5;
    } else {
        // Рекурсивный случай: суммируем текущий член ряда (5 * n) с предыдущими членами
        return 5 * n + sumOfSeries(n - 1);
    }
}

int main() {
    int n;
    std::cout << "Enter the value of n (> 0): ";
    std::cin >> n;

    if (n > 0) {
        int result = sumOfSeries(n);
        std::cout << "The sum of the series for n = " << n << " is " << result << std::endl;
    } else {
        std::cout << "Enter a value of n greater than 0." << std::endl;
    }

    return 0;
}

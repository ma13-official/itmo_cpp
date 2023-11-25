#include <iostream>
#include <string>

// Функция для перевода числа из десятичной системы в двоичную
std::string decimalToBinary(int num) {
    if (num == 0) {
        return "0"; // Базовый случай: если число равно 0, возвращаем строку "0"
    } else if (num == 1) {
        return "1"; // Базовый случай: если число равно 1, возвращаем строку "1"
    } else {
        // Рекурсивный случай: делим число на 2, рекурсивно вызываем функцию и конвертируем остаток в двоичную систему
        return decimalToBinary(num / 2) + std::to_string(num % 2);
    }
}

int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Please enter a positive number." << std::endl;
    } else {
        std::string binary = decimalToBinary(number);
        std::cout << "Number " << number << " in binary: " << binary << std::endl;
    }

    return 0;
}

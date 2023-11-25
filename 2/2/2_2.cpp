#include <iostream>
#include <string>

bool isValidSNILS(const std::string& snils) {
    if (snils.length() != 11) { // Проверка длины строки на соответствие формату СНИЛС
        return false;
    }

    // Проверка наличия только цифр во входной строке
    for (char c : snils) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    // Проверка, чтобы первые 9 цифр не содержали более двух одинаковых цифр подряд
    for (int i = 0; i < snils.length() - 2; ++i) {
        if (snils[i] == snils[i + 1] && snils[i] == snils[i + 2]) {
            return false;
        }
    }

    // Вычисление контрольного числа
    int controlNumber = 0;
    for (int i = 0; i < 9; ++i) {
        controlNumber += (snils[i] - '0') * (9 - i);
    }

    // Проверка полученного контрольного числа в соответствии с правилами
    if (controlNumber < 100) {
        return controlNumber == std::stoi(snils.substr(9, 2));
    } else if (controlNumber == 100 || controlNumber == 101) {
        return std::stoi(snils.substr(9, 2)) == 0;
    } else {
        int remainder = controlNumber % 101;
        if (remainder < 100) {
            return remainder == std::stoi(snils.substr(9, 2));
        } else {
            return std::stoi(snils.substr(9, 2)) == 0;
        }
    }
}

int main() {
    std::string snilsNumber;
    std::cout << "Enter SNILS: ";
    std::cin >> snilsNumber;

    if (isValidSNILS(snilsNumber)) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
    }

    return 0;
}

#include <iostream>
#include <limits>

bool Input(int &a, int &b) {
    std::cout << "Enter two numbers: ";
    
    // Проверка на корректность ввода первого числа
    if (!(std::cin >> a)) {
        std::cerr << "Error in input for first number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    
    // Проверка на корректность ввода второго числа
    if (!(std::cin >> b)) {
        std::cerr << "Error in input for second number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    
    return true;
}

int main() {
    int a, b;
    
    if (!Input(a, b)) {
        std::cerr << "Error in input\n";
        return 1;
    }
    
    int s = a + b;
    std::cout << "Sum: " << s << std::endl;
    
    return 0;
}

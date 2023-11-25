#include <iostream>
#include <cmath>

int Myroot(double a, double b, double c, double& x1, double& x2) {
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);
        return 2; // два различных корня
    } else if (discriminant == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
        return 0; // один корень
    } else {
        return -1; // корней нет
    }
}

int main() {
    double a, b, c, x1, x2;
    std::cout << "Enter the coefficients of the quadratic equation (a, b, c): ";
    std::cin >> a >> b >> c;

    int result = Myroot(a, b, c, x1, x2);

    if (result == 2) {
        std::cout << "The roots of the equation are x1 = " << x1 << ", x2 = " << x2 << std::endl;
    } else if (result == 0) {
        std::cout << "The root of the equation is x1 = x2 = " << x1 << std::endl;
    } else {
        std::cout << "There are no roots for the equation" << std::endl;
    }

    return 0;
}

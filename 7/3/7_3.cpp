#include <iostream>
#include <tuple>
#include <cmath>

std::tuple<double, double, bool> solveQuadraticEquation(double a, double b, double c) {
    double root1, root2;
    bool realRoots = false;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        realRoots = true;
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        realRoots = true;
        root1 = -b / (2 * a);
        root2 = root1;
    }

    return std::make_tuple(root1, root2, realRoots);
}

int main() {
    double a, b, c;
    std::cout << "Enter the coefficients of the quadratic equation (ax^2 + bx + c = 0): " << std::endl;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;

    auto result = solveQuadraticEquation(a, b, c);

    double root1, root2;
    bool realRoots;
    std::tie(root1, root2, realRoots) = result;

    if (realRoots) {
        std::cout << "The roots of the equation: x1 = " << root1 << ", x2 = " << root2 << std::endl;
    } else {
        std::cout << "The equation has no real roots." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <cmath>

struct QuadraticEquationSolution {
    double root1;
    double root2;
    bool realRoots; // Флаг, указывающий на наличие вещественных корней
};

QuadraticEquationSolution solveQuadraticEquation(double a, double b, double c) {
    QuadraticEquationSolution solution;
    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        solution.realRoots = true;
        solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
        solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        solution.realRoots = true;
        solution.root1 = -b / (2 * a);
        solution.root2 = solution.root1;
    } else {
        solution.realRoots = false;
        // Уравнение имеет комплексные корни
        // Можно выполнить обработку комплексных корней здесь, если необходимо
    }

    return solution;
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

    QuadraticEquationSolution result = solveQuadraticEquation(a, b, c);

    if (result.realRoots) {
        std::cout << "The roots of the equation: x1 = " << result.root1 << ", x2 = " << result.root2 << std::endl;
    } else {
        std::cout << "The equation has no real roots." << std::endl;
    }

    return 0;
}


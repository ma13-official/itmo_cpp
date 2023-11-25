#include <iostream>
#include <stdexcept>
#include <cmath>

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {
        if (!isValid()) {
            throw std::invalid_argument("Invalid side lengths for a triangle");
        }
    }

    bool isValid() const {
        return side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1;
    }

    double calculateArea() const {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    try {
        double s1, s2, s3;
        std::cout << "Enter the lengths of three sides of the triangle: ";
        std::cin >> s1 >> s2 >> s3;

        Triangle triangle(s1, s2, s3);
        double area = triangle.calculateArea();
        std::cout << "The area of the triangle is: " << area << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}

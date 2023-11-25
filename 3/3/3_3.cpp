#include <iostream>
#include <cmath>
using namespace std;

// Функция для вычисления площади равностороннего треугольника
double area(double side) {
    return (sqrt(3) / 4) * side * side;
}

// Функция для вычисления площади разностороннего треугольника по формуле Герона
double area(double side1, double side2, double side3) {
    double semi_perimeter = (side1 + side2 + side3) / 2;
    return sqrt(semi_perimeter *
                (semi_perimeter - side1) *
                (semi_perimeter - side2) *
                (semi_perimeter - side3));
}

int main() {
    int choice;
    cout << "Select the type of triangle: \n";
    cout << "1. Equilateral\n";
    cout << "2. Scalene\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        double side;
        cout << "Enter the length of the equilateral triangle side: ";
        cin >> side;
        cout << "Area of the equilateral triangle: " << area(side) << endl;
    } else if (choice == 2) {
        double side1, side2, side3;
        cout << "Enter the lengths of the sides of the scalene triangle: ";
        cin >> side1 >> side2 >> side3;
        cout << "Area of the scalene triangle: " << area(side1, side2, side3) << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}

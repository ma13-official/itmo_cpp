#include <iostream>
#include <cmath>
using namespace std;

// Структура для хранения координат точки
struct Point {
    double x, y;
};

// Функция для вычисления площади пятиугольника по формуле Гаусса
double calculateArea(Point vertices[]) {
    double area = 0.0;

    for (int i = 0; i < 4; ++i) {
        area += vertices[i].x * vertices[i + 1].y - vertices[i + 1].x * vertices[i].y;
    }

    area += vertices[4].x * vertices[0].y - vertices[0].x * vertices[4].y;

    area = std::abs(area) / 2.0;
    return area;
}

int main() {
    Point vertices[5];

    // Ввод координат вершин от пользователя
    for (int i = 0; i < 5; ++i) {
        cout << "Enter the x-coordinate for vertex " << i + 1 << ": ";
        cin >> vertices[i].x;
        cout << "Enter the y-coordinate for vertex " << i + 1 << ": ";
        cin >> vertices[i].y;
    }

    // Вычисление площади пятиугольника
    double area = calculateArea(vertices);

    cout << "The area of the pentagon is: " << area << endl;

    return 0;
}

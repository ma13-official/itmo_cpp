#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    int totalScore = 0; // Общее количество очков
    int shots = 0; // Количество выстрелов
    int targetX = rand() % 10; // Генерация случайных координат центра мишени
    int targetY = rand() % 10;

    int requiredScore = 50; // Заранее установленное количество очков для достижения

    cout << "Target coordinates: " << targetX << " " << targetY << endl;

    while (totalScore < requiredScore) {
        int x, y;
        cout << "Enter x and y coordinates of the shot: ";
        cin >> x >> y;

        // Рассчитываем расстояние от выстрела до центра мишени
        double distance = sqrt(pow(x - targetX, 2) + pow(y - targetY, 2));

        // Определяем баллы за выстрел в зависимости от расстояния до центра мишени
        if (distance <= 10) {
            totalScore += 10;
        } else if (distance <= 20) {
            totalScore += 5;
        }
        shots++; // Увеличиваем количество выстрелов
    }

    // Определение уровня стрелка
    string shooterLevel;
    if (shots < 10) {
        shooterLevel = "Sniper";
    } else if (shots < 20) {
        shooterLevel = "Shooter";
    } else {
        shooterLevel = "Beginner";
    }

    // Вывод результатов
    cout << "You have reached the required score: " << totalScore << std::endl;
    cout << "Number of shots taken: " << shots << std::endl;
    cout << "Shooter level: " << shooterLevel << std::endl;

    return 0;
}

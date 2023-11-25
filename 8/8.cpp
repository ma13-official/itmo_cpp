#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {} // Конструктор инициализации нулевыми значениями

    Time(int h, int m, int s) { // Конструктор с параметрами
        hours = h;
        minutes = m;
        seconds = s;
        normalizeTime(); // Нормализация времени
    }

    void displayTime() const { // Метод вывода времени
        std::cout << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    Time addTime(const Time& t) const { // Метод сложения времени
        int totalSeconds = seconds + t.seconds;
        int totalMinutes = minutes + t.minutes + totalSeconds / 60;
        int totalHours = hours + t.hours + totalMinutes / 60;

        totalSeconds %= 60;
        totalMinutes %= 60;
        totalHours %= 24;

        return Time(totalHours, totalMinutes, totalSeconds);
    }

private:
    void normalizeTime() { // Метод для коррекции времени
        int extraMinutes = seconds / 60;
        seconds %= 60;
        minutes += extraMinutes;

        int extraHours = minutes / 60;
        minutes %= 60;
        hours += extraHours;

        hours %= 24;
    }
};

int main() {
    const Time currentTime(10, 45, 30); // Инициализированный объект времени (константный)
    const Time anotherTime(2, 30, 45); // Инициализированный объект времени (константный)
    Time uninitializedTime; // Неинициализированный объект времени

    Time result = currentTime.addTime(anotherTime); // Сложение двух инициализированных значений

    result.displayTime(); // Вывод результата на экран

    return 0;
}

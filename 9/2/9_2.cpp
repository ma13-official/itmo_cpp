#include <iostream>
#include <stdexcept>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            throw std::invalid_argument("Invalid time values!");
        }
    }

    void setTime(int h, int m, int s) {
        if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
            throw std::invalid_argument("Invalid time values!");
        }
        hours = h;
        minutes = m;
        seconds = s;
    }

    void displayTime() {
        std::cout << "Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }
};

int main() {
    try {
        Time t(25, 70, 90); // Попытка создать объект с неправильными значениями
    } catch (std::invalid_argument &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Time t(12, 30, 45);
        t.setTime(35, 10, 5); // Попытка установить неправильное время
    } catch (std::invalid_argument &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

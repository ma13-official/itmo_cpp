#include <iostream>

struct Time {
    int hours;
    int minutes;
    int seconds;

    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    int timeInSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time addTime(const Time& t) const {
        int totalSeconds = timeInSeconds() + t.timeInSeconds();
        Time result;
        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;
        return result;
    }

    Time subtractTime(const Time& t) const {
        int totalSeconds = timeInSeconds() - t.timeInSeconds();
        if (totalSeconds < 0) {
            totalSeconds += 24 * 3600;
        }
        Time result;
        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;
        return result;
    }
};

int main() {
    Time time1, time2, result;
    int h, m, s;

    std::cout << "Enter the first time (hours minutes seconds): ";
    std::cin >> h >> m >> s;
    time1.setTime(h, m, s);

    std::cout << "Enter the second time (hours minutes seconds): ";
    std::cin >> h >> m >> s;
    time2.setTime(h, m, s);

    std::cout << "First time in seconds: " << time1.timeInSeconds() << std::endl;
    std::cout << "Second time in seconds: " << time2.timeInSeconds() << std::endl;

    result = time1.addTime(time2);
    std::cout << "Sum of times: " << result.hours << " hours, " << result.minutes << " minutes, " << result.seconds << " seconds" << std::endl;

    result = time1.subtractTime(time2);
    std::cout << "Difference between times: " << result.hours << " hours, " << result.minutes << " minutes, " << result.seconds << " seconds" << std::endl;

    return 0;
}

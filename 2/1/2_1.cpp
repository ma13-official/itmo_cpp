#include <iostream>
#include <vector>

bool isSuperPrime(int64_t num) {
    if (num < 2) {
        return false;
    }

    std::vector<bool> prime(num + 1, true);
    prime[0] = prime[1] = false;

    size_t primeCnt = 0;
    for (int64_t i = 2; i <= num; ++i) {
        if (prime[i]) {
            ++primeCnt;
            for (int64_t j = 2; i * j <= num; ++j) {
                prime[i * j] = false;
            }
        }
    }

    return prime[num] && prime[primeCnt];
}

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    if (isSuperPrime(number)) {
        std::cout << number << " is a superprime number." << std::endl;
    } else {
        std::cout << number << " is not a superprime number." << std::endl;
    }

    return 0;
}

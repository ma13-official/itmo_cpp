#include <iostream>
#include <vector>

void findMinimumCoins(int amount, std::vector<int>& coins) {
    std::vector<int> availableCoins = {10, 5, 2, 1}; // Доступные монеты в системе

    for (int i = 0; i < availableCoins.size(); ++i) {
        while (amount >= availableCoins[i]) {
            coins.push_back(availableCoins[i]);
            amount -= availableCoins[i];
        }
    }
}

int main() {
    int amount;
    std::cout << "Enter sum: ";
    std::cin >> amount;

    std::vector<int> selectedCoins;
    findMinimumCoins(amount, selectedCoins);

    std::cout << "Maximum number of coins: " << selectedCoins.size() << std::endl;
    std::cout << "Selected coins: ";
    for (int coin : selectedCoins) {
        std::cout << coin << " ";
    }
    std::cout << std::endl;

    return 0;
}

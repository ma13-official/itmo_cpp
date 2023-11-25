#include <iostream>

// Сортировка массива пузырьком
void SortArray(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;

        // Находим минимальный элемент в оставшейся части массива
        for (int j = i + 1; j < size; j++) {
            min = (nums[j] < nums[min]) ? j : min;
        }

        // Обмен значениями текущего элемента и минимального
        std::swap(nums[i], nums[min]);
    }
}

// Находим сумму всех элементов в массиве
int FindSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum;
}

// Находим сумму всех отрицательных элементов в массиве
int FindNegativeSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] < 0) {
            sum += nums[i];
        }
    }
    return sum;
}

// Находим сумму всех положительных элементов в массиве
int FindPositiveSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            sum += nums[i];
        }
    }
    return sum;
}

// Находим сумму элементов с нечетными индексами в массиве
int FindOddIndexSum(int nums[], int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += nums[i];
    }
    return sum;
}

// Находим сумму элементов с четными индексами в массиве
int FindEvenIndexSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += nums[i];
    }
    return sum;
}

// Находим индексы минимального и максимального элементов в массиве
std::pair<int, int> FindMinMaxPos(int nums[], int size) {
    int min_pos = 0;
    int max_pos = 0;

    for (int i = 0; i < size; ++i) {
        if (nums[i] < nums[min_pos]) {
            min_pos = i;
        }
        if (nums[i] > nums[max_pos]) {
            max_pos = i;
        }
    }

    return std::make_pair(min_pos, max_pos);
}

// Находим произведение элементов между минимальным и максимальным элементами в массиве
int FindMultBetweenMinAndMax(int nums[], int size) {
    std::pair<int, int> result = FindMinMaxPos(nums, size);
    int left = result.first;
    int right = result.second;
    if (left > right) {
        int temp = left;
        left = right;
        right = temp;
    }

    if (right - left < 3) {
        return 0;
    }

    int mult = nums[left++];
    for (int i = left; i < right; ++i) {
        mult *= nums[i];
    }
    return mult;
}

int main() {
    const int size = 5;
    int mas[size];
    for (int i = 0; i < size; i++) {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    const int sum = FindSum(mas, size);
    std::cout << "Sum: " << sum << std::endl;

    const double avg = static_cast<double>(sum) / size;
    std::cout << "Average: " << avg << std::endl;

    std::cout << "Sum of negative numbers: " << FindNegativeSum(mas, size) << std::endl;
    std::cout << "Sum of positive numbers: " << FindPositiveSum(mas, size) << std::endl;
    std::cout << "Sum of elements at odd indices: " << FindOddIndexSum(mas, size) << std::endl;
    std::cout << "Sum of elements at even indices: " << FindEvenIndexSum(mas, size) << std::endl;

    const std::pair<int, int> result = FindMinMaxPos(mas, size);
    const int min_pos = result.first;
    const int max_pos = result.second;
    std::cout << "Minimum element at position: " << min_pos << std::endl;
    std::cout << "Maximum element at position: " << max_pos << std::endl;
    std::cout << "Multiplication between minimum and maximum: "
              << FindMultBetweenMinAndMax(mas, size) << std::endl;

    SortArray(mas, size);
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << mas[i];
    }
    std::cout << std::endl;

    return 0;
}

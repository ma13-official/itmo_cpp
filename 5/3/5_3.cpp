#include <iostream>
#include <vector>

// Функция для обмена значений двух элементов массива
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для поиска элемента key с использованием метода транспозиции
int transpositionSearch(std::vector<int> &arr, int key) {
    int n = arr.size();
    int left = 0, right = n - 1, mid;

    while (left <= right) {
        if (arr[left] == key) {
            return left; // Элемент найден в начале массива
        } else if (arr[right] == key) {
            // Элемент найден в конце массива, выполним транспозицию
            swap(arr[right], arr[right - 1]);
            return right;
        } else {
            mid = left + (key - arr[left]) * (right - left) / (arr[right] - arr[left]);

            if (arr[mid] == key) {
                // Элемент найден в середине массива, выполним транспозицию
                swap(arr[mid], arr[mid - 1]);
                return mid;
            } else if (key < arr[mid]) {
                right = mid - 1; // Ищем в левой части массива
            } else {
                left = mid + 1; // Ищем в правой части массива
            }
        }
    }

    return -1; // Элемент не найден
}

int main() {
    std::vector<int> arr = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int key = 23;
    
    int result = transpositionSearch(arr, key);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <fstream> // Добавляем заголовочный файл для работы с файлами

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

int main() {
    const int size = 5;
    int mas[size];
    for (int i = 0; i < size; i++) {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    // Открытие файла для записи
    std::ofstream outputFile("array_data.txt");

    // Запись исходного массива в файл
    outputFile << "Original array: ";
    for (int i = 0; i < size; ++i) {
        outputFile << mas[i] << " ";
    }
    outputFile << std::endl;

    SortArray(mas, size);

    // Запись отсортированного массива в файл
    outputFile << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        outputFile << mas[i] << " ";
    }
    outputFile << std::endl;

    // Закрытие файла
    outputFile.close();

    std::cout << "Arrays have been written to file 'array_data.txt'" << std::endl;

    return 0;
}

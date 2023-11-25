#include <iostream>
using namespace std;

int* max_vect(int size, int a[], int b[]) {
    int *result = new int[size]; // Выделяем память под результирующий массив

    for (int i = 0; i < size; i++) {
        // Сравниваем элементы массивов a и b, выбираем больший элемент
        result[i] = (a[i] > b[i]) ? a[i] : b[i];
    }

    return result; // Возвращаем указатель на результирующий массив
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 2};
    int b[] = {7, 6, 5, 4, 3, 2, 1, 3};
    int kc = sizeof(a) / sizeof(a[0]); // Количество элементов массива
    int *c; // Указатель на результирующий массив
    c = max_vect(kc, a, b); // Вызов функции для создания массива

    for (int i = 0; i < kc; i++) { // Вывод результата
        cout << c[i] << " ";
    }
    cout << endl;
    
    delete[] c; // Освобождение памяти, выделенной под результирующий массив
    return 0;
}

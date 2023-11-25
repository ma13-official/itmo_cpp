#include <iostream>
#include <fstream>
#include <string>
#include <locale> // Для работы с локалью и кодировкой

int main() {
    std::locale::global(std::locale("en_US.UTF-8")); // Установка локали на UTF-8
    std::wofstream file("стихотворение.txt");

    if (!file.is_open()) {
        std::cout << "Unable to open the file!" << std::endl;
        return 1;
    }

    std::wcout << L"Enter the poem: " << std::endl;

    std::wstring poemLine;
    while (true) {
        std::getline(std::wcin, poemLine);

        if (poemLine == L"end") {
            break; // завершаем ввод при вводе "конец"
        }

        file << poemLine << std::endl;
    }

    std::cout << "Poem saved to 'стихотворение.txt'" << std::endl;

    file.close();

    return 0;
}

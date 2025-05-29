#include <iostream>
#include <vector>
#include "book_subscription.h"
#include "file_reader.h"
#include "sorting.h"

int main() {
    setlocale(LC_ALL, "ru");

    std::vector<CurrencyInfo*> currencies;

    if (!readFile("data.txt", currencies)) {
        std::cerr << "Ошибка чтения файла данных.\n";
        return 1;
    }

    int choice;
    std::cout << "Выберите сортировку:\n1 - по разнице между покупкой и продажей\n2 - по названию банка\n> ";
    std::cin >> choice;

    if (choice == 1) mergeSort(currencies, 0, currencies.size() - 1, compareByDiff);
    else if (choice == 2) bubbleSort(currencies, compareByName);

    for (auto* cur : currencies) {
        std::cout << cur->bank << " - Покупка: " << cur->buy
            << ", Продажа: " << cur->sell
            << ", Адрес: " << cur->address << '\n';
    }

    for (auto* c : currencies) delete c;

    return 0;
}

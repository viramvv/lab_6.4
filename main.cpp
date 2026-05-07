#include <iostream>
#include <string>
#include "templates.h"

int main() {
    // --- Тестування шаблону функції ---
    std::cout << "--- ТЕСТ ФУНКЦІЇ ---" << std::endl;
    int numbers[] = {1, 2, 3, 3, 4}; // Тут є однакові сусіди (3, 3)

    // Викликаємо шаблон для типу int
    if (hasNoAdjacentDuplicates(numbers, 5)) {
        std::cout << "У масиві немає однакових сусідів." << std::endl;
    } else {
        std::cout << "У масиві ЗНАЙДЕНО однакові сусідні елементи." << std::endl;
    }

    // --- Тестування шаблону класу ---
    std::cout << "\n--- ТЕСТ КІЛЬЦЕВОГО СПИСКУ ---" << std::endl;

    // Створюємо список рядків (інстанціювання шаблону типом std::string)
    CircularList<std::string> list;

    list.add("Apple");
    list.add("Banana");
    list.add("Cherry");

    std::cout << "Список фруктів: ";
    list.print();

    std::cout << "Шукаємо 'Banana': " << (list.find("Banana") ? "Знайдено" : "Відсутній") << std::endl;

    std::cout << "Видаляємо 'Banana'..." << std::endl;
    list.removeNode("Banana");

    std::cout << "Оновлений список: ";
    list.print();

    return 0;
}
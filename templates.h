#ifndef TEMPLATES_H
#define TEMPLATES_H

#include <iostream>

// ШАБЛОН ФУНКЦІЇ
// Перевіряє масив на відсутність однакових сусідів.
// T — це параметр типу (може бути int, double, char тощо).

template <typename T>
bool hasNoAdjacentDuplicates(T arr[], int size) {
    // Якщо в масиві 0 або 1 елемент, сусідів-дублікатів бути не може
    if (size <= 1) return true;

    // Цикл йде до size - 1, щоб не вийти за межі масиву при порівнянні з i+1
    for (int i = 0; i < size - 1; ++i) {
        // Якщо поточний елемент дорівнює наступному — умова порушена
        if (arr[i] == arr[i + 1]) {
            return false; 
        }
    }
    // Якщо пройшли весь цикл і не знайшли збігів — повертаємо true
    return true;
}


// Це список, де останній елемент вказує на перший.

template <typename T>
class CircularList {
private:
    // Структура вузла списку
    struct Node {
        T data;     // Дані, що зберігаються (тип T)
        Node* next; // Вказівник на наступний вузол
        Node(T val) : data(val), next(nullptr) {}
    };

    Node* tail; // Вказівник на ОСТАННІЙ елемент (зручно для кільця)
    int count;  // Кількість елементів у списку

public:
    // Конструктор: створює порожній список
    CircularList() : tail(nullptr), count(0) {}

    // Деструктор: автоматично видаляє всі вузли при знищенні об'єкта
    ~CircularList() {
        while (count > 0) {
            // Видаляємо вузли по одному, поки список не стане порожнім
            removeNode(tail->next->data); 
        }
    }

    // МЕТОД ДОДАВАННЯ: додає новий елемент у кінець
    void add(T val) {
        Node* newNode = new Node(val);
        if (!tail) {
            // Якщо список порожній, вузол вказує сам на себе (кільце)
            tail = newNode;
            tail->next = tail;
        } else {
            // Новий вузол вказує на голову (tail->next)
            newNode->next = tail->next;
            // Старий хвіст вказує на новий вузол
            tail->next = newNode;
            // Тепер новий вузол стає хвостом
            tail = newNode;
        }
        count++;
    }

    // МЕТОД ПОШУКУ: перевіряє наявність значення у списку
    bool find(T val) const {
        if (!tail) return false;
        Node* curr = tail->next; // Починаємо з голови
        for (int i = 0; i < count; ++i) {
            if (curr->data == val) return true;
            curr = curr->next;
        }
        return false;
    }

    // МЕТОД ВИЛУЧЕННЯ: видаляє вузол за значенням
    bool removeNode(T val) {
        if (!tail) return false;

        Node* curr = tail->next; // Поточний (голова)
        Node* prev = tail;       // Попередній (хвіст)

        for (int i = 0; i < count; ++i) {
            if (curr->data == val) {
                if (count == 1) {
                    // Випадок 1: у списку лише один елемент
                    delete curr;
                    tail = nullptr;
                } else {
                    // Випадок 2: видаляємо вузол, перенаправляючи вказівник в обхід нього
                    prev->next = curr->next;
                    // Якщо видаляємо саме хвіст, оновлюємо вказівник tail
                    if (curr == tail) tail = prev;
                    delete curr;
                }
                count--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false; // Значення не знайдено
    }

    // МЕТОД ВИВОДУ: друкує список у консоль
    void print() const {
        if (!tail) {
            std::cout << "Список порожній." << std::endl;
            return;
        }
        Node* curr = tail->next;
        for (int i = 0; i < count; ++i) {
            std::cout << "[" << curr->data << "] -> ";
            curr = curr->next;
        }
        std::cout << "(коло замкнулося)" << std::endl;
    }
};

#endif
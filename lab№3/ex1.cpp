#include <iostream>
#include <cmath>

// Структура для элемента списка
struct Node {
    int data;
    Node* next;
};

// Функция для создания нового элемента списка
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Функция для добавления элемента после к-ого элемента списка
void insertAfter(Node* head, int k, int value) {
    Node* current = head;
    int count = 0;

    while (current != nullptr && count < k) {
        current = current->next;
        count++;
    }

    if (current != nullptr) {
        Node* newNode = createNode(value);
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Функция для удаления из списка к-ого элемента
void deleteKth(Node* head, int k) {
    Node* current = head;
    int count = 0;

    while (current != nullptr && count < k - 1) {
        current = current->next;
        count++;
    }

    if (current != nullptr && current->next != nullptr) {
        Node* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
    }
}

// Функция для подсчета числа элементов в списке
int countElements(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

// Функция для перемещения р-ого элемента списка после к-ого элемента
void moveRthAfterKth(Node* head, int r, int k) {
    Node* current = head;
    int count = 0;

    while (current != nullptr && count < r) {
        current = current->next;
        count++;
    }

    if (current != nullptr) {
        Node* rNode = current;
        Node* prev = nullptr;
        current = head;
        count = 0;

        while (current != nullptr && count < k) {
            prev = current;
            current = current->next;
            count++;
        }

        if (prev != nullptr) {
            prev->next = rNode->next;
            rNode->next = current->next;
            current->next = rNode;
        }
    }
}

// Функция для удаления повторяющихся элементов из списка
void removeDuplicates(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        Node* runner = current;
        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* toDelete = runner->next;
                runner->next = runner->next->next;
                delete toDelete;
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Функция для вывода элементов списка
void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main() {
    // Создаем голову списка
    Node* head = createNode(0);

    // Заполним список полными квадратами из массива
    for (int i = 1; i <= 10; i++) {
        int square = i * i;
        insertAfter(head, i - 1, square);
    }

    std::cout << "Список до удаления повторяющихся элементов: ";
    printList(head);

    // Удаляем повторяющиеся элементы
    removeDuplicates(head);

    std::cout << "Список после удаления повторяющихся элементов: ";
    printList(head);

    // Определяем длину списка
    int length = countElements(head);
    std::cout << "Длина списка: " << length << std::endl;

    // Освобождаем память
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }

    return 0;
}

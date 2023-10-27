#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> stack;
    std::vector<int>::size_type maxSize;

public:
    Stack(std::vector<int>::size_type size) : maxSize(size) {}

    void push(int value) {
        if (stack.size() < maxSize) {
            stack.push_back(value);
        } else {
            std::cout << "Stack is full." << std::endl;
        }
    }

    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        } else {
            std::cout << "Stack is empty." << std::endl;
        }
    }

    void display() {
        std::cout << "Stack: ";
        for (int item : stack) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

class Queue {
private:
    std::vector<int> queue;
    std::vector<int>::size_type maxSize;

public:
    Queue(std::vector<int>::size_type size) : maxSize(size) {}

    void enqueue(int value) {
        if (queue.size() < maxSize) {
            queue.push_back(value);
        } else {
            std::cout << "Queue is full." << std::endl;
        }
    }

    void dequeue() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        } else {
            std::cout << "Queue is empty." << std::endl;
        }
    }

    void display() {
        std::cout << "Queue: ";
        for (int item : queue) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack(10);
    Queue queue(10);

    // Добавление и удаление элементов из стека и очереди, а также их отображение, чтобы продемонстрировать работу.
// Добавляем элементы в стек
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display(); // Отобразим содержимое стека

    // Добавляем элементы в очередь
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display(); // Отобразим содержимое очереди

    // Удаляем элементы из стека и очереди
    stack.pop();
    queue.dequeue();

    // Отображаем их содержимое после удаления
    stack.display();
    queue.display();

    return 0;
}

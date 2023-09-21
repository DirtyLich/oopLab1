#include <iostream>

class DynamicArray2D {
private:
    int** arr;
    int numRows;
    int* numCols;

public:
    // Конструктор класса
    DynamicArray2D(int rows) {
        numRows = rows;
        numCols = new int[numRows];
        arr = new int*[numRows];

        // Заполняем массив указателей на строки
        for (int i = 0; i < numRows; ++i) {
            std::cout << "Введите количество элементов в строке " << i << ": ";
            std::cin >> numCols[i];
            arr[i] = new int[numCols[i]];

            std::cout << "Введите элементы для строки " << i << ": ";
            for (int j = 0; j < numCols[i]; ++j) {
                std::cin >> arr[i][j];
            }
        }
    }

    // Деструктор класса
    ~DynamicArray2D() {
        for (int i = 0; i < numRows; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
        delete[] numCols;
    }

    // Метод для вывода массива построчно
    void printArray() {
        for (int i = 0; i < numRows; ++i) {
            std::cout << "Строка " << i << ": ";
            for (int j = 0; j < numCols[i]; ++j) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    int numRows;
    std::cout << "Введите количество строк: ";
    std::cin >> numRows;

    DynamicArray2D array(numRows);
    array.printArray();

    return 0;
}

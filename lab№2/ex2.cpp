#include <iostream>
#include <cstdlib>
#include <ctime>

class DynamicArray2D {
private:
    int** arr;
    int numRows;
    int* numCols;

public:
    // Конструктор класса
    DynamicArray2D(int rows, int maxCols) {
        numRows = rows;
        numCols = new int[numRows];
        arr = new int*[numRows];

        // Инициализируем генератор случайных чисел
        srand(static_cast<unsigned>(time(nullptr)));

        // Заполняем массив указателей на строки и случайными элементами
        for (int i = 0; i < numRows; ++i) {
            numCols[i] = rand() % maxCols + 1; // Определяем случайное количество элементов в строке
            arr[i] = new int[numCols[i]];

            for (int j = 0; j < numCols[i]; ++j) {
                arr[i][j] = rand() % 100; // Генерируем случайное число для элемента
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
    int numRows, maxCols;
    std::cout << "Введите количество строк: ";
    std::cin >> numRows;
    std::cout << "Введите максимальное количество элементов в строке: ";
    std::cin >> maxCols;

    DynamicArray2D array(numRows, maxCols);
    array.printArray();

    return 0;
}

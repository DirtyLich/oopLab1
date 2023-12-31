#include <iostream> // Подключение библиотеки для работы с потоками ввода/вывода
#include <cstdlib>  // Подключение библиотеки для работы с функциями выделения памяти и генерации случайных чисел
#include <ctime>    // Подключение библиотеки для работы со временем

using namespace std; // Использование пространства имен std

int *genRandArray(int size, int maxValue)
{                                 // Объявление функции для генерации случайного массива целых чисел
    int *arr = new int[size + 1]; // Выделение памяти под массив
    arr[0] = size;                // Запись размера массива в первый элемент
    for (int i = 1; i <= size; i++)
    {                                     // Цикл по всем элементам массива
        arr[i] = rand() % (maxValue + 1); // Заполнение элемента случайным числом в диапазоне от 0 до maxValue
    }
    return arr; // Возвращение указателя на массив
}

void print(int *arr)
{                         // Объявление функции для вывода массива на экран
    int size = arr[0];    // Получение размера массива из первого элемента
    cout << size << ": "; // Вывод размера массива на экран
    for (int i = 1; i <= size; i++)
    {                          // Цикл по всем элементам массива
        cout << arr[i] << " "; // Вывод элемента на экран
    }
    cout << endl; // Переход на новую строку
}

int main()
{                                            // Главная функция программы
    srand(time(NULL));                       // Инициализация генератора случайных чисел
    int size = rand() % 10;                  // Генерация случайного размера массива от 0 до 9
    int maxValue = 100;                      // Максимальное значение элементов массива
    int *arr = genRandArray(size, maxValue); // Создание массива
    print(arr);                              // Вывод массива на экран
    delete[] arr;                            // Освобождение памяти, выделенной под массив
    return 0;                                // Возврат нуля, обозначающего успешное завершение программы
}
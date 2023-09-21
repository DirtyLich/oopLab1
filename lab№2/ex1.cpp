#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>

using namespace std;

// переписывание элементов матрицы в массив D по правым диагоналям
void ex_A(int **matrix, int N, int *D) {
    int k = 0;
    for (int d = N-1; d >= -N; d--) {
        for (int i = 0; i < N; i++) {
            int j = d + i;
            if (j >= 0 && j < N) {
                D[k++] = matrix[i][j];
            }
        }
    }
}

// переписывание элементов матрицы в массив D по левым диагоналям
void ex_B(int **matrix, int N, int *D) {
    int k = 0;
    for (int d = 0; d < 2*N-1; d++) {
        for (int i = 0; i < N; i++) {
            int j = d - i;
            if (j >= 0 && j < N) {
                D[k++] = matrix[i][j];
            }
        }
    }
}

// переписывание элементов матрицы в массив D по спирали, начиная с центрального элемента
void ex_C(int **matrix, int N, int *D) {
    int x = N / 2; // Начальная координата x (центральная строка)
    int y = N / 2; // Начальная координата y (центральный столбец)
    int dx = 0;
    int dy = 1;
    int steps = 1;
    int count = 0;

    while (count < N * N) {
        D[count++] = matrix[x][y]; // Записываем текущий элемент в одномерный массив

        // Проверяем, нужно ли изменить направление
        if (steps == 0) {
            if (dx == 0 && dy == 1) {
                dx = 1;
                dy = 0; // Двигаемся вниз
            } else if (dx == 1 && dy == 0) {
                dx = 0;
                dy = -1; // Двигаемся влево
            } else if (dx == 0 && dy == -1) {
                dx = -1;
                dy = 0; // Двигаемся вверх
            } else {
                dx = 0;
                dy = 1; // Двигаемся вправо
            }

            if (dx != 0) {
                steps = abs(dx); // Устанавливаем количество шагов в новом направлении
            } else {
                steps = abs(dy);
            }
        }

        x += dx; // Перемещаемся в новую позицию
        y += dy;

        steps--; // Уменьшаем количество оставшихся шагов в текущем направлении
    }
}









void ex_D(int **matrix, int N, int *D) {
    int x = 0, y = 0;
    int k = 0;
    int total_elements = N * N;

    // Создаем матрицу для отслеживания посещенных ячеек
    int **visited = new int*[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new int[N];
        for (int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }

    while (k < total_elements) {
        if (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]) {
            D[k++] = matrix[x][y];
            visited[x][y] = 1; // Помечаем посещенную ячейку
        }

        // Двигаемся вправо
        while (y + 1 < N && !visited[x][y + 1]) {
            y++;
            D[k++] = matrix[x][y];
            visited[x][y] = 1;
        }

        // Двигаемся вниз
        while (x + 1 < N && !visited[x + 1][y]) {
            x++;
            D[k++] = matrix[x][y];
            visited[x][y] = 1;
        }

        // Двигаемся влево
        while (y - 1 >= 0 && !visited[x][y - 1]) {
            y--;
            D[k++] = matrix[x][y];
            visited[x][y] = 1;
        }

        // Двигаемся вверх
        while (x - 1 >= 0 && !visited[x - 1][y]) {
            x--;
            D[k++] = matrix[x][y];
            visited[x][y] = 1;
        }
    }

    // Освобождаем память от матрицы visited
    for (int i = 0; i < N; i++) {
        delete[] visited[i];
    }
    delete[] visited;
}




    


    
int main() {
    const int N = 5; // размер массива
    int **matrix = new int*[N]; // создание двумерного массива
    int *D = new int[N*N]; // создание одномерного массива
    memset(D, 0, N*N*sizeof(int)); // инициализация массива D нулями
    srand(time(NULL)); // инициализация генератора случайных чисел

    // заполнение двумерного массива случайными числами
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }

    // вывод двумерного массива на экран
    cout << "Двумерный массив:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    char user_sym;

    std::cout << "ex.A = по правым диагоналям, начиная с правого верхнего элемента\n ex.B = по левым диагоналям, начиная с левого верхнего элемента\n ex.C = по спирали, начиная с центрального элемента\n ex.D = по спирали, начиная с левого верхнего элемента\n";
    std::cout << "Enter a choice:";
    std::cin >> user_sym;
    switch (user_sym)
    {
    case 'a':
         ex_A(matrix, N, D);
            break;
    
    case 'b':
         ex_B(matrix, N, D);
            break;

    case 'c':
         ex_C(matrix, N, D);
            break;

    case 'd':
         ex_D(matrix, N, D);

    default:
         std::cout<< "wrong format";
        break;
    }
    
    


    // вывод одномерного массива на экран
    cout << "Одномерный массив:" << endl;
    for (int i = 0; i < N*N; i++) {
        cout << D[i] << " ";
    }
    cout << endl;

    // освобождение памяти
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] D;

    return 0;
}
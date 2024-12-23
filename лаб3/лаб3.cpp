#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateMatrix(int* matrix, int size)
{

    for (int i = 0; i < size * size; i++)
    {
        matrix[i] = (rand() % (size * size) + 1);
    }
}

void setCursorPosition(HANDLE hStdout, int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hStdout, coord);
}


void printMatrix(int* matrix, int size)
{
    int* end = matrix + size * size - 1;

    for (int* ptr = matrix; ptr <= end; ptr++)
    {
        cout << setw(4) << *ptr;
        if ((ptr - matrix + 1) % size == 0)
            cout << '\n';
    }
}

void printMatrixZmeya(int size)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int* matrix = new int[size * size];
    generateMatrix(matrix, size);

    setCursorPosition(hStdout, 0, 0);

    int value = 0;

    for (int j = 0; j < size; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < size; i++)
            {
                setCursorPosition(hStdout, j * 5, i + 2);
                cout << setw(4) << matrix[value];
                value++;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        }
        else
        {
            for (int i = size - 1; i >= 0; i--)
            {
                setCursorPosition(hStdout, j * 5, i + 2);
                cout << setw(4) << matrix[value];
                value++;
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        }
    }

    delete[] matrix;
}

void printMatrixSpiral(int size)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    int* matrix = new int[size * size];
    generateMatrix(matrix, size);
    int value = 0;
    int left = 0, right = size - 1, top = 0, bottom = size - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
        {
            setCursorPosition(hStdout, i * 5, top + size + 4);
            cout << setw(4) << matrix[value++];
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(150));
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            setCursorPosition(hStdout, right * 5, i + size + 4);
            cout << setw(4) << matrix[value++];
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(150));
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                setCursorPosition(hStdout, i * 5, bottom + size + 4);
                cout << setw(4) << matrix[value++];
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                setCursorPosition(hStdout, left * 5, i + size + 4);
                cout << setw(4) << matrix[value++];
                cout.flush();
                this_thread::sleep_for(chrono::milliseconds(150));
            }
            left++;
        }
    }
}

void printSquareA(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке a:" << endl;


    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j]; 
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j]; 
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j]; 
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j]; 
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}
void printSquareB(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке b:" << endl;

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}

void printSquareС(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке c:" << endl;

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}

void printSquareD(int* matrix, int size) {
    int halfSize = size / 2;
    int* quadrants[4];

    for (int i = 0; i < 4; ++i) {
        quadrants[i] = new int[halfSize * halfSize];
    }


    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            quadrants[0][i * halfSize + j] = *(matrix + i * size + j);
            quadrants[1][i * halfSize + j] = *(matrix + i * size + (j + halfSize));
            quadrants[2][i * halfSize + j] = *(matrix + (i + halfSize) * size + j);
            quadrants[3][i * halfSize + j] = *(matrix + (i + halfSize) * size + (j + halfSize));
        }
    }

    cout << "Матрица в порядке d:" << endl;

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[1][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[0][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[3][i * halfSize + j];
        }
        for (int j = 0; j < halfSize; ++j) {
            cout << setw(4) << quadrants[2][i * halfSize + j];
        }
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] quadrants[i];
    }
}

void shakerSort(int* matrix, int size) {
    bool swapped = true;
    int* start = matrix;
    int* end = matrix + size - 1;

    while (swapped) {
        swapped = false;


        for (int* ptr = start; ptr < end; ++ptr) {
            if (*ptr > *(ptr + 1)) {
                swap(*ptr, *(ptr + 1));
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
        swapped = false;
        --end;

        for (int* ptr = end; ptr > start; --ptr) {
            if (*ptr < *(ptr - 1)) {
                swap(*ptr, *(ptr - 1));
                swapped = true;
            }
        }
        ++start;
    }
}

void manipulateWithMatrix(int* matrix, int size, char operation, int value)
{

    for (int i = 0; i <= size * size; i++)
    {
        switch (operation)
        {
        case '+':
        {
            *(matrix + i) += value;
        }
        break;
        case '-':
        {
            *(matrix + i) -= value;
        }
        break;
        case '*':
        {
            *(matrix + i) *= value;
        }
        break;
        case '/':
        {
            if (value != 0)
                *(matrix + i) /= value;
            else
                cout << "Ошибочка, неопределенность\n\n";
            return;
        }
        }
    }
    cout << "Измененная матрица:" << endl;
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    setlocale(LC_ALL, "RU");
    int size;

    cout << "Выберите размер матрицы (6,8,10): ";
    cin >> size;

    if (size != 6 && size != 8 && size != 10) {
        cout << "Некорректный размер матрицы!!! Программа завершена:(" << endl;
        return 1;
    }
    printMatrixZmeya(size);
    cout << endl;
    printMatrixSpiral(size);
    cout << endl << endl << endl << endl << endl;

    int* matrix = new int[size * size];


    generateMatrix(matrix, size);

    int choice;
    do
    {
        cout << "\n\tЗадания 2, 3 и 4" << endl;
        cout << "[1] Вывести матрицу для выполнения заданий\n";
        cout << "[2] Вывод матрицы способом a\n";
        cout << "[3] Вывод матрицы способом b\n";
        cout << "[4] Вывод матрицы способом c\n";
        cout << "[5] Вывод матрицы способом d\n";
        cout << "[6] Shaker sort\n";
        cout << "[7] Арифметика над матрицей\n";
        cout << "[8] ИДЗ 1\n";
        cout << "[0] Завершить работу программы:)\n";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            printMatrix(matrix, size);
            break;
        case 2:
            printSquareA(matrix, size);
            break;
        case 3:
            printSquareB(matrix, size);
            break;
        case 4:
            printSquareС(matrix, size);
            break;
        case 5:
            printSquareD(matrix, size);
            break;
        case 6:
            shakerSort(matrix, size * size);
            printMatrix(matrix, size);
            break;
        case 7:
        {
            char operation;
            int value;
            cout << "Исходная матрица:" << endl;
            printMatrix(matrix, size);

            cout << "Пожалуйста, выберите операцию (+, -, *, /): ";
            cin >> operation;
            cout << "Введите значение для операции: ";
            cin >> value;

            manipulateWithMatrix(matrix, size, operation, value);
            printMatrix(matrix, size);
        }
        break;
        case 8:
        {
            cout << "\tИДЗ 1";
            int* firstMatrix = new int[size * size];
            int* secondMatrix = new int[size * size];
            int* resultMatrix = new int[size * size];

            generateMatrix(firstMatrix, size);
            cout << "Первая матрица: " << endl;
            printMatrix(firstMatrix, size);


            generateMatrix(secondMatrix, size);
            cout << "Вторая матрица: " << endl;
            printMatrix(secondMatrix, size);

            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    resultMatrix[i * size + j] = firstMatrix[i * size + j] + secondMatrix[i * size + j];
                }
            }
            cout << "Результирующая матрица:" << endl;
            printMatrix(resultMatrix, size);

            delete[] firstMatrix;
            delete[] secondMatrix;
            delete[] resultMatrix;

        }break;

        }
    } while (choice != 0);

    return 0;
}
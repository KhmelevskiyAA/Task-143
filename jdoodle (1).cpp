#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

/**
 * @brief Заполняет массив случайными числами в заданном диапазоне
 * @param arr Указатель на массив для заполнения
 * @param n Размер массива
 * @param min Минимальное значение элемента
 * @param max Максимальное значение элемента
 */
void fillArrayRandom(int* arr, int n, int min, int max);

/**
 * @brief Заполняет массив вручную с проверкой ввода
 * @param arr Указатель на массив для заполнения
 * @param n Размер массива
 * @param min Минимальное значение элемента
 * @param max Максимальное значение элемента
 */
void fillArrayManual(int* arr, int n, int min, int max);

/**
 * @brief Выводит массив на экран
 * @param arr Указатель на массив для вывода
 * @param n Размер массива
 */
void printArray(const int* arr, int n);

/**
 * @brief Заменяет минимальный элемент массива на среднее значение
 * @param arr Указатель на массив для обработки
 * @param n Размер массива
 */
void replaceMinWithAverage(int* arr, int n);

/**
 * @brief Выводит индексы элементов, больших предыдущего
 * @param arr Указатель на массив для анализа
 * @param n Размер массива
 */
void printIndicesGreaterThanPrevious(const int* arr, int n);

/**
 * @brief Проверяет наличие двух пар соседних элементов с одинаковыми знаками
 * @param arr Указатель на массив для проверки
 * @param n Размер массива
 * @return true если найдены две пары, иначе false
 */
bool hasTwoPairsWithSameSign(const int* arr, int n);

int main() {
    // Инициализация генератора случайных чисел
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    // Ввод размера массива
    int n;
    cout << "Введите размер массива (нечетное число): ";
    cin >> n;

    // Проверка на нечетность размера
    if (n % 2 == 0) {
        cerr << "Ошибка: размер массива должен быть нечетным!" << endl;
        return 1;
    }

    // Выделение памяти под массив
    int* arr = new int[n];
    
    // Выбор способа заполнения
    int choice;
    cout << "Выберите способ заполнения массива:\n"
         << "1 - Автоматическое заполнение случайными числами\n"
         << "2 - Ручное заполнение с клавиатуры\n"
         << "Ваш выбор: ";
    cin >> choice;

    // Диапазон допустимых значений
    const int min = -20;
    const int max = 40;
    
    // Заполнение массива
    if (choice == 1) {
        fillArrayRandom(arr, n, min, max);
    } else if (choice == 2) {
        fillArrayManual(arr, n, min, max);
    } else {
        cerr << "Неверный выбор!" << endl;
        delete[] arr;
        return 1;
    }

    // Вывод исходного массива
    cout << "\nИсходный массив:\n";
    printArray(arr, n);

    // Замена минимального элемента на среднее
    replaceMinWithAverage(arr, n);
    cout << "\nМассив после замены минимального элемента на средний:\n";
    printArray(arr, n);

    // Вывод индексов элементов, больших предыдущего
    cout << "\nИндексы элементов, больших предыдущего:\n";
    printIndicesGreaterThanPrevious(arr, n);

    // Проверка пар соседних элементов
    cout << "\nПроверка на две пары соседних элементов с одинаковыми знаками:\n";
    if (hasTwoPairsWithSameSign(arr, n)) {
        cout << "В массиве есть две пары соседних элементов с одинаковыми знаками.\n";
    } else {
        cout << "В массиве нет двух пар соседних элементов с одинаковыми знаками.\n";
    }

    // Освобождение памяти
    delete[] arr;
    return 0;
}

void fillArrayRandom(int* arr, int n, int min, int max) {
    // Заполнение массива случайными числами
    for (int i = 0; i < n; i++) {
        *(arr + i) = rand() % (max - min + 1) + min;
    }
}

void fillArrayManual(int* arr, int n, int min, int max) {
    // Ручной ввод элементов с проверкой диапазона
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент [" << i << "] (диапазон [" << min << ", " << max << "]): ";
        cin >> *(arr + i);
        while (*(arr + i) < min || *(arr + i) > max) {
            cerr << "Ошибка! Значение должно быть в диапазоне [" << min << ", " << max << "]. Повторите ввод: ";
            cin >> *(arr + i);
        }
    }
}

void printArray(const int* arr, int n) {
    // Вывод элементов массива
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void replaceMinWithAverage(int* arr, int n) {
    // Поиск минимального элемента и вычисление суммы
    int minIndex = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (*(arr + i) < *(arr + minIndex)) {
            minIndex = i;
        }
        sum += *(arr + i);
    }

    // Замена минимального элемента на среднее
    int average = sum / n;
    cout << "Минимальный элемент: " << *(arr + minIndex) 
         << " заменен на среднее: " << average << endl;
    *(arr + minIndex) = average;
}

void printIndicesGreaterThanPrevious(const int* arr, int n) {
    // Поиск и вывод индексов элементов, больших предыдущего
    for (int i = 1; i < n; i++) {
        if (*(arr + i) > *(arr + i - 1)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

bool hasTwoPairsWithSameSign(const int* arr, int n) {
    // Поиск двух пар соседних элементов с одинаковыми знаками
    int pairCount = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((*(arr + i) >= 0 && *(arr + i + 1) >= 0) || 
            (*(arr + i) < 0 && *(arr + i + 1) < 0)) {
            pairCount++;
            if (pairCount >= 2) {
                return true;
            }
            i++; // Пропуск следующего элемента
        }
    }
    return false;
}

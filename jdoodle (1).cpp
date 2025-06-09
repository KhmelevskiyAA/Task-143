#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

// Прототипы функций
void fillArrayRandom(int arr[], int n, int min, int max);
void fillArrayManual(int arr[], int n, int min, int max);
void printArray(int arr[], int n);
void replaceMinWithAverage(int arr[], int n);
void printIndicesGreaterThanPrevious(int arr[], int n);
bool hasTwoPairsWithSameSign(int arr[], int n);

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0)); // Инициализация генератора случайных чисел

    int n;
    cout << "Введите размер массива (нечетное число): ";
    cin >> n;

    // Проверка на нечетность размера массива
    if (n % 2 == 0) {
        cout << "Ошибка: размер массива должен быть нечетным!" << endl;
        return 1;
    }

    int* arr = new int[n];
    int choice;
    cout << "Выберите способ заполнения массива:\n"
         << "1 - Автоматическое заполнение случайными числами\n"
         << "2 - Ручное заполнение с клавиатуры\n"
         << "Ваш выбор: ";
    cin >> choice;

    const int min = -20;
    const int max = 40;
    
    if (choice == 1) {
        fillArrayRandom(arr, n, min, max);
    } else if (choice == 2) {
        fillArrayManual(arr, n, min, max);
    } else {
        cout << "Неверный выбор!" << endl;
        delete[] arr;
        return 1;
    }

    cout << "\nИсходный массив:\n";
    printArray(arr, n);

    // 1. Замена минимального элемента на средний
    replaceMinWithAverage(arr, n);
    cout << "\nМассив после замены минимального элемента на средний:\n";
    printArray(arr, n);

    // 2. Вывод индексов элементов, больших предыдущего
    cout << "\nИндексы элементов, больших предыдущего:\n";
    printIndicesGreaterThanPrevious(arr, n);

    // 3. Проверка на наличие двух пар соседних элементов с одинаковыми знаками
    cout << "\nПроверка на две пары соседних элементов с одинаковыми знаками:\n";
    if (hasTwoPairsWithSameSign(arr, n)) {
        cout << "В массиве есть две пары соседних элементов с одинаковыми знаками.\n";
    } else {
        cout << "В массиве нет двух пар соседних элементов с одинаковыми знаками.\n";
    }

    delete[] arr;
    return 0;
}

// Заполнение массива случайными числами в заданном диапазоне
void fillArrayRandom(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

// Заполнение массива вручную с проверкой диапазона
void fillArrayManual(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        cout << "Введите элемент [" << i << "] (диапазон [" << min << ", " << max << "]): ";
        cin >> arr[i];
        while (arr[i] < min || arr[i] > max) {
            cout << "Ошибка! Значение должно быть в диапазоне [" << min << ", " << max << "]. Повторите ввод: ";
            cin >> arr[i];
        }
    }
}

// Вывод массива на экран
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Замена минимального элемента на среднее значение
void replaceMinWithAverage(int arr[], int n) {
    int minIndex = 0;
    int sum = 0;

    // Находим минимальный элемент и считаем сумму
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
        sum += arr[i];
    }

    int average = sum / n;
    cout << "Минимальный элемент: " << arr[minIndex] << " заменен на среднее: " << average << endl;
    arr[minIndex] = average;
}

// Вывод индексов элементов, больших предыдущего
void printIndicesGreaterThanPrevious(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Проверка на наличие двух пар соседних элементов с одинаковыми знаками
bool hasTwoPairsWithSameSign(int arr[], int n) {
    int pairCount = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((arr[i] >= 0 && arr[i+1] >= 0) || (arr[i] < 0 && arr[i+1] < 0)) {
            pairCount++;
            if (pairCount >= 2) {
                return true;
            }
            i++; // Пропускаем следующий элемент, чтобы пары не перекрывались
        }
    }
    return false;
}
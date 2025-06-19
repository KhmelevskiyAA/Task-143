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
void fillArrayRandom(int* arr, const int n, const int min, const int max);

/**
 * @brief Заполняет массив вручную с проверкой ввода
 * @param arr Указатель на массив для заполнения
 * @param n Размер массива
 * @param min Минимальное значение элемента
 * @param max Максимальное значение элемента
 */
void fillArrayManual(int* arr, const int n, const int min, const int max);

/**
 * @brief Выводит массив на экран
 * @param arr Указатель на массив для вывода
 * @param n Размер массива
 */
void printArray(const int* arr, const int n);

/**
 * @brief Заменяет минимальный элемент массива на среднее значение
 * @param arr Указатель на массив для обработки
 * @param n Размер массива
 */
void replaceMinWithAverage(int* arr, const int n);

/**
 * @brief Выводит индексы элементов, больших предыдущего
 * @param arr Указатель на массив для анализа
 * @param n Размер массива
 */
void printIndicesGreaterThanPrevious(const int* arr, const int n);

/**
 * @brief Проверяет наличие двух пар соседних элементов с одинаковыми знаками
 * @param arr Указатель на массив для проверки
 * @param n Размер массива
 * @return true если найдены две пары, иначе false
 */
bool hasTwoPairsWithSameSign(const int* arr,const int n);

/**
 * @brief Главная функция программы для работы с массивом
 * 
 * @return int Код возврата:
 *             - 0 при успешном выполнении
 *             - 1 при ошибке ввода данных
 * 
 * Функция выполняет:
 * 1. Инициализацию генератора случайных чисел
 * 2. Ввод размера массива с проверкой на нечетность
 * 3. Создание динамического массива целых чисел
 * 4. Предоставление выбора способа заполнения массива:
 *    - Автоматическое заполнение случайными числами
 *    - Ручной ввод с клавиатуры
 * 5. Обработку массива (замена минимального элемента, анализ)
 * 6. Освобождение выделенной памяти
 *
 * @note Для корректной работы требуется:
 * - #include <locale.h> или <clocale> для setlocale()
 * - #include <stdlib.h> или <cstdlib> для srand()
 * - #include <time.h> или <ctime> для time()
 */
int main() {
    // Инициализация генератора случайных чисел
    setlocale(LC_ALL, "Russian");
    srand(time(0));

   // Ввод размера массива    
    int n;
    
    // Бесконечный цикл для ввода с проверкой
    while (true) {
        cout << "Введите размер массива (положительное нечетное число): ";
        cin >> n;
        
        // Проверка на корректность ввода (если ввели не число)
        if (cin.fail()) {
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
            cout << "Ошибка! Введите целое число." << endl;
            continue;
        }
        
        // Проверка на положительное нечётное число
        if (n > 0 && n % 2 != 0) {
            break; // Выход из цикла при корректном вводе
        }

    // Выделение памяти под массив
    int* arr = new int[n];
    
   // Перечисление (если всё равно нужен enum)
enum class FillMethod {
    MANUAL = 1  // Оставил 1 для удобства, если потом добавится автоматическое заполнение
};

// Выбор способа заполнения (если только ручной ввод)
cout << "Заполнение массива:\n"
     << " MANUAL- Ручной ввод с клавиатуры\n"
     << "Ваш выбор: ";
         
    int choice;
    
    while (true) {
        cout << "Введите 1 для продолжения: ";
        cin >> choice;
        
        // Проверка на ошибку ввода (если ввели не число)
        if (cin.fail()) {
            cin.clear(); // Сбрасываем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер
            cout << "Ошибка! Введите целое число." << endl;
            continue;
        }
        
        // Проверка на лишние символы во входной строке
        if (cin.peek() != '\n') {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка! Введите только число без дополнительных символов." << endl;
            continue;
        }
        
        // Проверка нужного значения
        if (choice == 1) {
            break; // Корректный ввод, выходим из цикла
        }
        
        cout << "Ошибка! Допустим только ввод числа 1." << endl;
    }
    
    cout << "Введено корректное значение: " << choice << endl;
    
    // Дальнейший код программы...
    
    return 0;
}

   
    #include <iostream>
using namespace std;

int min, max; {
    
    // Ввод минимального значения
    cout << "Введите минимальное значение диапазона: ";
    cin >> min;
    
    // Ввод максимального значения
    cout << "Введите максимальное значение диапазона: ";
    cin >> max;
    
    // Проверка, что min < max
    while (min >= max) {
        cout << "Ошибка! Минимальное значение должно быть меньше максимального.\n";
        cout << "Введите минимальное значение диапазона: ";
        cin >> min;
        cout << "Введите максимальное значение диапазона: ";
        cin >> max;
    }
    
    // Теперь можно использовать min и max как границы диапазона
    cout << "Диапазон значений установлен: от " << min << " до " << max << endl;
    
    // Дальнейшая логика программы...
    
    return 0;
}
    
   // Заполнение массива
switch (choice) {
    case 1:  // или static_cast<int>(FillMethod::RANDOM) если используете enum
        fillArrayRandom(arr, n, min, max);
        break;
    case 2:  // или static_cast<int>(FillMethod::MANUAL)
        fillArrayManual(arr, n, min, max);
        break;
    default:
        cerr << "Неверный выбор!" << endl;
        delete[] arr;
        return 1;
}

  // Вывод исходного массива
cout << "\nИсходный массив (" << n << " элементов):\n";
printArray (arr, n);

// Замена минимального элемента на среднее
replaceMinWithAverage(arr, n);
cout << "\nМассив после замены минимального элемента (" 
     << findMinValue(arr, n) << ") на среднее арифметическое:\n";
printArray (arr, n);

// Вывод индексов элементов, больших предыдущего
cout << "\nИндексы элементов, больших предыдущего:\n";
vector<int> indices = getIndicesGreaterThanPrevious(arr, n);
if (indices.empty()) {
    cout << "Таких элементов нет\n";
} else {
    for (int idx : indices) {
        cout << idx << " (значение: " << arr[idx] << ")\n";
    }
    cout << "Всего: " << indices.size() << " элементов\n";
}

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

void fillArrayRandom(int* arr, int n, int min, int max) {
    // Заполнение массива случайными числами
    for (size_t i = 0; i < n; ++i) {
        arr[i] = rand() % (max - min + 1) + min;
    }
}
#include <iostream>
#include <limits> // для numeric_limits

using namespace std;

void fillArrayManual(int* arr, size_t n, int min, int max) {
    for (size_t i = 0; i < n; ++i) {
        while (true) {
            cout << "Введите элемент [" << i << "] (диапазон [" << min << ", " << max << "]): ";
            
            // Проверка корректности ввода числа
            if (!(cin >> arr[i])) {
                cerr << "Ошибка! Введите целое число.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            
            // Проверка диапазона
            if (arr[i] < min || arr[i] > max) {
                cerr << "Ошибка! Значение должно быть в диапазоне [" 
                     << min << ", " << max << "]. Повторите ввод.\n";
            } else {
                break; // Ввод корректен, выходим из цикла
            }
        }
    }
}
        
void printArray(const int* arr, int n) {
    // Вывод элементов массива
    for (size_t i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

void replaceMinWithAverage(int* arr, int n) {
    // Поиск минимального элемента и вычисление суммы
    int minIndex = 0;
    int sum = 0;

    for (size_t i = 0; i < n; i++) {
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
    for (size_t i = 1; i < n; i++) {
        if (*(arr + i) > *(arr + i - 1)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

bool hasTwoPairsWithSameSign(const int* arr, int n) {
    // Поиск двух пар соседних элементов с одинаковыми знаками
    int pairCount = 0;
    for (size_t i = 0; i < n - 1; i++) {
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

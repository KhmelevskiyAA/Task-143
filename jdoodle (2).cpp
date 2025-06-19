#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

/**
 * @brief оператор выбоа способа заполнения массива
 * @param RANDOM = 0 автоматическое заполнение
 * @param MANUALLY =1 ручное заполнение
 */
enum SELECT
{
    RANDOM = 0,
    MANUALLY = 1
};

/**
 * @brief проверяет размер массива
 * @param n - размер массива
 */
void checkN(const int n);

/**
 * @brief считывает размер массива
 * @return размер массива в беззнаковом типе данных
 */
size_t getSize();

/**
 * @brief считывает значение типа int
 * @return считанное значение целочисленное
 */
int getNumber();

/**
 * @brief вывод массива на экран
 * @param arr - массив
 * @param n - размер массива
 */
void printArray(const int* arr, const int n);
/**
 * @brief заполнение массива автоматически случайнвми числами в заданном диапазоне
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArrayRandom(int* arr, const int n, const int min, const int max);
/**
 * @brief проверяет диапазон
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void checkRange(const int min, const int max);
/**
 * @brief Заменяет минимальный элемент массива на среднее арифметическое всех элементов
 * @param arr Указатель на массив целых чисел
 * @param n Размер массива
 * @return Среднее арифметическое значение
 */
int replaceMinWithAverage(const int* arr, const int n) 
/**
 * @brief Проверяет, содержит ли массив две пары соседних элементов с одинаковыми знаками
 * @param arr Указатель на массив целых чисел
 * @param n Количество элементов в массиве
 * @return true - если найдены две пары соседей с одинаковыми знаками, false - в противном случае
 * @throw std::invalid_argument если arr == nullptr или n < 4
 */
bool hasTwoPairsWithSameSign(const int* arr, const int n)
/**
 * @brief выводит индексы элементов массива, значения которых больше предыдущих элементов.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 */
void printIndicesGreaterThanPrevious(const int* arr, const int n);

/**
 * @brief заполнение массива вручную
 * @param arr - массив
 * @param n - размер массива
 * @param min - минимальное значение диапазона значений элементов массива
 * @param max - максимальное значение диапазона значений элементов массива
 */
void fillArray(int* arr, const int n, const int min, const int max);

/**
* @brief точка входа в программу
* @return 0 - если программма выполнена корректно, инече -1
*/

int main()
{
    setlocale(LC_ALL, "Russian");
    
    try {
        int n = getSize();
        int* arr = new int[n];

        cout << "Введите минимальное и максимальное значение диапазона: ";
        int minValue = getNumber();
        int maxValue = getNumber();
        checkRange(minValue, maxValue);

        cout << "Выберите способ заполнения массива:\n"
             << RANDOM << " - Случайное заполнение\n"
             << MANUALLY << " - Ручное заполнение\n"
             << "Ваш выбор: ";
        
        int choice = getNumber();

        switch (static_cast<SELECT>(choice))
        {
        case RANDOM:
            fillArrayRandom(arr, n, minValue, maxValue);
            break;
        case MANUALLY:
            fillArray(arr, n, minValue, maxValue);
            break;
        default:
            cerr << "Ошибка: неверный выбор!" << endl;
            delete[] arr;
            return EXIT_FAILURE;
        }

        cout << "\nИсходный массив:\n";
        printArray(arr, n);

        int averageValue = replaceMinWithAverage(arr, n);
        cout << "\nСреднее значение: " << averageValue << endl;
        cout << "Массив после замены минимального элемента на среднее:\n";
        printArray(arr, n);

        cout << "\nПроверка на две пары соседних элементов с одинаковыми знаками: "
             << (hasTwoPairsWithSameSign(arr, n) ? "да" : "нет") << endl;
             
        printIndicesGreaterThanPrevious(arr, n);

        delete[] arr;
    }
    catch (const exception& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        throw invalid_argument("Размер массива должен быть положительным числом");
    }
}

size_t getSize()
{
    int n = 0;
    while (true) {
        cout << "Введите размер массива: ";
        cin >> n;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Ошибка ввода. Пожалуйста, введите целое число.\n";
            continue;
        }
        
        try {
            checkN(n);
            return static_cast<size_t>(n);
        }
        catch (const exception& e) {
            cerr << e.what() << "\n";
        }
    }
}

int getNumber()
{
    int number = 0;
    while (true) {
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Ошибка ввода. Пожалуйста, введите целое число: ";
            continue;
        }
        return number;
    }
}

void printArray(const int* arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        throw invalid_argument("Минимальное значение не может быть больше максимального");
    }
}

int replaceMinWithAverage(int* arr, const int n)
{
    if (n == 0) return 0;

    int minIndex = 0;
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
        sum += arr[i];
    }

    int average = sum / n;
    int oldValue = arr[minIndex];
    arr[minIndex] = average;

    cout << "Минимальный элемент arr[" << minIndex << "] = " << oldValue
         << " заменен на среднее значение " << average << endl;

    return average;
}

bool hasTwoPairsWithSameSign(const int* arr, const int n)
{
    if (n < 4) return false;

    int pairsFound = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i] * arr[i + 1]) > 0)
        {
            if (++pairsFound >= 2)
                return true;
            i++;
        }
    }
    return false;
}

void printIndicesGreaterThanPrevious(const int* arr, const int n)
{
    if (n < 2) {
        cout << "Недостаточно элементов для сравнения" << endl;
        return;
    }

    cout << "Индексы элементов, значения которых больше предыдущих: ";
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void fillArray(int* arr, const int n, const int min, const int max)
{
    for (int i = 0; i < n; i++)
    {
        while (true) {
            cout << "Введите значение для arr[" << i << "] (" << min << ".." << max << "): ";
            arr[i] = getNumber();
            
            if (arr[i] >= min && arr[i] <= max) {
                break;
            }
            cerr << "Значение вне допустимого диапазона. Повторите ввод.\n";
        }
    }
}

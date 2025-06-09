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
 * @brief Заменяет минимальный элемент массива на средний, если количество элементов в массиве нечетное
 * @param arr  Массив целых чисел, в котором будет произведена замена
 * @param n Размер массива
 */
int replaceMinWithAverage(int arr[], const int n);

/**
 * @brief проверяет, содержит ли массив две пары соседних элементов с одинаковыми знаками.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 * @return true, если в массиве есть две пары соседних элементов с одинаковыми знаками, иначе false.
 */
bool hasTwoPairsWithSameSign(const int arr[], const int n);

/**
 * @brief выводит индексы элементов массива, значения которых больше предыдущих элементов.
 * @param arr Указатель на массив целых чисел.
 * @param n Количество элементов в массиве.
 */
void printIndicesGreaterThanPrevious(const int arr[], const int n);

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
    int n = getSize();
    int* arr = new int[n];

    cout << "Введите минимальное и максимальное значение диапазона: ";
    int minValue = getNumber();
    int maxValue = getNumber();
    checkRange(minValue, maxValue);

    cout << "Введите выбор для заполнения массива: " << endl
        << RANDOM << " - Для случайного заполнения" << endl
        << MANUALLY << " - Для ручного заполнения" << endl;

    int choice = getNumber();

    switch ((SELECT)choice)
    {
    case RANDOM:
        fillArrayRandom(arr, n, minValue, maxValue);
        break;
    case MANUALLY:
        fillArray(arr, n, minValue, maxValue);
        break;
    default:
        cout << "Ваш выбор неверен" << endl;
        delete[] arr;
        return -1;
    }

    cout << "Исходный массив:" << endl;
    printArray(arr, n);

    int averageValue = replaceMinWithAverage(arr, n);
    cout << "Среднее значение: " << averageValue << endl;

    cout << "Массив после замены минимального элемента на среднее:" << endl;
    printArray(arr, n);

    printIndicesGreaterThanPrevious(arr, n);

    if (hasTwoPairsWithSameSign(arr, n))
    {
        cout << "Есть две пары соседних элементов с одинаковыми знаками." << endl;
    }
    else
    {
        cout << "Две пары соседних элементов с одинаковыми знаками отсутствуют." << endl;
    }

    delete[] arr;
    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cerr << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n = 0;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number = 0;
    cin >> number;
    if (cin.fail())
    {
        cerr << "Неправильный ввод данных" << endl;
        abort();
    }
    return number;
}

void printArray(const int* arr, const int n)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}

void fillArrayRandom(int* arr, const int n, const int min, const int max)
{
    srand(static_cast<unsigned int>(time(0)));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cerr << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int replaceMinWithAverage(int arr[], const int n)
{
    if (n == 0) return 0;

    int minIndex = 0;
    int sum = 0;

    // Находим минимальный элемент и считаем сумму
    for (size_t i = 0; i < n; ++i)
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

bool hasTwoPairsWithSameSign(const int arr[], const int n)
{
    if (n < 4) return false;

    int pairsFound = 0;
    for (size_t i = 0; i < n - 1; i++)
    {
        if ((arr[i] * arr[i + 1]) > 0) // Одинаковые знаки
        {
            pairsFound++;
            if (pairsFound >= 2)
                return true;
            i++; // Пропускаем следующий элемент, чтобы не считать перекрывающиеся пары
        }
    }
    return false;
}

void printIndicesGreaterThanPrevious(const int arr[], const int n)
{
    if (n < 2) return;

    cout << "Индексы элементов, значения которых больше предыдущих:" << endl;
    for (size_t i = 1; i < n; i++)
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
    for (size_t i = 0; i < n; i++)
    {
        cout << "Введите значение для arr[" << i << "]: ";
        arr[i] = getNumber();

        while (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона [" << min << ", " << max << "]. Повторите ввод: ";
            arr[i] = getNumber();
        }
    }
}

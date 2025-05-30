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
        << RANDOM << " Для случайного заполнения" << endl
        << MANUALLY << " Для ручного заполнения" << endl;

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
        return -1;
    }

    cout << "Элементы массива:" << endl;
    printArray(arr, n);

    replaceMinWithAverage(arr, n);
    printArray(arr, n);

    printIndicesGreaterThanPrevious(arr, n);

    if (hasTwoPairsWithSameSign(arr, n))
    {
        cout << "Есть две пары соседних элементов с одинаковыми знаками.\\n";
    }
    else
    {
        cout << "Две пары соседних элементов с одинаковыми знаками отсутствуют.\\n";
    }

    delete[] arr; // Освобождаем память массива
    return 0;
}

void checkN(const int n)
{
    if (n <= 0)
    {
        cout << "Неправильный размер массива" << endl;
        abort();
    }
}

size_t getSize()
{
    cout << "Введите размер массива: ";
    int n=0;
    cin >> n;
    checkN(n);
    return (size_t)n;
}

int getNumber()
{
    int number =0;
    cin >> number;
    if (cin.fail())
    {
        cout << "Неправильный ввод данных";
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
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = rand() % (max - min + 1) + min;
    }
}

void checkRange(const int min, const int max)
{
    if (min > max)
    {
        cout << "Введен неправильный диапазон" << endl;
        abort();
    }
}

int replaceMinWithAverage(int arr[], const int n)
{
    // Создаем копию массива для работы
    vector<int> arrCopy(arr, arr + n);
    
    int minIndex = 0;
    int sum = 0; // Явная инициализация

    for (size_t i = 1; i < n; ++i)
    {
        if (arrCopy[i] < arrCopy[minIndex])
        {
            minIndex = i;
        }
    }

    for (size_t i = 0; i < n; ++i)
    {
        sum += arrCopy[i];
    }

    arrCopy[minIndex] = sum / n;

    cout << "Массив после замены минимального значения на среднее: ";
    for (size_t i = 0; i < n; ++i)
    {
        cout << arrCopy[i] << " ";
    }
    cout << endl;
    
    return sum / n;
}
bool hasTwoPairsWithSameSign(const int arr[], const int n)
{
    if (n < 4) return false; // Не может быть двух пар при n < 4
    int pairsFound = 0;
    for (size_t i = 0; i < n - 1; ) // Убрали ++i из условия цикла
    {
        if (arr[i] * arr[i + 1] > 0) // Одинаковые знаки
        {
            pairsFound++;
            if (pairsFound >= 2) 
                return true;
            i += 2; // Перескакиваем через следующий элемент
        }
        else
        {
            i++; // Переходим к следующему элементу
        }
    }
    return false;
}
void fillArray(int* arr, const int n, const int min, const int max)
{
    for (size_t i = 0; i < n; i++)
    {
        cout << "Enter value for arr[" << i << "]: ";
        arr[i] = getNumber();

        if (arr[i] < min || arr[i] > max)
        {
            cout << "Значение вне диапазона" << endl;
            i--;
        }
    }
} 

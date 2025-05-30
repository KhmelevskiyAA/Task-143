#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits> // Для очистки потока ввода
using namespace std;
/**
 * @brief Безопасно считывает числовое значение из стандартного ввода.
 * @return double Введённое пользователем число.
 */
double getValue();
/**
 * @brief Вычисляет площадь прямоугольника.
 * 
 * @param length Длина прямоугольника
 * @param width Ширина прямоугольника 
 * @return double Площадь прямоугольника (length * width).
 */
double rectangleArea(const double length, const double width);
/**
 * @brief Вычисляет площадь треугольника по формуле Герона.
 * 
 * @param a Первая сторона треугольника 
 * @param b Вторая сторона треугольника 
 * @param c Третья сторона треугольника 
 * @return double Площадь треугольника.
 */
double triangleArea(const double a, const double b, const double c);
int main() {
    try {
        // Ввод данных для прямоугольника
        cout << "Введите длину прямоугольника: ";
       const double length = getValue();
        cout << "Введите ширину прямоугольника: ";
       const double width = getValue();
        cout << "Площадь прямоугольника: " << rectangleArea(length, width) << endl;
        // Ввод данных для треугольника
        cout << "Введите три стороны треугольника:\n";
        cout << "Сторона a: ";
       const double a = getValue();
        cout << "Сторона b: ";
       const double b = getValue();
        cout << "Сторона c: ";
       const double c = getValue();
        cout << "Площадь треугольника: " << triangleArea(a, b, c) << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    return 0;
}
// Функция вычисления площади прямоугольника
double rectangleArea(const double length, const double width) {
    if (length <= 0 || width <= 0) {
        throw invalid_argument("Длина и ширина должны быть положительными числами.");
    }
    return length * width;
}
// Функция вычисления площади треугольника по формуле Герона
double triangleArea(const double a, const double b, const double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw invalid_argument("Все стороны треугольника должны быть положительными числами.");
    }
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw invalid_argument("Треугольник с такими сторонами не существует (нарушено неравенство треугольника).");
    }
    double p = (a + b + c) / 2; // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
// Функция для безопасного ввода числа
double getValue()
{
    double value = 0;
    cin >> value;
    if (cin.fail())
    {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}


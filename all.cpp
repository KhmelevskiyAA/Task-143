#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits> // Для очистки потока ввода

using namespace std;

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
double getValue() {
    double value;
    while (!(cin >> value)) {
        cerr << "Ошибка ввода! Ожидалось число. Попробуйте снова: ";
        cin.clear(); // Сбрасываем флаг ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
    }
    return value;
}

int main() {
    try {
        // Ввод данных для прямоугольника
        const double length, width;
        cout << "Введите длину прямоугольника: ";
        length = getValue();
        cout << "Введите ширину прямоугольника: ";
        width = getValue();
        cout << "Площадь прямоугольника: " << rectangleArea(length, width) << endl;

        // Ввод данных для треугольника
        double a, b, c;
        cout << "Введите три стороны треугольника:\n";
        cout << "Сторона a: ";
        a = getValue();
        cout << "Сторона b: ";
        b = getValue();
        cout << "Сторона c: ";
        c = getValue();
        cout << "Площадь треугольника: " << triangleArea(a, b, c) << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}

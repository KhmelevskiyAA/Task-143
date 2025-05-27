#include <iostream>
#include <cmath> // Для функции sqrt() в расчете площади треугольника
#include <stdexcept> // Для обработки исключений

using namespace std;

// Функция вычисления площади прямоугольника
double rectangleArea(double length, double width) {
    if (length <= 0 || width <= 0) {
        throw invalid_argument("Длина и ширина должны быть положительными числами.");
    }
    return length * width;
}

// Функция вычисления площади треугольника по формуле Герона
double triangleArea(double a, double b, double c) {
    if (a <= 0 , b <= 0 , c <= 0) {
        throw invalid_argument("Все стороны треугольника должны быть положительными числами.");
    }
    if (a + b <= c , a + c <= b , b + c <= a) {
        throw invalid_argument("Треугольник с такими сторонами не существует (нарушено неравенство треугольника).");
    }
    double p = (a + b + c) / 2; // Полупериметр
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    try {
        // Ввод данных для прямоугольника
        double length, width;
        cout << "Введите длину и ширину прямоугольника: ";
        cin >> length >> width;
        cout << "Площадь прямоугольника: " << rectangleArea(length, width) << endl;

        // Ввод данных для треугольника
        double a, b, c;
        cout << "Введите три стороны треугольника: ";
        cin >> a >> b >> c;
        cout << "Площадь треугольника: " << triangleArea(a, b, c) << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }

    return 0;
}

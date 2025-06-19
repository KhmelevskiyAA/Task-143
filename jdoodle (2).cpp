#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() {
    setlocale(LC_ALL, "Russian");
    cout << fixed << setprecision(4);

    constexpr double x = 2.0;
    constexpr double y = 0.7;
    constexpr double z = -1.0;

    cout << "Результаты вычислений:\n";
    cout << "A = " << calculateA(x, y, z) << endl;
    cout << "B = " << calculateB(x, y, z) << endl;

    return 0;
}

/**
 * @brief Вычисляет значение A (необходимо реализовать)
 * @param x Первый параметр
 * @param y Второй параметр
 * @param z Третий параметр
 * @return Результат вычисления
 */
double calculateA(const double x, const double y, const double z) {
    // Реализация функции calculateA
    // (добавьте свою формулу здесь)
    return 0.0;
}

/**
 * @brief Вычисляет значение B по формуле y*cos(x*z*sin(y)) + 3
 * @param x Первый параметр
 * @param y Второй параметр
 * @param z Третий параметр
 * @return Результат вычисления
 */
double calculateB(const double x, const double y, const double z) {
    return y * cos(x * z * sin(y)) + 3.0;
}

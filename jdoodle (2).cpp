#include <iostream>
#include <cmath>
#include <iomanip>  // Для управления выводом чисел
#include <stdexcept>  // Для обработки исключений

using namespace std;

/**
 * @brief Вычисляет значение A по формуле ∛(x*y*z + |z*sin(y)|)
 * @param x Первый параметр
 * @param y Второй параметр
 * @param z Третий параметр
 * @return Результат вычисления
 * @throw std::invalid_argument Если аргумент корня отрицательный
 */
double calculateA(const double x, const double y, const double z) {
    const double expression = x * y * z + abs(z * sin(y));
    if (expression < 0) {
        throw invalid_argument("Отрицательное значение под корнем");
    }
    return cbrt(expression);  // Используем cbrt вместо pow для точности
}

/**
 * @brief Вычисляет значение B по формуле y*cos(x*z*sin(y)) + 3
 * @param x Первый параметр
 * @param y Второй параметр
 * @param z Третий параметр
 * @return Результат вычисления
 */
double calculateB(const double x, const double y, const double z) {
    const double argument = x * z * sin(y);
    return y * cos(argument) + 3.0;
}

/**
 * @brief Точка входа в программу
 * @return 0 при успешном выполнении
 */
int main() {
    // Устанавливаем локаль для корректного вывода русских символов
    setlocale(LC_ALL, "Russian");
    
    // Устанавливаем точность вывода
    cout << fixed << setprecision(4);

    // Исходные данные
    constexpr double x = 2.0;
    constexpr double y = 0.7;
    constexpr double z = -1.0;

    try {
        // Вычисляем и выводим результаты
        cout << "Результаты вычислений:\n";
        cout << "A = " << calculateA(x, y, z) << endl;
        cout << "B = " << calculateB(x, y, z) << endl;
    } 
    catch (const invalid_argument& e) {
        cerr << "Ошибка вычисления: " << e.what() << endl;
        return 1;
    }
    catch (...) {
        cerr << "Неизвестная ошибка при вычислениях" << endl;
        return 2;
    }

    return 0;
}
#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

class Calculator
{
public:

    // Сумма двух чисел
    static double Sum(double a, double b)
    {
        double sum = a + b;

        double result = round(sum * 100.0) / 100.0;

        cout << "Сумма: " << result << endl;

        return result;
    }

    // Подзадача 2
    // Площадь круга
    static double CircleArea(double radius)
    {
        // Формула площади круга:
        // S = pi * r^2

        const double PI = 3.1415926535;

        double area = PI * radius * radius;

        // Округляем до двух знаков после запятой
        double result = round(area * 100.0) / 100.0;

        cout << "Площадь круга: " << result << endl;

        return result;
    }

    // Подзадача 3
    // Площадь прямоугольника
    static double RectangleArea(double first, double second)
    {
        // Формула:
        // S = a * b

        double area = first * second;

        // Округляем
        double result = round(area * 100.0) / 100.0;

        cout << "Площадь прямоугольника: " << result << endl;

        return result;
    }

    // Подзадача 4
    // Площадь треугольника по формуле Герона
    static double TriangleArea(double first, double second, double third)
    {
        // Полупериметр:
        // p = (a + b + c) / 2

        double p = (first + second + third) / 2.0;

        // Формула Герона:
        // S = sqrt(p * (p-a) * (p-b) * (p-c))

        double area = sqrt(
            p *
            (p - first) *
            (p - second) *
            (p - third)
        );

        // Округляем
        double result = round(area * 100.0) / 100.0;

        cout << "Площадь треугольника по формуле Герона: "
            << result << endl;

        return result;
    }

    // Подзадача 5
    // Площадь треугольника через основание и высоту
    static double TriangleArea(double base, double height)
    {
        // Формула:
        // S = 1/2 * основание * высота

        double area = 0.5 * base * height;

        // Округляем
        double result = round(area * 100.0) / 100.0;

        cout << "Площадь треугольника через основание и высоту: "
            << result << endl;

        return result;
    }
};

// Функция для безопасного ввода числа
double readDouble(const string& prompt)
{
    double value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите число!\n";
        }
        else
        {
            return value;
        }
    }
}

// Функция вывода меню
void printMenu()
{
    cout << "\n========== КАЛЬКУЛЯТОР ==========\n";
    cout << "1. Сумма двух чисел\n";
    cout << "2. Площадь круга\n";
    cout << "3. Площадь прямоугольника\n";
    cout << "4. Площадь треугольника (формула Герона)\n";
    cout << "5. Площадь треугольника (основание и высота)\n";
    cout << "0. Выход\n";
    cout << "=================================\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int choice;

    while (true)
    {
        printMenu();
        choice = (int)readDouble("Выберите подзадачу: ");

        switch (choice)
        {
        case 1:
        {
            double a = readDouble("Введите первое число: ");
            double b = readDouble("Введите второе число: ");
            Calculator::Sum(a, b);
            break;
        }
        case 2:
        {
            double r = readDouble("Введите радиус круга: ");
            if (r < 0)
            {
                cout << "Ошибка: радиус не может быть отрицательным!\n";
                break;
            }
            Calculator::CircleArea(r);
            break;
        }
        case 3:
        {
            double a = readDouble("Введите первую сторону: ");
            double b = readDouble("Введите вторую сторону: ");
            Calculator::RectangleArea(a, b);
            break;
        }
        case 4:
        {
            double a = readDouble("Введите первую сторону: ");
            double b = readDouble("Введите вторую сторону: ");
            double c = readDouble("Введите третью сторону: ");

            // Проверка существования треугольника
            if (a + b <= c || a + c <= b || b + c <= a)
            {
                cout << "Ошибка: треугольник с такими сторонами не существует!\n";
                break;
            }
            Calculator::TriangleArea(a, b, c);
            break;
        }
        case 5:
        {
            double base = readDouble("Введите основание: ");
            double height = readDouble("Введите высоту: ");
            Calculator::TriangleArea(base, height);
            break;
        }
        case 0:
            cout << "Выход из программы. До свидания!\n";
            return 0;
        default:
            cout << "Ошибка: неверный пункт меню. Попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
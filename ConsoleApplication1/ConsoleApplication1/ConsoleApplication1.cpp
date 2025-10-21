#include <iostream>
#include <vector>
#include <cmath>
#include <windows.h>
using namespace std;

class Trapezoid {

private:
    double a, b, c, d; 

public:
    Trapezoid(double base1, double base2, double side1, double side2) {
        a = base1; b = base2; c = side1; d = side2;
    }

    void resize(double factor) {
        a *= factor; b *= factor; c *= factor; d *= factor;
    }

    double perimeter() const {
        return a + b + c + d;
    }

    double area() const {
        double h = height();
        return (a + b) * h / 2.0;
    }

    bool isSimilar(const Trapezoid& other) const {
        double k1 = a / other.a;
        double k2 = b / other.b;
        double k3 = c / other.c;
        double k4 = d / other.d;

        return abs(k1 - k2) < 1e-6 && abs(k2 - k3) < 1e-6 && abs(k3 - k4) < 1e-6;
    }

    double midline() const {
        return (a + b) / 2.0;
    }

    double height() const {
        double x = (d * d - c * c + (a - b) * (a - b)) / (2 * (a - b));
        return sqrt(d * d - x * x);
    }

    void print() const {
        cout << "Основания: " << a << ", " << b << " | Боковые: " << c << ", " << d;
    }
};

int main() {
    SetConsoleCP(1251);
SetConsoleOutputCP(1251);

    vector<Trapezoid> trapezoids;
    int choice;

    do {
        cout << "\n1. Добавить трапецию\n2. Вывести все\n3. Операции\nВыберите: ";
        cin >> choice;

        if (choice == 1) {
            double a, b, c, d;
            cout << "Введите основания и боковые стороны: ";
            cin >> a >> b >> c >> d;
            trapezoids.push_back(Trapezoid(a, b, c, d));
        }
        else if (choice == 2) {
            for (int i = 0; i < trapezoids.size(); i++) {
                cout << i << ": "; trapezoids[i].print(); cout << endl;
            }
        }
        else if (choice == 3 && !trapezoids.empty()) {
            int index;
            cout << "Выберите индекс (0-" << trapezoids.size() - 1 << "): ";
            cin >> index;

            if (index >= 0 && index < trapezoids.size()) {
                int op;
                cout << "1. Изменить размер\n2. Периметр\n3. Площадь\n";
                cout << "4. Проверить подобие\n5. Средняя линия\n6. Высота\nВыберите операцию: ";
                cin >> op;

                switch (op) {
                case 1: {
                    double factor;
                    cout << "Коэффициент: "; cin >> factor;
                    trapezoids[index].resize(factor);
                    break;
                }
                case 2:
                    cout << "Периметр: " << trapezoids[index].perimeter() << endl;
                    break;
                case 3:
                    cout << "Площадь: " << trapezoids[index].area() << endl;
                    break;
                case 4: {
                    int otherIndex;
                    cout << "Индекс другой трапеции: "; cin >> otherIndex;
                    if (otherIndex >= 0 && otherIndex < trapezoids.size()) {
                        bool similar = trapezoids[index].isSimilar(trapezoids[otherIndex]);
                        cout << (similar ? "Подобны" : "Не подобны") << endl;
                    }
                    break;
                }
                case 5:
                    cout << "Средняя линия: " << trapezoids[index].midline() << endl;
                    break;
                case 6:
                    cout << "Высота: " << trapezoids[index].height() << endl;
                    break;
                }
            }
        }
    } while (choice != 0);

    return 0;
}

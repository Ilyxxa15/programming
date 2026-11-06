#include <iostream>

using namespace std;

// Функція обчислення середнього гармонійного двох чисел
double PrintGarm(double x, double y) {
    return (2.0 * x * y) / (x + y);
}

int main() {
    double a, b;

    while (true) {
        cout << "\n Enter two numbers (or 0 to stop):" << endl;
        cout << "First number: ";
        cin >> a;
        cout << "Second number: ";
        cin >> b;

        // Перевірка умови зупинки: якщо хоч одне з чисел дорівнює 0
        if (a == 0 || b == 0) {
            cout << "Entered 0. Program stopped." << endl;
            break;
        }

        // Обчислення та вивід результату
        double harmonic_mean = PrintGarm(a, b);
        cout << "Harmonic mean of " << a << " and " << b
            << " is: " << harmonic_mean << endl;
    }

    return 0;
}
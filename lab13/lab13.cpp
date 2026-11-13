#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Zahalni parametry dlya 1-ho variantu (i = 1)
    double a = 0.0;       // Pochatok intervalu [0; i]
    double b = 1.0;       // Kinec intervalu (i = 1)
    double h = 0.1 * 1.0; // Krok h = 0.1 * i

    double first_y = 0.0;
    double last_y = 0.0;
    int count = 0;

    cout << fixed << setprecision(4);
    cout << "--- Tablytsya znachen funktsii ---" << endl;
    cout << setw(10) << "x" << setw(15) << "y" << endl;

    // Tsykl for dlya tabulyatsiyi funktsiyi na vidrizku
    for (double x = a; x <= b + 1e-9; x += h) {
        // Obchyslennya funktsii (variant 9: f_{1+8}(x))
        double y = cos(x * x + 1.0) - abs(sin(2.0 * x) - 5.76);

        // Zberezhennya pershoho znachennya
        if (count == 0) {
            first_y = y;
        }
        last_y = y; // Ostannye znachennya
        count++;

        // Vyvid par chisel x, y u viglyadi tablytsi
        cout << setw(10) << x << setw(15) << y << endl;
    }

    // Obrahunok suymy pershoho i ostannoho znachen funktsii
    double sum_first_last = first_y + last_y;

    // Vyvid rezultativ poshuku danych
    cout << "\n---------------------------------" << endl;
    cout << "Kilkist usikh znachen: " << count << endl;
    cout << "Suma pershoho i ostannoho znachen: " << sum_first_last << endl;

    return 0;
}
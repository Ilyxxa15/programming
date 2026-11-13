#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Zminni ta rozmirnist matrytsi
    const int rows = 4;
    const int cols = 4;
    double a[rows][cols];

    cout << fixed << setprecision(2);
    cout << "--- Matrytsya a[k][n] ---" << endl;

    // Formuvannya ta vyvid dvovymirnoho masyvu
    for (int k = 0; k < rows; k++) {
        double x_k = k + 1;
        double f12 = pow(cos(x_k), 3) / 2.1 + pow(cos(x_k), 2) / 1.1 - 8.3 * sin(3.0 * x_k + 1.0);

        for (int n = 0; n < cols; n++) {
            double x_n = n + 1;
            double f13 = pow(sin(x_n), 2) * pow(cos(x_n), 3) - sin(x_n) + 5.2;

            a[k][n] = x_n * f12 + sin(x_k) * f13;
            cout << setw(12) << a[k][n] << " ";
        }
        cout << endl;
    }

    // Poshuk minimalnoho elementa ta dobutku vid'emnykh
    double min_val = a[0][0];
    int min_k = 0, min_n = 0;
    double neg_product = 1.0;
    bool has_neg = false;

    for (int k = 0; k < rows; k++) {
        for (int n = 0; n < cols; n++) {
            if (a[k][n] < min_val) {
                min_val = a[k][n];
                min_k = k;
                min_n = n;
            }
            if (a[k][n] < 0) {
                neg_product *= a[k][n];
                has_neg = true;
            }
        }
    }

    // Vyvid rezultativ
    cout << "\n----------------------------------------" << endl;
    cout << "Minimalnyy element: " << min_val << " (indeksy: [" << min_k + 1 << "][" << min_n + 1 << "])" << endl;
    if (has_neg) {
        cout << "Dobutok vid'emnykh elementiv: " << neg_product << endl;
    }
    else {
        cout << "U matrytsi nemaye vid'emnykh elementiv." << endl;
    }

    return 0;
}
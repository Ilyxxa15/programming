#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Oholoshennya konstanty rozmiru masyvu (k vid 1 do 7)
    const int n = 7;
    double y[n];

    int positive_count = 0;
    int third_positive_index = -1;

    cout << fixed << setprecision(2);
    cout << "--- Elementy masyvu ---" << endl;

    // Tsykl for dlya stvorennya ta vyvodu masyvu
    for (int k = 1; k <= n; k++) {
        // Obchyslennya za variantom 1 (i = 1, funktsiya 1 + 10 = 11)
        double f = abs(sin(12.0 * k) * cos(abs(2.0 * k))) / 3.0 + 4.21;
        y[k - 1] = f;

        // Vyvid elementu na ekran
        cout << "y[" << k << "] = " << y[k - 1] << endl;

        // Poshuk tretoho dodatnoho elementu
        if (y[k - 1] > 0) {
            positive_count++;
            if (positive_count == 3) {
                third_positive_index = k - 1; // Indeks u C++ pochynayetsya z 0
            }
        }
    }

    // Vykonannya zavdannya 1: Chy tretiy dodatnyy element ye ostannim
    cout << "------------------------" << endl;
    if (third_positive_index != -1) {
        if (third_positive_index == n - 1) {
            cout << "Tak, tretiy dodatnyy element ye ostannim u masyvi." << endl;
        }
        else {
            cout << "Ni, tretiy dodatnyy element ne ye ostannim u masyvi." << endl;
        }
    }
    else {
        cout << "U masyvi nemaye 3 dodatnykh elementiv." << endl;
    }

    return 0;
}
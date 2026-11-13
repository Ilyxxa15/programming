#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    // Vstanovlennya seed dlya generatsiyi vypadkovyh chysel
    srand(time(NULL));

    const int rows = 6; // 6 naselenykh punktiv (k)
    const int cols = 5; // 5 kandydativ (n)
    int votes[rows][cols];

    // Generatsiya holosiv za variantom 1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            votes[i][j] = rand() % 500 + 50;
        }
    }

    // Vyvid tablytsi rezultativ holosuvannya
    cout << "--- Tablytsya rezultativ holosuvannya ---" << endl;
    for (int i = 0; i < rows; i++) {
        cout << "Punkt " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << votes[i][j];
        }
        cout << endl;
    }

    // Zavdannya 4: Kilkist holosiv za pershoho i tretoho kandydativ u vsiakh punktakh[cite: 71]
    int sum_1_3 = 0;
    for (int i = 0; i < rows; i++) {
        sum_1_3 += votes[i][0] + votes[i][2]; // Indeks 0 - 1-y kandydat, 2 - 3-y
    }
    cout << "\nZavdannya 4 - Suma za 1-go ta 3-go kandydativ: " << sum_1_3 << endl;

    // Zavdannya 6: Skilky vybortsiv u kozhnomu naselenomu punkti[cite: 71]
    cout << "\nZavdannya 6 - Vybortsi u kozhnomu punkti:" << endl;
    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += votes[i][j];
        }
        cout << "Punkt " << i + 1 << ": " << row_sum << " osib" << endl;
    }

    // Zavdannya 10: V yakykh punktakh pershyy kandydat nabrav maks. kilkist holosiv[cite: 72]
    int max_v1 = votes[0][0];
    for (int i = 1; i < rows; i++) {
        if (votes[i][0] > max_v1) {
            max_v1 = votes[i][0];
        }
    }
    cout << "\nZavdannya 10 - Punkty, de 1-y kandydat nabrav maksimum (" << max_v1 << "):" << endl;
    for (int i = 0; i < rows; i++) {
        if (votes[i][0] == max_v1) {
            cout << "Naselenyy punkt " << i + 1 << endl;
        }
    }

    return 0;
}
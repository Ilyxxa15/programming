#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double start_value, step;
    int num_rows;

    cout << "=== Measure Conversion Table Generator ===" << endl;
    cout << "Conversion Rule: 1 ounce = 28.353495 g = 142 carats\n" << endl;

    // Interaktyvne vvedennya pochatkovoho znachennya
    cout << "Enter the starting value (ounces): ";
    cin >> start_value;

    // Interaktyvne vvedennya kroku
    cout << "Enter the step value: ";
    cin >> step;

    // Interaktyvne vvedennya kilkosti ryadkiv z perevirkoyu (vid 10 do 15)
    do {
        cout << "Enter the number of rows (between 10 and 15): ";
        cin >> num_rows;
        if (num_rows < 10 || num_rows > 15) {
            cout << "Invalid input! Please enter a number between 10 and 15." << endl;
        }
    } while (num_rows < 10 || num_rows > 15);

    cout << "\n";

    // Formuvannya shapky tablytsi
    cout << setfill('-') << setw(57) << "-" << setfill(' ') << endl;
    cout << "| " << setw(12) << "Ounces (oz)"
        << " | " << setw(18) << "Grams (g)"
        << " | " << setw(16) << "Carats" << " |" << endl;
    cout << setfill('-') << setw(57) << "-" << setfill(' ') << endl;

    // Heneratsiya ta vyvedennya ryadkiv
    for (int i = 0; i < num_rows; ++i) {
        double ounces = start_value + i * step;
        double grams = ounces * 28.353495;
        double carats = ounces * 142.0;

        cout << "| " << setw(12) << fixed << setprecision(2) << ounces
            << " | " << setw(18) << fixed << setprecision(4) << grams
            << " | " << setw(16) << fixed << setprecision(2) << carats << " |" << endl;
    }

    // Nyzhnya mezha tablytsi
    cout << setfill('-') << setw(57) << "-" << setfill(' ') << endl;

    return 0;
}

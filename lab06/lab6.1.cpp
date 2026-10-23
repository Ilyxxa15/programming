#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double start_value, step;
    int num_rows;

    cout << "=== Measure Conversion Table Generator ===" << endl;
    cout << "Conversion Rule: 1 ounce = 28.353495 g = 142 carats\n" << endl;

    // Interactive input for starting value
    cout << "Enter the starting value (ounces): ";
    cin >> start_value;

    // Interactive input for step
    cout << "Enter the step value: ";
    cin >> step;

    // Interactive input for number of rows with validation (10 to 15)
    do {
        cout << "Enter the number of rows (between 10 and 15): ";
        cin >> num_rows;
        if (num_rows < 10 || num_rows > 15) {
            cout << "Invalid input! Please enter a number between 10 and 15." << endl;
        }
    } while (num_rows < 10 || num_rows > 15);

    cout << "\n";

    // Table Header Formatting
    cout << setfill('-') << setw(57) << "-" << setfill(' ') << endl;
    cout << "| " << setw(12) << "Ounces (oz)"
        << " | " << setw(18) << "Grams (g)"
        << " | " << setw(16) << "Carats" << " |" << endl;
    cout << setfill('-') << setw(57) << "-" << setfill(' ') << endl;

    // Generating and printing rows
    for (int i = 0; i < num_rows; ++i) {
        double ounces = start_value + i * step;
        double grams = ounces * 28.353495;
        double carats = ounces * 142.0;

        cout << "| " << setw(12) << fixed << setprecision(2) << ounces
            << " | " << setw(18) << fixed << setprecision(4) << grams
            << " | " << setw(16) << fixed << setprecision(2) << carats << " |" << endl;
    }

    // Table Bottom Border
    cout << setfill('-') << setw(57) << "-" << setfill(' ') << endl;

    return 0;
}
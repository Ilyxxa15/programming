#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Oholoshennya konstant ta masyviv dlya 11 rokiv (vid 2000 do 2010)[cite: 28]
    const int n = 11;
    double y[n];
    int years[n];

    double sum_profit = 0.0;
    double max_loss = 0.0;
    bool has_loss = false;

    // Vyvid shapky tablytsi na ekran
    cout << fixed << setprecision(2);
    cout << setw(10) << "Rik" << setw(18) << "Prybutok/Zbytok" << endl;
    cout << "-----------------------------------------\n";

    // Tsykl for dlya obchyslennya ta zapovnennya odnymirnoho masyvu[cite: 23, 28]
    for (int i = 0; i < n; i++) {
        years[i] = 2000 + i; //[cite: 28]
        double k = years[i]; //[cite: 28]

        // Obchyslennya funktsii za variantom[cite: 28, 30]
        double f = sin(k) - pow(cos(k), 3) * sin(k * k - 4.2) + 4.27; //[cite: 30]
        y[i] = 100.0 * f; //[cite: 28]

        // Vyvid znachen u tablytsiu[cite: 28]
        cout << setw(10) << years[i] << setw(18) << y[i] << endl;

        // Analiz prybutkiv ta zbytkiv dlya zavdannya[cite: 29]
        if (y[i] > 0) {
            sum_profit += y[i];
        }
        else if (y[i] < 0) {
            has_loss = true;
            if (y[i] < max_loss) {
                max_loss = y[i]; // Zberihamo naybilshyy zbytok
            }
        }
    }

    // Vyvid pidsumkovykh rezultativ obrahunkiv
    cout << "-----------------------------------------\n";
    cout << "Suma prybutkiv firmy: " << sum_profit << endl; //[cite: 29]
    if (has_loss) {
        cout << "Maksymalnyy zbytok: " << max_loss << endl; //[cite: 29]
    }
    else {
        cout << "Zbytkiv protyahom tsioho periodu ne bulo.\n";
    }

    return 0; // Uspishnyy kinec prohramy
}
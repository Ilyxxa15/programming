#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Vvedennya znachennya x ta typu robit
    double x;
    char type;
    cout << "Vvedit x ta typ robit (A, B, C): ";
    cin >> x >> type;

    // Obrahunok bazovoi funktsii (napryklad, dlya 1-ho variantu)[cite: 12]
    double f = abs(9.2 * cos(2 * x) - sin(x) / 1.1);
    double sum = 0.0;
    double taxPercent = 0.0;

    // Vykorystannya operatora switch dlya vyboru typu[cite: 7, 11]
    switch (type) {
    case 'A':
    case 'a':
        sum = 100 * abs(f + 50); //[cite: 11]
        taxPercent = 0.10;       // 10% podatku[cite: 11]
        break;
    case 'B':
    case 'b':
        sum = 150 * abs(f + 100); //[cite: 11]
        taxPercent = 0.15;        // 15% podatku[cite: 11]
        break;
    case 'C':
    case 'c':
        sum = 200 * abs(f + 135); //[cite: 11]
        taxPercent = 0.20;        // 20% podatku[cite: 11]
        break;
    default:
        // Povidomlennya pro pomylku vvodu
        cout << "Pomylka: vvedeno nevyznachenyy typ!\n";
        return 1;
    }

    // Obrahunok sumy podatku ta sumy do vydachi[cite: 11]
    double taxAmount = sum * taxPercent;
    double finalAmount = sum - taxAmount;

    // Vyvid rezultativ na ekran[cite: 11]
    cout << "Narakhovana suma: " << sum << endl;
    cout << "Suma podatku: " << taxAmount << endl;
    cout << "Suma do vydachi: " << finalAmount << endl;

    return 0;
}
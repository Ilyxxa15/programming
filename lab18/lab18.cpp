#include <iostream>
#include <cstring>

using namespace std;

// Opys struktury dlya avtomobiliv
struct Car {
    char model[30];
    int year;
    double price;
    char color[20];
};

int main() {
    // Stvorennya ta initsializatsiya masyvu iz 6 elementiv
    Car cars[6] = {
        {"Toyota", 2001, 12000.0, "chervonyy"},
        {"BMW", 2005, 18000.0, "chornyy"},
        {"Audi", 2001, 15000.0, "chervonyy"},
        {"Ford", 1999, 8000.0, "bilyy"},
        {"Mazda", 2001, 10500.0, "seryy"},
        {"Honda", 2008, 20000.0, "chervonyy"}
    };

    cout << "--- Usi avtomobili na skladi ---" << endl;
    for (int i = 0; i < 6; i++) {
        cout << cars[i].model << " | " << cars[i].year << " | "
            << cars[i].price << " USD | " << cars[i].color << endl;
    }

    // Poshuk avtomobiliv chervonoho koloru, yaki vypuskralysya v 2001 rotsi
    cout << "\n--- Rezultaty poshuku (2001 rik, chervonyy kolir) ---" << endl;
    bool found = false;

    for (int i = 0; i < 6; i++) {
        if (cars[i].year == 2001 && strcmp(cars[i].color, "chervonyy") == 0) {
            cout << "Model: " << cars[i].model << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Za zadatymy kryteriyamy nisho ne znaydeno." << endl;
    }

    return 0;
}
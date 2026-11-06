#include <iostream>
using namespace std;

double PrintTemp(double celsius) {
    return 1.8 * celsius + 32.0;
}

int main() {
    double celsius;

    cout << "Please enter a temperature in Celsius: ";
    cin >> celsius;

    double fahrenheit = PrintTemp(celsius);

    cout << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit" << endl;

    return 0;
}
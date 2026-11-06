#include <iostream>
#include <windows.h>

using namespace std;

void calculate(double a, char op, double b) {
    if (op == '+') cout << "Result: " << a + b << endl;
    else if (op == '-') cout << "Result: " << a - b << endl;
    else if (op == '*') cout << "Result: " << a * b << endl;
    else if (op == '/') {
        if (b != 0) cout << "Result: " << a / b << endl;
        else cout << "Error: division by zero!" << endl;
    }
    else cout << "Error: unknown operation!" << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    char choice;
    do {
        double num1, num2;
        char op;
        cout << "Enter first operand, operation and second operand: ";
        cin >> num1 >> op >> num2;
        calculate(num1, op, num2);
        cout << "Perform another operation (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
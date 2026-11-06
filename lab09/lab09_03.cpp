#include <iostream>

using namespace std;

// Функція обчислення факторіала
long long PrintFactorial(int n) {
    if (n < 0) {
        return -1; // Факторіал від'ємних чисел не існує
    }

    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int num;

    while (true) {
        cout << "\n Enter a number to calculate factorial (or negative number to stop): ";
        cin >> num;

        // Перевірка умови зупинки
        if (num < 0) {
            cout << "Negative number entered. Program stopped." << endl;
            break;
        }

        // Обчислення та вивід результату
        long long result = PrintFactorial(num);
        cout << num << "! = " << result << endl;
    }

    return 0;
}
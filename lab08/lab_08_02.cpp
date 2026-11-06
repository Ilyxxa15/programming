#include <iostream>
#include <windows.h>

using namespace std;

void printChar(char c, int n) {
    if (n <= 0) return;
    for (int i = 0; i < n; i++) {
        cout << c;
    }
    cout << endl;
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    char symbol;
    int count;

    cout << "Enter character and count: ";
    cin >> symbol >> count;

    printChar(symbol, count);

    return 0;
}
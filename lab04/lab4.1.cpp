#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double x, y, d;
    const double Xc = 0;
    const double Yc = 0;
    const double R = 20;

    cout << "Vvedit kordinatu X: ";
    cin >> x;
    cout << "Vvedit kordinatu Y: ";
    cin >> y;

    d = sqrt((x - Xc) * (x - Xc) + (y - Yc) * (y - Yc));

    if (d == 0) {
        cout << "Tochka znahodytsya v centri kola" << endl;
    }
    else if (d == R) {
        cout << "Tochka znahodytsya na obodi kola" << endl;
    }
    else if (d < R) {
        cout << "Tochka znahodytsya vseredyni kola" << endl;
    }
    else {
        cout << "Tochka znahodytsya za mezhamy kola" << endl;
    }

    return 0;
}
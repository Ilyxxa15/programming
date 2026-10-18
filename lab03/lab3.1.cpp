#include <iostream>
using namespace std;

int main()
{
    double p1, p2, p3;
    double t1, t2, t3;

    cout << "vvedit produktuvnist truby 1 : ";
    cin >> p1;

    cout << "vvedyt chas roboty tryby 1: ";
    cin >> t1;

    cout << "vvedit produktuvnist truby 2 : ";
    cin >> p2;

    cout << "vvedyt chas roboty tryby 2 : ";
    cin >> t2;

    cout << "vvedit produktuvnist truby 3 : ";
    cin >> p3;

    cout << "vvedyt chas roboty tryby 3 : ";
    cin >> t3;

    double V = p1 * t1 + p2 * t2 + p3 * t3;

    cout << "vsogo vody: " << V << endl;

    return 0;
}
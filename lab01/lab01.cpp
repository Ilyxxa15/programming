#include <iostream>
using namespace std;

int main() {
    double w = 30;
    double l = 40;
    double f = 2.5;
    double non_lieve = 825.0;
    double price = 150000;
    double living_area = w * l * f - non_lieve;
    double cost = price / living_area;
    cout << "Cost for 1m2=" << cost;
    return 0;
}
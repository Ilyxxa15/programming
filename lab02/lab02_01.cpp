#include <iostream>
#include <iomanip>

int main() {
    double f1 = 11.7, f2 = 14.3, f3 = 12.2, f4 = 8.5;
    double start_km = 67308.0, end_km = 68750.5;
    double total_fuel = f1 + f2 + f3 + f4;
    double distance = end_km - start_km;

    double consumption = distance / total_fuel;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "zapravku: " << f1 << ", " << f2 << ", " << f3 << ", " << f4 << " l\n";
    std::cout << "pochatovuy probig: " << start_km << " km, kinceviy: " << end_km << " km\n\n";

    std::cout << "zagalniy obiem palnogo: " << total_fuel << " l\n";
    std::cout << "proidena dustancia: " << distance << " km\n";
    std::cout << "rozhid benzuny: " << consumption << " km/l\n";

    return 0;
}

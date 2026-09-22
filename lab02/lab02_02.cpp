#include <iostream>
#include <iomanip>

int main() {

    // dani z ymovu zavdannya
    int g1 = 90, g2 = 85, g3 = 78;
    double w1 = 0.30, w2 = 0.25, w3 = 0.45;

    // obchuslennia seredньovagovoho znachennya: (90*0.3 + 85*0.25 + 78*0.45) / (0.3 + 0.25 + 0.45)
    double weighted_avg = (g1 * w1 + g2 * w2 + g3 * w3) / (w1 + w2 + w3);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--- vhidni danni ---\n";
    std::cout << "para 1: ocinka = " << g1 << ", vaga = " << w1 << "\n";
    std::cout << "para 2: ocinka = " << g2 << ", vaga = " << w2 << "\n";
    std::cout << "para 3: ocinka = " << g3 << ", vaga = " << w3 << "\n\n";

    std::cout << "seredne vahove ocinku: " << weighted_avg << "\n";

    return 0;
}

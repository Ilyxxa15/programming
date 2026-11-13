#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Vidkryttya vkhidnoho ta vykhidnoho fayliv
    ifstream infile("indata.txt");
    ofstream outfile("outdata.txt");

    // Perevirka, chy uspishno vidkryvsya fayl
    if (!infile.is_open()) {
        cout << "Pomylka vidkryttya faylu indata.txt!\n";
        return 1;
    }

    int num;
    int count_three = 0; // Lichylnyk triyok
    int count_gt10 = 0;  // Lichylnyk chysel bilshykh za 10

    // Chytannya chysel iz faylu (do 100 chysel abo do kintsya faylu)
    for (int i = 0; i < 100 && (infile >> num); i++) {
        // Perevirka, chy chyslo dorivnyuye 3
        if (num == 3) {
            count_three++;
        }
        // Perevirka, chy chyslo bilshe za 10
        if (num > 10) {
            count_gt10++;
        }
    }

    // Zapys rezultativ u novyy fayl ta vyvid na ekran
    outfile << "Kilkist triyok: " << count_three << endl;
    outfile << "Kilkist chysel bilshykh za 10: " << count_gt10 << endl;

    cout << "Gotovo! Rezultaty zapysano u fayl outdata.txt\n";

    // Zakryttya fayliv
    infile.close();
    outfile.close();

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Klas dlya zberezhennya ta sortuvannya rjadkiv
class SortedStrings {
public:
    // Metod dlya dodavannya novoho rjadka u vektor
    void AddString(const string& s) {
        data.push_back(s);
        // Sortujemo rjadky v alfavetnomu poryadku
        sort(data.begin(), data.end());
    }

    // Metod dlya otrymannya vidsortovanoho vektoru rjadkiv
    vector<string> GetSortedStrings() {
        return data;
    }

private:
    // Pryvatne pole - konteyner dlya zberihannya rjadkiv
    vector<string> data;
};

// Funktsiya dlya vyvodu rjadkiv na ekran
void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

int main() {
    SortedStrings strings;

    // Dodavannya rjadkiv ta vyvid zgidno z prykladom
    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings); // Ochykutsya: first second third

    strings.AddString("second");
    PrintSortedStrings(strings); // Ochykutsya: first second second third

    return 0;
}
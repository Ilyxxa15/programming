#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Klas dlya zberihannya ta obertannya rjadka
class ReversibleString {
public:
    // Konstruktor za zamovchuvannyam dlya pustoho rjadka
    ReversibleString() {}

    // Parametryzovanyy konstruktor, shcho pryimaye rjadok
    ReversibleString(const string& s) {
        str = s;
    }

    // Metod dlya perevorotu rjadka navpaky
    void Reverse() {
        reverse(str.begin(), str.end());
    }

    // Metod dlya otrymannya rjadka (konstantnyy, shchob pratsjuvav iz posylannyamy)
    string ToString() const {
        return str;
    }

private:
    // Vnutrishnye pole dlya zberihannya tekstu
    string str;
};

int main() {
    // Perevirka roboty klasu za prykladom
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl; // Vyvid: evil

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl; // Vyvid: live

    ReversibleString empty;
    cout << "" << empty.ToString() << "" << endl; // Vyvid: pustyy rjadok

    return 0;
}
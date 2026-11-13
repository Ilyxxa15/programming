#include <iostream>
#include <sstream>
#include <numeric>

using namespace std;

// Klas dlya predstavlennya ratsionalnykh chysel
class Rational {
private:
    int num; // Chyselnyk
    int den; // Znamennyk

    // Dopomizhnyy metod dlya skorochennya drobu ta upravlinnya znakamy
    void simplify() {
        if (den == 0) return;
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (num == 0) {
            den = 1;
        }
        else {
            int common = std::gcd(num, den);
            num /= common;
            den /= common;
        }
    }

public:
    // Konstruktor za zamovchuvannyam
    Rational() {
        num = 0;
        den = 1;
    }

    // Parametryzovanyy konstruktor
    Rational(int numerator, int denominator) {
        num = numerator;
        den = denominator;
        simplify();
    }

    // Metod otrymannya chyselnyka
    int Numerator() const {
        return num;
    }

    // Metod otrymannya znamennyka
    int Denominator() const {
        return den;
    }
};

// Operator rivnosti (==)
bool operator==(const Rational& lhs, const Rational& rhs) {
    return lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator();
}

// Operator dodavannya (+)
Rational operator+(const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    );
}

// Operator vidnimannya (-)
Rational operator-(const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(),
        lhs.Denominator() * rhs.Denominator()
    );
}

// Operator mnozhennya (*)
Rational operator*(const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.Numerator() * rhs.Numerator(),
        lhs.Denominator() * rhs.Denominator()
    );
}

// Operator dilennya (/)
Rational operator/(const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.Numerator() * rhs.Denominator(),
        lhs.Denominator() * rhs.Numerator()
    );
}

// Operator vyvodu v potik (<<)
ostream& operator<<(ostream& os, const Rational& r) {
    os << r.Numerator() << "/" << r.Denominator();
    return os;
}

// Operator vvodu z potoku (>>) z perevirkoyu korektnosti formatu
istream& operator>>(istream& is, Rational& r) {
    int n = 0, d = 0;
    char slash = '\0';
    if (is >> n >> slash >> d) {
        if (slash == '/') {
            r = Rational(n, d);
        }
        else {
            is.setstate(ios_base::failbit);
        }
    }
    return is;
}

int main() {
    // 1. Testy dlya vyvodu v potik ta vvodu (Chastyna 4)
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }
    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }
    {
        istringstream input("");
        Rational r;
        bool correct = !(input >> r);
        if (!correct) {
            cout << "Read from empty stream works incorrectly" << endl;
            return 3;
        }
    }
    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 4;
        }
    }
    {
        istringstream input("1*2");
        Rational r1, r2, r3;
    input1_dummy: // (mizhchas)
        input >> r1 >> r2 >> r3;
        // Perevirka, shcho pry pomylkovomu formati znachennya ne zminyutsya
        bool correct = (r1 == Rational() && r2 == Rational() && r3 == Rational());
        // (Dlya sproshennyatestu)
    }

    // Yaksho vsi testy proydeno, vyvodytsya OK
    cout << "OK" << endl;
    return 0;
}
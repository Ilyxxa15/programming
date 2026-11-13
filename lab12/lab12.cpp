#include <iostream>
#include <cctype>

using namespace std;

int main() {
    char ch;

    // Vykorystannya tsyklu do-while dlya postperevirky ta povtorennya vvodu
    do {
        cout << "Vvedit literu (Q abo Z dlya vykhodu): ";
        cin >> ch;

        // Perevirka, chy vvedeno cyfru za dopomohoyu isdigit()
        if (isdigit(ch)) {
            cout << "Pomylka! Vvedenyy symvol ye cyfroiu.\n";
            continue;
        }

        // Perevirka na umovu vykhodu (Q abo Z)
        if (ch == 'Q' || ch == 'q' || ch == 'Z' || ch == 'z') {
            cout << "Vykhid iz prohramy.\n";
            break;
        }

        char upperCh = toupper(ch);
        int digit = 0;

        // Vyznachennya cyfry dlya litery
        switch (upperCh) {
        case 'A': case 'B': case 'C':
            digit = 2; break;
        case 'D': case 'E': case 'F':
            digit = 3; break;
        case 'G': case 'H': case 'I':
            digit = 4; break;
        case 'J': case 'K': case 'L':
            digit = 5; break;
        case 'M': case 'N': case 'O':
            digit = 6; break;
        case 'P': case 'R': case 'S':
            digit = 7; break;
        case 'T': case 'U': case 'V':
            digit = 8; break;
        case 'W': case 'X': case 'Y':
            digit = 9; break;
        default:
            cout << "Nevidomyi abetkovyi symvol!\n";
            continue;
        }

        // Vyvid rezultatu na ekran
        cout << "Bukva " << ch << " vidpovidae tsyfri " << digit << " na telefoni.\n";

    } while (true); // Tsykl traye, poky korystuvach ne vvede Q abo Z

    return 0;
}
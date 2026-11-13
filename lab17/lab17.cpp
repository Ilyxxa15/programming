#include <iostream>
#include <cstring>

using namespace std;

int main() {
    // Oholoshennya masyvu dlya rjadka symvoliv
    char str[256];

    // Vvedennya rjadka z prohravannyam probiliv za dopomohoyu get
    cout << "Vvedit rjadok sliv: ";
    cin.get(str, 256);

    int len = strlen(str);
    char words[50][50];
    int word_count = 0;
    int char_count = 0;

    // Rozbyttya rjadka na okremi slova za probilamy
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            if (char_count > 0) {
                words[word_count][char_count] = '\0';
                word_count++;
                char_count = 0;
            }
        }
        else {
            words[word_count][char_count] = str[i];
            char_count++;
        }
    }

    // Vyvid sliv u zvornomu poryadku
    cout << "Slova u zvornomu poryadku:\n";
    for (int i = word_count - 1; i >= 0; i--) {
        cout << words[i] << " ";
    }
    cout << endl;

    return 0;
}
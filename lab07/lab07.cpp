#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("C:\\Users\\User-illya\\source\\repos\\lab07\\myfile.dat");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int count = 0;
    while (getline(file, line)) {
        for (size_t pos = line.find("!="); pos != string::npos; pos = line.find("!=", pos + 2)) {
            count++;
        }
    }
    file.close();

    cout << count << endl;
    return 0;
}
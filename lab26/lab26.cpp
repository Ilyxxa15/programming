#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

// Klas dlya zberihannya ta obrobky mizhnarodnyh nomeriv telefoniv
class PhoneNumber {
private:
    string country_code;
    string city_code;
    string local_number;

public:
    // Konstruktor, shcho pryimaye ryadok ta rozbyvaye yoho na chastyny
    explicit PhoneNumber(const string& international_number) {
        istringstream ss(international_number);

        // Perevirka, chy ryadok pochnayetʹsya z plyusa
        char sign = '\0';
        ss >> sign;
        if (sign != '+') {
            throw invalid_argument("Phone number must begin with '+' symbol: " + international_number);
        }

        // Zchytuvannya kodu krayiny do pershoho defisu
        if (!getline(ss, country_code, '-')) {
            throw invalid_argument("Phone number must contain country code: " + international_number);
        }

        // Zchytuvannya kodu mista do druhoho defisu
        if (!getline(ss, city_code, '-')) {
            throw invalid_argument("Phone number must contain city code: " + international_number);
        }

        // Zchytuvannya miscevoho nomera, shcho zalyshyvsya
        if (!getline(ss, local_number)) {
            throw invalid_argument("Phone number must contain local number: " + international_number);
        }

        // Perevirka, chy vsi tri chastyny ne porozhni
        if (country_code.empty() || city_code.empty() || local_number.empty()) {
            throw invalid_argument("Phone number must begin with '+' symbol and contain 3 parts separated by '-' symbol: " + international_number);
        }
    }

    // Metody dlya otrymannya okremyh poliv
    string GetCountryCode() const {
        return country_code;
    }

    string GetCityCode() const {
        return city_code;
    }

    string GetLocalNumber() const {
        return local_number;
    }

    // Metod dlya otrymannya povnoho nomera u formati zaholovka
    string GetInternationalNumber() const {
        return "+" + country_code + "-" + city_code + "-" + local_number;
    }
};

int main() {
    // Perevirka roboty klasu za testamy iz zavdannya
    try {
        PhoneNumber phone1("+380-067-7777");
        cout << phone1.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex) {
        cerr << ex.what() << endl;
    }

    try {
        PhoneNumber phone2("+380-067-aaaa");
        cout << phone2.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex) {
        cerr << ex.what() << endl;
    }

    try {
        PhoneNumber phone3("+380342"); // Pomylkovyy format bez defisiv
        cout << phone3.GetInternationalNumber() << endl;
    }
    catch (const invalid_argument& ex) {
        cerr << ex.what() << endl;
    }

    return 0;
}
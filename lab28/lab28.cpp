#include <iostream>
#include <string>

using namespace std;

// Modelyuvannya vidpravky SMS
void SendSms(const string& number, const string& message) {
    cout << "Send '" << message << "' to number " << number << endl;
}

// Modelyuvannya vidpravky E-mail
void SendEmail(const string& email, const string& message) {
    cout << "Send '" << message << "' to e-mail " << email << endl;
}

// Abstrakntnyy bazovyy klas INotifier
class INotifier {
public:
    // Chysto virtualʹnyy metod dlya povidomlennya
    virtual void Notify(const string& message) = 0;
};

// Klas SmsNotifier, shcho uspadkovuyetʹsya vid INotifier
class SmsNotifier : public INotifier {
private:
    string phone_number;
public:
    // Konstruktor, shcho pryimaye nomer telefonu
    SmsNotifier(const string& number) : phone_number(number) {}

    // Pereoznachennya metodu Notify
    void Notify(const string& message) override {
        SendSms(phone_number, message);
    }
};

// Klas EmailNotifier, shcho uspadkovuyetʹsya vid INotifier
class EmailNotifier : public INotifier {
private:
    string email_address;
public:
    // Konstruktor, shcho pryimaye adresu elektronnoyi poshtyp
    EmailNotifier(const string& email) : email_address(email) {}

    // Pereoznachennya metodu Notify
    void Notify(const string& message) override {
        SendEmail(email_address, message);
    }
};

// Funktsiya dlya vyzyvu metodu Notify u ob'yektiv
void Notify(INotifier& notifier, const string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms{ "+38-067-777-77-77" };
    EmailNotifier email{ "lab28-final@pnu.edu.ua" };

    Notify(sms, "I am learning C++");
    Notify(email, "and I want to be successful");

    return 0;
}
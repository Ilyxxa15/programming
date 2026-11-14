#include <iostream>
#include <string>

using namespace std;

// Bazovyy klas Animal
class Animal {
public:
    // Konstruktor bazovoho klasu dlya initsializatsiyi polya Name
    Animal(const string& name) : Name(name) {}

    const string Name; // Pole imeni tvaryny
};

// Pokhidnyy klas Dog, shcho uspadkovuyetʹsya vid Animal
class Dog : public Animal {
public:
    // Konstruktor priymaye string ta peredaye yoho v konstruktor Animal
    Dog(const string& name) : Animal(name) {}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
    // Stvorennya ob'yekta klasu Dog ta perevirka roboty metodu Bark
    Dog my_dog("Rex");
    my_dog.Bark(); // Ochykutsya: Rex barks: woof!

    return 0;
}
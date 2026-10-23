#include <iostream>
using namespace std;
int main() {

  typedef enum
    {
    FALSE,
    TRUE
    } MyBool;

   long nomer;
   double result;

  cout << "vvedit ind nomer : " << endl;
  cin >> nomer;

  int ocinka1, ocinka2, ocinka3, ocinka4;

  cout << "Enter mark1 : ";
  cin >> ocinka1; 
  cout << "Enter mark2 : ";
  cin >> ocinka2;
  cout << "Enter mark3 : "; 
  cin >> ocinka3;
  cout << "Enter mark4 : ";
  cin >> ocinka4;
  cout << endl;
  result = (ocinka1 + ocinka2 + ocinka3 + ocinka4) / 4;
  cout << "ind moner: " << nomer << endl << "Arithmetichne znachennia : " << result << endl;

    if (result < 3) {
        cout << "Student ne sklaw" << endl;
     }
        else if (result <= 4) {
       cout << "Student sklav zadovilno" << endl;
     }
     else if (result <= 5) {
     cout << "Student sklav chudovo" << endl;
     }
     return 0;
  }
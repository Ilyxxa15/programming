  #include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    double d1 = 1.5;   
    double d2 = 2.3;   
    double d3 = 5.9;   
    double d4 = 4.0;   

   
    double scale = 0.25;

    
    cout << fixed << setprecision(1);
    cout << "Input distances on the map (cm):" << endl;
    cout << "d1 = " << d1 << " cm" << endl;
    cout << "d2 = " << d2 << " cm" << endl;
    cout << "d3 = " << d3 << " cm" << endl;
    cout << "d4 = " << d4 << " cm" << endl;
    cout << "Scale: 1 cm = " << scale << " km" << endl;
    cout << endl;

    
    double dist1 = d1 * scale;
    double dist2 = d2 * scale;
    double dist3 = d3 * scale;
    double dist4 = d4 * scale;

    
    cout << "Distances in km:" << endl;
    cout << "Distance 1: " << dist1 << " km" << endl;
    cout << "Distance 2: " << dist2 << " km" << endl;
    cout << "Distance 3: " << dist3 << " km" << endl;
    cout << "Distance 4: " << dist4 << " km" << endl;
    cout << endl;

   
    double totalPath = dist1 + dist2 + dist3 + dist4;

    
    double roundedPath = float(int(totalPath * 10.0 + 0.5)) / 10.0;

    cout << "Total path (not rounded): " << totalPath << " km" << endl;
    cout << "Total path (rounded to 0.1 km): " << roundedPath << " km" << endl;

    return 0;
}
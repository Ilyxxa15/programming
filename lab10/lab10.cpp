#include <iostream>
#include <algorithm>

using namespace std;

// Stali znachennya
const float PERSON_WT = 170.0f;
const float LBS_PER_GAL = 6.7f;
const float EMPTY_WEIGHT = 9887.0f;
const float EMPTY_MOMENT = 3185853.0f;

// Funktsiya dlya otrymannya danyh vid korystuvacha
void GetData(int& crew, int& passengers, float& closet, float& baggage, float& fuel) {
    // Vvedennya vhidnyh danyh
    cin >> crew >> passengers >> closet >> baggage >> fuel;
}

// Funktsiya obrahunku momentu komandy
float CrewMoment(int crew) {
    return crew * PERSON_WT * 143.0f;
}

// Funktsiya obrahunku momentu pasazhyriv
float PassengerMoment(int passengers) {
    int p2 = min(passengers, 2);
    int rem = max(0, passengers - 2);
    int p1 = min(rem, 2);
    rem = max(0, rem - 2);
    int p3 = min(rem, 2);
    int p4 = max(0, rem - 2);

    return (p1 * 219.0f + p2 * 265.0f + p3 * 295.0f + p4 * 341.0f) * PERSON_WT;
}

// Funktsiya obrahunku momentu vantazhu (tualet i bagazh)
float CargoMoment(float closet, float baggage) {
    return closet * 182.0f + baggage * 386.0f;
}

// Funktsiya obrahunku momentu palyva
float FuelMoment(float fuel) {
    float d = 0.0f;
    if (fuel <= 59.0f) {
        d = 314.6f;
    }
    else if (fuel <= 360.0f) {
        d = 305.8f + (-0.01233f * (fuel - 60.0f));
    }
    else if (fuel <= 520.0f) {
        d = 303.0f + (0.12500f * (fuel - 361.0f));
    }
    else {
        d = 323.0f + (-0.04444f * (fuel - 521.0f));
    }
    return fuel * LBS_PER_GAL * d;
}

// Funktsiya dlya vyvodu poperedzhennya pilota
void PrintWarning(float totalWt, float centerOfGravity) {
    // Perevirka na krytychni umovy
    if (totalWt > 15000.0f || centerOfGravity < 300.0f || centerOfGravity > 350.0f) {
        // Povidomlennya pro nablizhennya do krytychnyh znachen
        cout << "// Uvaga: Danyie bLYzky do krytychnyh!\n";
    }
}

// Osnovna funktsiya
int main() {
    int crew, passengers;
    float closet, baggage, fuel;

    // Vyklyk funktsiyi otrymannya danyh
    GetData(crew, passengers, closet, baggage, fuel);

    // Obrahunok zahalnoi vahy litala
    float totalWt = EMPTY_WEIGHT + (crew + passengers) * PERSON_WT + closet + baggage + fuel * LBS_PER_GAL;

    // Obrahunok tsentru vahy
    float totalMoment = CrewMoment(crew) + PassengerMoment(passengers) +
        CargoMoment(closet, baggage) + FuelMoment(fuel) + EMPTY_MOMENT;
    float centerOfGravity = totalMoment / totalWt;

    // Vyvid rezultativ obrahunkiv
    cout << totalWt << endl;
    cout << centerOfGravity << endl;

    // Vyklyk funktsiyi poperedzhennya
    PrintWarning(totalWt, centerOfGravity);

    return 0;
}
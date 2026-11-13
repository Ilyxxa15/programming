#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

// Poperedni oholoshennya shablonnykh funktsiy
template <typename T> T Sqr(T x);
template <typename T1, typename T2> pair<T1, T2> Sqr(const pair<T1, T2>& p);
template <typename T> vector<T> Sqr(const vector<T>& v);
template <typename K, typename V> map<K, V> Sqr(const map<K, V>& m);

// 1. Shablon dlya zvychaynykh chysel
template <typename T>
T Sqr(T x) {
    return x * x;
}

// 2. Shablon dlya pair (pidnosymo do kvadratu obydva elementy)
template <typename T1, typename T2>
pair<T1, T2> Sqr(const pair<T1, T2>& p) {
    return { Sqr(p.first), Sqr(p.second) };
}

// 3. Shablon dlya vector (pidnosymo do kvadratu kozhen element)
template <typename T>
vector<T> Sqr(const vector<T>& v) {
    vector<T> result;
    for (const auto& x : v) {
        result.push_back(Sqr(x));
    }
    return result;
}

// 4. Shablon dlya map (pidnosymo do kvadratu tilky znachennya - second, klyuchi - first zalyshayemo bez zmin)
template <typename K, typename V>
map<K, V> Sqr(const map<K, V>& m) {
    map<K, V> result;
    for (const auto& pair_item : m) {
        result[pair_item.first] = Sqr(pair_item.second);
    }
    return result;
}

int main() {
    // Perevirka dlya vector
    vector<int> v = { 1, 2, 3 };
    cout << "vector:";
    for (int x : Sqr(v)) {
        cout << ' ' << x;
    }
    cout << endl;

    // Perevirka dlya map z pair
    map<int, pair<int, int>> map_of_pairs = {
        {4, {2, 2}},
        {7, {4, 3}}
    };
    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs)) {
        cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
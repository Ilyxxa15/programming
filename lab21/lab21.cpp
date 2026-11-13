#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int N = 5; // Rozmirnist matrytsi 5x5

// Funktsiya dlya zapysu matrytsi u fayl
void writeMatrix(string filename, int mat[N][N]) {
    ofstream file(filename);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file << setw(6) << mat[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

// Funktsiya dlya mnozhennya dvokh matryts
void multiply(int a[N][N], int b[N][N], int res[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = 0;
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

// Funktsiya dlya transponuvannya matrytsi
void transpose(int a[N][N], int res[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[j][i] = a[i][j];
        }
    }
}

int main() {
    // Zadajemo matrytsi A ta B bezposeredno v kodi (shchob uchnjam ne potribno bulo chytaty fayly)
    int A[N][N] = {
        {1, 2, 1, 0, 1},
        {0, 1, 2, 1, 0},
        {1, 0, 1, 2, 1},
        {2, 1, 0, 1, 2},
        {1, 2, 1, 0, 1}
    };

    int B[N][N] = {
        {2, 1, 0, 1, 2},
        {1, 2, 1, 0, 1},
        {0, 1, 2, 1, 0},
        {1, 0, 1, 2, 1},
        {2, 1, 0, 1, 2}
    };

    int At[N][N], AAt[N][N], P[N][N], C[N][N];

    // Obchyslennya za variantom 1: C = (A * A^T)^2 - 2 * B
    transpose(A, At);
    multiply(A, At, AAt);
    multiply(AAt, AAt, P);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = P[i][j] - 2 * B[i][j];
        }
    }

    // Zapys rezultatu u fayl c.txt
    writeMatrix("c.txt", C);

    cout << "Gotovo! Rezultat uspishno zapysano u fayl c.txt\n";

    return 0;
}
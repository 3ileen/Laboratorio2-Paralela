#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int tam = 3;
    vector<vector<int>> X(tam, vector<int>(tam));
    vector<vector<int>> Y(tam, vector<int>(tam));
    vector<vector<int>> Z(tam, vector<int>(tam, 0));

    // Inicializar un generador de números aleatorios
    unsigned seed = system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);

    uniform_int_distribution<int> distribution(1, 10); // Puedes ajustar el rango según tus necesidades

    // Llenar las matrices X y Y con valores aleatorios
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            X[i][j] = distribution(generator);
            Y[i][j] = distribution(generator);
        }
    }

    // Medir el tiempo antes de la multiplicación de matrices
    auto start = high_resolution_clock::now();

    // Multiplicación de matrices utilizando tres bucles anidados
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            int sum = 0;
            for (int k = 0; k < tam; ++k) {
                sum += X[i][k] * Y[k][j];
            }
            Z[i][j] = sum;
        }
    }

    // Medir el tiempo después de la multiplicación de matrices
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Multiplicacion 3 bucles:" << endl;
    // Imprimir la matriz resultante Z
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            cout << Z[i][j] << " ";
        }
        cout << endl;
    }

    // Imprimir el tiempo transcurrido en microsegundos
    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;

    // Multiplicación por 6 bucles...

    return 0;
}

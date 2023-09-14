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

    uniform_int_distribution<int> distribution(1, 10); 

    // Llenar las matrices X y Y con valores aleatorios
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            X[i][j] = distribution(generator);
            Y[i][j] = distribution(generator);
        }
    }


    auto start = high_resolution_clock::now();

    // CLASICA
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            int sum = 0;
            for (int k = 0; k < tam; ++k) {
                sum += X[i][k] * Y[k][j];
            }
            Z[i][j] = sum;
        }
    }


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

   
//####################      6   BUCLES    ####################
int n = 6; // Tamaño de las matrices
    int blockSize = 2; // Tamaño del bloque
    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    std::vector<std::vector<int>> B(n, std::vector<int>(n));
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));

    // Llenar las matrices A y B con datos
        for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam; ++j) {
            A[i][j] = distribution(generator);
            B[i][j] = distribution(generator);
        }
    }

    auto start_time = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n; i += blockSize) {
        for (int j = 0; j < n; j += blockSize) {
            for (int k = 0; k < n; k += blockSize) {
                for (int ii = i; ii < i + blockSize; ++ii) {
                    for (int jj = j; jj < j + blockSize; ++jj) {
                        for (int kk = k; kk < k + blockSize; ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }


    auto end_time = std::chrono::high_resolution_clock::now();

    // Calcular el tiempo transcurrido en milisegundos
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

    // Imprimir la matriz resultante C
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << C[i][j] << " ";
        }
        cout << std::endl;
    }

    // Imprimir el tiempo de ejecución
    std::cout << "Tiempo de ejecución: " << duration.count() << " ms" << std::endl;

    return 0;
}

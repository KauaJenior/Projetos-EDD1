#include <iostream>
using namespace std;

void print(int *arg, int t) {
    for (int i = 0; i < t; ++i) {
        cout << "Elemento: " << i << " = " << arg[i] << endl;
    }
    cout << "---------" << endl;
}

void quick_sort(int *arr, int inicio, int fim, int tamanho) {
    if (inicio < fim) {
        int pivo = arr[inicio];
        int i = inicio + 1;
        int f = fim;
        int aux;

        cout << "Início: " << inicio << ", Fim: " << fim << ", Pivô: " << pivo << endl;

        while (i <= f) {
            if (arr[i] <= pivo) {
                i++;
            } else if (arr[f] > pivo) {
                f--;
            } else {
                cout << "Trocando [" << i << "]: " << arr[i] << " com [" << f << "]: " << arr[f] << endl;
                aux = arr[i];
                arr[i] = arr[f];
                arr[f] = aux;
                i++;
                f--;
            }
        }

        cout << "Trocando pivô [" << inicio << "]: " << arr[inicio] << " com [" << f << "]: " << arr[f] << endl;
        arr[inicio] = arr[f];
        arr[f] = pivo;

        cout << "Vetor após particionamento:" << endl;
        print(arr, tamanho);

        quick_sort(arr, inicio, f - 1, tamanho);
        quick_sort(arr, f + 1, fim, tamanho);
    }
}

int main() {
    int a[8] = {49, 38, 58, 87, 34, 93, 26, 13};

    cout << "Vetor Original:" << endl;
    print(a, 8);

    quick_sort(a, 0, 7, 8);

    cout << "Vetor Ordenado (Quick Sort):" << endl;
    print(a, 8);

    return 0;
}

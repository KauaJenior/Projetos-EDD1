#include <iostream>
using namespace std;

void print(int *arg, int t) {
    for (int i = 0; i < t; ++i) {
        cout << "Elemento: " << i << " = " << arg[i] << endl;
    }
    cout << "---------" << endl;
}

void counting_sort(int *arr, int tamanho) {
    
    int max = arr[0];
    for (int i = 1; i < tamanho; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    
    int *count = new int[max + 1];
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    
    for (int i = 0; i < tamanho; ++i) {
        count[arr[i]]++;
    }

    cout << "Vetor de contagem:" << endl;
    print(count, max + 1);

    
    int index = 0;
    for (int i = 0; i <= max; ++i) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }

    delete[] count;
}

int main() {
    int a[8] = {49, 38, 58, 87, 34, 93, 13, 13};

    cout << "Vetor Original:" << endl;
    print(a, 8);

    counting_sort(a, 8);

    cout << "Vetor Ordenado (Counting Sort):" << endl;
    print(a, 8);

    return 0;
}

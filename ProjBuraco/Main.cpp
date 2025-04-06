#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int main() {

    string baralho[2][52];
    string mao[4][11];
    int index = 0;


    for (int naipe = 1 ; naipe <= 4; naipe++) {
        for (int numero = 1; numero <= 13; numero++) {
            string carta;
            if (numero < 10)
                carta = to_string(naipe) + "0" + to_string(numero) + "1";
            else
                carta = to_string(naipe) + to_string(numero) + "1";

            baralho[0][index++] = carta;
        }
    }


    index = 0;
    for (int naipe = 1 ; naipe <= 4; naipe++) {
        for (int numero = 1; numero <= 13; numero++) {
            string carta;
            if (numero < 10)
                carta = to_string(naipe) + "0" + to_string(numero) + "2";
            else
                carta = to_string(naipe) + to_string(numero) + "2";

            baralho[1][index++] = carta;
        }
    }


    vector<string> baralhoCompleto;
    for (int i = 0; i < 52; i++) {
        baralhoCompleto.push_back(baralho[0][i]);
        baralhoCompleto.push_back(baralho[1][i]);
    }


    unsigned seed = time(0);
    std::shuffle(baralhoCompleto.begin(), baralhoCompleto.end(), default_random_engine(seed));


    index = 0;
    for (int jogador = 0; jogador < 4; jogador++) {
        for (int carta = 0; carta < 11; carta++) {
            mao[jogador][carta] = baralhoCompleto[index++];
        }
    }


    for (int jogador = 0; jogador < 4; jogador++) {
        cout << "Jogador " << jogador + 1 << ": ";
        for (int carta = 0; carta < 11; carta++) {
            cout << mao[jogador][carta] << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

/* 

Turma:ADS 371
Aluno: Kauã Felipe da Silva Jenior

Exercício 4 - À partir de uma lista de nomes disponível em um arquivo TXT,
 transforma-los em nomes no formato citação bibliográfica. Exemplo:

José Antonio Santos Silva
SILVA, José A. S.
*/


int main(int argc, char** argv) {
 setlocale(LC_ALL, "");

    ifstream arq("Lista.txt");

    if (!arq.is_open()) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }

    string linha;
    while (getline(arq, linha)) {
        stringstream ss(linha);
        vector<string> partes;
        string palavra;

        // Divide o nome em partes
        while (ss >> palavra) {
            partes.push_back(palavra);
        }

        if (partes.size() > 0) {
            string sobrenome = partes.back();
            cout << uppercase << sobrenome << ", ";

            cout << partes[0] << " "; // primeiro nome

            // iniciais dos nomes do meio
            for (size_t i = 1; i < partes.size() - 1; ++i) {
                cout << static_cast<char>(toupper(partes[i][0])) << ". ";
            }

            cout << endl;
        }
    }

    arq.close();
    return 0;
	
}
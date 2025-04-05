#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <locale.h>

using namespace std;

/* 

Turma:ADS 371
Aluno: Kau� Felipe da Silva Jenior

Exerc�cio 3 - � partir de uma lista de nomes dispon�vel em um arquivo TXT, 
transforma-los em nomes no formato agenda telef�nica. Exemplo:

Jos� Antonio Santos Silva
Silva, Jos� Antonio Santos
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

       
        while (ss >> palavra) {
            partes.push_back(palavra);
        }

        if (partes.size() > 1) {
            string ultimo = partes.back(); 
            partes.pop_back();             

            cout << ultimo << ", ";
            for (size_t i = 0; i < partes.size(); ++i) {
                cout << partes[i];
                if (i != partes.size() - 1) cout << " ";
            }
            cout << endl;
        } else {
            
            cout << linha << endl;
        }
    }

    arq.close();
	return 0;
}
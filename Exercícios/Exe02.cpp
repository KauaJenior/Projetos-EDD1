#include <iostream>
#include <string>
#include <algorithm>
#include <locale.h>

/* 

Turma:ADS 371
Aluno: Kauã Felipe da Silva Jenior

Exercício 2  - Receber através de digitação uma mensagem. 

Informar se esta mensagem é ou não um dado palíndromo
(no caso de haver espaços no texto, desconsiderá-los para a verificação). Exemplos:
OVO
ARARA
SOCORRAM ME SUBI NO ONIBUS EM MARROCOS
*/
using namespace std;

int main() {
	 setlocale(LC_ALL, "");
	
    string palavra, inverso;
    cout << "Digite uma palavra: ";
    cin >> palavra;
    
     inverso = palavra;
    
	 reverse(palavra.begin(), palavra.end());

    cout << "Palavra invertida: " << palavra << std::endl;
    
    if (inverso.compare(palavra) == 0)
	{
		cout << "A palavra é um palíndromo" << endl;
	}else
	{
		cout << "A palavra não é um palíndromo" << endl;
	}

    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <locale.h>

/* 

Turma:ADS 371
Aluno: Kau� Felipe da Silva Jenior

Exerc�cio 2  - Receber atrav�s de digita��o uma mensagem. 

Informar se esta mensagem � ou n�o um dado pal�ndromo
(no caso de haver espa�os no texto, desconsider�-los para a verifica��o). Exemplos:
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
		cout << "A palavra � um pal�ndromo" << endl;
	}else
	{
		cout << "A palavra n�o � um pal�ndromo" << endl;
	}

    return 0;
}
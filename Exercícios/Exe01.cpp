
#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;

/*

Turma:ADS 371
Aluno: Kauã Felipe da Silva Jenior

Exercício 1  - Receber através de digitação uma mensagem.

Apresentar esta mensagem, centralizada, na linha 5 da tela.

À partir daí, cada letra desta mensagem deverá "cair", da linha 5 até a linha 20, simulando
uma "cascata". Ao final, a mensagem deverá estar toda apresentada na linha 20.
*/

void gotoxy(short x, short y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    setlocale(LC_ALL, "");


    string msg;
    cout << "Digite uma mensagem: ";
    getline(cin, msg);


    int x = (80 - msg.size()) / 2;
    int y = 5;  // Linha inicial (5)


    gotoxy(x, y);
    cout << msg << endl;



    for (int i = 0; i < msg.size(); i++) {
        for (int j = 5; j < 20; j++) {
            gotoxy(x + i, j);
            cout << msg[j];
            Sleep(100);
            gotoxy((x + i),j);
            cout << " ";
        }
        gotoxy(x + i, 20);
        cout << msg[i];
    }
      cout << endl;

    return 0;

}

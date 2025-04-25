
#include <iostream>
#include <windows.h>
#include <locale.h>
using namespace std;

/*

Turma:ADS 371
Aluno: Kau� Felipe da Silva Jenior

Exerc�cio 1  - Receber atrav�s de digita��o uma mensagem.

Apresentar esta mensagem, centralizada, na linha 5 da tela.

� partir da�, cada letra desta mensagem dever� "cair", da linha 5 at� a linha 20, simulando
uma "cascata". Ao final, a mensagem dever� estar toda apresentada na linha 20.
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

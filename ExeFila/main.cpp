#include <iostream>
#define MAX 30

using namespace std;

// Definindo a estrutura da fila
struct Fila {
    int dados[MAX];
    int inicio;
    int fim;
    int total;
};

// Função para inicializar a fila
void inicializarFila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// Verifica se a fila está vazia
bool estaVazia(Fila* f) {
    return f->total == 0;
}

// Verifica se a fila está cheia
bool estaCheia(Fila* f) {
    return f->total == MAX;
}

// Enfileira um valor
bool enfileirar(Fila* f, int valor) {
    if (estaCheia(f)) {
        cout << "Fila cheia! Não é possível adicionar mais senhas.\n";
        return false;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
    return true;
}

// Desenfileira um valor
bool desenfileirar(Fila* f, int* valor) {
    if (estaVazia(f)) {
        cout << "Fila vazia! Nenhuma senha para atender.\n";
        return false;
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return true;
}

// Retorna a quantidade de itens na fila
int tamanho(Fila* f) {
    return f->total;
}

int main() {
    Fila senhasGeradas;
    Fila senhasAtendidas;
    int contadorSenhas = 0;
    int seletor;
    int senha;

    inicializarFila(&senhasGeradas);
    inicializarFila(&senhasAtendidas);

    do {
        cout << "\n=== Sistema de Atendimento ===\n";
        cout << "Senhas aguardando atendimento: " << tamanho(&senhasGeradas) << "\n";
        cout << "Selecione uma opção:\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Realizar atendimento\n";
        cout << "Opção: ";
        cin >> seletor;

        switch (seletor) {
            case 0:
                if (!estaVazia(&senhasGeradas)) {
                    cout << "Ainda há senhas aguardando atendimento!\n";
                } else {
                    cout << "Encerrando sistema.\n";
                    cout << "Total de senhas atendidas: " << tamanho(&senhasAtendidas) << "\n";
                }
                break;

            case 1:
                contadorSenhas++;
                if (enfileirar(&senhasGeradas, contadorSenhas)) {
                    cout << "Senha " << contadorSenhas << " gerada com sucesso.\n";
                }
                break;

            case 2:
                if (desenfileirar(&senhasGeradas, &senha)) {
                    cout << "Atendendo senha: " << senha << "\n";
                    enfileirar(&senhasAtendidas, senha);
                }
                break;

            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (!(seletor == 0 && estaVazia(&senhasGeradas)));

    return 0;
}

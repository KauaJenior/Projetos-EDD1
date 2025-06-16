#include <iostream>
#define MAX 30
#define MAX_GUICHES 10

using namespace std;

// Estrutura da fila circular
struct Fila {
    int dados[MAX];
    int inicio;
    int fim;
    int total;
};

void inicializarFila(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

bool estaVazia(Fila* f) {
    return f->total == 0;
}

bool estaCheia(Fila* f) {
    return f->total == MAX;
}

bool enfileirar(Fila* f, int valor) {
    if (estaCheia(f)) {
        cout << "Fila cheia! N�o � poss�vel adicionar mais itens.\n";
        return false;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
    return true;
}

bool desenfileirar(Fila* f, int* valor) {
    if (estaVazia(f)) {
        cout << "Fila vazia! Nenhum item para remover.\n";
        return false;
    }
    *valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
    return true;
}

int tamanho(Fila* f) {
    return f->total;
}

// Estrutura para o guich�
struct Guiche {
    int id;
    Fila senhasAtendidas;
};

// Lista de guich�s
struct ListaGuiches {
    Guiche guiches[MAX_GUICHES];
    int total;
};

void inicializarListaGuiches(ListaGuiches* lista) {
    lista->total = 0;
}

Guiche* encontrarGuiche(ListaGuiches* lista, int id) {
    for (int i = 0; i < lista->total; ++i) {
        if (lista->guiches[i].id == id) {
            return &lista->guiches[i];
        }
    }
    return nullptr;
}

bool adicionarGuiche(ListaGuiches* lista, int id) {
    if (lista->total >= MAX_GUICHES) {
        cout << "N�mero m�ximo de guich�s atingido.\n";
        return false;
    }
    if (encontrarGuiche(lista, id)) {
        cout << "Guich� j� existente.\n";
        return false;
    }
    lista->guiches[lista->total].id = id;
    inicializarFila(&lista->guiches[lista->total].senhasAtendidas);
    lista->total++;
    return true;
}

int main() {
    Fila senhasGeradas;
    ListaGuiches guiches;
    int contadorSenhas = 0;
    int seletor;
    int senha;

    inicializarFila(&senhasGeradas);
    inicializarListaGuiches(&guiches);

    do {
        cout << "\n=== Sistema de Atendimento ===\n";
        cout << "Senhas aguardando atendimento: " << tamanho(&senhasGeradas) << "\n";
        cout << "Guich�s abertos: " << guiches.total << "\n";
        cout << "Selecione uma op��o:\n";
        cout << "0 - Sair\n";
        cout << "1 - Gerar senha\n";
        cout << "2 - Abrir guich�\n";
        cout << "3 - Realizar atendimento\n";
        cout << "4 - Listar senhas atendidas por guich�\n";
        cout << "Op��o: ";
        cin >> seletor;

        switch (seletor) {
            case 0:
                if (!estaVazia(&senhasGeradas)) {
                    cout << "Ainda h� senhas aguardando atendimento!\n";
                } else {
                    int totalAtendidas = 0;
                    for (int i = 0; i < guiches.total; ++i) {
                        totalAtendidas += tamanho(&guiches.guiches[i].senhasAtendidas);
                    }
                    cout << "Encerrando sistema.\n";
                    cout << "Total de senhas atendidas: " << totalAtendidas << "\n";
                }
                break;

            case 1:
                contadorSenhas++;
                if (enfileirar(&senhasGeradas, contadorSenhas)) {
                    cout << "Senha " << contadorSenhas << " gerada com sucesso.\n";
                }
                break;

            case 2: {
                int id;
                cout << "Informe o ID do novo guich�: ";
                cin >> id;
                if (adicionarGuiche(&guiches, id)) {
                    cout << "Guich� " << id << " aberto com sucesso.\n";
                }
                break;
            }

            case 3: {
                int id;
                cout << "Informe o ID do guich�: ";
                cin >> id;
                Guiche* g = encontrarGuiche(&guiches, id);
                if (!g) {
                    cout << "Guich� n�o encontrado.\n";
                } else {
                    if (desenfileirar(&senhasGeradas, &senha)) {
                        cout << "Guich� " << id << " est� atendendo a senha: " << senha << "\n";
                        enfileirar(&g->senhasAtendidas, senha);
                    }
                }
                break;
            }

            case 4: {
                int id;
                cout << "Informe o ID do guich�: ";
                cin >> id;
                Guiche* g = encontrarGuiche(&guiches, id);
                if (!g) {
                    cout << "Guich� n�o encontrado.\n";
                } else {
                    cout << "Senhas atendidas pelo guich� " << id << ": ";
                    if (estaVazia(&g->senhasAtendidas)) {
                        cout << "Nenhuma senha atendida ainda.\n";
                    } else {
                        int temp = g->senhasAtendidas.inicio;
                        for (int i = 0; i < g->senhasAtendidas.total; ++i) {
                            cout << g->senhasAtendidas.dados[temp] << " ";
                            temp = (temp + 1) % MAX;
                        }
                        cout << "\n";
                    }
                }
                break;
            }

            default:
                cout << "Op��o inv�lida. Tente novamente.\n";
        }
    } while (!(seletor == 0 && estaVazia(&senhasGeradas)));

    return 0;
}

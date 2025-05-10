#include <iostream>
#include <locale.h>
using namespace std;

struct Funcionario
{
	int prontuario;
	string nome;
	double salario;
};


struct Lista
{
	int Prontuario_dado;
	string nome_dado;
	double salario_dado;
	Lista *ant;
	int dado;
};

Lista* init()
{
	return NULL;
}

bool isEmpty(Lista* lista)
{
	return (lista == NULL);
}

Lista* insert(Lista* lista, int i,string n, double s)


{
	Lista* novo = new Lista();
	novo->Prontuario_dado = i;
	novo->nome_dado = n;
	novo->salario_dado = s;
	novo->ant = lista;
	
	return novo;
	
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	double TotalSalario = 0;
	cout << "---------------------------------------------------" << endl;
	while (aux != NULL)
	{
		cout << "Prontuario: " << aux->Prontuario_dado << endl;
		cout << "Nome: " << aux->nome_dado << endl;
		cout << "Salariio: R$" << aux->salario_dado << endl;
		cout << "---------------------------------------------------" << endl;
		TotalSalario = TotalSalario + aux->salario_dado;
		aux = aux->ant;
	}
	
	cout << "Total de salario: R$" << TotalSalario << endl;
	
}

void find(Lista* lista, int i)
{
    Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado != i)
	{
		if(aux->Prontuario_dado == i){
			
            cout << "Funcionario encontrado:" << endl;
            cout << "---------------------------------------------------" << endl;
            cout << "Nome: " <<aux->nome_dado << endl;
			cout << "Salario: R$" << aux->salario_dado << endl;
            cout << "---------------------------------------------------" << endl;
            return;
		}
		aux = aux->ant;
	}
	cout << "Funcionario com prontuario " << i << " nao encontrado." << endl;	
}

Lista* remove(Lista* lista, int i)
{
    Lista* aux = lista;
    Lista* apoio = NULL;

    while (aux != NULL && aux->Prontuario_dado != i)
    {
        apoio = aux;
        aux = aux->ant;
    }

    if (aux == NULL)
    {
        cout << "Funcionario com prontuario " << i << " nao encontrado para exclusao." << endl;
        return lista;
    }

    if (apoio == NULL)
    {
        // Elemento a ser removido está no início da lista
        lista = aux->ant;
    }
    else
    {
        apoio->ant = aux->ant;
    }

    delete aux;
    cout << "Funcionario com prontuario " << i << " excluido com sucesso." << endl;
    return lista;
}

bool verificarProntuario(Lista* lista, int pront){
	Lista* atual = lista;
	
	while(atual != NULL)
	{
		if(atual->Prontuario_dado == pront){
			return true;
		}
		atual = atual->ant;
	}
	return false;
}


int main(int argc, char** argv)
{
	setlocale(LC_ALL,"Portuguese");
	
	Lista *Funcionario;
	Funcionario = init();
	int menu;
	
	
 do {
 	   	cout << "---------------------------------------------------";
        cout << "\nMenu de Opções:\n";
        cout << "0. Sair\n";
        cout << "1. Incluir\n";
        cout << "2. Excluir\n";
        cout << "3. Pesquisar\n";
        cout << "4. Listar\n";
        cout << "Escolha uma opção: ";        
        cin >> menu;
        
        

        switch (menu) {
            case 1: {
                int pront;
                string nome;
                double salario;

                cout << "Prontuario: ";
                cin >> pront;
                
                if(verificarProntuario(Funcionario,pront)){
					cout << "Erro: prontuario ja cadastrado." << endl;
					break;
				}
                
                cin.ignore(); 
                cout << "Nome: ";
                getline(cin, nome);
                cout << "Salario: ";
                cin >> salario;
                
                Funcionario = insert(Funcionario, pront, nome, salario);
                break;
            }
            case 2: {
                int pront;
                cout << "Informe o prontuario para excluir: ";
                cin >> pront;
                Funcionario = remove(Funcionario, pront);
                break;
            }
            case 3: {
                int pront;
                cout << "Informe o prontuario para pesquisar: ";
                cin >> pront;
                
                find(Funcionario,pront);
                
                
                break;
            }
            case 4:
            	if(isEmpty(Funcionario)){
					cout << "A Lista se encontra vazia!" << endl;
				}
				else
				{
					print(Funcionario);
				}
                
                break;
            case 0:
                cout << "Saindo..." << endl;
                break;
            default:
                cout << "Opção inválida.";
        }
    } while (menu != 0);
	
    
	return 0;
}
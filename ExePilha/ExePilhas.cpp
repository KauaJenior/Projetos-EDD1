#include <iostream> 
#include <limits>   
#include <string>   
#include <vector>   


const int TOTAL_NUMEROS_A_LER = 30;


class IPilha {
public:
    
    virtual ~IPilha() {} 
    
    
    virtual void empilhar(int valor) = 0;
    
    
    virtual int desempilhar() = 0;
    
    virtual bool estaVazia() const = 0;
    
    
    virtual int verTopo() const = 0; 
};


struct No {
    int dado;   
    No* proximo; 

    // Construtor do Nó.
    No(int val) : dado(val), proximo(nullptr) {}
};

class PilhaListaEncadeada : public IPilha {
private:
    No* topoPilha; 

public:
    
    PilhaListaEncadeada() : topoPilha(nullptr) {}

    
    ~PilhaListaEncadeada() {
        while (!estaVazia()) {
            desempilhar(); 
        }
    }

    
    void empilhar(int valor) override {
        No* novoNo = new No(valor);
        novoNo->proximo = topoPilha;
        topoPilha = novoNo;
    }

    
    int desempilhar() override {
        if (estaVazia()) {
            std::cerr << "ALERTA: Tentativa de desempilhar de uma PilhaListaEncadeada vazia!" << std::endl;
           
            return -1; 
        }
        No* noTemporario = topoPilha;
        int valorDesempilhado = noTemporario->dado;
        topoPilha = topoPilha->proximo;
        delete noTemporario; 
        return valorDesempilhado;
    }

    
    bool estaVazia() const override {
        return topoPilha == nullptr;
    }

    
    int verTopo() const override {
        if (estaVazia()) {
            std::cerr << "ALERTA: Tentativa de ver o topo de uma PilhaListaEncadeada vazia!" << std::endl;
            return -1; 
        }
        return topoPilha->dado;
    }
};


const int TAMANHO_MAXIMO_VETOR = TOTAL_NUMEROS_A_LER; 

class PilhaVetor : public IPilha {
private:
    int elementos[TAMANHO_MAXIMO_VETOR]; 
    int indiceTopo;                       

public:
    
    PilhaVetor() : indiceTopo(-1) {}

    ~PilhaVetor() {}

    
    void empilhar(int valor) override {
        if (indiceTopo >= TAMANHO_MAXIMO_VETOR - 1) {
            std::cerr << "ERRO: Estouro da PilhaVetor! Capacidade maxima de " << TAMANHO_MAXIMO_VETOR << " atingida." << std::endl;
           
            return; 
        }
        elementos[++indiceTopo] = valor;
    }

    
    int desempilhar() override {
        if (estaVazia()) {
            std::cerr << "ALERTA: Tentativa de desempilhar de uma PilhaVetor vazia!" << std::endl;
            return -1; 
        }
        return elementos[indiceTopo--];
    }

    bool estaVazia() const override {
        return indiceTopo == -1;
    }

    
    int verTopo() const override {
        if (estaVazia()) {
            std::cerr << "ALERTA: Tentativa de ver o topo de uma PilhaVetor vazia!" << std::endl;
            return -1;
        }
        return elementos[indiceTopo];
    }
};


void executarLogicaDoPrograma(IPilha& pilhaPares, IPilha& pilhaImpares, const std::string& tipoPilhaStr) {
    
    long long ultimoNumeroDigitado = std::numeric_limits<long long>::min(); 
    int numeroAtual;

    std::cout << "\n--- Usando Pilhas do tipo: " << tipoPilhaStr << " ---" << std::endl;
    std::cout << "Digite " << TOTAL_NUMEROS_A_LER << " numeros inteiros. Cada numero deve ser MAIOR que o anterior." << std::endl;

    for (int i = 0; i < TOTAL_NUMEROS_A_LER; ++i) {
        bool entradaCorreta = false;
        while (!entradaCorreta) {
            std::cout << "Digite o " << (i + 1) << "º numero: ";
            if (!(std::cin >> numeroAtual)) {
                std::cout << "Entrada invalida. Por favor, digite um numero inteiro." << std::endl;
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                continue; 
            }

            if (i > 0 && static_cast<long long>(numeroAtual) <= ultimoNumeroDigitado) {
                std::cout << "Erro: O numero " << numeroAtual 
                          << " nao e maior que o numero anterior (" << ultimoNumeroDigitado 
                          << "). Tente novamente." << std::endl;
            } else {
                entradaCorreta = true; 
            }
        }

        if (numeroAtual % 2 == 0) {
            pilhaPares.empilhar(numeroAtual);
        } else {
            pilhaImpares.empilhar(numeroAtual);
        }
        ultimoNumeroDigitado = numeroAtual; 
    }

    std::cout << "\n--- Desempilhando e Mostrando os Numeros (" << tipoPilhaStr << ") ---" << std::endl;

    std::cout << "\nNumeros Pares (ordem decrescente):" << std::endl;
    if (pilhaPares.estaVazia()) {
        std::cout << "(Nenhum numero par foi digitado)";
    } else {
        while (!pilhaPares.estaVazia()) {
            std::cout << pilhaPares.desempilhar() << " ";
        }
    }
    std::cout << std::endl;

    std::cout << "\nNumeros Impares (ordem decrescente):" << std::endl;
    if (pilhaImpares.estaVazia()) {
        std::cout << "(Nenhum numero impar foi digitado)";
    } else {
        while (!pilhaImpares.estaVazia()) {
            std::cout << pilhaImpares.desempilhar() << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    

    std::cout << "==========================================================" << std::endl;
    std::cout << " Programa de Empilhamento de Numeros Pares e Impares" << std::endl;
    std::cout << "==========================================================" << std::endl;

    
    PilhaListaEncadeada pilhaParesLista;
    PilhaListaEncadeada pilhaImparesLista;
    executarLogicaDoPrograma(pilhaParesLista, pilhaImparesLista, "Lista Encadeada");

    std::cout << "\n==========================================================" << std::endl;

    
    PilhaVetor pilhaParesVetor;
    PilhaVetor pilhaImparesVetor;
    executarLogicaDoPrograma(pilhaParesVetor, pilhaImparesVetor, "Vetor (Array)");
    
    std::cout << "\n\nPrograma finalizado." << std::endl;
    std::cout << "==========================================================" << std::endl;

    return 0;
}
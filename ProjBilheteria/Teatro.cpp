#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

const int FILEIRAS = 15;
const int ASSENTOS = 40;

void MostrarMapa(char teatro[FILEIRAS][ASSENTOS])
{
	 std::cout << "\n   ";
    for (int i = 0; i < ASSENTOS; i++) {
         std::cout << std::setw(2) << i + 1 << " ";   // Números dos assentos
    }
    std::cout << "\n";
    
        for (int i = 0; i < FILEIRAS; i++) {
        std::cout << std::setw(2) << i + 1 << " ";   // Identificação da fileira
        for (int j = 0; j < ASSENTOS; j++) {
            std::cout << std::setw(2) << teatro[i][j] << " ";
        }
        std::cout << "\n";
		}
}

void ReservarAssento(char teatro[FILEIRAS][ASSENTOS]){
	int fileira, assento;
	
	std::cout<< "\nDigite a fileira (1 a " << FILEIRAS << "): ";
	std::cin >> fileira;
	std::cout<< "\nDigite o assento (1 a " << ASSENTOS << "): ";
	std::cin >> assento;
	
	if (fileira < 1 || fileira > FILEIRAS || assento < 1 || assento > ASSENTOS)
	{
      std::cout << "Assento inválido! Escolha Novamente.\n";
      return;
	}
	
	fileira--;
	assento--;
	
	if(teatro[fileira][assento] == '#'){
		std::cout <<"Esse assento já está ocupado!\n";
	}else{
		teatro[fileira][assento] = '#';
		std::cout <<"Assento reservado com sucesso!\n";
	}
}

 void Faturamento(char teatro[FILEIRAS][ASSENTOS])
 {
 	int fileira_frente = 0;
 	int fileira_meio = 0;
 	int fileira_fundo = 0;
 	double total = 0;
 	int total_assento;
 	for (int i = 0; i <= 4 ; i++){
		for (int j =0; j <= 39; j++){
			if (teatro[i][j] == '#'){
            fileira_frente++;
			}		
		}
	}
	
		for (int i = 5; i <= 9; i++){
		for (int j =0; j <= 39; j++){
			if (teatro[i][j] == '#'){
            fileira_meio++;
			}		
		}
	}
	
		for (int i = 10; i <= 14 ; i++){
		for (int j =0; j <= 39; j++){
			if (teatro[i][j] == '#'){
            fileira_fundo++;
			}		
		}
	}
	
 	total = (fileira_frente * 50.00) + (fileira_meio * 30.00) + (fileira_fundo * 15.00);
 	total_assento = fileira_frente + fileira_meio + fileira_fundo;
 	
 	
 	std::cout << "Qtde de lugares ocupados:  "	 << total_assento << "\n";
 	
 	std::cout << "Valor da bilheteria:  R$"<<total << "\n";
 }

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao;
	char teatro[FILEIRAS][ASSENTOS];
	
	for (int i = 0; i < FILEIRAS; i++){
		for (int j =0; j < ASSENTOS; j++){
			teatro[i][j] = '.';
		}
	}
	
	
	
	do{
    cout << "------------------------------\n";
	cout << " 0.   Finalizar               \n";
    cout << " 1.   Reservar Poltrona       \n";
	cout << " 2.   Mapa de ocupação        \n";	
	cout << " 3.   Faturamento             \n";
	cout << "------------------------------\n";
	
	cout << "Selecione a opção: ";
	std::cin >> opcao;
	
	 if (std::cin.fail()) {  
            std::cin.clear();  
            std::cin.ignore(1000, '\n');  
            opcao = -1;  
        }
        
        switch (opcao){
		case 0:
			std::cout << "Finalizando...\n";
			break;
		case 1:
			ReservarAssento(teatro);
			break;
		case 2:
			MostrarMapa(teatro);
			break;
		case 3:
			Faturamento(teatro);
			break;
	}
    
    } while (opcao != 0);
    
    
    
	return 0;
 }

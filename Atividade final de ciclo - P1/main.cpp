#include <iostream>
#include <locale.h>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int dia, int mes, int ano) {
        this->dia = dia;
        this->mes = mes;
        this->ano = ano;
    }

    Data() {
        this->dia = 0;
        this->mes = 0;
        this->ano = 0;
    }

    void setDia(int dia) {
        this->dia = dia;
    }

    void setMes(int mes) {
        this->mes = mes;
    }

    void setAno(int ano) {
        this->ano = ano;
    }

    int getDia() const {
        return this->dia;
    }

    int getMes() const {
        return this->mes;
    }

    int getAno() const {
        return this->ano;
    }

    string getData() const {
        string sdia = to_string(this->dia);
        string smes = to_string(this->mes);
        string sano = to_string(this->ano);

        return sdia.insert(0, 2 - sdia.size(), '0') + "/" +
               smes.insert(0, 2 - smes.size(), '0') + "/" +
               sano.insert(0, 4 - sano.size(), '0');
    }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato() {} // Construtor padrão

    Contato(string email, string nome, string telefone, Data dtnasc) {
        this->email = email;
        this->nome = nome;
        this->telefone = telefone;
        this->dtnasc = dtnasc;
    }

    void setEmail(string email) {
        this->email = email;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    void setTelefone(string telefone) {
        this->telefone = telefone;
    }

    void setDataNascimento(Data dtnasc) {
        this->dtnasc = dtnasc;
    }

    string getEmail() const {
        return email;
    }

    string getNome() const {
        return nome;
    }

    string getTelefone() const {
        return telefone;
    }

    Data getDataNascimento() const {
        return dtnasc;
    }

    int idade() const {
        time_t t = time(0);
        tm* now = localtime(&t);

        int anoAtual = now->tm_year + 1900;
        int mesAtual = now->tm_mon + 1;
        int diaAtual = now->tm_mday;

        int idade = anoAtual - dtnasc.getAno();

        if (mesAtual < dtnasc.getMes() || (mesAtual == dtnasc.getMes() && diaAtual < dtnasc.getDia())) {
            idade--;
        }
 
        return idade;
    }
 
  
    
	    string bio() {
	    vector<string> partes;
	    string palavra;
	    istringstream iss(nome); // Converter nome em um fluxo de entrada
	
	    while (iss >> palavra) {
	        partes.push_back(palavra);
	    }
	
	    if (partes.empty()) return "";
	
	    stringstream bioStream;
	
	    string sobrenome = partes.back();
	    for (char &c : sobrenome) c = toupper(c); // Uppercase sobrenome
	    bioStream << sobrenome << ", ";
	
	    bioStream << partes[0] << " "; // Primeiro nome
	
	    for (size_t i = 1; i < partes.size() - 1; ++i) {
	        bioStream << static_cast<char>(toupper(partes[i][0])) << ". ";
	    }
	
	    return bioStream.str();
	}


	};
	double mediaIdades(int somaIdades){
		double media = somaIdades / 10; 

		
           return media;

		
	}
int main() {
    setlocale(LC_ALL, "Portuguese");

    Contato contatos[10];

    for (int i = 0; i < 10; i++) {
        string nome, email, telefone;
        int dia, mes, ano;

        cout << "Cadastro do " << i + 1 << "º contato:" << endl;
        cout << "Nome: ";
        getline(cin, nome);
        cout << "Email: ";
        getline(cin, email);
        cout << "Telefone: ";
        getline(cin, telefone);
        cout << "Data de nascimento (dia mes ano): ";
        cin >> dia >> mes >> ano;
        cin.ignore(); 
        
        Data nascimento(dia, mes, ano);
        contatos[i] = Contato(email, nome, telefone, nascimento);

        cout << endl;
    }
       int somaIdades = 0, maiorIdade = 0;
    cout << "\n===== Lista de Contatos =====\n";

    for (int i = 0; i < 10; i++) {
    	
        cout << "Nome: " << contatos[i].bio() << endl;
        cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;
        cout << "Idade: " << contatos[i].idade() << " anos" << endl;
        cout << "---------------------------\n";
        
         somaIdades += contatos[i].idade();
         if(contatos[i].idade() >= maiorIdade) {
			 
			 maiorIdade = contatos[i].idade();
		 } 
    }
    cout << "\n===== Lista de Nomes maiores que média =====\n";
    for(int i = 0; i < 10; ++i) {
    if (contatos[i].idade() > mediaIdades(somaIdades)){
		  
		  cout << "Nome: " << contatos[i].bio() << endl;
	  }
    }
    cout << "Media das idades: " << mediaIdades(somaIdades) << endl;
    
     int maiores = 0;
     for(int i = 0; i < 10; ++i) {
    if (contatos[i].idade() >= 18){
		  maiores++;
		  
	  }
    }
    cout << "Contatos com maiores de idades: " << maiores << endl;

	
	cout << "\n===== Contato Mais Velho =====\n";
    for(int i = 0; i < 10; ++i) {
    if (contatos[i].idade() >= maiorIdade){
		  
		  cout << "Nome: " << contatos[i].bio() << endl;
		    cout << "Email: " << contatos[i].getEmail() << endl;
        cout << "Telefone: " << contatos[i].getTelefone() << endl;  
	  }
    }
    return 0;
}
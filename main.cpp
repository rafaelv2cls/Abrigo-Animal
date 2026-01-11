/*
Abrigo Animal

Alunos: Rafael de Vasconcelos Costa, Pedro Henrique Rodrigues Moy
*/

#include <iostream>
#include <string>
#include <fstream>
#ifdef _WIN32
    #include <windows.h>
#endif
using namespace std;

typedef struct Animal {
    int id;
    string nome;
    string especie;
    int idade;
    float peso;
    string descricao;
	string vacinas;
} animal;

void busca();
void buscaId();
void buscaNome();
void buscaEspecie();
void buscaVacina();
void listagem();
void cadastro();
void edicao();
void remocao();
void gravacao();


int main(){
	#ifdef _WIN32
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);
    #endif
	ifstream arq("animais.csv");
	int i = 0, capacidade = 40;
	string aux;
	animal* bancoDeDados = new animal[capacidade];
	
	while (getline(arq, aux, ';')){

		if (i == capacidade){
			animal* bancoAux = new animal[capacidade + 5];
			for (int j = 0; j < capacidade; j++){
				bancoAux[j] = bancoDeDados[j];
			}
			delete[] bancoDeDados;
			bancoDeDados = bancoAux;
			capacidade += 5;
		}

		bancoDeDados[i].id = stoi(aux);
		getline(arq, bancoDeDados[i].nome, ';');
		getline(arq, bancoDeDados[i].especie, ';');
		getline(arq, aux, ';');
		bancoDeDados[i].idade = stoi(aux);
		getline(arq, aux, ';');
		bancoDeDados[i].peso = stof(aux);
		getline(arq, bancoDeDados[i].descricao);
		
		i++;
	}

	int x = 0;

	do {
		cout << "=============================================" << endl;
		cout << "O que você deseja fazer?" << endl;
		cout << "=============================================" << endl;
		cout << "1. Listar Animais" << endl;
		cout << "2. Buscar Animais" << endl;
		cout << "3. Cadastrar Animal" << endl;
		cout << "4. Remover Animal" << endl;
		cout << "5. Editar Animal" << endl;
		if(true) cout << "6. Gravar Alterações" << endl;
		cout << "0. Encerrar Programa" << endl;
		cout << "=============================================" << endl;

		cin >> x;
		switch (x) {
			case 1:
				listagem();
				break;
			case 2:
				busca();
				break;
			case 3:
				cadastro();
				break;
			case 4:
				remocao();
				break;
			case 5:
				edicao();
				break;
			case 6:
				gravacao();
				break;
			case 0:
				break;
			default:
				cout << endl << "Entrada inválida, tente novamente." << endl << endl;
		}
	} while (x != 0);

	return 0;
}

void busca(){
	cout << "=============================================" << endl;
	cout << "1. Busca por ID" << endl;
	cout << "2. Busca por nome" << endl;
	cout << "3. Busca por espécie" << endl;
	cout << "4. Busca por vacina" << endl;
	cout << "0. Cancelar" << endl;
	cout << "=============================================" << endl;
	int busca = 0;
	switch (busca) {
		case 1:
			buscaId();
			break;
		case 2:
			buscaNome();
			break;
		case 3:
			buscaEspecie();
			break;
		case 4:
			buscaVacina();
			break;
		case 0:
			break;
		default:
	}
}
void buscaId(){
}
void buscaNome(){
}
void buscaEspecie(){
}
void buscaVacina(){
}
void listagem(){
}
void cadastro(){
}
void edicao(){
}
void remocao(){
}
void gravacao(){
}

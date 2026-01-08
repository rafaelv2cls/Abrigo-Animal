/*
Abrigo Animal

Alunos: Rafael de Vasconcelos Costa, Pedro Henrique Rodrigues Moy
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct Animal {
    int id;
    string nome;
    string especie;
    int idade;
    float peso;
    string descricao;
} animal;

void buscaId();
void buscaNome();
void buscaEspecie();
void listagem();
void cadastro();
void edicao();
void remocao();
void gravacao();


int main(){
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

	return 0;
}

void buscaId(){
}
void buscaNome(){
}
void buscaEspecie(){
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

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
	char sexo;
    int idade; // em meses
    float peso;
    string descricao;
	string vacinas;
} animal;

void printAnimal(animal* &bancoDeDados, int n);
void busca(animal* &bancoDeDados, int qnt);
void buscaId(animal* &bancoDeDados);
void buscaNome(animal* &bancoDeDados, int qnt);
void listagem(animal* &bancoDeDados, int qnt);
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
		bancoDeDados[i].sexo = aux[0];
		getline(arq, aux, ';');
		bancoDeDados[i].idade = stoi(aux);
		getline(arq, aux, ';');
		bancoDeDados[i].peso = stof(aux);
		getline(arq, bancoDeDados[i].descricao, ';');
		getline(arq, bancoDeDados[i].vacinas);
		
		i++;
	}

	int x = 0;

	do {
		cout << endl << "=============================================" << endl;
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
				listagem(bancoDeDados, i);
				break;
			case 2:
				busca(bancoDeDados, i);
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
				cout << endl << "Entrada inválida, tente novamente." << endl;
				break;
		}
	} while (x != 0);

	return 0;
}

void printAnimal(animal* &bancoDeDados, int n){
	cout << bancoDeDados[n].id << ". "<< bancoDeDados[n].nome << endl;
	cout << bancoDeDados[n].especie << ", ";
	(bancoDeDados[n].sexo == 'M') ? cout << "Macho" << endl : cout << "Fêmea" << endl;
	// lógica para impressão da idade do animal
	if (bancoDeDados[n].idade <= 12) {
		cout << bancoDeDados[n].idade << " meses" << endl;
	} else {
		cout << bancoDeDados[n].idade/12 << " ano";
		if (bancoDeDados[n].idade >= 24) cout << "s";
		if (bancoDeDados[n].idade%12 != 0) cout << " e " << bancoDeDados[n].idade%12 << " mes";
		if (bancoDeDados[n].idade%12 > 1) {
			cout << "es" << endl;
		} else cout << endl;
	}
	
	cout << bancoDeDados[n].peso << " Kg" << endl;
	cout << bancoDeDados[n].descricao << endl;
	cout << "Vacinas: " << bancoDeDados[n].vacinas << endl;
}

void busca(animal* &bancoDeDados, int qnt){
	cout << endl << "=============================================" << endl;
	cout << "1. Busca por ID" << endl;
	cout << "2. Busca por nome" << endl;
	cout << "0. Cancelar" << endl;
	cout << "=============================================" << endl;
	int n;
	cin >> n;
	switch (n) {
		case 1:
			buscaId(bancoDeDados);
			break;
		case 2:
			buscaNome(bancoDeDados, qnt);
			break;
		case 0:
			break;
		default:
			cout << endl << "Entrada inválida, tente novamente." << endl << endl;
			busca(bancoDeDados, qnt);
			break;
	}
}

void buscaId(animal* &bancoDeDados){
	int n;
	cout << endl << "Insira o id:" << endl;
	cin >> n;

	cout << endl << "=============================================" << endl;
	printAnimal(bancoDeDados, n - 1);
	cout << "=============================================" << endl;
}

void buscaNome(animal* &bancoDeDados, int qnt){
	
}

void listagem(animal* &bancoDeDados, int qnt){
	cout << endl << "=============================================" << endl;
	for(int n = 0; n < qnt;n++){
		cout << "_____________________________________________" << endl;
		printAnimal(bancoDeDados, n);
		cout << "_____________________________________________" << endl;
	}
	cout << "=============================================" << endl;
}

void cadastro(){
}

void edicao(){
}

void remocao(){
}

void gravacao(){
}

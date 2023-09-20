/*
 * main.cpp
 *
 *  Created on: 14 de set de 2023
 *      Author: user
 */

#include "gerenciador.hpp"
#include "carro.hpp"
#include "ordenacao.hpp"
#include "arvoreComClasse.hpp"

template<typename T>

void imprime(vector<T> linha, int max = 0) {
	max = (max == 0 ? linha.size() : max);
	for (int i = 0; i < max; ++i) {
		cout << linha[i].toString() << endl;
	}
}

int main(int argc, char **argv) {

	// Questão 1
	vector<string> lista1 = GerenciadoDeArquivo::carregaAquivo("lista1.csv");
	vector<string> lista2 = GerenciadoDeArquivo::carregaAquivo("lista2.csv");

	vector<Carro> carro1;
	vector<Carro> carro2;

	for (int i = 0; i < lista1.size(); i++) {

		Carro novo(lista1[i]);
		carro1.push_back(novo);

	}
	for (int i = 0; i < lista2.size(); i++) {

		Carro novo(lista2[i]);
		carro2.push_back(novo);

	}

	cout << "---------Dados desordenados.---------" << endl;

	cout << "\n\n---------Lista 1.---------" << endl;
	imprime<Carro>(carro1);
	cout << "\n\n---------Lista 2.---------" << endl;
	imprime<Carro>(carro2);

	// Questão 2 e 3
	quicksort<Carro>(carro2);
	insertionSort<Carro>(carro1);

	cout << "\n\n---------Dados ordenados.---------" << endl;

	cout << "\n\n---------Lista 1.---------" << endl;
	imprime<Carro>(carro1);
	cout << "\n\n---------Lista 2.---------" << endl;
	imprime<Carro>(carro2);

	// Questão 4

	cout << "\n\n---------Arvore1---------" << endl;
	mainTeste(carro1);
	cout << "\n\n---------Arvore2---------" << endl;
	mainTeste(carro2);

	return 0;
}


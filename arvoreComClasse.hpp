#ifndef CLASS_ARVORE_HPP_
#define CLASS_ARVORE_HPP_

//============================================================================
// Name        : LP1-ArvoresEncadeadas.cpp
// Author      : Alisson RS
// Version     :
// Description : Versão da arvore descrita por apontadores .
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>
#include "carro.hpp"

using namespace std;

// Classe para armazenar o dado.
class TipoItem {
public:
	Carro valor; //Troque pelo tipo de dado ou classe usada.
			   // O ideal é que a classe tenha <>== e toString.

	//Construtores para auxiliar o uso.
	TipoItem():valor(){}
	TipoItem(Carro novoValor):valor(novoValor){}
	//Sobrecarga dos operadores de comparação.

	bool operator>(const TipoItem &outro) {
		return valor > outro.valor;
	}
	bool operator<(const TipoItem &outro) {
		return valor < outro.valor;
	}
	bool operator==(const TipoItem &outro) {
		return valor == outro.valor;
	}
	string toString() {

		return valor.toString();
		//ou apague tudo e retorne o toString da
		//classe como em:
		//return aluno.toString();
	}
};

// definindo o nó da arvore
class No {
public:
	TipoItem info;
	No *esq;
	No *dir;
};

// definindo a estrutura da arvore
class Arvore {
public:
	No *raiz;

	// Criação da árvore
	//Arv* abb_cria(void)
	Arvore() {
		raiz = NULL;
	}

	// Inserção de um nó
	void insere(TipoItem v) {
		raiz = abb_insere(raiz, v);
	}

	void imprime() {
		abb_imprime(raiz);
	}

private:
	No* abb_insere(No *a, TipoItem v) {
		if (a == NULL) {
			a = new No;
			a->info = v;
			a->esq = a->dir = NULL;
		} else if (v < a->info)
			a->esq = abb_insere(a->esq, v);
		else
			/* v > a->info */
			a->dir = abb_insere(a->dir, v);
		return a;
	}

// impressão dos dados da árvore

	void abb_imprime(No *a) {
		if (a != NULL) {
			abb_imprime(a->esq);
			printf("%s\n", a->info.toString().c_str());
			abb_imprime(a->dir);
		}
	}

};
int mainTeste(vector<Carro> carro) {
	Arvore arvore;
	for(int i = 0; i < carro.size(); i++){
	arvore.insere(TipoItem (carro[i]));
	}
	arvore.imprime();
	return 0;
}

#endif /* CLASS_ARVORE_HPP_ */

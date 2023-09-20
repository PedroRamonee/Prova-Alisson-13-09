/*
 * carro.hpp
 *
 *  Created on: 14 de set de 2023
 *      Author: user
 */

#ifndef SRC_CARRO_HPP_
#define SRC_CARRO_HPP_

#include "gerenciador.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

class Carro {

public:

	string id;
	string montadora;
	int cilindradas;

	string toString() {
		stringstream ss;
		ss << id << "," << montadora << "," << cilindradas;
		return ss.str();
	}
	Carro(){
		this->id = "";
		this->montadora = "";
		this->cilindradas = NULL;
	}

	Carro(string line) {
		string dado;
		stringstream ss(line); 	//stringstream => 	<sstream>

		getline(ss, dado, ',');
		this->id = (dado);

		getline(ss, dado, ',');

		this->montadora = (dado);

		getline(ss, dado, ',');
		this->cilindradas = atoi(dado.c_str());

		getline(ss, dado, ',');
	}

	bool operator>(const Carro &outroCarro) {
		return montadora > outroCarro.montadora;
	}
	bool operator<(const Carro &outroCarro) {
		return montadora < outroCarro.montadora;
	}
	bool operator==(const Carro &outroCarro) {
		return montadora == outroCarro.montadora;
	}
};

#endif /* SRC_CARRO_HPP_ */

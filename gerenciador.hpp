/*
 * gerenciador.hpp
 *
 *  Created on: 14 de set de 2023
 *      Author: user
 */

#ifndef SRC_GERENCIADOR_HPP_
#define SRC_GERENCIADOR_HPP_

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::stringstream;
using namespace std;

class GerenciadoDeArquivo {

public:
	static vector<string> carregaAquivo(string caminho) {

		string line;
		vector<string> linhas;

		ifstream arquivo(caminho.c_str());

		if (arquivo.is_open()) {
			//Busca dados no arquivo.
			getline(arquivo, line); //descarta rotulo

			while (getline(arquivo, line)) {
				linhas.push_back(line);
			}

		} else {
			std::cerr << "O arquivo não pôde ser aberto." << std::endl;
		}
		return linhas;
	}

	static bool escreveLinhaNoAquivo(string caminho, string line,
			bool adicionar) {
		ofstream arquivo;

		if (adicionar == true) {
			arquivo.open(caminho.c_str(), std::ios::app);
		} else if (adicionar == false) {
			arquivo.open(caminho.c_str());
		}

		if (!arquivo.is_open()) {
			std::cerr << "Não foi possível abrir o arquivo." << std::endl;
			return false;
		}

		arquivo << line << std::endl;

		arquivo.close();
		return true;
	}

	static bool escreveVetorNoAquivo(string caminho, vector<string> linhas,
			bool adicionar) {
		std::ofstream arquivo;

		if (adicionar == true) {
			arquivo.open(caminho.c_str(), std::ios::app);
		} else if (adicionar == false) {
			arquivo.open(caminho.c_str());
		}

		if (!arquivo.is_open()) {
			std::cerr << "Não foi possível abrir o arquivo." << std::endl;
			return false;
		}

		for (int i = 0; i < linhas.size(); i++) {
			arquivo << linhas[i] << std::endl;
		}

		arquivo.close();
		return true;
	}

};

#endif /* SRC_GERENCIADOR_HPP_ */

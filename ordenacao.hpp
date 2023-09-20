/*
 * ordenacao.hpp
 *
 *  Created on: 14 de set de 2023
 *      Author: user
 */

#ifndef SRC_ORDENACAO_HPP_
#define SRC_ORDENACAO_HPP_

#include "gerenciador.hpp"

template<typename T>
void quicksort(std::vector<T> &v) {
	quicksort<T>(v, 0, v.size() - 1);
}

//Chamada interna e chamadas recursivas.
template<typename T>
void quicksort(std::vector<T> &X, int IniVet, int FimVet) {
	int i, j;
	T aux, pivo;

	if (IniVet < FimVet) {
		pivo = X[(IniVet + FimVet) / 2];
		i = IniVet;
		j = FimVet;

		while (i <= j) {
			while (X[i] < pivo) {
				i++;
			}
			while (X[j] > pivo) {
				j--;
			}
			if (i <= j) {
				aux = X[i];
				X[i] = X[j];
				X[j] = aux;
				i++;
				j--;
			}
		}

		quicksort<T>(X, IniVet, j);
		quicksort<T>(X, i, FimVet);
	}
}
template<typename T>
void insertionSort(std::vector<T> &v) {

	for (int i = v.size() - 2; i >= 0; i--) {
		v[v.size() - 1] = v[i];

		int j = i + 1;

		while (v[v.size() - 1] > v[j]) {
			v[j - 1] = v[j];
			j++;
		}
		v[j - 1] = v[v.size() - 1];
	}

}
#endif /* SRC_ORDENACAO_HPP_ */

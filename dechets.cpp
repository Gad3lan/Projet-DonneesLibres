#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Calcule et affiche l'arrondissement ayant le plus de déchets sur l'année
 * ainsi que son tonnage annuel **/
int main() {
	ifstream donnees("donnees/tonnages_des_dechets_bacs_jaunes.txt");
	int arr, arr_max, arr_dechets_max, dechets, total_dechets_arr;
	string indice = "er ";

	for (int i = 0; i < 20; i++) {
		total_dechets_arr = 0;
		donnees >> arr;
		for (int j = 0; j < 12; j++) {
			donnees >> dechets;
			total_dechets_arr += dechets;
		}
		if (arr_dechets_max < total_dechets_arr) {
			arr_dechets_max = total_dechets_arr;
			arr_max = arr;
		}
	}
	if (arr_max - 75000 > 1) {
		indice = "eme ";
	}
	cout << "Le " << arr_max - 75000 << indice << "arrondissement est celui qui a produit le plus de dechets dans l'année avec un total de : " << arr_dechets_max << " tonnes" << endl;
	return 1;
}

#include <stdexcept>
/** @file **/
#include <fstream>
#include "tableau-donnees.h"

int moyenne(vector<int> t) {
	int total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total / t.size();
}

int somme(vector<int> t) {
	int total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total;
}

int sommePartielle(vector<int> t, int i) {
	int total = 0;

	for (int j = i; j < t.size(); j++) {
		total += t[j];
	}
	return total;
}


int indiceMax(vector<int> t) {
	int max = 0;
	int indice;

	if (t.size() <= 0) {
		return -1;
	}
	for (int i = 0; i < t.size(); i++) {
		if (max < t[i]) {
			max = t[i];
			indice = i;
		}
	}
	return indice;
}

vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {
	ifstream donnees(nom_fichier);
	vector<vector<int>> tab2D;
	vector<int> tab_ligne(nb_colonnes);

	for (int i = 0; !donnees.eof(); i++) {
		for (int j = 0; j < nb_colonnes ; j++) {
			donnees >> tab_ligne[j];
		}
		if (!donnees.eof()) {		//Obligatoire sinon repete la dernier ligne
			tab2D.push_back(tab_ligne);
		}
	}
	return tab2D;
}

vector<int> colonne(vector<vector<int>> t, int i) {
	vector<int> tab(t.size());

	for (int j = 0; j < t.size(); j++) {
		tab[j] = t[j][i];
	}
	return tab;
}

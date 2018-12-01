#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include "tableau-donnees-csv.h"

void afficheTableau(vector<vector<string>> tableau) {
	for (int i = 0; i < tableau.size(); i++) {
		for (int j = 0; j < tableau[i].size(); j++) {
			cout << tableau[i][j] << "\t";
		}
		cout << endl;
	}
}

vector<vector<string>> litTableauCSV(string nom_fichier, int nb_colonnes) {
	ifstream donnees(nom_fichier);
	string valeur;
	vector<vector<string>> tab2D;
	vector<string> tab_ligne(nb_colonnes);

	getline(donnees, valeur);
	while (!donnees.eof()) {
		for (int i = 0; i < nb_colonnes - 1; i++) {
			getline(donnees, valeur, ';');
			tab_ligne[i] = valeur;
		}
		getline(donnees, valeur);
		if ( valeur.size() > 0 and valeur[valeur.length()-1] == '\r' ) {
			valeur.resize(valeur.length() - 1);
		}
		tab_ligne[nb_colonnes - 1] = valeur;
		if (!donnees.eof()) {
			tab2D.push_back(tab_ligne);
		}
	}
	return tab2D;
}

vector<vector<string>> litTableauCSV(string nom_fichier) {
	ifstream donnees(nom_fichier);
	int j;
	string ligne, tmp;
	vector<vector<string>> tab2D;

	getline(donnees, ligne);
	while(getline(donnees, ligne)) {
		vector<string> tab_ligne;
		tmp.resize(0);
		j = 0;
		if ( ligne.size() > 0 and ligne[ligne.length()-1] == '\r' ) {
			ligne.resize(ligne.length() - 1);
		}
		for (int i = 0; ligne[i]; i++) {
			if (ligne[i] != ';' && ligne[i]) {
				tmp.push_back(ligne[i]);
				j++;
			} else {
				tab_ligne.push_back(tmp);
				tmp.resize(0);
				j = 0;
			}
		}
		tab_ligne.push_back(tmp);
		if (!donnees.eof()) {
			tab2D.push_back(tab_ligne);
		}
	}
	return tab2D;
}

vector<string> colonne(vector<vector<string>> t, int i) {
	vector<string> col;

	for (int j = 0; j < t.size(); j++) {
		if (t[j][i] != "") {
			col.push_back(t[j][i]);
		} else {
			col.push_back("0");
		}
	}
	return col;
}

vector<int> conversionInt(vector<string> t) {
	vector<int> tab_int;

	for (int i = 0; i < t.size(); i++) {
		tab_int.push_back(stoi(t[i]));
	}
	return tab_int;
}

vector<double> conversionDouble(vector<string> t) {
	vector<double> tab_double;

	for (int i = 0; i < t.size(); i++) {
		tab_double.push_back(stod(t[i]));
	}
	return tab_double;
}

template<class T>
vector<T> conversion(vector<string> t) {
	vector<T> tab(t.size());

	for (int i = 0; i < t.size(); i++) {
		istringstream conv(t[i]);
		conv >> tab[i];
	}
	return tab;
}

// Force l'instanciation des templates
template vector<int> conversion<int>(vector<string> t);
template vector<double> conversion<double>(vector<string> t);

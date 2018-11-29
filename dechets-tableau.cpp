#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl


/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
 * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
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

/** Test de la fonction litTableauInt **/
void testLitTableauInt() {
	vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);

	ASSERT(t[0][0] == 75007);
	ASSERT(t[3][5] == 876);
	ASSERT(t[19][12] == 235);
}


/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur d'entiers
 **/
vector<int> colonne(vector<vector<int>> t, int j) {
	vector<int> tab(t.size());

	for (int i = 0; i < t.size(); i++) {
		tab[i] = t[i][j];
	}
	return tab;
}

/** Test de la fonction colonne **/
void testColonne() {
	vector<vector<int>> t = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

	ASSERT( colonne(t,0) == vector<int>({1,4,7,10}));
	ASSERT( colonne(t,1) == vector<int>({2,5,8,11}));
	ASSERT( colonne(t,2) == vector<int>({3,6,9,12}));
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs
 **/
int somme(vector<int> t) {
	int total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total;
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 **/
int moyenne(vector<int> t) {
	int total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total / t.size();
}

/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
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

/** Lance les tests de litTableauInt et colonne
 * puis demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 **/
int main() {
	int mois;
	vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);
	vector<int> tab = colonne(t, mois);

	testLitTableauInt();
	testColonne();
	cout << "Entrez un numéro de mois (entre 1 et 12) : ";
	cin >> mois;
	cout << "La somme des déchets pour ce mois est de : " << somme(tab) << endl;
	cout << "La moyenne des déchets pour ce mois est de : " << moyenne(tab) << endl;
	cout << "L’arrondissement avec le plus de déchets pour ce mois est : " << t[indiceMax(tab)][0] << " avec " << t[indiceMax(tab)][mois] << " tonnes de déchets." << endl;
	return 1;
}

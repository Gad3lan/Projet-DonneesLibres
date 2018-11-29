#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Affiche
 * - le volume d'eau total sur l'année
 * - la moyenne par mois
 * - le mois avec le plus gros volume d'eau et son volume
 **/
int main() {
	vector<vector<int>> t = litTableau("donnees/volumes_d_eau_distribues.txt", 2);
	vector<int> valeurs = colonne(t, 1);
	string mois[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

	cout << "Le volume d´eau total sur l´année est de : " << somme(valeurs) << endl;
	cout << "La moyenne d´eau utilisée par mois est de : " << moyenne(valeurs) << endl;
	cout << "Le mois avec le plus gros volume d´eau est << mois[t[0][indiceMax(valeurs)] - 1] << " avec " << t[1][indiceMax(valeurs)] << " litres." << endl;
	return 1;
}

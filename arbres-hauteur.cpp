#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.h"
#include "tableau-donnees-csv.h"
using namespace std;

int main() {
	vector<vector<string>> t = litTableauCSV("donnees/arbresremarquablesparis2011.csv");

	int grand_arbre = indiceMax(conversionInt(colonne(t, 6)));
	int vieil_arbre = indiceMax(conversionInt(colonne(t, 5)));
	cout << "Le plus grand arbre de Paris est un " << t[grand_arbre][3] << " " << t[grand_arbre][2] << " avec une taille de " << t[grand_arbre][6] << "m." << endl;
	cout << "Le plus vieil arbre de Paris est un " << t[vieil_arbre][3] << " " << t[vieil_arbre][2] << " avec un age de " << 2018 - stoi(t[vieil_arbre][5]) << endl;
	return 0;
}

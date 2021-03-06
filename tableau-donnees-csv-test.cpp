#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees-csv.h"
using namespace std;

/** Infrastructure minimale de test modifiée pour visualiser les réussites**/
#define ASSERT(test, t) if (!(test)) cout << " Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl; else if (t == 1) cout << "\tOK!\n"; else if (t == 2) cout << "\t\tOK!\n"

vector<vector<string>> donnees = {
					{ "avr-11", "15688700" },
					{ "juil-11", "16049700" },
					{ "mars-11", "16260600" },
					{ "juin-11", "17028600" },
					{ "sept-11", "16858200" },
					{ "déc-11", "15530100" },
					{ "févr-11", "14019000" },
					{ "août-11", "13959600" },
					{ "janv-11", "16231200" },
					{ "oct-11", "16592900" },
					{ "nov-11", "15672000" },
					{ "mai-11", "17711200" },
};

vector<int> donnees_int = {15688700, 16049700, 16260600, 17028600, 16858200, 15530100, 14019000, 13959600, 16231200, 16592900, 15672000, 17711200};

vector<string> donnees_str = {"avr-11", "juil-11", "mars-11", "juin-11", "sept-11", "déc-11", "févr-11", "août-11", "janv-11", "oct-11", "nov-11", "mai-11"};

vector<double> donnees_dbl = {15688700, 16049700, 16260600, 17028600, 16858200, 15530100, 14019000, 13959600, 16231200, 16592900, 15672000.0, 17711200};

vector<vector<string>> petites_donnees = { { "a0", "b0"}, { "a1", "b1" } };

vector<string> t = colonne(litTableauCSV("donnees/volumes_d_eau_distribues.csv"), 1);

void litTableauCSVTest() {
	ASSERT( litTableauCSV("donnees/volumes_d_eau_distribues.csv", 2) == donnees, 0 );
	ASSERT( litTableauCSV("donnees/volumes_d_eau_distribues.csv") == donnees, 1 );
}

void colonneTest() {
	ASSERT( colonne(litTableauCSV("donnees/volumes_d_eau_distribues.csv"), 0) == donnees_str, 1 );
}

void conversionTest() {
	ASSERT( conversionInt(t) == donnees_int,    0 );
	ASSERT( conversionDouble(t) == donnees_dbl, 1 );
}

int main() {
	cout << "Lancement de l'affichage de litTableauCSV avec le nombre de colonnes : " << endl;
	afficheTableau(litTableauCSV("donnees/volumes_d_eau_distribues.csv", 2));
	cout << "Lancement de l'affichage de litTableauCSV sans le nombre de colonnes : " << endl;
	afficheTableau(litTableauCSV("donnees/volumes_d_eau_distribues.csv"));
	cout << "Lancement des tests de litTableauCSV:";
	litTableauCSVTest();
	cout << "Lancement des tests de colonneTest:";
	colonneTest();
	cout << "Lancement des tests de conversion:";
	conversionTest();
}

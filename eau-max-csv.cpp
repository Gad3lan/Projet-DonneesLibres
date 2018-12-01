#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	ifstream donnees("donnees/volumes_d_eau_distribues.csv");
	int vol_max = 0;
	int vol;
	string mois, entete, vol_str, vol_max_mois;
	string nom_mois[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

	getline(donnees, entete);
	while (getline(donnees, mois, ';') && getline(donnees, vol_str)) {
		if ( vol_str.size() > 0 and vol_str[vol_str.length()-1] == '\r' ) {
			vol_str.resize(vol_str.length() - 1);
		}
		vol = stoi(vol_str);
		if (vol > vol_max) {
			vol_max = vol;
			vol_max_mois = mois;
		}
	}
	cout << "Le mois où on a distribué le plus d'eau est " << vol_max_mois << " avec une volume de " << vol_max << "L" << endl;
	return 1;
}

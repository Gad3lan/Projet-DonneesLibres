#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/** Calcule et affiche le mois et le voume où le volume d'eau
* distribué à Paris en 2011 a été maximal **/
int main() {
	ifstream donnees("donnees/volumes_d_eau_distribues.txt");
	int vol, mois, vol_max_mois;
	int vol_max = 0;
	string nom_mois[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
	
	while (donnees >> mois && donnees >> vol)
		if (vol > vol_max) {
			vol_max = vol;
			vol_max_mois = mois;
		}
	cout << "Le moois où on a distribué le plus d'eau est " << nom_mois[vol_max_mois - 1] << " avec un volume de  " << vol_max << "L" << endl;
	return 1;
}

#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	ifstream donnees("donnees/volumes_d_eau_distribues.csv");
	int vol_moyen;
	int vol_total = 0;
	string entete, mois, volume_str;

	getline(donnees, entete);
	while (getline(donnees, mois, ';') && getline(donnees, volume_str)) {
		if ( volume_str.size() > 0 and volume_str[volume_str.length()-1] == '\r' ) {
			volume_str.resize(volume_str.length() - 1);
		}
		vol_total += stoi(volume_str);
	}
	vol_moyen = vol_total  / 12;
	cout << "Le volume moyen par mois d'eau distribué dans l'année est de : " << vol_moyen << endl;
	return 1;
}

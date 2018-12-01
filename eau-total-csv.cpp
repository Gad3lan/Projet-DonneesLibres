#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
	ifstream donnees("donnees/volumes_d_eau_distribues.csv");
	int vol_total = 0;
	string entete;
	string mois, vol_str;

	getline(donnees, entete);
	while(getline(donnees, mois, ';') && getline(donnees, vol_str)) {
		vol_total += stoi(vol_str);
	}
	cout << "Le volume total d'eau distribué dans l'année est de : " << vol_total << "L" << endl;
	return 1;
}

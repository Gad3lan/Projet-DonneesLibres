#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;

/** Calcule et affiche le volume d'eau moyen distribué par mois à Paris en 2011 **/
int main() {
	ifstream data("donnees/volumes_d_eau_distribues.txt");
	int vol_total, vol_moyen = 0;
	int vol, mois;

	while(data >> mois && data >> vol) {
		vol_total += vol;
	}
	vol_moyen = vol_total/ 12;
	cout << "Le volume moyen d'eau distribué par mois de cette année est de : " << vol_moyen << "L" << endl;
	return 1;
}

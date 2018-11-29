#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

/** Calcule et affiche le mois et le voume où le volume d'eau
* distribué à Paris en 2011 a été maximal **/
int main() {
	ifstream data("donnees/volumes_d_eau_distribues.txt");
	int volume, month, max_volume_month;
	int max_volume = 0;
	string month_names[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
	
	while (data >> month && data >> volume)
		if (volume > max_volume) {
			max_volume = volume;
			max_volume_month = month;
		}
	cout << "Le volume maximum d'eau distribué a été atteint en " << month_names[month - 1] << " et était de : " << max_volume << "L" << endl;
	return 1;
}

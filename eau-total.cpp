#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;

/** Calcule et affiche le volume d'eau total distribué à Paris en 2011 **/
int main() {
	ifstream data("donnees/volumes_d_eau_distribues.txt");
	int total_volume = 0;
	int volume, month;
	
	while(data >> month && data >> volume) {
		total_volume += volume;
	}
	cout << "Le volume total d'eau distribué dans l'année est de : " << total_volume << "L" << endl;
	return 1;
}

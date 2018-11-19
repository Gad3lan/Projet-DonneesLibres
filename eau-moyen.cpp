#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
using namespace std;

/** Calcule et affiche le volume d'eau moyen distribué par mois à Paris en 2011 **/
int main() {
     ifstream data("donnees/volumes_d_eau_distribues.txt");
     int total_volume, average_volume = 0;
     int volume, month;
     while(data >> month && data >> volume)
          total_volume += volume;
     average_volume = total_volume/ 12;
     cout << "Le volume moyen d'eau distribué par mois de cette année est de : " << average_volume << "L" << endl;
     return 1;
}

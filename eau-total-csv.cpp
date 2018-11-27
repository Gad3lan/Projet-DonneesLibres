#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <sstream>
#inculde <string>
using namespace std;

int main() {
    ifstream donnees("donnes/volumes_d_eau_distribues.csv");
    string entete;
    getline(donnees, entete);
	
	
	 string mois, string volume_str;
	 int total_volume = 0;
     while(getline(fichier, mois, ';') && getline(fichier, volume_str))
          total_volume += stoi(volume_str);
     cout << "Le volume total d'eau distribué de cette année est de : " << total_volume << "L" << endl;
     return 1;
}


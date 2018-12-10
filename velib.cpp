#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include "tableau-donnees-csv.h"
using namespace std;

double carre(double i) {
	return i*i;
}

double moyenne(vector<double> t) {
	double total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total/t.size();
}

int main () {
	vector<vector<string>> t = litTableauCSV("donnees/velib_a_paris_et_communes_limitrophes.csv");
	vector<double> latitudes = conversionDouble(colonne(t, 6));
	vector<double> longitudes = conversionDouble(colonne(t, 7));
	vector<int> stations_dist_min(2);
	double distance;
	double distance_min = 99999;

	for (int i = 0; i < t.size() - 1; i++) {
		for (int j = i + 1; j < t.size(); j++) {
			distance = sqrt(carre((latitudes[i]-latitudes[j])*111319)*111319+carre((longitudes[i]-longitudes[j])*111319*cos(moyenne({longitudes[i],longitudes[j]})))*111319);
			if (distance < distance_min) {
				distance_min = distance;
				stations_dist_min[0] = i;
				stations_dist_min[1] = j;
			}
		}
	}
	cout << "Les deux stations de Velib' les plus proches sont " << t[stations_dist_min[0]][1] << " et " << t[stations_dist_min[1]][1] << " avec une distance de " << distance_min << "m." << endl;
	return 0;
}

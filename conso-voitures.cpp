#include <stdexcept>
/** @file **/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "tableau-donnees.h"
#include "tableau-donnees-csv.h"
using namespace std;

vector<vector<string>> tab2D = litTableauCSV("donnees/mars-2014-complete.csv");

int indiceMax(vector<double> t) {
	int max = 0;
	int indice_max;

	for (int i = 0; i < t.size(); i++) {
		if (t[i] > max) {
			max = t[i];
			indice_max = i;
		}
	}
	return indice_max;
}

int indiceMin(vector<double> t) {
	int min = 9999;
	int indice_min;

	for (int i = 0; i < t.size(); i++) {
		if (t[i] < min) {
			min = t[i];
			indice_min = i;
		}
	}
	return indice_min;
}

vector<double> moyenneMaxMarque(vector<double> t) {
	vector<double> moyenne_marque;
	vector<double> nb_nom_marque;

	double tot_tmp = t[0];
	int taille = 1;

	for (int i = 1; i < t.size(); i++) {
		if (tab2D[i][0] == tab2D[i-1][0]) {
			tot_tmp += t[i];
			taille++;
		} else {
			moyenne_marque.push_back(tot_tmp/taille);
			nb_nom_marque.push_back((double)i-1);
			tot_tmp = t[i];
			taille = 1;
		}
	}
	return {nb_nom_marque[indiceMax(moyenne_marque)], moyenne_marque[indiceMax(moyenne_marque)]};
}

vector<double> moyenneMinMarque(vector<double> t) {
	vector<double> moyenne_marque;
	vector<double> nb_nom_marque;

	double tot_tmp = t[0];
	int taille = 1;
	int x = 0;

	for (int i = 1; i < t.size(); i++) {
		if (tab2D[i][0] == tab2D[i-1][0]) {
			tot_tmp += t[i];
			taille++;
		} else {
			moyenne_marque.push_back(tot_tmp/taille);
			nb_nom_marque.push_back((double)i-1);
			cout << tab2D[nb_nom_marque[nb_nom_marque.size()-1]][0] << " " << moyenne_marque[moyenne_marque.size()-1] << " " << tot_tmp << " " << taille << endl;
			tot_tmp = t[i];
			x += taille;
			taille = 1;
		}
	}
	cout << x << endl;
	return {nb_nom_marque[indiceMin(moyenne_marque)], moyenne_marque[indiceMin(moyenne_marque)]};
}

int main() {
	vector<double> t = conversionDouble(colonne(tab2D, 13));
	vector<double> moyenne_max = moyenneMaxMarque(t);
	vector<double> moyenne_min = moyenneMinMarque(t);
	int consomax = indiceMax(t);
	int consomin = indiceMin(t);

	cout << "La voiture consommant le plus en France est la " << tab2D[consomax][0] << " " << tab2D[consomax][3] << " avec un consommation de " << t[consomax] << "L/100km." << endl;
	cout << "La voiture consommant le moins en France est la " << tab2D[consomin][0] << " " << tab2D[consomin][3] << " avec une consommation de " << t[consomin] << "L/100km." << endl;
	cout << "La marque produisant les voitures qui consomment le plus est " << tab2D[(int)moyenne_max[0]][0] << " avec une moyenne de " << moyenne_max[1] << "L/100km." << endl;
	cout << "La marque produisant les voitures qui consomment le moins est " << tab2D[(int)moyenne_min[0]][0] << " avec une moyenne de " << moyenne_min[1] << "L/100km." << endl;
	return 0;
}

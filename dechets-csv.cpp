#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees-csv.h"
using namespace std;

/** Calcule et affiche l'arrondissement ayant le plus de déchets sur l'année
 * ainsi que son tonnage annuel **/
int main() {
    vector<vector<string>> t = litTableauCSV("donnees/tonnages_des_dechets_bacs_jaunes.csv");
    vector<float> poids_arr;
    int tout_paris;
    int arr_max;
    float total;
    float poids_arr_max = 0;

    for (int i = 0; i < t.size(); i++) {
        total = 0;
        if (t[i][0] != "Tout Paris") {
            for (int j = 1; j < t[i].size() - 1; j++) {
                for (int k = 0; k < t[i][j].size(); k++) {
                    if (t[i][j][k] == ',') {
                        t[i][j][k] = '.';
                    }
                }
                total += stof(t[i][j]);
            }
            poids_arr.push_back(total);
        }
    }
    for (int i = 0; i < poids_arr.size(); i++) {
        if (poids_arr[i] > poids_arr_max) {
            poids_arr_max = poids_arr[i];
            arr_max = i;
        }
    }
    cout << "L'arrondissement qui a produit le plus de dechets est le " << t[arr_max][0] << " avec une masse totale de " << poids_arr[arr_max] << " tonnes.";
	return 0;
}
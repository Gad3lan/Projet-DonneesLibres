#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Renvoie le tableau des dechets annuels par arrondissement
 * @param t un double tableau contenant sur chaque ligne l'arrondissement
 * suivi du tonnage des déchets par mois
 * @return un tableau ou chaque case i contient les déchets annuels
 * de l'arrondissement correspondant dans t
 **/
vector<int> dechetsAnnuels(vector<vector<int>> t) {
	vector<int> r;

	for(int i=0; i<t.size(); i++) {
		r.push_back(sommePartielle(t[i],1));
	}
	return r;
}


/**
 * Demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 * Puis, affiche pour l'année :
 * - la somme totale des dechets annuels
 * - la moyenne par arrondissement pour l'année
 * - l'arrondissement avec le plus de déchets pour l'année (et son tonnage annuel)
 **/
int main() {
	int mois;
	vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);
	vector<int> dechets_annuels_arr = dechetsAnnuels(t);
	vector<int> tab = colonne(t, mois);
	int arr_max_mois = indiceMax(tab);
	int arr_max_annee = indiceMax(dechetsAnnuels(t));

	cout << "Entrez un numéro de mois (entre 1 et 12) : ";
	cin >> mois;
	cout << "La somme des déchets pour ce mois est de : " << somme(tab) << endl;
	cout << "La moyenne des déchets pour ce mois est de : " << moyenne(tab) << endl;
	cout << "L’arrondissement avec le plus de déchets pour ce mois est : " << t[arr_max_mois][0] << " avec " << t[arr_max_mois][mois] << " tonnes de déchets." << endl;
	cout << "---" << endl;
	cout << "La somme des déchets annuel est de " << somme(dechetsAnnuels(t)) << endl;
	cout << "La moyenne des déchets pour l'année est de " << moyenne(dechetsAnnuels(t)) << endl;
	cout << "L'arrondissement avec le plus de déchets de l'année est : " << t[arr_max_annee][0] << " avec " << dechets_annuels_arr[arr_max_annee] << " tonnes de déchets." << endl;
	return 1;
}

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
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction main non implanté ligne 35");
}

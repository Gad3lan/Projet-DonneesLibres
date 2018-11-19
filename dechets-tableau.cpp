#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl


/** Construction d'un tableau 2D d'entiers lu depuis un fichier
 * @param fichier le nom d'un fichier contenant un nombre fixe
  * d'entiers par lignes, séparés par des espaces
 * @param nb_colonnes le nombre de colonnes du fichier
 * @return un tableau d'entiers à deux dimensions
 **/
vector<vector<int>> litTableauInt(string nom_fichier, int nb_colonnes) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction litTableauInt non implanté ligne 21");
}

/** Test de la fonction litTableauInt **/
void testLitTableauInt() {
    vector<vector<int>> t = litTableauInt("donnees/tonnages_des_dechets_bacs_jaunes.txt", 13);
    ASSERT(t[0][0] == 75007);
    ASSERT(t[3][5] == 876);
    ASSERT(t[19][12] == 235);
}

/** Extraction d'une colonne d'un tableau d'entiers
 * @param t un tableau 2D d'entiers
 * @param i un numéro de colonne
 * @return la colonne j, représentée par un vecteur d'entiers
 **/
vector<int> colonne(vector<vector<int>> t, int j) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction colonne non implanté ligne 39");
}

/** Test de la fonction colonne **/
void testColonne() {
    vector<vector<int>> t = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    ASSERT( colonne(t,0) == vector<int>({1,4,7,10}));
    ASSERT( colonne(t,1) == vector<int>({2,5,8,11}));
    ASSERT( colonne(t,2) == vector<int>({3,6,9,12}));
}

/** copier la fonction somme déjà écrite **/
int somme(vector<int> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction somme non implanté ligne 53");
}

/** copier la fonction moyenne déjà écrite **/
int moyenne(vector<int> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction moyenne non implanté ligne 59");
}

/** copier la fonction indiceMax déjà écrite **/
int indiceMax(vector<int> t) {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction indiceMax non implanté ligne 65");
}

/** Lance les tests de litTableauInt et colonne
 * puis demande à l'utilisateur un mois et calcule et affiche
 * - la somme des déchets pour le mois
 * - la moyenne par arrondissement pour le mois
 * - l'arrondissement avec le plus de déchets pour le mois (et son tonnage)
 **/
int main() {
    // Remplacer la ligne suivante par le code adéquat
    throw runtime_error("Fonction main non implanté ligne 76");
}

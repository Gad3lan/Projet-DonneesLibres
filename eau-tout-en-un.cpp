#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Infrastructure minimale de test **/
#define ASSERT(test) if (!(test)) cout << "Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl

/** Construction d'un tableau d'entiers lu depuis un fichier
 * On suppose que le fichier contient sur chaque ligne un numéro de mois
 * suivi d'une donnée correspondant au mois.
 * @param nom_fichier, le nom du fichier de données
 * @return un tableau d'entiers de taille 12 tel que dans chaque
 * case d'indice i, on trouve la donnée du mois i
 **/
vector<int> litTableauMois(string nom_fichier) {
	ifstream donnees(nom_fichier);
	int mois, volume;
	vector<int> t(12, 0);

	while(donnees >> mois && donnees >> volume){
		t[mois - 1] = volume;
	}
	return t;
}

/** Test de la fonction litTableauMois **/
void testLitTableauMois() {
	vector<int> t = litTableauMois("donnees/volumes_d_eau_distribues.txt");

	ASSERT(t[0] == 16231200); // Le volume pour janvier
	ASSERT(t[11] == 15530100); // Le volume pour décembre
	ASSERT(t[4] == 17711200); //Le volume pour mai
}

/** Renvoie la somme d'un tableau d'entiers
 * @param t, un tableau d'entier
 * @return la somme des valeurs
 **/
int somme(vector<int> t) {
	int total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total;
}

/** Test de la fonction somme **/
void testSomme() {
	ASSERT(somme({1,2,3}) == 6);
	ASSERT(somme({}) == 0);
	ASSERT(somme({2,2,4,8}) == 16);
}

/** Renvoie la moyenne d'un tableau d'entier
 * @param t, un tableau d'entiers
 * @return la moyenne (entière) des valeurs
 **/
int moyenne(vector<int> t) {
	int total = 0;

	for (int i = 0; i < t.size(); i++) {
		total += t[i];
	}
	return total / t.size();
}

/** Test de la fonction moyenne **/
void testMoyenne() {
	ASSERT(moyenne({1,2,3}) == 2);
	ASSERT(moyenne({1}) == 1);
	ASSERT(moyenne({2,2,4,8}) == 4);
}


/** Renvoie l'indice de la valeur maximale du tableau
 * @param t, un tableau d'entier
 * @return l'indice de la valeur maximale ou -1 si le tableau est vide
 **/
int indiceMax(vector<int> t) {
	int max = 0;
	int indice;

	if (t.size() <= 0) {
		return -1;
	}
	for (int i = 0; i < t.size(); i++) {
		if (max < t[i]) {
			max = t[i];
			indice = i;
		}
	}
	return indice;
}

/** Test de la fonction IndiceMax **/
void testIndiceMax() {
	ASSERT(indiceMax({}) == -1);
	ASSERT(indiceMax({1,2,3}) == 2);
	ASSERT(indiceMax({1,3,2}) == 1);
	ASSERT(indiceMax({1}) == 0);
	ASSERT(indiceMax({2,8,4,4}) == 1);
}

/** Lance les fonctions de test puis affiche :
 * - le volume d'eau total sur l'année
 * - la moyenne par mois
 * - le mois avec le plus gros volume d'eau et son volume
 **/
int main() {
	vector<int> t = litTableauMois("donnees/volumes_d_eau_distribues.txt");
	string mois[12] = {"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};

	testLitTableauMois();
	testSomme();
	testMoyenne();
	testIndiceMax();
	cout << "Le volume total d’eau distribué dans l’année est de : " << somme(t) << endl;
	cout << "Le volume moyen par mois d’eau distribué dans l’année est de : " << moyenne(t) << endl;
	cout << "Le mois avec le plus gros volume d´eau est " << mois[indiceMax(t)] << " avec " << t[indiceMax(t) - 1] << "litres." << endl;
	return 0;
}

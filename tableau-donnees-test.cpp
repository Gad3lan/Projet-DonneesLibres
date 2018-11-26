#include <stdexcept>
/** @file **/
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Infrastructure minimale de test modifiée pour visualiser les réussites**/
#define ASSERT(test, t) if (!(test)) cout << " Test failed in file " << __FILE__ << " line " << __LINE__ << ": " #test << endl; else if (t == 1) cout << "\tOK!"; else if (t == 2) cout << "\t\tOK!"

vector<int> c = { 1, 5, 3, 5, 1 };
vector<vector<int>> t = { {1, 2}, {2,4}, {3,1}, {0,0} };

void testMoyenne() {
    ASSERT( moyenne(c) == 3, 2 );
}

void testSomme() {
    ASSERT( somme({}) == 0,  0 );
    ASSERT( somme(c)  == 15, 2 );
}

void testSommePartielle() {
    ASSERT( sommePartielle(c,0) == 15, 0 );
    ASSERT( sommePartielle(c,1) == 14, 0 );
    ASSERT( sommePartielle(c,2) == 9,  0 );
    ASSERT( sommePartielle(c,5) == 0,  2 );
}


void testIndiceMax() {
	ASSERT(  indiceMax(colonne(litTableauInt("donnees/volumes_d_eau_distribues.txt", 2), 1)) == 11, 1 );
}

void testLitTableauInt() {
    ASSERT(  litTableauInt("donnees/volumes_d_eau_distribues.txt", 2) ==
            vector<vector<int>>({
                    {  4, 15688700 },
                    {  7, 16049700 },
                    {  3, 16260600 },
                    {  6, 17028600 },
                    {  9, 16858200 },
                    { 12, 15530100 },
                    {  2, 14019000 },
                    {  8, 13959600 },
                    {  1, 16231200 },
                    { 10, 16592900 },
                    { 11, 15672000 },
                    {  5, 17711200 },
            }), 1 );
}

void testColonne() {
	vector<vector<int>> t = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
	ASSERT( colonne(t,0) == vector<int>({1,4,7,10}), 0 );
	ASSERT( colonne(t,1) == vector<int>({2,5,8,11}), 0 );
	ASSERT( colonne(t,2) == vector<int>({3,6,9,12}), 2 );
}

int main() {
    cout << "Lancement des tests de moyenne:";
    testMoyenne();
	cout << endl;
    cout << "Lancement des tests de somme:";
    testSomme();
	cout << endl;
    cout << "Lancement des tests de indiceMax:";
    testIndiceMax();
	cout << endl;
    cout << "Lancement des tests de litTableauInt:";
    testLitTableauInt();
	cout << endl;
    cout << "Lancement des tests de colonne:";
    testColonne();
	cout << endl;
}

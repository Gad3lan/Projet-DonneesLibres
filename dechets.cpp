#include <stdexcept>
/** @file **/
#include <fstream>
#include <iostream>
#include "tableau-donnees.h"
using namespace std;

/** Calcule et affiche l'arrondissement ayant le plus de déchets sur l'année
 * ainsi que son tonnage annuel **/
int main() {
     ifstream donnees("donnees/tonnages_des_dechets_bacs_jaunes.txt");
     int arrondissement, arrondissement_max, arrondissement_dechets_max, dechets, total_dechets_arrondissement;
     string indice = "er ";
     for (int i = 0; i < 20; i++) {
          total_dechets_arrondissement = 0;
          donnees >> arrondissement;
          for (int j = 0; j < 12; j++) {
               donnees >> dechets;
               total_dechets_arrondissement += dechets;
          }
          if (arrondissement_dechets_max < total_dechets_arrondissement) {
               arrondissement_dechets_max = total_dechets_arrondissement;
               arrondissement_max = arrondissement;
          }
     }
     if (arrondissement_max - 75000 > 1)
          indice = "eme ";
     cout << "Le " << arrondissement_max - 75000 << indice << "arrondissement est celui qui a produit le plus de dechets dans l'année avec un total de :" << arrondissement_dechets_max << " tonnes" << endl;
     return 1;
}

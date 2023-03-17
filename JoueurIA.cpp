#include "JoueurIA.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

JoueurIA::JoueurIA(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur IA : " << this->tuile << std::endl;  
}


Carte * JoueurIA::JouerUneCarte() {
  /** Initialiser une graine aléatoire avec la base de la librairie time.h */
  srand (time(NULL));

  /** renvoyer une des cartes aléatoires de la main */
  return this->cartes_en_main[rand() % 4];
}
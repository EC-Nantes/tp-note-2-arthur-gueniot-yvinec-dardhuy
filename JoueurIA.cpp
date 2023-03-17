#include "JoueurIA.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

JoueurIA::JoueurIA(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur IA : " << this->tuile << std::endl;  
}


Carte * JoueurIA::JouerUneCarte() {
  Carte* carte_a_jouer;
  int it = rand() % 4;
  
  /** Initialiser une graine aléatoire avec la base de la librairie time.h */
  srand (time(NULL));

  carte_a_jouer = this->cartes_en_main.at(it);
  this->cartes_en_main.erase(this->cartes_en_main.begin()+it, this->cartes_en_main.begin()+it);
  
  /** renvoyer une des cartes aléatoires de la main */
  return carte_a_jouer;
}
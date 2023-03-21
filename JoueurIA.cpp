#include "JoueurIA.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

JoueurIA::JoueurIA(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur IA : " << this->tuile << std::endl;  
}


Carte * JoueurIA::JouerUneCarte() {
  Carte* carte_a_jouer;
  std::cout << "Carte1" << std::endl;
  int it = rand() % 4;
  
  std::cout << "Carte2" << std::endl;
  
  /** Initialiser une graine aléatoire avec la base de la librairie time.h */
  srand (time(NULL));
  
  std::cout << "Carte3" << std::endl;

  carte_a_jouer = this->cartes_en_main.at(it);
  
  std::cout << "Carte4" << std::endl;
  this->cartes_en_main.erase(this->cartes_en_main.begin()+it, this->cartes_en_main.begin()+it);
  
  std::cout << "Carte5" << std::endl;
  /** renvoyer une des cartes aléatoires de la main */
  return carte_a_jouer;
}
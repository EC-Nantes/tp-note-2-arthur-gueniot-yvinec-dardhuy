#include "JoueurIA.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

JoueurIA::JoueurIA(std::vector<Carte*> cartes, Tortue *tuile, int num) : Joueur(cartes, tuile, num) {
  std::cout << "Création du joueur IA " << this->numero_de_joueur << " : " << this->tuile << std::endl;  
}


Carte * JoueurIA::JouerUneCarte() {
  Carte* carte_a_jouer;
  /** Initialiser une graine aléatoire avec la base de la librairie time.h */
  srand (time(NULL));
  
  int it = rand() % 4;
  
  std::cout << "Carte jouee par l'IA : " << std::endl;

  carte_a_jouer = this->cartes_en_main.at(it);
  
  this->cartes_en_main.erase(this->cartes_en_main.begin()+it, this->cartes_en_main.begin()+it+1);
  std::cout << *carte_a_jouer<< std::endl;
  
  /** renvoyer une des cartes aléatoires de la main */
  return carte_a_jouer;
}
#include "JoueurHumain.hpp"

JoueurHumain::JoueurHumain(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur : " << this->tuile << std::endl;
  
}


Carte * JoueurHumain::JouerUneCarte() {
  /** Montrer au joueur les cartes dans sa main */
  std::cout << this << std::endl;

  /** Le joueur doit choisir une carte à jouer */
  
  
  /** Renvoyer la cartes choisie */
  return this->cartes_en_main[rand() % 4];
}
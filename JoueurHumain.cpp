#include "JoueurHumain.hpp"

JoueurHumain::JoueurHumain(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur : " << this->tuile << std::endl;
  
}


Carte * JoueurHumain::JouerUneCarte() {
  /** Le joueur doit choisir une carte à jouer */
  
  Carte* carte_a_jouer;
  int it = rand() % 4;
  
  /** Initialiser une graine aléatoire avec la base de la librairie time.h */
  srand (time(NULL));

  carte_a_jouer = this->cartes_en_main.at(it);
  this->cartes_en_main.erase(this->cartes_en_main.begin()+it, this->cartes_en_main.begin()+it+1);
  
  /** renvoyer une des cartes aléatoires de la main */
  return carte_a_jouer;
}

void JoueurHumain::ConsulterCarteEnMain() {
  /** Montrer au joueur les cartes dans sa main */
  std::cout << this << std::endl;
}
#include "JoueurHumain.hpp"

JoueurHumain::JoueurHumain(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur : " << this->tuile << std::endl;
  
}


/** Le joueur doit choisir une carte à jouer */
Carte * JoueurHumain::JouerUneCarte() {
  int choix;
  Carte* carte_a_jouer;
  
  std::cout << "Choisssez une carte de votre main (1..5) : ";
  std::cin >> choix;

  /* Réajuster la valeur de choix (1..5) => (0..4) */
  choix -= 1;

  /* Mettre à jour la main du joueur en supprimant la carte de la main */
  carte_a_jouer = this->cartes_en_main.at(choix);
  this->cartes_en_main.erase(this->cartes_en_main.begin()+choix, this->cartes_en_main.begin()+choix+1);
  
  /** renvoyer une des cartes aléatoires de la main */
  return carte_a_jouer;
}

void JoueurHumain::ConsulterCarteEnMain() {
  /** Montrer au joueur les cartes dans sa main */
  std::cout << this << std::endl;
}
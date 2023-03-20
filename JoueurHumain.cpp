#include "JoueurHumain.hpp"
#include <string>

bool verifierChoixUtilisateur(std::string &choix);

JoueurHumain::JoueurHumain(std::vector<Carte*> cartes, Tortue *tuile) : Joueur(cartes, tuile) {
  std::cout << "Création du joueur : " << this->tuile << std::endl;
  
}


/** Le joueur doit choisir une carte à jouer */
Carte * JoueurHumain::JouerUneCarte() {
  int choix;
  std::string choix_str;
  Carte* carte_a_jouer;

  do {
    std::cout << "Choisssez une carte de votre main (1..5) : ";
    std::cin >> choix_str;
  } while (verifierChoixUtilisateur(choix_str) != true);
  
  /* Réajuster la valeur de choix (1..5) => (0..4) */
  choix = std::stoi(choix_str) - 1;

  /* Mettre à jour la main du joueur en supprimant la carte de la main */
  carte_a_jouer = this->cartes_en_main.at(choix);
  this->cartes_en_main.erase(this->cartes_en_main.begin()+choix, this->cartes_en_main.begin()+choix+1);
  
  /** renvoyer une des cartes aléatoires de la main */
  return carte_a_jouer;
}

void JoueurHumain::ConsulterCarteEnMain() {
  /** Montrer au joueur les cartes dans sa main */
  std::cout << *this << std::endl;
}

/** 
  *  Outillage permettant de vérifier la valeur d'entrée de l'utilisateur pour un choix de carte
  */
bool verifierChoixUtilisateur(std::string &choix) {
  bool valeurEstAcceptee = true;
  if ( (choix != "1") && (choix != "2") && (choix != "3") && (choix != "4") && (choix != "5") ) {
    valeurEstAcceptee = false;
    std::cout << "Entrez une valeur entre 1 et 5" << std::endl;
  }
  return valeurEstAcceptee;
}
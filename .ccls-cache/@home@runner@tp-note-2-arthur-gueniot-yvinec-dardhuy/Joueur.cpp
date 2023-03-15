#include "Joueur.hpp"

#define NOMBRE_DE_CARTE_EN_MAIN_MAX 5

Joueur::Joueur(std::vector<Carte*> cartes, Tortue &tuile) {
  if ( cartes.size() != NOMBRE_DE_CARTE_EN_MAIN_MAX ) {
    throw("Le joueur doit avoir %d cartes pour démarrer", NOMBRE_DE_CARTE_EN_MAIN_MAX);
  }
  this->cartes_en_main = cartes;
  this->tuile = tuile;
}

std::vector<Carte *> Joueur::GetCartes_en_main() {
  return this->cartes_en_main;
}
void Joueur::SetCartes_en_main(std::vector<Carte*> & cartes) {
  this->cartes_en_main = cartes;
}

void Joueur::AjouterUneCarteDansLaMain(Carte *carte) {
  if ( this->cartes_en_main.size() >= NOMBRE_DE_CARTE_EN_MAIN_MAX ) {
    throw("La main du joueur est déja pleine");
  }
  this->cartes_en_main.push_back(carte);
}

std::ostream &operator<<(std::ostream &o, Joueur &j) {
  
  for (auto uneCarte : j.GetCartes_en_main()) {
    std::cout << uneCarte << std::endl;
  }
  return o;
}
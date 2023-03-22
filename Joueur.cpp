#include "Joueur.hpp"

#define NOMBRE_DE_CARTE_EN_MAIN_MAX 5

Joueur::Joueur(std::vector<Carte*> cartes, Tortue *tuile, int numero) {
  this->numero_de_joueur = numero;
  if ( cartes.size() != NOMBRE_DE_CARTE_EN_MAIN_MAX ) {
    throw("Joueur::Joueur(std::vector<Carte*> cartes, Tortue *tuile) : Le joueur doit avoir 5 cartes pour démarrer");
  }
  this->cartes_en_main = cartes;
  this->tuile = tuile;
}

std::vector<Carte *> Joueur::GetCartesEnMain() {
  return this->cartes_en_main;
}
void Joueur::SetCartesEnMain(std::vector<Carte*> & cartes) {
  this->cartes_en_main = cartes;
}

void Joueur::AjouterUneCarteDansLaMain(Carte *carte) {
  if ( this->cartes_en_main.size() >= NOMBRE_DE_CARTE_EN_MAIN_MAX ) {
    throw("Joueur::AjouterUneCarteDansLaMain(Carte *carte) : Impossible d'ajouter une carte, La main du joueur est déja pleine");
  }
  this->cartes_en_main.push_back(carte);
}

// std::ostream &operator<<(std::ostream &os, Joueur &j) {
//   std::cout << "Carte du Joueur " << j.tuile << std::endl;
//   int i = 1;
//   for (auto uneCarte : j.GetCartesEnMain()) {
//     os << "\t" << i << " - " << *uneCarte << std::endl;
//     i++;
//   }
//   return os;
// }
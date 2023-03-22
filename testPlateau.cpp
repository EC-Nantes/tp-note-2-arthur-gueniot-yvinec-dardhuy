#include "Plateau.hpp"
#include <sstream>
#include <cassert>
/*
// Test unitaire pour AfficherCarteEtTuileJoueur
void test_AfficherCarteEtTuileJoueur() {
  // Créer un plateau
  Plateau plateau(false);
  std::stringstream output;

  // Rediriger la sortie standard vers output
  std::streambuf* old_cout = std::cout.rdbuf();
  std::cout.rdbuf(output.rdbuf());

  // Appeler la fonction AfficherCarteEtTuileJoueur
  plateau.AfficherCarteEtTuileJoueur();

  // Remettre la sortie standard à sa place
  std::cout.rdbuf(old_cout);

  // Vérifier que la sortie est correcte
  assert(output.str() == "Cartes en main du joueur 1:\n\nCartes en main du joueur 2:\n\n");
}

// Test unitaire pour Deroulement_partie
void test_Deroulement_partie() {
  // Créer un plateau
  Plateau plateau(false);

  // Appeler la fonction Deroulement_partie plusieurs fois
  bool partie_terminee = false;
  for (int i = 0; i < 100; i++) {
    partie_terminee = plateau.Deroulement_partie();
    if (partie_terminee) {
      break;
    }
  }

  // Vérifier que la partie a bien été terminée
  assert(partie_terminee);
}
*/
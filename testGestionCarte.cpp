#include "Carte.hpp"
#include "GestionCarte.hpp"
#include "TestGestionCarte.hpp"
#include <cassert>
#include <iostream>
#include <vector>

void testCreationGestionCarte() {
  GestionCarte gestionCarte;
  assert(gestionCarte.Distribuer5Cartes().size() == 5);
}

void testMelanger() {
  GestionCarte gestionCarte;
  Carte *ancienne_carte = gestionCarte.Distribuer5Cartes()[0];
  gestionCarte.melanger();
  assert(gestionCarte.Distribuer5Cartes().size() == 5);
  assert(gestionCarte.piocher(ancienne_carte) != ancienne_carte);
}

void testPiocher() {
  GestionCarte gestionCarte;
  Carte *ancienne_carte = gestionCarte.Distribuer5Cartes()[0];
  Carte *nouvelle_carte = gestionCarte.piocher(ancienne_carte);
  assert(nouvelle_carte != ancienne_carte);
}

int testGestionCarte() {
  testCreationGestionCarte();
  testMelanger();
  testPiocher();

  std::cout << "Test de la classe GestionCarte OK !" << std::endl;
  return 0;
}

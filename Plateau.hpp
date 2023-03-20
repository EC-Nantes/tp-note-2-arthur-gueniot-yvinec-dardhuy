#ifndef _PLATEAU_HPP_
#define _PLATEAU_HPP_

#include "Carte.hpp"
#include "Tortue.hpp"
#include "Joueur.hpp"
#include "Case.hpp"
#include "GestionCarte.hpp"
#include "JoueurHumain.hpp"
#include "JoueurIA.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

class Plateau {
private:
  GestionCarte pioche;
  std::vector<Case> liste_cases;
  JoueurHumain j1,j2;
  JoueurIA jIA;
  bool modeIA;

public:
  
  Plateau(bool modeIA);
  bool Deroulement_partie();
  void AfficherCarteEtTuileJoueur();
  void Initialisation();
  bool AppliquerEffet(Couleur couleurcarte, int deplacement);//Si on a une couleur de carte spécifique, c'est cette tortue et celle du dessus qui seront bougées
  bool AppliquerEffet(int deplacement); //Sinon surcharge opérateur, celle-ci sera appelé et viendra sélectionner la tortue en dernière position du jeu.
  bool JouerEffetCarteDefausser(Carte cartejouer);
  Couleur ChoixCouleur();
  void Affichage();
};

#endif /* _Plateau_HPP_ */
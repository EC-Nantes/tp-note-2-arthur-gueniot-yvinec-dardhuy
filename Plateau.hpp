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
  std::vector<Joueur*> liste_joueur;

public:
//constructeur de la classe plateau  
  Plateau (int choix_IA_str, int choix_joueur_str); 
  bool Deroulement_partie();// partie finie ou non 
  void AfficherCarteEtTuileJoueur();
  bool QuiAGagner();//regarde la tortue gagnante
  bool AppliquerEffet(Couleur couleurcarte, int deplacement);//Si on a une couleur de carte spécifique, c'est cette tortue et celle du dessus qui seront bougées


  bool AppliquerEffet(int deplacement); //Sinon surcharge opérateur, celle-ci sera appelée et viendra sélectionner la tortue en dernière position du jeu.
  bool JouerEffetCarteDefausser(Carte cartejouer,Joueur* joueur);
  Couleur ChoixCouleur();
//Affichage du plateau
  void Affichage();
};

#endif /* _Plateau_HPP_ */
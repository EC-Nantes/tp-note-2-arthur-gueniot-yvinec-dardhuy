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
  
  Plateau (int choix_IA_str, int choix_joueur_str); //constructeur de la classe plateau
//méthode qui permet de dérouler une partie en faisant jouer tous les joueurs une fois de la liste l=joueur, on retourne un booleen indiquant true si la aprtie est finie car une tortue a atteint la dernière case
bool Deroulement_partie();
//methode appelée en début de partie pour faire afficher les cartes et la tuile du joueur au départ
  void AfficherCarteEtTuileJoueur();
// Une fois la partie stoppée, on regarde la tortue gagnante ou celle qui est la plus proche dans le cas où c'est une tortue qui n'appartient pas à des joueurs
  bool QuiAGagner();
//appliquer effet se décline en deux fonctions, l'une pour le cas où l'effet s'appliquera sur une couleur spécifique, retourne un booleen true si victoire 
  bool AppliquerEffet(Couleur couleurcarte, int deplacement);//Si on a une couleur de carte spécifique, c'est cette tortue et celle du dessus qui seront bougées

//Méthode appelée lorsqu'on déplace toutes les tortues d'une case, peu importe la couleur
  bool AppliquerEffet(int deplacement); //Sinon surcharge opérateur, celle-ci sera appelée et viendra sélectionner la tortue en dernière position du jeu.

//Méthode qui appelera selon la carte jouée, l'effet avec le deplacement adequat
  bool JouerEffetCarteDefausser(Carte cartejouer,Joueur* joueur);
//Si carte tirée est neutre alors on demande au joueur quelle couleur choisir, retourne la couleur choisie
  Couleur ChoixCouleur();
//Affichage du plateau
  void Affichage();
};

#endif /* _Plateau_HPP_ */
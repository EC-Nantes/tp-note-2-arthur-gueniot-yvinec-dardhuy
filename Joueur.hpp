#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include "Carte.hpp"
#include "Tortue.hpp"

#include <iostream>
#include <vector>

class Joueur {
protected:
  Tortue *tuile;
  std::vector<Carte*> cartes_en_main;
  int numero_de_joueur;

public:
  Joueur(){}
  Couleur getCouleurTuile(){
    return tuile->GetCouleur();
  }
  /**
   *  Constructeur
   */
  Joueur(std::vector<Carte*> cartes, Tortue *tuile,int numero);

  /**
  *  Accesseur pour les cartes en main
  */
  std::vector<Carte*> GetCartesEnMain();

  /**
  *  Accesseur au numéro de joueur
  */
  int getId(){return numero_de_joueur;}

  /**
  *  Mutateur pour les cartes en main
  *  Les cartes dans la main seront remplacées
  *
  * @param cartes Ensembel de carte à placer dans la main du joueur
  */
  void SetCartesEnMain(std::vector<Carte*> & cartes);

  /**
   *  Le plateau pioche la carte et la donne au joueur
   *  Retourne une exception si le nombre de carte est supérieur au nombre de cartes autorisée
   *  dans la main
   *
   * @param carte Carte à ajouter dans la main du joueur
   */
  void AjouterUneCarteDansLaMain(Carte *carte);

  /**
   *  Demande au joeuur de renvoyer une des carte de sa main
   *  Cette action supprime la carte de la main Il faut donc faire piocher une
   * carte au joueur ensuite.
   *  A redéfinir dans chaque sous-classe
   */
  virtual Carte *JouerUneCarte() = 0;

  /**
   *  Demande au joueur de consulter toutes ces cartes sous affichage console
   *  A redéfinir dans chaque sous-classe
   */
  virtual void ConsulterCarteEnMain() = 0;

  /** Surcharge de méthode de la classe mère ou librairie standard */
  //friend std::ostream& operator<<(std::ostream &o, Joueur &j);

  /**
   *  Affichage pour redéfinition dans les sous-classes
   */
  virtual void Affichage() = 0;
};

#endif /* _JOUEUR_HPP_ */
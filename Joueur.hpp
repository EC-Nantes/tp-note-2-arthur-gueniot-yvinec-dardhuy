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

public:
  /**
   *  Constructeur
   */
  Joueur(std::vector<Carte*> cartes, Tortue *tuile);

  /**
  *  Accesseur pour les cartes en main
  */
  std::vector<Carte*> GetCartesEnMain();

  /**
  *  Mutateur pour les cartes en main
  */
  void SetCartesEnMain(std::vector<Carte*> & cartes);

  /**
   *  Le plateau pioche la carte et la donne au joueur
   *  Retourne une exception si le nombre de carte est supérieur au nombre de cartes autorisée
   *  dans la main
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
  friend std::ostream& operator<<(std::ostream &o, Joueur &j);
};

#endif /* _JOUEUR_HPP_ */
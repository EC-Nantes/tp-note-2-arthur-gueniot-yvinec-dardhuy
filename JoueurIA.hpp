#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include "Carte.hpp"
#include "Tortue.hpp"

#include <iostream>
#include <vector>

class JoueurIA {
private:

public:
  /**
   *  Constructeur
   */
  JoueurIA();

  /**
   *  Demande au joeuur de renvoyer une des carte de sa main
   *  Cette action supprime la carte de la main Il faut donc faire piocher une
   * carte au joueur ensuite.
   *  A redéfinir dans chaque sous-classe
   */
  Carte *JouerUneCarte();

  void ConsulterCarteEnMain();

  /** Surcharge de méthode de la classe mère ou librairie standard */
  friend std::ostream& operator<<(std::ostream &o, JoueurIA &j);
};

#endif /* _JOUEUR_HPP_ */
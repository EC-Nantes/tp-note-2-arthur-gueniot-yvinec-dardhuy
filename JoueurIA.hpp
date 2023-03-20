#ifndef _JOUEURIA_HPP_
#define _JOUEURIA_HPP_

#include "Joueur.hpp"

class JoueurIA: public virtual Joueur {
public:
  JoueurIA(){}
  JoueurIA(std::vector<Carte*> cartes, Tortue *tuile);
  Carte *JouerUneCarte();
  void ConsulterCarteEnMain() {};
};

#endif /* _JOUEUR_HPP_ */
#ifndef _JOUEURHUMAIN_HPP_
#define _JOUEURHUMAIN_HPP_

#include "Joueur.hpp"

class JoueurHumain: public Joueur {
public:
  JoueurHumain(){}
  JoueurHumain(std::vector<Carte*> cartes, Tortue *tuile);
  Carte *JouerUneCarte();
  void ConsulterCarteEnMain();
};

#endif /* _JOUEURHUMAIN_HPP_ */
#ifndef _PLATEAU_HPP_
#define _PLATEAU_HPP_

#include "Carte.hpp"
#include "Tortue.hpp"
#include "Joueur.hpp"

#include <iostream>
#include <vector>

class Plateau {
private:
  GestionCarte pioche;
  Joueur j1, j2;
  std::vector<Case> liste_cases;

public:
  
  Plateau();
  void Deroulement_partie();
  

};

#endif /* _Plateau_HPP_ */
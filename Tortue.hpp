#ifndef _TORTUE_HPP_
#define _TORTUE_HPP_

/* Il n'y a pas de lien entre carte et tortue mais pour éviter de recréer un Enum couleur ici on importe la classe Carte qui la contient. Il faudrait trouver une stratégie pour ne pas avoir se doublon sans rendre les deux classes Tortue et Carte liée :
  - Un outillage indépendant
  - une classe couleur
*/
#include "Carte.hpp"
#include <iostream>
#include <string>

class Tortue {
  private:
    Couleur couleur_tortue;
  public:
    Tortue();
    Tortue(Couleur couleur) { this->couleur_tortue = couleur;};

    bool operator==(const Tortue& other) const {
      return (couleur_tortue == other.couleur_tortue);
    }

    Couleur GetCouleur(){ return this->couleur_tortue; }

    friend std::ostream& operator<<(std::ostream &o, Tortue* tortue);
};

#endif /* _TORTUE_HPP_ */
#ifndef _TORTUE_HPP_
#define _TORTUE_HPP_
/* 
*/
#include "Carte.hpp"
#include ""
#include <iostream>
#include <string>

class Tortue {
  private:
    Couleur couleur_tortue;
  public:
    Tortue();
    Tortue(Couleur couleur) { this->couleur_tortue = couleur;};
    bool operator==( Tortue& other) const {
      bool state=false;
      if((couleur_tortue == other.GetCouleur())){
        state=true;
      }
      else{
        state=false;
      }
      return state;
    }

    Couleur GetCouleur(){return this->couleur_tortue; }

    friend std::ostream& operator<<(std::ostream &o, Tortue* tortue);
};

#endif /* _TORTUE_HPP_ */
#ifndef _TORTUE_HPP_
#define _TORTUE_HPP_
/* 
*/
#include "Carte.hpp"
#include <iostream>
#include <string>

/**
*  La classe Tortue représente une tortue du jeu et possède une couleur
*/
class Tortue {
  private:
    /**
    *  Couleur de la tortue à définir à la création de la Tortue
    */
    Couleur couleur_tortue;
  public:
    Tortue();
    /** 
    *  Constructeur
    * @param couleur Couleur de la tortue à enregistrer
    */
    Tortue(Couleur couleur) { this->couleur_tortue = couleur;};

    /**
    *  Redéfinition de l'opérateur de condition d'égalité, pour comparer la couelur des tortues directement
    *
    * @param other Tortue à comparer avce l'objet 
    *
    * @return Retourne "vrai" si la couleur est identique, sinon "faux"
    */
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
    
    /**
    * Accesseur de la couleur de la tortue
    *
    * @return Retourne la couleur de la tortue
    */
    Couleur GetCouleur(){return this->couleur_tortue; }

    /**
    * Surcharge de l'opérateur d'affichage pour la classe, affiche la couleur l'image de la tortue avec la bonne couleur
    *
    * @return Retourne le flux de donnée
    */
    friend std::ostream& operator<<(std::ostream &o, Tortue* tortue);
};

#endif /* _TORTUE_HPP_ */
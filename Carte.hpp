#ifndef _CARTE_HPP_
#define _CARTE_HPP_

#include <iostream>
#include <string>

/** Enumération des effets possibles pour les cartes */
enum Effet {
  Avancer2,
  Avancer1,
  Reculer1,
  Saute2,
  Saute1
};

/** Enumération des couleurs possibles pour les cartes et els tortues */
enum Couleur {
  Rouge,
  Vert,
  Jaune,
  Bleu,
  Violette,
  Neutre
};

/**
*  La classe Carte représente une carte du jeu
*/
class Carte {
  public:
    /**
    * Constructeur défini avec les paramètre initiaux
    *
    * @param effet Effet qui sera réalisé par la carte si elle est jouée
    * @param Couleur Couleur que la carte aura
    */
    Carte(Effet effet, Couleur couleur) : m_effet(effet), m_couleur(couleur) {}

    /**
    * Accesseur à l'attribut d'effet de la carte
    *
    * @return Retour l'effet de la carte (avancer, reculer...)
    */
    Effet getEffet() const {
      return m_effet;
    }

    /**
    * Renvoyer l'information de l'effet de la carte
    *
    * @return Retourne une chaine de caractère décrivant l'action de la carte
    */
    std::string getDescription() const;

    /**
    * Accesseur à l'attribut couleur de la carte
    *
    * @return Retourne la couleur de la carte
    */
    Couleur getCouleur() const {
      return m_couleur;
    }

    /**
    * Convertir et renvoyer la couleur de la carte au format texte
    *
    * @return Retourne la couleur de la carte au format string
    */
    std::string getCouleurString() const ;

  /** 
  * Surcharge de méthode de la classe mère ou librairie standard
  */
  friend std::ostream& operator<<(std::ostream &o, Carte &c);

  private:
    /** 
    * Effet de la carte
    */
    Effet m_effet;
    /** 
    * Couleur de la carte
    */
    Couleur m_couleur;
};
#endif  /* _CARTE_HPP_ */





#ifndef _CARTE_HPP_
#define _CARTE_HPP_
#include <iostream>
#include <string>

enum Effet {
  Avancer2,
  Avancer1,
  Reculer1,
  Saute2,
  Saute1
};

enum Couleur {
  Rouge,
  Vert,
  Jaune,
  Bleu,
  Violette,
  Neutre
};

class Carte {
  public:
    Carte(Effet effet, Couleur couleur) : m_effet(effet), m_couleur(couleur) {}

    Effet getEffet() const {
      return m_effet;
    }

    std::string getDescription() const;

    Couleur getCouleur() const {
      return m_couleur;
    }

  /** Surcharge de méthode de la classe mère ou librairie standard */
  friend std::ostream& operator<<(std::ostream &o, Carte &c);

  private:
    Effet m_effet;
    Couleur m_couleur;
};


#endif  /* _CARTE_HPP_ */
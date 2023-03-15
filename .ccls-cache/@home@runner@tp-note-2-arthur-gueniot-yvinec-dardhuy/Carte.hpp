#ifndef _CARTE_HPP_
#define _CARTE_HPP_
#include <iostream>
#include <string>


    enum Effet {
    Avancer2,
    Avancer1,
    Reculer1,
    Saute2,
    Saute1,
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

    std::string getDescription() const {
      std::string phrase;
        switch(m_effet) {
            case Avancer2:
                phrase= "Avancer 1 case";
                break;
            case Avancer1:
                phrase=  "Avancer 2 cases";
                break;
            case Reculer1:
                phrase=  "Reculer 1 case";
                break;
            case Saute2:
                phrase=  "la dernière tortue avance de 2 cases, sil y en a plusieurs empilées le joueur choisit soit de les déplacer toutes soit celle de son choix";
                break;
            case Saute1:
                phrase=  "la dernière tortue avance de 1 cases, sil y en a plusieurs empilées le joueur choisit soit de les déplacer toutes soit celle de son choix";
                break;
            default:
                phrase=  "Effet inconnu";
                break;
        }
      return phrase;
    }

    Couleur getCouleur() const {
        return m_couleur;
    }

private:
    Effet m_effet;
    Couleur m_couleur;
};


#endif  /* _CARTE_HPP_ */
#include "Carte.hpp"
#include <string>


std::string Carte::getDescription() const {
  std::string phrase;
  switch(m_effet) {
    case Avancer1:
        phrase= "Avancer 1 case";
        break;
    case Avancer2:
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

std::string Carte::getCouleurString() const {
  std::string str;
  switch(this->getCouleur()) {
    case Rouge:
        str= "Rouge";
        break;
    case Vert:
        str=  "Vert";
        break;
    case Jaune:
        str=  "Jaune";
        break;
    case Bleu:
        str=  "Bleu";
        break;
    case Violette:
        str=  "Violette";
        break;
    case Neutre:
        str=  "Neutre";
        break;
    default:
        str=  "Couleur inconnu";
        throw("Couleur::getCouleurString() : Couleur n'existe pas");
        break;
  }
  return str;
}


std::ostream &operator<<(std::ostream &os, Carte &c) {
  os << c.getCouleurString() << " - " << c.getDescription();
  return os;
}
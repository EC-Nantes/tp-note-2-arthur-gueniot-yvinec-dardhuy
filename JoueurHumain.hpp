#ifndef _JOUEURHUMAIN_HPP_
#define _JOUEURHUMAIN_HPP_

#include "Joueur.hpp"

/**
* \brief Classe pour un joueur "Humain" qui hérite d'une classe joueur (Abstraite)
*/
class JoueurHumain: public Joueur {
public:
  /**
  * \brief Constructeur par défaut de la classe JoueurHumain
  */
  JoueurHumain(){}

  /**
  * \brief Constructeur de la classe JoueurHumain initialisée
  *
  * \param cartes Ensemble des cartes à distribuer au joueur
  * \param tuile Tortue liée au joueur
  * \param num Numéro du joueur pour identification
  */
  JoueurHumain(std::vector<Carte*> cartes, Tortue *tuile, int numero);

  /**
  * \brief Le joueur choisis une carte dans sa main à l'aide d'une saisie clavier
  *
  * \return Renvoie la carte choisie par le joueur
  */
  Carte *JouerUneCarte();

  /**
  * \brief Afficher l'ensemble des cartes en main du joueur dans la console
  */
  void ConsulterCarteEnMain();

  /**
  * \brief Affiche tous les attributs formattés du Joueur dans la console
  */
  void Affichage();
};

#endif /* _JOUEURHUMAIN_HPP_ */
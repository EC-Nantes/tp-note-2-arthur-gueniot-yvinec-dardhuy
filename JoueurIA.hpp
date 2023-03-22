#ifndef _JOUEURIA_HPP_
#define _JOUEURIA_HPP_

#include "Joueur.hpp"

/**
* \brief Classe pour un joueur IA qui hérite d'une classe joueur (Abstraite)
*/
class JoueurIA: public virtual Joueur {
public:
  /**
  * \brief Constructeur par défaut de la classe Joueur IA
  */
  JoueurIA(){}

  /**
  * \brief Constructeur de la classe Joueur IA initialisée
  *
  * \param cartes Ensemble des cartes à distribuer au joueur
  * \param tuile Tortue liée au joueur
  * \param num Numéro du joueur pour identification
  */
  JoueurIA(std::vector<Carte*> cartes, Tortue *tuile, int num);


  /**
  * \brief Le joueur choisis une carte dans sa main aléatoirement
  *
  * \param cartes Ensemble des cartes à distribuer au joueur
  * \param tuile Tortue liée au joueur
  *
  * \return Renvoie la carte choisie par le joueur
  */
  Carte *JouerUneCarte();

  /**
  * \brief Ne fait rien pour la classe Joueur IA
  */
  void ConsulterCarteEnMain() {};
  void Affichage(){};
};

#endif /* _JOUEUR_HPP_ */
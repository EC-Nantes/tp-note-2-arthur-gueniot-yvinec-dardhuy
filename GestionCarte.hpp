#ifndef _GESTIONCARTE_HPP_
#define _GESTIONCARTE_HPP_

#include <iostream>
#include <vector>
#include "Carte.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

/**
*  La classe GestionCarte représente la pioche du jeu
*/
class GestionCarte {
  private:
    /**
    *  Ensemble des cartes contenues dans la pioche
    */
    std::vector<Carte*> pointeur_cartes;//la pioche
  public:
    /**
    *  Constructeur de la pioche
    */
    GestionCarte();

    /**
    *  Mélange les carte de la pioche
    */
    void melanger();

    /**
    *  Piocher une carte et remettre une carte jouée dans la pioche
    *
    *  @param ancienne_carte Carte déja jouée à remettre sous la pioche
    *  
    *  @return La carte piochée
    */
    Carte* piocher(Carte *ancienne_carte );

    /**
    *  Piocher 5 cartes pour le début de jeu. Ces cartes seront ensuites données à un joueur
    *
    *  @return Un vecteur de 5 cartes
    */
    std::vector<Carte*> Distribuer5Cartes();
};

#endif /* _GESTIONCARTE_HPP_ */

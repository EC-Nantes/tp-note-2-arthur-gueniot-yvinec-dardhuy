#ifndef _GESTIONCARTE_HPP_
#define _GESTIONCARTE_HPP_

#include <iostream>
#include <vector>
#include "Carte.hpp"

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class GestionCarte {
public:
    GestionCarte();

    // Mélange les cartes dans le paquet
    void melanger();
    // Pioche la première carte du paquet et la renvoie
    Carte* piocher(Carte *ancienne_carte );
    std::vector<Carte*> Distribuer5Cartes();
private:
    std::vector<Carte*> pointeur_cartes;//la pioche
};


#endif /* _GESTIONCARTE_HPP_ */
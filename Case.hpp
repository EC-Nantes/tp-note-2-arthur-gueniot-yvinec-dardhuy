#ifndef _CASE_HPP_
#define _CASE_HPP_

#include <iostream>
#include "Tortue.hpp"
#include <vector>

/** Tableau de couleur pour utilisation dans la classe, utilise  */
const Couleur tab_couleur[]= {Rouge,Bleu,Jaune,Vert,Violette};

/**
*  La classe Case représente une case du plateau
*/
class Case {
  private:
    /**
    *  Une case peut contenir 0, une ou des tortues
    */
    std::vector<Tortue*> liste_tortues;

    /**
    * Représente la place de la case dans le plateau
    */
    int num;

  public:
    /** 
    * Constructeur
    *
    * /param num Numéro de la case sur le plateau
    */
    Case(int num);

    /**
    * Accesseur de l'attribut de tortue
    *
    * /return Retourne la liste de tortue sur la case
    */
    std::vector<Tortue*> getTortue() const;

    /**
    * Mutateur de l'attribut de tortue
    *
    * /param Tortues à enregistrer EN PLUS sur la case
    */
    void setTortue(std::vector<Tortue*> liste_tortues);

    /**
    * Accesseur du numero de la case (1 à 10)
    *
    * /return Retourne le numéro de la case
    */
    int getNumeroCase() const;

    /**
    *  Chercher une tortue sur la case
    *
    * /param couleur_tortue Tortues à rechercher
    *
    * /return Retourne le pointeur de la tortue, retourne null si rien n'est trouvé
    */
    Tortue* find_number_tortue(Couleur couleur_tortue);

    /**
    *  A partir de la tortue cible envoyée en paramètre, on récupère la liste des tortues au dessus la retourne et enfin les retire de la liste.
    *
    * /param tortueCible à rechercher
    *
    * /return Retourne le pointeur de la tortue, retourne null si rien n'est trouvé
    */
    std::vector<Tortue*> get_range_tortue_and_clean(Tortue* tortueCible);

    /**
    *  Supprime les pointeurs de la liste de tortues 
    */
    void CleanListeTortues();
};

#endif
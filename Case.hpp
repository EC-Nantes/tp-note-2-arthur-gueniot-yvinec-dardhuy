#ifndef _CASE_HPP_
#define _CASE_HPP_
#include <iostream>
#include "Tortue.hpp"
#include <vector>

const Couleur tab_couleur[]= {Rouge,Bleu,Jaune,Vert,Violette};
class Case {
  private:
    std::vector<Tortue*> liste_tortues;
    int num;
  public:
   /* Constructeur */
    Case(int num);//constructeur
    std::vector<Tortue*> getTortue() const;//recupérer liste tortue
    void setTortue(std::vector<Tortue*> liste_tortues);//ajouter une liste de tortue en plus de l'éxistante
    int getNumeroCase() const;//retourne le numero de la case (1 à 10)
    Tortue* find_number_tortue(Couleur couleur_tortue);//retourne le pointeur de la tortue que l'on recherche sinon retourne null si rien n'est trouvé
    std::vector<Tortue*> get_range_tortue_and_clean(Tortue* tortueCible);//à partir de la tortue cible envoyée en paramètre, on récupère la liste des tortues au dessus la retourne et enfin les retire de la liste.
    void CleanListeTortues();
};
#endif
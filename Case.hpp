#ifndef _CASE_HPP_
#define _CASE_HPP_


#include <iostream>
#include "Tortue.hpp"
#include <vector>


class Case {
  private:
    std::vector<Tortue> liste_tortues;
    int num;

  public:
   /* Constructeur */
    Case(int num,std::vector<Tortue> liste_tortues);
    std::vector<Tortue> getTortue() const;
    void setTortue(std::vector<Tortue> liste_tortues);
    int getNumeroCase() const;
    int find_number_tortue(Tortue* tortue);
};
#endif
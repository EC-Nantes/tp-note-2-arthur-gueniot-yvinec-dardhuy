#ifndef _ZA_HPP_
#define _ZA_HPP_

#include <iostream>
#include "Parcelle.hpp"


using namespace std;

class Za: public virtual Parcelle {

  private:
    string typeCulture;
    float surfaceBatAgri;

  public:
   /* Constructeur */
    Za(int num, string prop, Polygone<int> forme, string typeCulture, float surfaceBatAgri, int pConstructible);
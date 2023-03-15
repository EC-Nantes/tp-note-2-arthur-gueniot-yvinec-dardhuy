#include "Case.hpp"


/* Retourner une liste de tortues*/
Case::Case(int num,std::vector<Tortue> liste_tortues){
    this->num = num;
    this->liste_tortues= liste_tortues;
    
   }

std::vector<Tortue> Case::getTortue() const{
  return this->liste_tortues;
}
int Case::getNumeroCase() const{
  return this->num;
}

void Case::setTortue(std::vector<Tortue> liste_tortues){
  this->liste_tortues = liste_tortues;
}

int find_number_tortue(Tortue* tortue){
  while()
}


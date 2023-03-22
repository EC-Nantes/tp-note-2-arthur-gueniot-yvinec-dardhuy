#include "Tortue.hpp"

 std::ostream& operator<<(std::ostream &o, Tortue* tortue){
   switch(tortue->GetCouleur()){
     case Rouge:
      std::cout<< "\033[31m"<<"o"<<"\033[0m";
      break;
     case Violette:
      std::cout<< "\033[35m"<<"o"<<"\033[0m";
      break;
     case Bleu:
      std::cout<< "\033[34m"<<"o"<<"\033[0m";
      break;
     case Vert:
      std::cout<< "\033[32m"<<"o"<<"\033[0m";
      break;
     case Jaune:
      std::cout<< "\033[33m"<<"o"<<"\033[0m";
      break;
     default:
      throw("ostream& operator<<(std::ostream &o, Tortue* tortue) : Aucune tortue de la couleur demandée");
      break;
     
   }
   return o;
 }
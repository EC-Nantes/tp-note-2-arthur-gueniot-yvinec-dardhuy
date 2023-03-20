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
      std::cout<< "neutral";
   }
   return o;
 }
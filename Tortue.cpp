#include "Tortue.hpp"

 std::ostream& operator<<(std::ostream &o, Tortue* tortue){
   switch(tortue->GetCouleur()){
     case Rouge:
      std::cout<<"rouge ";
      break;
     case Violette:
      std::cout<<"violette ";
      break;
     case Bleu:
      std::cout<<"bleue ";
      break;
     case Vert:
      std::cout<<"verte ";
      break;
     case Jaune:
      std::cout<<"jaune ";
      break;
     default:
      std::cout<<"no color";
   }
   return o;
 }
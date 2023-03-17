#include "Carte.hpp"
#include "Joueur.hpp"
#include "Tortue.hpp"
#include "JoueurHumain.hpp"

int main(){
  // std::vector <char> test;
  // test.push_back('a');
  // test.push_back('b');
  // test.push_back('c');
  // test.push_back('d');
  // test.erase(test.begin());
  // for(int i=0;i<4;i++){
  //   std::cout<<"voici l'it : "<<i<<" voici la valeur vecteur : "<< test[i]<<std::endl;
  // }

  
  std::vector <Carte*> carte_main = {
    new Carte(Avancer2, Rouge), 
    new Carte(Avancer1, Vert),
    new Carte(Reculer1, Jaune),
    new Carte(Saute2, Bleu),
    new Carte(Saute1, Violette),
  };
  JoueurHumain j1(carte_main, new Tortue(Rouge));

  std::cout << j1 << std::endl;

  return 0;
}
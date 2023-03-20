#include "Carte.hpp"
#include "Joueur.hpp"
#include "Tortue.hpp"
#include "Plateau.hpp"
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

  /* Test de la création et de l'affichage d'un Joueur */
  // std::vector <Carte*> carte_main = {
  //   new Carte(Avancer2, Rouge), 
  //   new Carte(Avancer1, Vert),
  //   new Carte(Reculer1, Jaune),
  //   new Carte(Saute2, Bleu),
  //   new Carte(Avancer2, Neutre),
  // };
  // JoueurHumain j1(carte_main, new Tortue(Rouge));

  // std::cout << j1 << std::endl;

  // /* Jouer une carte dans la main */
  // std::cout << "Joueur une carte" << std::endl;
  // std::cout << *j1.JouerUneCarte() << std::endl;
  // std::cout << j1 << std::endl;
  
  // /* Ajouter à nouveau une carte dans la main sans erreur */
  // std::cout << "Ajouter une carte sans erreur" << std::endl;
  // try{
  //   j1.AjouterUneCarteDansLaMain(new Carte(Avancer1, Neutre));
  // }
  // catch (char const* &erreur) {
  //   std::cerr << erreur << std::endl;
  // }
  // std::cout << j1 << std::endl;

  // /* Test erreur de l'ajout d'une carte */
  // std::cout << "Cas erreur ajouter une carte" << std::endl;
  // try{
  //   j1.AjouterUneCarteDansLaMain(new Carte(Reculer1, Rouge));
  // }
  // catch (char const* &erreur) {
  //   std::cerr << erreur << std::endl;
  // }
  // std::cout << j1 << std::endl;
  bool choix;
    std::cout<<"Quel mode de jeu ? 0-Joueur Humain vs Joueur Humain ou 1- Joueur Humain vs IA ? Indiquez le numero du mode de jeu : ";
  std::cin>>choix;
  Plateau jeu(choix);
  jeu.AfficherCarteEtTuileJoueur();
  do{
      jeu.Affichage();
  }while(!jeu.Deroulement_partie());

  
  return 0;
}
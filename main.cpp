#include "Carte.hpp"
#include "Joueur.hpp"
#include "Tortue.hpp"
#include "Plateau.hpp"
#include "JoueurHumain.hpp"
#include <string>

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

  /**
  *
  *  LANCEMENT DU JEU
  *
  */

  std::cout << "\033[1,34m\033[45mBIENVENUE DE LE JEU DES TORTUES\033[0m" << std::endl;
  
  /** Choix du nombre de joueur */
  std::string choix_joueur_str;
  bool valeurEstAcceptee = true;
  do {
    valeurEstAcceptee = true;
    std::cout<<"Choisissez le nombre de joueur (2..5) : ";
    std::cin>>choix_joueur_str;
    if ( (choix_joueur_str != "2") && (choix_joueur_str != "3") && (choix_joueur_str != "4") && (choix_joueur_str != "5") ) {
        valeurEstAcceptee = false;
        std::cout << "Entrez un nombre de joueur entre 2 et 5" << std::endl;
    }
  } while ( valeurEstAcceptee == false);
  
  /** Choisir le nombre d'IA */
  std::string choix_IA_str;
  do {
    valeurEstAcceptee = true;
    std::cout<<"Combien d'IA voulez vous ( 0 à " << std::stoi(choix_joueur_str) - 1 << " ?  ";
    std::cin>>choix_IA_str;
    if ( (choix_IA_str != "1") && (choix_IA_str != "2") && (choix_IA_str != "3") && (choix_IA_str != "4") ) {
        if ( (std::stoi(choix_joueur_str) - std::stoi(choix_IA_str)) < 0)
        valeurEstAcceptee = false;
        std::cout << "Entrez un nombre d'IA correct 0 à " << std::stoi(choix_joueur_str) - 1 << std::endl;
    }
  } while ( valeurEstAcceptee == false);
  
  /** Choisir son mode de jeu */
  std::string choix_mode_str;
  do {
    valeurEstAcceptee = true;
    std::cout<<"Quel mode de jeu ? \n\t0-Joueur Humain vs Joueur Humain \n\t ou \n\t1- Joueur Humain vs IA ? \n\tIndiquez le numero du mode de jeu : ";
    std::cin>>choix_mode_str;
    if ( (choix_mode_str != "0") && (choix_mode_str != "1") ) {
        valeurEstAcceptee = false;
        std::cout << "Entrez le mode 0 ou 1" << std::endl;
    }
  } while ( valeurEstAcceptee == false);

  /** Créer le plateau de jeu */
  Plateau jeu(std::stoi(choix_mode_str));
  jeu.AfficherCarteEtTuileJoueur();
  do{
      jeu.Affichage();
  }while(!jeu.Deroulement_partie());
  
  return 0;
}
#include "Carte.hpp"
#include "Joueur.hpp"
#include "Tortue.hpp"
#include "Plateau.hpp"
#include "JoueurHumain.hpp"
#include "TestGestionCarte.hpp"
#include <string>

int main(){
  /**
  *
  *  TEST utilisé pour la classe JoueurHumain mais plus opérationnel après merge des travaux de chacun.
  *
  */
  /* Test de la création et de l'affichage d'un Joueur */
  // std::vector <Carte*> carte_main = {
  //   new Carte(Avancer2, Rouge), 
  //   new Carte(Avancer1, Vert),
  //   new Carte(Reculer1, Jaune),
  //   new Carte(Saute2, Bleu),
  //   new Carte(Avancer2, Neutre),
  // };
  // JoueurHumain j1(carte_main, new Tortue(Rouge), 1);

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
  *  TEST de la classe GestionCarte
  *
  */
  testGestionCarte();
  
  /**
  *
  *  LANCEMENT DU JEU
  *
  */
  

  std::cout << "\033[1,34m\033[45mBIENVENUE DANS LE JEU DES TORTUES\033[0m" << std::endl;
  
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
    std::cout<<"Combien d'IA voulez vous ( 0 à " << std::stoi(choix_joueur_str) - 1 << ") ?  ";
    std::cin>>choix_IA_str;
    if ( (choix_IA_str != "1") && (choix_IA_str != "2") && (choix_IA_str != "3") && (choix_IA_str != "4") ) {
        if ( (std::stoi(choix_joueur_str) - std::stoi(choix_IA_str)) < 0)
        valeurEstAcceptee = false;
        std::cout << "Entrez un nombre d'IA correct 0 à " << std::stoi(choix_joueur_str) - 1 << std::endl;
    }
  } while ( valeurEstAcceptee == false);

  /** Créer le plateau de jeu */
  std::cout <<  "Nombre de joueur : " << choix_joueur_str << "\tNombre d'IA : " << choix_IA_str << std::endl;
  Plateau jeu(std::stoi(choix_IA_str),std::stoi(choix_joueur_str)-std::stoi(choix_IA_str));
  jeu.AfficherCarteEtTuileJoueur();
  do{ }while(!jeu.Deroulement_partie());
  
  return 0;
}
#include "Plateau.hpp"

void Plateau::Deroulement_partie(){
  Carte* carte_jouer;
  j1.ConsulterCarteEnMain();
  carte_jouer = j1.JouerUneCarte();
  j1.AjouterUneCarteDansLaMain(pioche.piocher(carte_jouer));
}

Plateau::Plateau(){
  
}

bool Plateau::JouerEffetCarteDefausser(Carte cartejouer,Joueur joueur){
  bool etat=false;
  switch(cartejouer.getEffet()){
    case Avancer2 : 
      etat= this->AppliquerEffet(cartejouer.getCouleur(), 2);
      break;
    case Avancer1 : 
      if(cartejouer.getCouleur()== Neutre){
        etat= this->AppliquerEffet(this->ChoixCouleur(), 1);
      }
  }
}

Couleur Plateau::ChoixCouleur(){
  int choix=0;
  do{
        std::cout<< "Joueur, la carte tire est de couleur neutre, choisis donc une couleur parmi le 1-Rouge, 2-Jaune, 3-Vert, 4-Violet, 5-Bleu de tortue a faire bouger en indiquant le numero : ";
        std::cin>>choix;
    }while(choix<0 || choix > 5);
  switch(choix){
    case 1:
      return Rouge;
      break;
    case 2:
      return Jaune;
      break;
    case 3 : 
      return Vert;
      break;
    case 4 : 
      return Violette;
      break;
    case 5 : 
      return Bleu;
      break;
    default:
      return Rouge;
  }
}

bool Plateau::AppliquerEffet(Couleur couleurcarte, int deplacement){
  Tortue* tortue;
  for(int i =0; i < liste_cases.size(); i++) {
      tortue = liste_cases[i].find_number_tortue(couleurcarte);
      if(tortue != nullptr){
        liste_cases[i+deplacement].setTortue( liste_cases[i].get_range_tortue_and_clean(tortue) );
      }
      /** Vérifier si il y a une tortue gagnante */
      if(i==9){
        if(liste_cases[i].getTortue().front() != nullptr){
          std::cout <<"La tortue "<< liste_cases[i].getTortue().front() <<" gagne !!!"<<std::endl;
          return true;
          }
      } 
  }
  return false;  
}
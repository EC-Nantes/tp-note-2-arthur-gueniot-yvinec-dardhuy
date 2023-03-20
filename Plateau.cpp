#include "Plateau.hpp"

void Plateau::AfficherCarteEtTuileJoueur(){
  std::cout<<j1<<std::endl;
  if(this->modeIA==false){
   std::cout<<j2<<std::endl;
  }  
}

bool Plateau::Deroulement_partie() {
  Carte *carte_jouer;
  if(this->modeIA == false){
    std::cout<<std::endl<<"Au tour du Joueur 1 !"<<std::endl;
    j1.ConsulterCarteEnMain();
    carte_jouer = j1.JouerUneCarte();
    j1.AjouterUneCarteDansLaMain(pioche.piocher(carte_jouer));
    if(this->JouerEffetCarteDefausser(*carte_jouer))
      return true;
    this->Affichage();
    std::cout<<std::endl<<"Au tour du Joueur 2 !"<<std::endl;
    j2.ConsulterCarteEnMain();
    carte_jouer = j2.JouerUneCarte();
    j2.AjouterUneCarteDansLaMain(pioche.piocher(carte_jouer));
    if(this->JouerEffetCarteDefausser(*carte_jouer))
      return true;
    }
  else{
    std::cout<<std::endl<<"Au tour du Joueur 1 !"<<std::endl;
    j1.ConsulterCarteEnMain();
    carte_jouer = j1.JouerUneCarte();
    j1.AjouterUneCarteDansLaMain(pioche.piocher(carte_jouer));
    if(this->JouerEffetCarteDefausser(*carte_jouer))
      return true;
    this->Affichage();
    std::cout<<std::endl<<"Au tour de l'IA !"<<std::endl;
    carte_jouer = j2.JouerUneCarte();
    j2.AjouterUneCarteDansLaMain(pioche.piocher(carte_jouer));
    if(this->JouerEffetCarteDefausser(*carte_jouer))
      return true;
    }
  return false;
  }


void Plateau::Affichage() { 
  for (int j = 4; j >= 0; j--) {
    for (int i = 0; i < liste_cases.size(); i++) {
      if (liste_cases[i].getTortue().size() <= j) {
        std::cout << "   ";
      } else {
        std::cout << " " << liste_cases[i].getTortue()[j] << " ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << " _  _  _  _  _  _  _  _  _  _ " << std::endl;
}

Plateau::Plateau(bool modeIA) {
  srand((unsigned int)time(0));
  int numeroTortueJ1, numeroTortueJ2;
  this->modeIA = modeIA;
  GestionCarte piochecreation;
  this->pioche = piochecreation;
  for (int i = 0; i < 10; i++) {
    this->liste_cases.push_back(Case(i));
  }

  numeroTortueJ1 = rand()%4;
  j1 = JoueurHumain(pioche.Distribuer5Cartes(),liste_cases[0].getTortue()[numeroTortueJ1]);
  do{
    numeroTortueJ2 = rand()%4;
  }while(numeroTortueJ1 == numeroTortueJ2);
  
  if(modeIA==false){
        j2 = JoueurHumain(pioche.Distribuer5Cartes(),liste_cases[0].getTortue()[numeroTortueJ2]);
    }
  else{
        jIA = JoueurIA(pioche.Distribuer5Cartes(),liste_cases[0].getTortue()[numeroTortueJ2]);
    }
  }

bool Plateau::JouerEffetCarteDefausser(Carte cartejouer) {
  bool etat = false;
  switch (cartejouer.getEffet()) {

  case Avancer2:
    etat = this->AppliquerEffet(cartejouer.getCouleur(), 2);
    break;
  case Avancer1:
    if (cartejouer.getCouleur() == Neutre) {
      etat = this->AppliquerEffet(this->ChoixCouleur(), 1);
    } else {
      etat = this->AppliquerEffet(cartejouer.getCouleur(), 1);
    }
    break;
  case Reculer1:
    if (cartejouer.getCouleur() == Neutre) {
      etat = this->AppliquerEffet(this->ChoixCouleur(), -1);
    } else {
      etat = this->AppliquerEffet(cartejouer.getCouleur(), -1);
    }
    break;
  case Saute1:
    etat = this->AppliquerEffet(1);
    break;
  case Saute2:
    etat = this->AppliquerEffet(2);
    break;
  }
  return etat;
}

Couleur Plateau::ChoixCouleur() {
  int choix = 0;
  do {
    std::cout << "Joueur, la carte tire est de couleur neutre, choisis donc "
                 "une couleur parmi le 1-Rouge, 2-Jaune, 3-Vert, 4-Violet, "
                 "5-Bleu de tortue a faire bouger en indiquant le numero : ";
    std::cin >> choix;
  } while (choix < 0 || choix > 5);
  switch (choix) {
  case 1:
    return Rouge;
    break;
  case 2:
    return Jaune;
    break;
  case 3:
    return Vert;
    break;
  case 4:
    return Violette;
    break;
  case 5:
    return Bleu;
    break;
  default:
    return Rouge;
  }
}

bool Plateau::AppliquerEffet(Couleur couleurcarte, int deplacement) {
  Tortue *tortue;
  bool etat=false;
  for (int i = 0; i < liste_cases.size(); i++) {
    tortue = liste_cases[i].find_number_tortue(couleurcarte);
    if (tortue != nullptr) {
      this->liste_cases[i + deplacement].setTortue(
          this->liste_cases[i].get_range_tortue_and_clean(tortue));
      // for(int j=0; j<liste_cases[i].get_range_tortue_and_clean(tortue).size(); j++){
      //   std::cout<<liste_cases[i].get_range_tortue_and_clean(tortue)[j];
      // }
      etat=true;
    }
    /** Vérifier si il y a une tortue gagnante */
      if (liste_cases[9].getTortue().size() != 0) {
        std::cout << "La tortue " << liste_cases[9].getTortue().front()
                  << " gagne !!!" << std::endl;
        return true;
      }
    if(etat==true)
      break;
  }
  return false;
}

bool Plateau::AppliquerEffet(int deplacement) {
  bool etat=false;
  std::cout<<"etape 4"<<std::endl;
  for (int i = 0; i < liste_cases.size(); i++) {
    // std::cout<<liste_cases[i].getTortue().front()<<std::endl;
    // std::cout<<"etape 5"<<std::endl;
    
    std::cout<<"case : "<<i<<std::endl;
    if (liste_cases[i].getTortue().size() !=0){
      // std::cout<<"etape 6"<<std::endl;
      // liste_cases[i + deplacement].setTortue(liste_cases[i].getTortue());
      liste_cases[i+deplacement].setTortue(liste_cases[i].get_range_tortue_and_clean(liste_cases[i].getTortue().front()));
      // std::cout<<"etape 7"<<std::endl;
      // liste_cases[i].CleanListeTortues();
      etat=true;
      }
      std::cout<<"etape 8"<<std::endl;
      if (liste_cases[9].getTortue().size() != 0) {
        this->Affichage();
        std::cout << "La tortue " << liste_cases[9].getTortue().front()
                  << " gagne !!!" << std::endl;
        return true;
      }
    
    std::cout<<"etape 9"<<std::endl;
    if(etat==true)
      break;
  }
  return false;
}
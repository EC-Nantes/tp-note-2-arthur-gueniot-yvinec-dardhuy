#include "Plateau.hpp"

void Plateau::AfficherCarteEtTuileJoueur() {
  for (auto &it : liste_joueur) // On parcourt chaque joueur de la liste et on
                                // affiche ses informations
    it->Affichage();
}

bool Plateau::Deroulement_partie() {

  Carte *carte_jouer;
  int compteurJ = 1;
  for (auto &it : liste_joueur) { // Pour chaque joueur
    this->Affichage();            // affichage
    std::cout << std::endl << "Au tour du Joueur " << compteurJ << std::endl;
    it->ConsulterCarteEnMain();
    carte_jouer = it->JouerUneCarte();
    try {
      it->AjouterUneCarteDansLaMain(pioche.piocher(carte_jouer));

      if (this->JouerEffetCarteDefausser(
              *carte_jouer,
              it)) { // si on recupère un boolen true alors la case 10 a été
                     // atteinte, on vient donc regarder qui est dessus ou aux
                     // alentours avec la méthode QuiAGagner
        this->Affichage();
        this->QuiAGagner();
        return true;
      }
    } catch (std::string const &erreur) {
      std::cerr << erreur << std::endl;
    }
    compteurJ++;
  }
  return false;
}

bool Plateau::QuiAGagner() {
  for (auto it = liste_cases.rbegin(); it != liste_cases.rend();
       it++) { // on parcourt la boucle à l'envers, on démarre de la fin, donc
               // des tortues à supprimer
    if (it->getTortue().size() != 0) { // si il y a des tortues sur la case
                                       // alors
      for (auto &it_tortue :
           it->getTortue()) { // on parcourt les tortues de la case it
        for (auto &it_joueur :
             liste_joueur) { // puis pour chaque tortue on compare les tuiles de
                             // couleurs des joueurs

          if (it_tortue->GetCouleur() ==
              it_joueur->getCouleurTuile()) { // si il y a la meme couleur alors
            std::cout << "le joueur " << it_joueur->getId() << " gagne !"
                      << std::endl;
            return true;
          }
        }
      }
    }
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

Plateau::Plateau(int choix_IA_str, int choix_joueur_str) {
  srand((unsigned int)time(0));
  GestionCarte piochecreation;
  int i;
  int id_joueur = 1;
  this->pioche = piochecreation;
  // Initialie les cases du plateau
  for (i = 0; i < 10; i++) {
    this->liste_cases.push_back(Case(i));
  }
  // initialise les joueurs humains en les ajoutant à la liste de joueurs du
  // plateau
  for (i = 0; i < choix_joueur_str; i++) {
    liste_joueur.push_back(new JoueurHumain(
        pioche.Distribuer5Cartes(), liste_cases[0].getTortue()[i], id_joueur));
    id_joueur++;
  }
  // initialise les joueurs IA en les ajoutant à la liste de joueurs du plateau
  for (int j = 0; j < choix_IA_str; j++) {
    liste_joueur.push_back(new JoueurIA(pioche.Distribuer5Cartes(),
                                        liste_cases[0].getTortue()[i + j],
                                        id_joueur));
    id_joueur++;
  }
}

bool Plateau::JouerEffetCarteDefausser(Carte cartejouer, Joueur *joueur) {
  srand((unsigned int)time(0));
  const Couleur tab_couleur[] = {Rouge, Bleu, Jaune, Vert, Violette};

  bool etat = false;
  // Pour chaque effet
  switch (cartejouer.getEffet()) {

  case Avancer2:
    etat = this->AppliquerEffet(cartejouer.getCouleur(), 2);
    break;

  case Avancer1:
    if (cartejouer.getCouleur() == Neutre) { // si carte neutre
      std::string nom_classe = typeid(*joueur).name();
      if (nom_classe.find("JoueurIA") !=
          std::string::npos) // Si c'est un joueur de type IA
        etat = this->AppliquerEffet(tab_couleur[rand() % 4], 1);
      else {
        etat = this->AppliquerEffet(this->ChoixCouleur(), 1);
      }
    } else {
      etat = this->AppliquerEffet(cartejouer.getCouleur(), 1);
    }
    break;
  case Reculer1:
    if (cartejouer.getCouleur() == Neutre) {
      std::string nom_classe = typeid(*joueur).name();
      if (nom_classe.find("JoueurIA") != std::string::npos)
        etat = this->AppliquerEffet(tab_couleur[rand() % 4], 1);
      else {
        etat = this->AppliquerEffet(this->ChoixCouleur(), 1);
      }
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
  default:
    throw("bool Plateau::JouerEffetCarteDefausser(Carte cartejouer) : Effet "
          "inconnu");
    break;
  }
  return etat;
}

Couleur Plateau::ChoixCouleur() {
  int choix = 0;
  Couleur couleur;
  do {
    std::cout << "Joueur, la carte tire est de couleur neutre, choisis donc "
                 "une couleur parmi le 1-Rouge, 2-Jaune, 3-Vert, 4-Violet, "
                 "5-Bleu de tortue a faire bouger en indiquant le numero : ";
    std::cin >> choix;
  } while (choix < 0 || choix > 5);

  switch (choix) {
  case 1:
    couleur = Rouge;
    break;
  case 2:
    couleur = Jaune;
    break;
  case 3:
    couleur = Vert;
    break;
  case 4:
    couleur = Violette;
    break;
  case 5:
    couleur = Bleu;
    break;
  default:
    throw("Couleur Plateau::ChoixCouleur() : Couleur inconnue");
    break;
  }
  return couleur;
}

bool Plateau::AppliquerEffet(Couleur couleurcarte, int deplacement) {
  Tortue *tortue;
  bool etat = false;
  for (int i = 0; i < liste_cases.size(); i++) {
    tortue = liste_cases[i].find_number_tortue(couleurcarte);
    if (tortue != nullptr) {
      if (i == 0 &
          deplacement ==
              -1) { // si le joueur tente de reculer en dehors du plateau
        return false;
      }
      if (i == 8 & deplacement == 2){ // si le joueur tente de sortir du plateau
        deplacement = 1;
      }
      try {
        this->liste_cases[i + deplacement].setTortue(
            this->liste_cases[i].get_range_tortue_and_clean(tortue));
      } catch (std::string const &erreur) {
        std::cerr << erreur << std::endl;
      }
      etat = true;
    }
    /** Vérifier si il y a une tortue gagnante */
    if (liste_cases[9].getTortue().size() != 0) {
      this->Affichage();
      return true;
    }
    if (etat == true)
      break;
  }
  return false;
}

bool Plateau::AppliquerEffet(int deplacement) {
  bool etat = false;
  for (int i = 0; i < liste_cases.size(); i++) {
    if (liste_cases[i].getTortue().size() != 0) {
      if (i == 0 & deplacement == -1) {
        return false;
      }
      if (i == 8 & deplacement == 2){
        deplacement = 1;
      }
      try{
        liste_cases[i + deplacement].setTortue(
            liste_cases[i].get_range_tortue_and_clean(
                liste_cases[i].getTortue().front()));
      } catch (std::string const &erreur) {
        std::cerr << erreur << std::endl;
      }
      etat = true;
    }
    if (liste_cases[9].getTortue().size() != 0) {
      this->Affichage();
      return true;
    }
    if (etat == true)
      break;
  }
  return false;
}
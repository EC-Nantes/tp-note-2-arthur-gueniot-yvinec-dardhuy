#include "GestionCarte.hpp"

GestionCarte::GestionCarte() {
  // Initialisation du paquet de cartes
  // création des cartes
  Couleur iteration_couleur[]={Rouge,Vert,Jaune,Bleu,Violette,Neutre};
  for(int it = 0 ; it <6; it++){//parcourir les 5 couleurs avec un iterateur
    //Couleur cartes créations
    if(iteration_couleur[it]!=Neutre) {
      pointeur_cartes.push_back(new Carte(Effet::Avancer2,iteration_couleur[it]));
    }
    
    pointeur_cartes.push_back(new Carte(Effet::Reculer1,iteration_couleur[it]));
    pointeur_cartes.push_back(new Carte(Effet::Reculer1,iteration_couleur[it]));
    
    for(int it2=0; it2<5;it2++){
        pointeur_cartes.push_back(new Carte(Effet::Avancer1,iteration_couleur[it]));
    }        
  }
  //Neutre Cartes créations complémentaire
  pointeur_cartes.push_back(new Carte(Effet::Saute2,Neutre));
  pointeur_cartes.push_back(new Carte(Effet::Saute2,Neutre));

  pointeur_cartes.push_back(new Carte(Effet::Saute1,Neutre));
  pointeur_cartes.push_back(new Carte(Effet::Saute1,Neutre));
  pointeur_cartes.push_back(new Carte(Effet::Saute1,Neutre));
  melanger();    
}

// Mélange les cartes dans le paquet
void GestionCarte::melanger() {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(pointeur_cartes.begin(), pointeur_cartes.end(), std::default_random_engine(seed));
}

// Pioche la première carte du paquet et la renvoie
Carte* GestionCarte::piocher(Carte *ancienne_carte ) {
  //on ajoute l'ancienne carte à la fin de la pioche
  pointeur_cartes.push_back(ancienne_carte);
  Carte *nouvelle_carte = pointeur_cartes.front();

  /** Supprimer la carte pioché de la pioche */
  pointeur_cartes.erase(pointeur_cartes.begin());
  
  return nouvelle_carte;
}

std::vector<Carte*> GestionCarte::Distribuer5Cartes(){
  std::vector <Carte*> paquet;
  for(int i=0; i<5;i++){
    paquet.push_back(pointeur_cartes.front());//ajouter
    pointeur_cartes.erase(pointeur_cartes.begin());//supress
  }
  return paquet;
}

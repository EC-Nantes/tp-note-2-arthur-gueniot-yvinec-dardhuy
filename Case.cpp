#include "Case.hpp"


/* Retourner une liste de tortues*/
Case::Case(int num,std::vector<Tortue*> liste_tortues){
    this->num = num;
    this->liste_tortues= liste_tortues;
    
   }

std::vector<Tortue*> Case::getTortue() const{
  return this->liste_tortues;
}
int Case::getNumeroCase() const{
  return this->num;
}

void Case::setTortue(std::vector<Tortue*> liste_tortues){
  this->liste_tortues = liste_tortues;
}

Tortue* Case::find_number_tortue(Couleur couleur_tortue){
  int index = 0;
    while ( index < liste_tortues.size() ) {
        if(liste_tortues[index]->GetCouleur() == couleur_tortue)
          return liste_tortues[index];
        else
          index++;
    }
  return nullptr;
}

std::vector<Tortue*> Case::get_range_tortue_and_clean(Tortue* tortueCible){
  bool inRange=false;
  std::vector<Tortue*> liste_tortue_deplacement;
    for(auto it= liste_tortues.begin(); it<liste_tortues.end();it++){//it est une pointeur qui pointe sur un pointeur de la liste_tortue d'où la nécessité de mettre ** pour accéder à la valeur tortue : **it == it->pointeur_tortue->objet_tortue
      if( (**it == *tortueCible) || (inRange == true) )//une fois la tortue trouvée avec it==tortuecible, on active la variable inRange en true afin que les futurs tortues (qui sont au dessus de celle trouvée) soit ajouté aussi a la liste-tortue_deplacement
        inRange = true;
        liste_tortue_deplacement.push_back(*it);  
       }
  //boucle de suppression des tortues qui vont être déplacé
    for(auto it= liste_tortues.end(); it<liste_tortues.end();it++){//on parcourt la boucle à l'envers, on démarre de la fin, donc des tortues à supprimer
      if(**it == *tortueCible){//si oui alors on est arrivé jusqu'à la dernière tortue à supp
        liste_tortues.erase(it);
        break;        
      }
      liste_tortues.erase(it);
   }
  return liste_tortue_deplacement;
}



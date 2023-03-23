#include "Case.hpp"


/* Constructeur : Créer une case du plateau */
Case::Case(int num){
  this->num = num;
  if(num==0){
    for(int i=0; i<5; i++){
      this->liste_tortues.push_back(new Tortue(tab_couleur[i]) );
    }
  }
}

std::vector<Tortue*> Case::getTortue() const{
  return this->liste_tortues;
}
int Case::getNumeroCase() const{
  return this->num;
}

void Case::setTortue(std::vector<Tortue*> liste_tortues){
  for(auto &it : liste_tortues){
    this->liste_tortues.push_back(it);
  }
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

  if (tortueCible == nullptr) {
    throw("vector<Tortue*> Case::get_range_tortue_and_clean(Tortue* tortueCible) : Pointeur nul");
  }
  
  std::vector<Tortue*> liste_tortue_deplacement;
    for(auto it= liste_tortues.begin(); it<liste_tortues.end();it++){
      //it est un pointeur qui pointe sur un pointeur de la liste_tortue d'où la nécessité de mettre ** pour accéder à la valeur tortue : **it == it->pointeur_tortue->objet_tortue
      if( (**it == *tortueCible) || (inRange == true) ){//une fois la tortue trouvée avec it==tortuecible, on active la variable inRange en true afin que les futurs tortues (qui sont au dessus de celle trouvée) soit ajouté aussi a la liste-tortue_deplacement
        inRange = true;
        liste_tortue_deplacement.push_back(*it);  
       }
      }
  //boucle de suppression des tortues qui vont être déplacé
    for(std::vector<Tortue*>::reverse_iterator it= liste_tortues.rbegin(); it != liste_tortues.rend(); it++){//on parcourt la boucle à l'envers, on démarre de la fin, donc des tortues à supprimer
      //std::cout<<"tortue it : "<<*it<<" tortue cible :"<<tortueCible<<std::endl;
      if(**it == *tortueCible){//si oui alors on est arrivé jusqu'à la dernière tortue à supp
        liste_tortues.erase(std::next(it).base()); //Attention erase attend en argument un iterateur, or le type it ICI est de type : reverse_iterateur soit un type qui ne convient pas, Nous devons donc procéder à une petite gymnatisque informatique afin de donner une équivalence de notre reverse_iterateur à notre méthode erase() via l'appel de std::next().base().
        break;        
      }
      liste_tortues.erase(std::next(it).base());
   }
  
  return liste_tortue_deplacement;
}

void Case::CleanListeTortues(){
  std::cout<<"etape 1"<<std::endl;
  liste_tortues.clear();
  std::cout<<"etape 2"<<std::endl;
  //liste_tortues[0]=nullptr;
   std::cout<<"etape 3"<<std::endl;
}



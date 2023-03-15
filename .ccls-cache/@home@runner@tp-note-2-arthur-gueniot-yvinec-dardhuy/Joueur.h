#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_

#include "Carte.h"
#include "Tortue.h"

#include <iostream>
#include <vector>

class Joueur {
private:
  Tortue tuile();
  std::vector<Carte*> cartes_en_main;

public:
  /**
   *  Constructeur
   */
  Joueur(std::vector<Carte*> cartes);

  /**
  *  Getteur pour les cartes en main
  */
  std::vector<Carte*> GetCartes_en_main();

  /**
   *  Demande au joeuur de renvoyer une des carte de sa main
   *  Cette action supprime la carte de la main Il faut donc faire piocher une
   * carte au joueur ensuite.
   *  A redéfinir dans chaque sous-classe
   */
  virtual Carte *JouerUneCarte() = 0;

  /**
   *  Demande au joueur de renvoyer une des carte de sa main
   *  Cette action supprime la carte de la main Il faut donc faire piocher une
   * carte au joueur ensuite.
   *  A redéfinir dans chaque sous-classe
   */
  virtual void ConsulterCarteEnMain() = 0;

  /**
   *  Le plateau pioche la carte et la donne au joueur
   *  Retourne une exception si le nombre de carte est supérieur au nombre de cartes autorisée
   *  dans la main
   */
  void AjouterUneCarteDansLaMain(Carte *carte);

  /** Surcharge de méthode de la classe mère ou librairie standard */
  friend std::ostream& operator<<(std::ostream &o, Joueur &j);
};

#endif /* _JOUEUR_HPP_ */
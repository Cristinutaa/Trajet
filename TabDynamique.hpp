#ifndef TabDynamique_hpp
#define TabDynamique_hpp

#include "Trajet.hpp"
#include <stdio.h>

class TabDynamique
{
public:
    // Constructeur par défaut qui met la valeur de cases alluées à max si une valeur est introduite et à 5 sinon
    TabDynamique(int max = 5);
    // Constructeur qui prends comme parametres: max - le nombre de cases alluées, taille - le nombre de cases utilisées et un tableau pointeurs de trajet
    TabDynamique(int max, int taille, const Trajet** t);

    //Destructeur de la classe
    virtual ~TabDynamique();

    //Methode qui permet l'ajout d'un trajet dans le tableau
    const Trajet* ajouter(const Trajet* t);

    //Methode qui renvoie le trajet qui est dans la case i de tableau
    const Trajet* get(int i) const;

    //Methode qui renvoie le nombre d'elements dans le tableau
    int nbElement() const;
    
private:
    //Methode qui augment le nombre des cases allouées pour le tableau
    void reallouer();
    
protected:
    // Le nombre de cases allouées pour le tableau
    int alloue;

    // Le nombtre de cases utilisées
    int utilise;

    // Le tableau de trajets
    const Trajet** trajets;
    
};

#endif /* TabDynamique_hpp */

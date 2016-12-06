
#ifndef Catalogue_hpp
#define Catalogue_hpp

#include <iostream>
#include "Trajet.hpp"
#include "TabDynamique.hpp"

class Catalogue
{
public:
    //Constructeur par défaut
    Catalogue();

    //Destructeur de catalogue
    virtual ~Catalogue();

    //Methode qui affiche les trajets de catalogue
    void afficherTrajet() const;

    //Methode pour ajouter un trajet au catalogue
    const Trajet* ajouterTrajet(const Trajet* t);

    //Methode qui affiche, si ils existent, les trajets qui ont comme ville de depart d et comme ville d'arrivé a
    // et le nombre de trajets qui respecte cette condition
    void rechercherParcourV1(const char* d, const char* a) const;

    //Methode qui affiche, si ils existent, les combinaisons de trajets qui ont comme ville de depart d et comme ville d'arrivé a
    // et le nombre de combinaison de trajets qui respecte cette condition
    int rechercherParcourV2(const char* d, const char* a) const;
    
private:
    //Affiche combinaisons possibles de trajets avec ville de depart d et ville d'arrivé a,
    //en commancant avec le trajet j
    //en ch est stocké la description des trajet d'avant qui forme la combinaison
    int nbrTrajet(const char* d, const char* a, const int j, const char* ch) const;
protected:
    TabDynamique trajets;
    
};

#endif /* Catalogue_hpp */

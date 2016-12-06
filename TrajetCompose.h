#if !defined (TrajetCompose_H)
#define TrajetCompose_H

#include "Trajet.hpp"
#include "TrajetSimple.hpp"
#include "TabDynamique.hpp"

class TrajetCompose: public Trajet
{
public:
    //Constructeur qui prends comme parametre un tableau dynamique de trajets
    TrajetCompose(const TabDynamique* listeDeTrajets);

    // Constructeur par copie
    TrajetCompose( TrajetCompose const &t);

    // Methode qui renvoie la ville de depart d'un trajet
    const char* getDepart() const;

    // Methode qui renvoie la ville d'arrivée d'un trajet
    const char* getArrivee() const;

    // Methode virtuelle qui renvoie une description d'un trajet simple
    virtual const char* description() const;

    //Destructeur de la classe
    virtual ~TrajetCompose();
    
    
protected:
    //Le tableau dynamique de trajets qui forment le trajet composé
    TabDynamique trajets;
};
#endif

#ifndef TrajetSimple_hpp
#define TrajetSimple_hpp

#include "Trajet.hpp"
#include <iostream>

class TrajetSimple: public Trajet
{
public:
    // Constructeur par défaut
    TrajetSimple(const char* d = "", const char* a = "", const char* t = "");

    //Constructeur par copie
    TrajetSimple(TrajetSimple const &t);

    //Destructeur
    virtual ~TrajetSimple();

    // Une methode virtuelle qui renvoie une description d'un trajet simple
    virtual const char* description() const;

    // Une methode qui renvoie la ville de depart d'un trajet
    const char* getDepart() const;

    // Une methode qui renvoie la ville d'arrivée d'un trajet
    const char* getArrivee() const;
    
protected:
    // Le moyenne de transport pour efectuer le trajet
    const char* transport;

    // La ville de depart
    const char* depart;

    //La ville d'arrivée
    const char* arrivee;
};

#endif /* TrajetSimple_hpp */

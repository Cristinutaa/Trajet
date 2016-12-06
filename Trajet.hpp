
#ifndef Trajet_hpp
#define Trajet_hpp

#include <iostream>

class Trajet
{
public:
    // Le constructeur et le destructeur des trajets
    Trajet();
    virtual ~Trajet();

    // Methode virtuelle pure qui renvoie la description d'un trajet
    virtual const char* description() const = 0;

    // Methode virtuelle pure qui renvoie la ville de depart d'un trajet
    virtual const char* getDepart() const = 0;

    // Methode virtuelle pure qui renvoie la ville d'arrivée d'un trajet
    virtual const char* getArrivee() const = 0;
    
};
#endif /* Trajet_hpp */

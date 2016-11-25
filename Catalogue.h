//
//  Catalogue.hpp
//  TP2-POO1
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#ifndef Catalogue_hpp
#define Catalogue_hpp

#include <iostream>
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

class Catalogue
{
public:
    Catalogue();
    virtual ~Catalogue();
    void afficherTrajet() const;
    Trajet* ajouterTrajet(Trajet* const t);
    void rechercherParcour(char* d, char* a) const;

private:
    void reallouer();
protected:
    const Trajet** liste;
    int alloue;
    int utilise;

};

#endif /* Catalogue_hpp */

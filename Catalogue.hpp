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
#include "Trajet.hpp"
#include "TabDynamique.hpp"

class Catalogue
{
public:
    Catalogue();
    virtual ~Catalogue();
    void afficherTrajet() const;
    const Trajet* ajouterTrajet(const Trajet* t);
    void rechercherParcourV1(const char* d, const char* a) const;
    void rechercherParcourV2(const char* d, const char* a) const;
    
private:
    void reallouer();
protected:
    TabDynamique trajets;
    
};

#endif /* Catalogue_hpp */

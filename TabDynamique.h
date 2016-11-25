//
//  TabDynamique.hpp
//  TP2-POO1
//
//  Created by Justin Gally on 25/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#ifndef TabDynamique_hpp
#define TabDynamique_hpp

#include "Trajet.h"
#include <stdio.h>

class TabDynamique
{public:
    TabDynamique(int max = 5);
    TabDynamique(int max, int taille, const Trajet** t);
    virtual ~TabDynamique();
    const Trajet* ajouter(const Trajet* t);
    const Trajet* get(int i) const;
    int nbElement() const;

private:
    void reallouer();

protected:
    int alloue;
    int utilise;
    const Trajet** trajets;

};

#endif /* TabDynamique_hpp */

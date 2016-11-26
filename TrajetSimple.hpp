//
//  TrajetSimple.hpp
//  TP2-POO1
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#ifndef TrajetSimple_hpp
#define TrajetSimple_hpp

#include "Trajet.hpp"
#include <iostream>

class TrajetSimple: public Trajet
{
public:
    TrajetSimple(const char* d = "", const char* a = "", const char* t = "");
    TrajetSimple(TrajetSimple const &t);
    virtual ~TrajetSimple();
    virtual const char* description() const;
    const char* getDepart() const;
    const char* getArrivee() const;
    
protected:
    const char* transport;
    const char* depart;
    const char* arrivee;
};

#endif /* TrajetSimple_hpp */

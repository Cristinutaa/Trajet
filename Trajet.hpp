//
//  Trajet.hpp
//  TP2-POO1
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#ifndef Trajet_hpp
#define Trajet_hpp

#include <iostream>

class Trajet
{
public:
    Trajet();
    virtual ~Trajet();
    virtual const char* description() const = 0;
    virtual const char* getDepart() const = 0;
    virtual const char* getArrivee() const = 0;
    
};
#endif /* Trajet_hpp */

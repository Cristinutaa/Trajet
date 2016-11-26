//
//  TrajetSimple.cpp
//  TP2-POO1
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#include "TrajetSimple.hpp"

using namespace std;

TrajetSimple::TrajetSimple(const char* d, const char* a, const char* t): depart(d), arrivee(a), transport(t)
{
    //cout << "Constructeur Trajet Simple" << endl;
}

TrajetSimple::TrajetSimple(TrajetSimple const &t): Trajet(), transport(t.transport)
{
    //cout << "Constructeur Trajet Simple de copie" << endl;
}

const char* TrajetSimple::getDepart() const
{
    return depart;
}

const char* TrajetSimple::getArrivee() const
{
    return arrivee;
}

TrajetSimple::~TrajetSimple()
{
   // cout << "Destructeur Trajet Simple Normale" << endl;
}

const char* TrajetSimple::description() const
{
    char* res = new char[255];
    return strcat(strcat(strcat(strcat(strcat(strcat(res, "De "), depart), " à "), arrivee), " en "), transport);
}

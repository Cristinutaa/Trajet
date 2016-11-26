//
//  TabDynamique.cpp
//  TP2-POO1
//
//  Created by Justin Gally on 25/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#include "TabDynamique.hpp"

using namespace std;

TabDynamique::TabDynamique(int max)
{
    alloue = max;
    utilise = 0;
    trajets = new const Trajet*[alloue];
    //cout << "Constructeur de TabDynamique avec une liste de taille "  << alloue << " avec " << utilise << " éléments !" << endl;
}

TabDynamique::TabDynamique(int max, int taille, const Trajet** liste):alloue(max), utilise(taille), trajets(liste)
{
    //cout << "Constructeur de TabDynamique avec une liste de taille "  << alloue << " avec " << utilise << " éléments !" << endl;
}

TabDynamique::~TabDynamique()
{
    //cout << "Destructeur de TabDynamique avec une liste de taille "  << alloue << " avec " << utilise << " éléments !"  << endl;
    for(int i = 0; i < utilise; i++)
    {
        delete trajets[i];
    }
    delete[] trajets;
}

const Trajet* TabDynamique::ajouter(const Trajet* t)
{
    if(utilise == alloue){
        reallouer();
    }
    trajets[utilise] = t;
    return trajets[utilise++];
}

void TabDynamique::reallouer()
{
    const Trajet** l = new const Trajet*[utilise*2];
    for(int i = 0; i < utilise; i++)
    {
        l[i] = trajets[i];
    }
    delete[] trajets;
    trajets = l;
    alloue = utilise*2;
}

const Trajet* TabDynamique::get(int i) const
{
    return trajets[i];
}

int TabDynamique::nbElement() const
{
    return utilise;
}

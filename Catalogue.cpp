//
//  Catalogue.cpp
//  TP2-POO1
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#include "Catalogue.h"

using namespace std;
Catalogue::Catalogue()
{
    cout << "Constructeur de Catalogue" << endl;
    utilise = 0;
    alloue = 5;
    liste = new const Trajet*[alloue];
};

Catalogue::~Catalogue()
{
    cout << "Destructeur de Catalogue" << endl;
    for(int i = 0; i < utilise; i++)
    {
        delete liste[i];
    }
    delete[] liste;
};

void Catalogue::afficherTrajet() const
{

    cout << "Le catalogue contient " << utilise << " trajet(s) :" << endl;
    for(int i = 0; i < utilise; i++)
    {
        cout << "- ";
        (*liste[i]).description();
        cout << endl;
    }
}

void Catalogue::reallouer()
{
    const Trajet** l = new const Trajet*[utilise*2];
    for(int i = 0; i < utilise; i++)
    {
        l[i] = liste[i];
        delete liste[i];
    }
    delete[] liste;
    liste = l;
    alloue = utilise*2;
}

Trajet* Catalogue::ajouterTrajet(Trajet* const t)
{
    if(utilise == alloue){
        reallouer();
    }
    liste[utilise] = t;
    utilise++;
    return t;
}

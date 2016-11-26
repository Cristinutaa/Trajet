//
//  Catalogue.cpp
//  TP2-POO1
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#include "Catalogue.hpp"

using namespace std;
Catalogue::Catalogue()
{
    cout << "Constructeur de Catalogue" << endl;
};

Catalogue::~Catalogue()
{
    cout << "Destructeur de Catalogue" << endl;
};

void Catalogue::afficherTrajet() const
{
    
    cout << "Le catalogue contient " << trajets.nbElement() << " trajet(s) :" << endl;
    
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        cout << "- ";
        (*trajets.get(i)).description();
        cout << endl;
    }
}

void Catalogue::rechercherParcourV1(const char* d, const char* a) const
{
    int cpt = 0;
    cout << "Recherche de niveau 1 pour les trajets au départ de " << d << " arrivant à " << a << " : " << endl;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(strcmp(trajets.get(i)->getDepart(), d) == 0 && strcmp(trajets.get(i)->getArrivee(), a) == 0)
        {
            cout << "- ";
            trajets.get(i)->description();
            cout << endl;
            cpt ++;
        }
    }
    cout << cpt << " trajet(s) trouvé(s) !" << endl;
}

const Trajet* Catalogue::ajouterTrajet(const Trajet* t)
{
    return trajets.ajouter(t);
}

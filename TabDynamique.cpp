#include "TabDynamique.hpp"
#include <stdio.h>

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
    if(i < utilise && i >= 0)
        return trajets[i];
    else
        return NULL;
}

int TabDynamique::nbElement() const
{
    return utilise;
}

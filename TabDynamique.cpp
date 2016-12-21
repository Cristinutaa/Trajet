/*************************************************************************
TabDynamique  -  Classe representant un tableau dynamique de trajets
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/


//---------- Réalisation de la classe <TabDynamique> (fichier TabDynamique.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;


//-------------------------------------------------------- Include personnel
#include "TabDynamique.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const Trajet* TabDynamique::ajouter(const Trajet* t)
// Algorithme :
//
{
    if(utilise == alloue){
        reallouer();
    }
    trajets[utilise] = t;
    return trajets[utilise++];
} //----- Fin de ajouter


void TabDynamique::reallouer()
// Algorithme :
//
{
    const Trajet** l = new const Trajet*[utilise*2];
    for(int i = 0; i < utilise; i++)
    {
        l[i] = trajets[i];
    }
    delete[] trajets;
    trajets = l;
    alloue = utilise*2;
} //----- Fin de reallouer


const Trajet* TabDynamique::get(int i) const
// Algorithme :
//
{
    if(i < utilise && i >= 0)
        return trajets[i];
    else
        return nullptr;
} //----- Fin de get


int TabDynamique::nbElement() const
// Algorithme :
//
{
    return utilise;
} //----- Fin de nbElement


//------------------------------------------------- Surcharge d'opérateurs
TabDynamique & TabDynamique::operator = ( const TabDynamique & t )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de l'operateur = de TabDynamique" << endl;
#endif
    for(int i = 0; i < utilise; i++)
    {
        delete trajets[i];
    }
    delete[] trajets;
    
    alloue = t.alloue;
    utilise = t.utilise;
    trajets = t.trajets;
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur


TabDynamique::TabDynamique(int max)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur de TabDynamique avec une liste de taille "  << max << " avec " << 0 << " éléments !" << endl;
#endif
    
    alloue = max;
    utilise = 0;
    trajets = new const Trajet*[alloue];
} //----- Fin de TabDynamique


TabDynamique::TabDynamique(int taille, const Trajet** liste):alloue(taille), utilise(taille), trajets(liste)
// Algotithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur avec liste de TabDynamique avec une liste de taille "  << alloue << " avec " << utilise << " éléments !" << endl;
#endif
} //----- Fin de TabDynamique


TabDynamique::TabDynamique(const TabDynamique & t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur de copie de TabDynamique" << endl;
#endif
} //----- Fin de TabDynamique (constructeur de copie)


TabDynamique::~TabDynamique()
// Algorithme :
//
{
#ifdef MAP
    cout << "Destructeur de TabDynamique avec une liste de taille "  << alloue << " avec " << utilise << " éléments !"  << endl;
#endif
    for(int i = 0; i < utilise; i++)
    {
        delete trajets[i];
    }
    delete[] trajets;
} //----- Fin de ~TabDynamique


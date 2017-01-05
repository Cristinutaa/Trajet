/*************************************************************************
 TrajetSimple  -  Classe representant un trajet simple
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Realisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;


//-------------------------------------------------------- Include personnel
#include "TrajetSimple.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* TrajetSimple::getDepart() const
// Algorithme :
//
{
    return depart;
} //----- Fin de getDepart


const char* TrajetSimple::getArrivee() const
// Algorithme :
//
{
    return arrivee;
} //----- Fin de getArrivee


const char TrajetSimple::getType() const
{
    return 'S';
}


const char* TrajetSimple::getMoyenDeTransport() const
{
    return transport;
}


void TrajetSimple::ecrireTrajet(string c) const
{
    ofstream fichier;
    fichier.open(("Documents/Programmation/Trajet/Trajet/export/"+c).c_str(), ios::out | ios::app);
    if(fichier.is_open())
    {
        fichier << "S#" << depart << '#' << arrivee << '#' << transport << endl;
    }
    else
        cout << "Impossible d'ouvrire " << c << endl;
    
    fichier.close();
}

const char* TrajetSimple::description() const
// Algorithme :
//
{
    char* res = new char[2000];
    strcpy(res, "");
    return strcat(strcat(strcat(strcat(strcat(strcat(res ,"De ") , depart), " à "), arrivee), " en "), transport);
} //----- Fin de description


//------------------------------------------------- Surcharge d'opérateurs
TrajetSimple & TrajetSimple::operator = ( const TrajetSimple & t )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de l'operateur = de TrajetSimple" << endl;
#endif
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const char* d, const char* a, const char* t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur de TrajetSimple" << endl;
#endif
    transport = new char[255];
    depart = new char[255];
    arrivee = new char[255];
    
    strcpy(transport, t);
    strcpy(depart, d);
    strcpy(arrivee, a);
    
} //----- Fin de TrajetSimple

TrajetSimple::TrajetSimple(TrajetSimple const &t)
{
#ifdef MAP
    cout << "Appel du constructeur de copie de TrajetSimple" << endl;
#endif
    transport = new char[255];
    depart = new char[255];
    arrivee = new char[255];
    
    strcpy(transport, t.transport);
    strcpy(depart, t.depart);
    strcpy(arrivee, t.arrivee);
    
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple()
{
#ifdef MAP
    cout << "Appel du destructeur de TrajetSimple" << endl;
#endif
    
    delete[] transport;
    delete [] arrivee;
    delete [] depart;
} //----- Fin de ~TrajetSimple

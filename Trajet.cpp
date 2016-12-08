/*************************************************************************
 Trajet  -  Classe representant un trajet
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/


//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;


//-------------------------------------------------------- Include personnel
#include "Trajet.h"

//------------------------------------------------- Surcharge d'opérateurs
Trajet & Trajet::operator = ( const Trajet & t )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de l'operateur = de Trajet" << endl;
#endif
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur de Trajet" << endl;
#endif
} //----- Fin de Trajet


Trajet::Trajet(const Trajet & t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur de copie de Trajet" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)


Trajet::~Trajet()
// Algorithme :
//
{
#ifdef MAP
    cout << "Destructeur de Trajet" << endl;
#endif
} //----- Fin de ~Trajet

/*************************************************************************
 TrajetCompose  -  Classe representant un trajet compose
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Realisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;


//-------------------------------------------------------- Include personnel
#include "TrajetCompose.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
const char* TrajetCompose::getDepart() const
// Algorithmie :
//
{
    return (*trajets.get(0)).getDepart();
} //----- Fin de getDepart


const char* TrajetCompose::getArrivee() const
// Algorithme :
//
{
    return (*trajets.get(trajets.nbElement()-1)).getArrivee();
} //----- Fin de getArrivee


const char TrajetCompose::getType() const
{
    return 'C';
}


const char* TrajetCompose::description() const
// Algorithme :
//
{
    char* res = new char[2000];
    strcpy(res, "");
    for(int i = 0; i<trajets.nbElement(); i++){
        
        strcat(res, trajets.get(i)->description());
        if(i < trajets.nbElement() -1)
            strcat(res, " - ");
    }
    return res;
} //----- Fin de description

void TrajetCompose::ecrireTrajet(string c) const
{
    ofstream fichier;
    fichier.open("Documents/Programmation/Trajet/Trajet/"+c, ios::out | ios::app);
    if(fichier.is_open())
    {
        fichier << 'C' << trajets.nbElement() << '#' << getDepart() << '#' << getArrivee() << '#' ;
        for(int i = 0; i < trajets.nbElement() - 1; i++)
        {
            if(trajets.get(i)->getType() == 'S')
                fichier << trajets.get(i)->getArrivee() << '#' << (static_cast<const TrajetSimple*>(trajets.get(i)))->getMoyenDeTransport() << '#';
            else
                fichier << trajets.get(i)->getArrivee() << "#-#";
        }
        if(trajets.get(trajets.nbElement() - 1)->getType() == 'S')
            fichier << (static_cast<const TrajetSimple*>(trajets.get(trajets.nbElement() - 1)))->getMoyenDeTransport() << endl;
        else
            fichier << '-' << endl;
    }
    else
        cout << "Impossible d'ouvrire " << c << endl;
    
    fichier.close();
}


//------------------------------------------------- Surcharge d'opérateurs
TrajetCompose & TrajetCompose::operator = ( const TrajetCompose & t )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de l'operateur = de TrajetComposé" << endl;
#endif
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const TabDynamique* listeDeTrajets)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de constructeur de TrajetComposé" << endl;
#endif
    trajets = *listeDeTrajets;
    
} //----- Fin de TrajetCompose


TrajetCompose::TrajetCompose( TrajetCompose const &t)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur de copie de TrajetComposé" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)


TrajetCompose::~TrajetCompose()
// Algorithme :
//
{
#ifdef MAP
   cout << "Appel de destructeur de TrajetCompose " << endl;
#endif
} //----- Fin de ~TrajetCompose

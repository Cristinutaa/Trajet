/*************************************************************************
 Catalogue  -  Classe representant le catalogue de trajets
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/


//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <cstring>
#include <iostream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::afficherTrajet() const
// Algorithme :
//
{
    cout << "Le catalogue contient " << trajets.nbElement() << " trajet(s) :" << endl;
    
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        cout << "- " << (*trajets.get(i)).description() << endl;
    }
} //----- Fin de afficherTrajet


void Catalogue::rechercherParcourV1(const char* d, const char* a) const
// Algorithme :
//
{
    int cpt = 0;
    cout << "Recherche de niveau 1 pour les trajets au départ de " << d << " arrivant à " << a << " : " << endl;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(strcmp(trajets.get(i)->getDepart(), d) == 0 && strcmp(trajets.get(i)->getArrivee(), a) == 0)
        {
            cout << "     - " <<  trajets.get(i)->description() << endl;
            cpt ++;
        }
    }
    cout << cpt << " trajet(s) trouvé(s) !" << endl;
} //----- Fin de rechercheParcourV1


int Catalogue::nbrTrajet(const char* d, const char* a, const int j, const char* ch) const
// Algorithme :
//
{
    // Si le trajet j respecte la condition, affiche-lui et renvoie 1
    if(strcmp(trajets.get(j)->getDepart(), d) == 0 && strcmp(trajets.get(j)->getArrivee(), a) == 0)
    {
        cout << ch << trajets.get(j)->description() << endl;
        return 1;
    }
    // Sinon, si la ville de depart coincide avec celle demandée,
    // essaye de voir si il y a des combinaisons possibles pour arriver dans la ville d'arrivée
    else if(strcmp(trajets.get(j)->getDepart(), d) == 0 )
    {
        int cpt = 0;
        char chemin[255];
        char c[255];
        strcpy(chemin, strcat(strcpy(chemin,ch), strcat(strcpy(c, trajets.get(j)->description()), " + ")));
        for(int i = 0; i < trajets.nbElement(); i++)
        {
            cpt+= nbrTrajet(trajets.get(j)->getArrivee(), a, i, chemin);
            
        }
        
        return cpt;
    }
    // Sinon, renvoie 0
    else
        return 0;
} //----- Fin de nbrTrajet


int Catalogue::rechercherParcourV2(const char* d, const char* a) const
// Algorithme :
//
{
    int cpt = 0;
    const char* res = new char[255];
    res = "     - ";
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        cpt += nbrTrajet(d, a, i, res);
    }
    return cpt;
} //----- Fin de rechercheParcourV2


const Trajet* Catalogue::ajouterTrajet(const Trajet* t)
// Algorithme :
//
{
    return trajets.ajouter(t);
} //----- Fin de ajouterTrajet


//------------------------------------------------- Surcharge d'opérateurs
Catalogue & Catalogue::operator = ( const Catalogue & c )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel de l'operateur = de Catalogue" << endl;
#endif
    return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur par defaut de Catalogue" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::Catalogue(const Catalogue & c)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du constructeur par copie de Catalogue" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)


Catalogue::~Catalogue()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel du destructeur de Catalogue" << endl;
#endif
} //----- Fin de ~Catalogue


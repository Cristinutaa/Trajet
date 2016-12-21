/*************************************************************************
 TrajetSimple  -  Classe representant un trajet simple
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#ifndef TrajetSimple_h
#define TrajetSimple_h


//--------------------------------------------------- Interfaces utilisées
#include <string.h>
#include "Trajet.h"
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
//
// Cette classe represente un trajets simple du catalogue.
//
//
//------------------------------------------------------------------------


class TrajetSimple: public Trajet
{
//----------------------------------------------------------------- PUBLIQUE
public:
    
    //----------------------------------------------------- Méthodes publiques

    
    const char* getDepart() const;
    // Description :
    //      Cette methode renvoie la ville de depart du trajet composé.
    
    
    const char* getArrivee() const;
    // Description :
    //      Cette methode renvoie la ville d'arrivée du trajet composé.
    
    const char* getMoyenDeTransport() const;
    
    virtual const char getType() const;
    
    virtual void ecrireTrajet(string c) const;
    
    
    virtual const char* description() const;
    // Description :
    //      Cette methode affiche le trajet composé.
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    TrajetSimple & operator = ( const TrajetSimple & t );
    // Description :
    //      Surcharge de l'opérateur égale.
    
    
    //-------------------------------------------- Constructeurs - destructeur
    
    
    TrajetSimple(const char* d = "", const char* a = "", const char* t = "");
    // Description :
    //      Constructeur par défaut.
    // Mode d'emploi :
    //      Faire passer en parametre la ville de départ, celle d'arrivée et le moyen de transport utilisé.
    
    
    TrajetSimple(TrajetSimple const &t);
    // Description :
    //      Constructeur par copie.
    // Mode d'emploi :
    //      Faire passer en argument le trajet simple que vous souhaitez copier.
    
    
    virtual ~TrajetSimple();
    // Description :
    //      Destructeur de la classe trajet simple.
    

//------------------------------------------------------------------ PROTEGE
protected:
    
    //----------------------------------------------------- Attributs protégés
    
    
    char* transport;
    // Description :
    //      Cet atribut est le moyen de transport pour efectuer le trajet simple.

    
    char* depart;
    // Description :
    //      Cet atribut est la ville de depart du trajet simple.

    
    char* arrivee;
    // Description :
    //      Cet atribut est la ville d'arrivée du trajet simple.
    
    
};

#endif // TrajetSimple_h

/*************************************************************************
 TrajetCompose  -  Classe representant un trajet compose
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if ! defined (TrajetCompose_h)
#define TrajetCompose_h


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabDynamique.h"
#include <string.h>
using namespace std;


//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
//
// Cette classe represente un trajets compose du catalogue.
//
//
//------------------------------------------------------------------------


class TrajetCompose: public Trajet
{
//----------------------------------------------------------------- PUBLIQUE
public:
    
    //----------------------------------------------------- Méthodes publiques
    
    
    virtual const char* getDepart() const;
    // Description :
    //      Cette methode renvoie la ville de depart du trajet composé.

    
    virtual const char* getArrivee() const;
    // Description :
    //      Cette methode renvoie la ville d'arrivée du trajet composé.
    
    
    
    virtual const char* description() const;
    // Description :
    //      Cette methode renvoi le trajet composé.
    
    virtual void ecrireTrajet(string c) const;
    
    virtual const char getType() const;
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    TrajetCompose & operator = ( const TrajetCompose & t );
    // Description :
    //      Surcharge de l'opérateur égale.
    
    
    //-------------------------------------------- Constructeurs - destructeur

    
    TrajetCompose(const TabDynamique* listeDeTrajets);
    // Description :
    //      Constructeur par défaut.
    // Mode d'emploi :
    //      Faire passer en paramètre un tableau dynamique referencant la liste des trajets composant ce trajet dynamique.
    
    
    TrajetCompose( TrajetCompose const &t);
    // Description :
    //      Constructeur par copie.
    // Mode d'emploi :
    //      Faite passer en parametre le trajet composé que vous voulez copier.
    
    
    virtual ~TrajetCompose();
    // Desription :
    //      Destructeur par defaut.
    
    
//------------------------------------------------------------------ PROTEGE
protected:
    
    //----------------------------------------------------- Attributs protégés
    
    
    TabDynamique trajets;
    // Description :
    //      Cet attribut est le tableau dynamique des trajets qui forment le trajet composé
};
#endif // TrajetCompose_h

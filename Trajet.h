/*************************************************************************
 Trajet  -  Classe representant un trajet
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.hpp) ----------------
#if ! defined (Trajet_h)
#define Trajet_h


#include <string.h>
using namespace std;

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//  Classe mère des classes TrajetSimple et TrajetCompose.
//
//------------------------------------------------------------------------


class Trajet
{
//----------------------------------------------------------------- PUBLIQUE
public:
    
    //----------------------------------------------------- Méthodes publiques
    
    
    virtual const char* description() const = 0;
    // Description :
    //      Methode virtuelle pure qui renvoie la description d'un trajet.

    
    virtual const char* getDepart() const = 0;
    // Description :
    //      Methode virtuelle pure qui renvoie la ville de depart d'un trajet.

    
    virtual const char* getArrivee() const = 0;
    // Description :
    //      Methode virtuelle pure qui renvoie la ville d'arrivée d'un trajet
    
    
    virtual void ecrireTrajet(string c) const = 0;
    
    virtual const char getType() const = 0;
    //------------------------------------------------- Surcharge d'opérateurs
    Trajet & operator = ( const Trajet & t );
    // Description :
    //      Surcharge de l'opérateur égale.
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Trajet();
    // Description :
    //      Constructeur par défaut d'un trajet.
    
    Trajet(const Trajet & t);
    // Description :
    //      Constructeur de copie de trajet.
    // Mode d'emploi :
    //      Faite passer en parametre le trajet que vous voulez copier.
    
    
    virtual ~Trajet();
    // Description :
    //      Destructeur d'un trajet.
    
    
};
#endif // Trajet_h

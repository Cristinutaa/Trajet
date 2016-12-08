/*************************************************************************
 TabDynamique  -  Classe representant un tableau dynamique de trajets
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <TabDynamique> (fichier TabDynamique.hpp) ----------------
#if ! defined (TabDynamique_h)
#define TabDynamique_h


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"


//------------------------------------------------------------------------
// Rôle de la classe <TabDynamique>
//
// Cette classe gère l'allocation mémoire d'un tableau de trajets.
//
//
//------------------------------------------------------------------------


class TabDynamique
{
//----------------------------------------------------------------- PUBLIQUE
public:
    
    //----------------------------------------------------- Méthodes publiques
    
    
    const Trajet* ajouter(const Trajet* t);
    // Description :
    //      Methode qui permet l'ajout d'un trajet dans le tableau.
    // Mode d'emploi :
    //      Faire passer en parametre le pointeur vers le trajet que vous souhaitez ajouter au tableau.

    
    const Trajet* get(int i) const;
    // Description :
    //      Methode qui renvoie le trajet qui est situé à la position i du tableau.
    // Mode d'emploi :
    //      Faire passer en parametre la position du trajet recherché.

    
    int nbElement() const;
    // Description :
    //      Methode qui renvoie le nombre d'elements dans le tableau.
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    TabDynamique & operator = ( const TabDynamique & tab );
    // Description :
    //      Surcharge de l'opérateur égale.
    
    
    //-------------------------------------------- Constructeurs - destructeur
    TabDynamique(int max = 5);
    // Description :
    //      Constructeur par défaut qui met la valeur des cases allouées à max si une valeur est introduite et à 5 sinon.
    // Mode d'emploi :
    //      Entrer la valeur maximum que vous souhaitez allouer au tableau.
    // Contrat :
    //      max doit être positif.
    
    
    TabDynamique(int taille, const Trajet** t);
    // Description :
    //      Constructeur qui prends comme parametres: taille - le nombre de cases utilisées
    //      et un tableau de pointeurs de trajet.
    // Mode d'emploi :
    //      Entrer la valeur maximum que vous souhaitez allouer au tableau, la taille du tableau de pointeurs de trajets t
    //      ainsi que ce même tableau t.
    // Contrat :
    //      La taille passée en parametre doit correspondre au nombre de pointeurs définit dans le tableau de pointeurs
    //      de trajets t.
    
    
    TabDynamique(const TabDynamique & tab);
    // Description :
    //      Constructeur de copie.
    // Mode d'emploi :
    //      Faite passer en parametre le tableau dynamique de trajets que vous voulez copier.
    
    
    virtual ~TabDynamique();
    // Description :
    //      Destructeur de la classe.

    
//------------------------------------------------------------------ PRIVE
private:
    
    //----------------------------------------------------- Méthodes privées
    
    
    void reallouer();
    // Description :
    //      Methode qui augmente le nombre de cases mémoires allouées pour le tableau dynamique.
    
    
//------------------------------------------------------------------ PROTEGE
protected:
    
    //----------------------------------------------------- Attributs protégés
    
    
    int alloue;
    // Description :
    //      Le nombre de cases allouées pour le tableau.

    
    int utilise;
    // Description :
    //      Le nombre de cases utilisées.

    
    const Trajet** trajets;
    // Description :
    //      Le tableau de trajets.
    
    
};

#endif // TabDynamique_hpp

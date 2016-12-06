/*************************************************************************
 Catalogue  -  Classe representant le catalogue de trajets
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.hpp) ----------------
#if ! defined (Catalogue_hpp)
#define Catalogue_hpp


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.hpp"
#include "TabDynamique.hpp"


//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//  Cette classe stock tout les trajets enregistrer et recherche les trajets possibles.
//
//
//------------------------------------------------------------------------


class Catalogue
{
//----------------------------------------------------------------- PUBLIQUE
public:
    
    //----------------------------------------------------- Méthodes publiques
    
    void afficherTrajet() const;
    // Description :
    //      Methode pour afficher les trajets du catalogue.

    
    const Trajet* ajouterTrajet(const Trajet* t);
    // Description :
    //      Methode pour ajouter un trajet au catalogue
    // Mode d'emploi :
    //      Faire passer en parametre le pointeur vers le trajet que vous souhaitez ajouter au catalogue.
    
    void rechercherParcourV1(const char* d, const char* a) const;
    // Description :
    //      Methode qui affiche, si ils existent, les trajets qui ont comme ville de depart d et comme ville d'arrivé a
    //      et le nombre de trajets trouvés.
    // Mode d'emploi :
    //      Faite passer en parametre le lieu de départ et d'arriver correspondant à votre recherche.
    // Contrat :
    //      Les lieux passés en parametre devront respecter la casse des lieux rentré lors de la saisie des trajets.


    int rechercherParcourV2(const char* d, const char* a) const;
    // Description :
    //      Methode qui affiche, si ils existent, les combinaisons de trajets qui ont comme ville de depart d et comme ville d'arrivé a
    //      et le nombre de trajets trouvés.
    // Mode d'emploi :
    //      Faite passer en parametre le lieu de départ et d'arriver correspondant à votre recherche.
    // Contrat :
    //      Les lieux passés en parametre devront respecter la casse des lieux rentré lors de la saisie des trajets.

    
    //------------------------------------------------- Surcharge d'opérateurs
    Catalogue & operator = ( const Catalogue & c );
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Description :
    //      Constructeur par defaut.
    
    
    Catalogue ( const Catalogue & c );
    // Description :
    //      Constructeur de copie.
    // Mode d'emploi :
    //      Faite passer en parametre le Catalogue que vous voulez copier.
    
    
    virtual ~Catalogue();
    // Description :
    //      Destructeur.
    
//------------------------------------------------------------------ PRIVE
private:
    
    //----------------------------------------------------- Méthodes privées
    
    int nbrTrajet(const char* d, const char* a, const int j, const char* ch) const;
    // Description :
    //      Affiche la combinaisons possibles de trajets au depart de d et arrivant en a, en commancant par le trajet situé à la position j
    // Mode d'emploi :
    //      Faite passer en parametre le lieu de départ et d'arriver correspondant à votre recherche, la position de depart souhaité ainsi
    //      que l'ensemble des trajets composant la combinaison antérieure.
    // Contrat :
    //      L'entier j devra être inférieur à la taille du tableau de trajet.
    
    
//------------------------------------------------------------------ PROTEGE
protected:
    
    //----------------------------------------------------- Attributs protégés
    
    TabDynamique trajets;
    
};

#endif // Catalogue_hpp

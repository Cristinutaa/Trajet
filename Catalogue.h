/*************************************************************************
 Catalogue  -  Classe representant le catalogue de trajets
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.hpp) ----------------
#if ! defined (Catalogue_h)
#define Catalogue_h


//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TabDynamique.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <cstring>
using namespace std;


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
    
    
    void chargementTotal(string chemin);
    // Description :
    //      Methode pour lire un fichier à l'adresse donné.
    // Mode d'emploi :
    //      Passez en paramettre le chemin d'acces au fichier.
    
    
    void chargementType(string chemin, char type);
    void chargementVilleD(string chemin, string depart);
    void chargementVilleA(string chemin, string arrivee);
    void chargementVilleDA(string chemin, string depart, string arrivee);
    void chargementIntervalle(string chemin, int n, int m);
    
    string getInfo(string ligne, int id) const;
    
    
    void sauvegardeTotal(string chemin) const;
    void sauvegardeType(string chemin, char type) const;
    void sauvegardeVilleD(string chemin, string depart) const;
    void sauvegardeVilleA(string chemin, string arrivee) const;
    void sauvegardeVilleDA(string chemin, string depart, string arrivee) const;
    void sauvegardeIntervalle(string chemin, int n, int m) const;
    
    
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
    // Description :
    //      Surcharge de l'opérateur égale.
    
    
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

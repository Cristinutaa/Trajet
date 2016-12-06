#include "Catalogue.hpp"
#include <cstring>

using namespace std;
Catalogue::Catalogue()
{
    //cout << "Constructeur de Catalogue" << endl;
};

Catalogue::~Catalogue()
{
    //cout << "Destructeur de Catalogue" << endl;
};

void Catalogue::afficherTrajet() const
{
    
    cout << "Le catalogue contient " << trajets.nbElement() << " trajet(s) :" << endl;
    
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        cout << "- " << (*trajets.get(i)).description() << endl;
    }
}

void Catalogue::rechercherParcourV1(const char* d, const char* a) const
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
}

int Catalogue::nbrTrajet(const char* d, const char* a, const int j, const char* ch) const
{
    // Si le trajet j respecte la condition, affiche-lui et renvoie 1 - le nombre de trajets;
    if(strcmp(trajets.get(j)->getDepart(), d) == 0 && strcmp(trajets.get(j)->getArrivee(), a) == 0)
    {
        cout << ch << trajets.get(j)->description() << endl;
        return 1;
    }
    // Sinon, mais si la ville de depart coincide avec celle demandé,
    // essaye de voir si il y a des combinaisons possibles pour arriver dans la ville d'arrivée
    // Si il y a, affiche le trajets et renvoie leur nombre
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
}

int Catalogue::rechercherParcourV2(const char* d, const char* a) const
{
    int cpt = 0;
    const char* res = new char[255];
    res = "     - ";
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        cpt += nbrTrajet(d, a, i, res);
    }
    return cpt;
}

const Trajet* Catalogue::ajouterTrajet(const Trajet* t)
{
    return trajets.ajouter(t);
}

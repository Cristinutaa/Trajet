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
#include <fstream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Catalogue.h"


//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const string chemin = "Documents/Programmation/Trajet/Trajet/import/";

bool Catalogue::isEmpty() const
{
    return (trajets.nbElement() == 0);
}

void Catalogue::afficherTrajet() const
// Algorithme :
//
{
    cout << "Le catalogue contient " << trajets.nbElement() << " trajet(s) :" << endl;
    
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        cout << "-  " << trajets.get(i)->description() << endl;
    }
    cout << "\r\n" << endl;
} //----- Fin de afficherTrajet


void Catalogue::sauvegardeTotal(string chemin) const
{
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        trajets.get(i)->ecrireTrajet(chemin);
    }
    cout << "Exportation terminée, "<< trajets.nbElement() << " trajet(s) exporté(s)\r\n" << endl;
}


void Catalogue::sauvegardeType(string chemin, char type) const
{
    int cpt = 0;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(trajets.get(i)-> getType() == type)
        {
            trajets.get(i)->ecrireTrajet(chemin);
            cpt++;
        }
    }
    cout << "Exportation terminée, "<< cpt << " trajet(s) exporté(s)\r\n" << endl;
}


void Catalogue::sauvegardeVilleD(string chemin, string depart) const
{
    int cpt = 0;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(strcmp(trajets.get(i)-> getDepart(),depart.c_str()) == 0)
        {
            trajets.get(i)->ecrireTrajet(chemin);
            cpt++;
        }
    }
    
}


void Catalogue::sauvegardeVilleA(string chemin, string arrivee) const
{
    int cpt = 0;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(strcmp(trajets.get(i)-> getArrivee(),arrivee.c_str()) == 0)
        {
            trajets.get(i)->ecrireTrajet(chemin);
            cpt++;
        }
    }
    cout << "Exportation terminée, "<< cpt << " trajet(s) exporté(s)\r\n" << endl;
}


void Catalogue::sauvegardeVilleDA(string chemin, string depart, string arrivee) const
{
    int cpt = 0;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(strcmp(trajets.get(i)-> getDepart(),depart.c_str()) == 0 && strcmp(trajets.get(i)-> getArrivee(),arrivee.c_str()) == 0)
        {
            trajets.get(i)->ecrireTrajet(chemin);
            cpt++;
        }
    }
    cout << "Exportation terminée, "<< cpt << " trajet(s) exporté(s)\r\n" << endl;
}


void Catalogue::sauvegardeIntervalle(string chemin, int n, int m) const
{
    int cpt = 0;
    for(int i = 0; i < trajets.nbElement(); i++)
    {
        if(i >= n && i <= m)
        {
            trajets.get(i)->ecrireTrajet(chemin);
            cpt++;
        }
        else if(i > m)
            break;
    }
    cout << "Exportation terminée, "<< cpt << " trajet(s) exporté(s)\r\n" << endl;
}


string Catalogue::getInfo(string ligne, int id) const
// Algorithme :
//
{
    if(id >= 0){
        for(int i = 0; i < id; i++)
        {
            if(ligne.find('#') != string::npos)
            {
                int taille = ligne.substr(0, ligne.find('#') +1).length();
                ligne = ligne.substr(ligne.find('#') + 1, ligne.length()-taille);
            }
            else
            {
                cerr << "Mauvaise valeur de position" << endl;
                ligne = "";
                break;
            }
        }
        if(ligne.find('#') != string::npos)
        {
            ligne = ligne.substr(0,ligne.find('#'));
        }
    }
    else
    {
        cerr << "Mauvaise valeur de position" << endl;
        ligne = "";
    }
    return ligne;
} //----- Fin de getInfo


void Catalogue::chargementIntervalle(string c, int n, int m)
// Algorithme :
//
{
    if(m-n >= 0)
    {
        string line;
        int nbrTrajet;
        ifstream fichier;
        fichier.open((chemin+c).c_str());
        if (fichier.is_open())
        {
            int cpt = 0;
            while ( getline (fichier,line)  && cpt <= m)
            {
                if(cpt >= n)
                {
                    if(line[0] == 'S'){
                        ajouterTrajet(new TrajetSimple(getInfo(line, 1).c_str(), getInfo(line, 2).c_str(), getInfo(line, 3).c_str()));
                        
                        
                    }
                    else if(line[0] == 'C')
                    {
                        nbrTrajet = line[1] - '0';
                        TabDynamique* liste = new TabDynamique(nbrTrajet);
                        string depart = getInfo(line, 1);
                        string arrive, mdt;
                        for(int i = 3; i < (nbrTrajet *2 +1); i+= 2)
                        {
                            arrive = getInfo(line, i);
                            mdt = getInfo(line, i+1);
                            liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                            depart = arrive;
                        }
                        arrive = getInfo(line, 2);
                        mdt = getInfo(line, nbrTrajet*2 + 1);
                        liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                        ajouterTrajet(new TrajetCompose(liste));
                        
                    }
                }
                cpt++;
            }
            
            fichier.close();
            cout << "Importation terminée, voici le nouveau catalogue : \r\n" << endl;
            afficherTrajet();
        }
        else cout << "Unable to open " << c << endl;
    }

} //----- Fin de lire


void Catalogue::chargementVilleDA(string c, string depart, string arrivee)
// Algorithme :
//
{
    string line;
    int nbrTrajet;
    ifstream fichier;
    fichier.open((chemin+c).c_str());
    if (fichier.is_open())
    {
        while ( getline (fichier,line) )
        {
            if(getInfo(line, 1) == depart && getInfo(line, 2) == arrivee)
            {
                if(line[0] == 'S'){
                    ajouterTrajet(new TrajetSimple(getInfo(line, 1).c_str(), getInfo(line, 2).c_str(), getInfo(line, 3).c_str()));
                    
                    
                }
                else if(line[0] == 'C')
                {
                    nbrTrajet = line[1] - '0';
                    TabDynamique* liste = new TabDynamique(nbrTrajet);
                    string depart = getInfo(line, 1);
                    string arrive, mdt;
                    for(int i = 3; i < (nbrTrajet *2 +1); i+= 2)
                    {
                        arrive = getInfo(line, i);
                        mdt = getInfo(line, i+1);
                        liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                        depart = arrive;
                    }
                    arrive = getInfo(line, 2);
                    mdt = getInfo(line, nbrTrajet*2 + 1);
                    liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                    ajouterTrajet(new TrajetCompose(liste));
                    
                }
            }
        }
        
        fichier.close();
        cout << "Importation terminée, voici le nouveau catalogue : \r\n" << endl;
        afficherTrajet();
    }
    else cout << "Unable to open " << c << endl;
    
} //----- Fin de lire


void Catalogue::chargementVilleA(string c, string arrivee)
// Algorithme :
//
{
    string line;
    int nbrTrajet;
    ifstream fichier;
    fichier.open((chemin+c).c_str());
    if (fichier.is_open())
    {
        while ( getline (fichier,line) )
        {
            if(getInfo(line, 2) == arrivee)
            {
                if(line[0] == 'S'){
                    ajouterTrajet(new TrajetSimple(getInfo(line, 1).c_str(), getInfo(line, 2).c_str(), getInfo(line, 3).c_str()));
                    
                    
                }
                else if(line[0] == 'C')
                {
                    nbrTrajet = line[1] - '0';
                    TabDynamique* liste = new TabDynamique(nbrTrajet);
                    string depart = getInfo(line, 1);
                    string arrive, mdt;
                    for(int i = 3; i < (nbrTrajet *2 +1); i+= 2)
                    {
                        arrive = getInfo(line, i);
                        mdt = getInfo(line, i+1);
                        liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                        depart = arrive;
                    }
                    arrive = getInfo(line, 2);
                    mdt = getInfo(line, nbrTrajet*2 + 1);
                    liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                    ajouterTrajet(new TrajetCompose(liste));
                    
                }
            }
        }
        
        fichier.close();
        cout << "Importation terminée, voici le nouveau catalogue : \r\n" << endl;
        afficherTrajet();
    }
    else cout << "Unable to open " << c << endl;
    
} //----- Fin de lire


void Catalogue::chargementVilleD(string c, string depart)
// Algorithme :
//
{
    string line;
    int nbrTrajet;
    ifstream fichier;
    fichier.open((chemin+c).c_str());
    if (fichier.is_open())
    {
        while ( getline (fichier,line) )
        {
            if(getInfo(line, 1) == depart)
            {
                if(line[0] == 'S'){
                    ajouterTrajet(new TrajetSimple(getInfo(line, 1).c_str(), getInfo(line, 2).c_str(), getInfo(line, 3).c_str()));
                    
                    
                }
                else if(line[0] == 'C')
                {
                    nbrTrajet = line[1] - '0';
                    TabDynamique* liste = new TabDynamique(nbrTrajet);
                    string depart = getInfo(line, 1);
                    string arrive, mdt;
                    for(int i = 3; i < (nbrTrajet *2 +1); i+= 2)
                    {
                        arrive = getInfo(line, i);
                        mdt = getInfo(line, i+1);
                        liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                        depart = arrive;
                    }
                    arrive = getInfo(line, 2);
                    mdt = getInfo(line, nbrTrajet*2 + 1);
                    liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                    ajouterTrajet(new TrajetCompose(liste));
                    
                }
            }
        }
        
        fichier.close();
        cout << "Importation terminée, voici le nouveau catalogue : \r\n" << endl;
        afficherTrajet();
    }
    else cout << "Unable to open " << c << endl;
    
} //----- Fin de lire


void Catalogue::chargementType(string c, char type)
// Algorithme :
//
{
    string line;
    int nbrTrajet;
    ifstream fichier;
    fichier.open((chemin+c).c_str());
    if (fichier.is_open())
    {
        while ( getline (fichier,line) )
        {
            if(line[0] == type)
            {
                if(line[0] == 'S'){
                    ajouterTrajet(new TrajetSimple(getInfo(line, 1).c_str(), getInfo(line, 2).c_str(), getInfo(line, 3).c_str()));
                    
                    
                }
                else if(line[0] == 'C')
                {
                    nbrTrajet = line[1] - '0';
                    TabDynamique* liste = new TabDynamique(nbrTrajet);
                    string depart = getInfo(line, 1);
                    string arrive, mdt;
                    for(int i = 3; i < (nbrTrajet *2 +1); i+= 2)
                    {
                        arrive = getInfo(line, i);
                        mdt = getInfo(line, i+1);
                        liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                        depart = arrive;
                    }
                    arrive = getInfo(line, 2);
                    mdt = getInfo(line, nbrTrajet*2 + 1);
                    liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                    ajouterTrajet(new TrajetCompose(liste));
                    
                }
            }
        }
        
        fichier.close();
        cout << "Importation terminée, voici le nouveau catalogue : \r\n" << endl;
        afficherTrajet();
    }
    else cout << "Unable to open " << c << endl;
    
} //----- Fin de lire


void Catalogue::chargementTotal(string c)
// Algorithme :
//
{
    string line;
    int nbrTrajet;
    ifstream fichier;
    fichier.open((chemin+c).c_str());
    if (fichier.is_open())
    {
        while ( getline (fichier,line) )
        {
            if(line[0] == 'S'){
                ajouterTrajet(new TrajetSimple(getInfo(line, 1).c_str(), getInfo(line, 2).c_str(), getInfo(line, 3).c_str()));
                
                
            }
            else if(line[0] == 'C')
            {
                nbrTrajet = line[1] - '0';
                TabDynamique* liste = new TabDynamique(nbrTrajet);
                string depart = getInfo(line, 1);
                string arrive, mdt;
                for(int i = 3; i < (nbrTrajet *2 +1); i+= 2)
                {
                    arrive = getInfo(line, i);
                    mdt = getInfo(line, i+1);
                    liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                    depart = arrive;
                }
                arrive = getInfo(line, 2);
                mdt = getInfo(line, nbrTrajet*2 + 1);
                liste->ajouter(new TrajetSimple(depart.c_str(), arrive.c_str(), mdt.c_str()));
                ajouterTrajet(new TrajetCompose(liste));
            }
        }
        
        fichier.close();
        cout << "Importation terminée, voici le nouveau catalogue : \r\n" << endl;
        afficherTrajet();
    }
    else cout << "Unable to open " << c << endl;
    
} //----- Fin de lire


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
    cout << "Error : Appel de l'operateur = de Catalogue" << endl;
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
    cout << "Error : Appel du constructeur par copie de Catalogue" << endl;
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


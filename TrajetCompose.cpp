#include <iostream>
#include "TrajetCompose.h"

using namespace std;

TrajetCompose::TrajetCompose(const TabDynamique* listeDeTrajets)
{
    //cout << "Constructeur Trajet Composé" << endl;
    trajets = *listeDeTrajets;
    
}

TrajetCompose::TrajetCompose( TrajetCompose const &t):trajets(t.trajets)
{
    //cout << "Constructeur Trajet Composé De copie" << endl;
}

const char* TrajetCompose::getDepart() const
{
    return (*trajets.get(0)).getDepart();
}

const char* TrajetCompose::getArrivee() const
{
    return (*trajets.get(trajets.nbElement()-1)).getArrivee();
}

const char* TrajetCompose::description() const{
    char* res = new char[255];
    for(int i = 0; i<trajets.nbElement(); i++){
        
        strcat(res, (*trajets.get(i)).description());
        if(i < trajets.nbElement() -1)
            strcat(res, " - ");
    }
    return res;
}

TrajetCompose::~TrajetCompose(){
   // cout << "Destructeur Trajet Compose Normale" << endl;
}

#include <iostream>
#include "TrajetCompose.h"

using namespace std;

TrajetCompose::TrajetCompose(int t, TabDynamique listeDeTrajets):taille(t), trajets(listeDeTrajets)
{
    cout << "Constructeur Trajet Composé Normale" << endl;
}

TrajetCompose::TrajetCompose( TrajetCompose const &t): taille(t.taille), trajets(t.trajets)
{
    cout << "Constructeur Trajet Composé De copie" << endl;
}

const char* TrajetCompose::getDepart() const
{
    return (*trajets.get(0)).getDepart();
}

const char* TrajetCompose::getArrivee() const
{
    return (*trajets.get(trajets.nbElement()-1)).getArrivee();
}

void TrajetCompose::description() const{
	for(int i = 0; i<taille; i++){
        (*trajets.get(i)).description();
        cout << " - ";
	}
}

TrajetCompose::~TrajetCompose(){
    cout << "Destructeur Trajet Simple Normale" << endl;
}

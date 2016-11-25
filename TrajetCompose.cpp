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


void TrajetCompose::description() const{
	for(int i = 0; i<taille; i++){
        trajets[i].description();
        cout << " - ";
	}
}

TrajetCompose::~TrajetCompose(){
    cout << "Destructeur Trajet Simple Normale" << endl;
}

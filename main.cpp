//
//  main.cpp
//  TP2-POO1
//
//  Pour le 9/12/2016 avant 14h
//
//  Created by Justin Gally on 18/11/2016.
//  Copyright © 2016 Justin Gally. All rights reserved.
//

#include <iostream>
#include <limits>
#include "Catalogue.h"

using namespace std;

void saut(){
    cout << "\n\n\n\r";
}

int main(int argc, const char * argv[]) {
    
    Catalogue c;
    bool boucle = true;
    int choix;
    while(boucle){  // La boucle principale du programme.
        saut();
        cout << "Que shouaitez vous faire ?" << endl;
        cout << "- Afficher le catalogue de voyage (1)." << endl;
        cout << "- Rechercher un trajet (2)." << endl;
        cout << "- Ajouter un nouveau trajet (3)." << endl;
        cout << "- Quitter (4)." << endl;
        while (!(cin >> choix) || choix < 1 || choix > 4){  // On verrifie que l'entrée saisie est bien un entier et qu'il est compris entre 1 et 4.
            cerr << "Erreur de saisie." << endl;
            cin.clear(); // effacer les bits d'erreurs
            cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }
        
        switch (choix) {
            case 1: // On affiche le catalogue.
                saut();
                c.afficherTrajet();
                break;
                
            case 2: //On recherche un trajet.
                
                break;
                
            case 3: // On ajoute un trajet.
                while(boucle){
                    saut();
                    cout << "Quelle type de trajet voulez vous saisire ?" << endl;
                    cout << "- Un trajet simple (1)." << endl;
                    cout << "- Un trajet composé (2)." << endl;
                    cout << "- Retour au menu (4)." << endl;
                    
                    while (!(cin >> choix) || choix < 1 || choix > 4 || choix == 3){
                        cerr << "Erreur de saisie." << endl;
                        cin.clear();
                        cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                    }
                    
                    if(choix == 1)
                    {
                        char dep[255];
                        char arr[255];
                        char mdt[255];
                        saut();
                        cout << "Quelle est votre trajet ?" << endl;
                        cout << "Ecrivez de la forme : <depart> - <arrivée> - <moyen de transport>" << endl;
                        scanf("%255s - %255s - %255s",dep, arr, mdt);
                        TrajetSimple* t = new TrajetSimple(dep, arr, mdt);
                        cout << t;
                        saut();
                        cout << "Le trajet :" << endl;
                        (*c.ajouterTrajet(t)).description();
                        cout << "\n\rA été ajouté avec succès !\n\n\r" << endl;
                        c.afficherTrajet();
                    }
                    else if(choix == 2)
                    {
                        while(boucle)
                        {
                            saut();
                            cout << "Combien de trajet compose votre trajet composé ? (-1 pour quitter)";
                            
                            while (!(cin >> choix) || choix < 2)
                            {
                                cerr << "Erreur de saisie." << endl;
                                if(choix < 2){
                                    cerr << "Veuillez saisire un nombre supérieur à 2 !" << endl;
                                }
                                cin.clear();
                                cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                            }
                            
                        }
                        boucle = true;
                    }
                    else if(choix == 4)
                    {
                        boucle = false;
                    }
                    
                }
                boucle = true;
                break;
                
            case 4: // On quitte le programme.
                boucle = false;
                break;
                
            default:
                break;
        }
    }
   /*TrajetSimple* tab = new TrajetSimple[3];
    tab[0] = TrajetSimple("Lyon", "Paris", "Bus");
    tab[1] = TrajetSimple("Paris", "Le Mans", "Bus");
    tab[2] = TrajetSimple("Le Mans", "Renne", "Train");
    TrajetSimple* t = new TrajetSimple("Lyon", "Paris", "Train");
    TrajetSimple* t1 = new TrajetSimple("Marseille", "Montpellier", "Avion");
    TrajetCompose* t2 = new TrajetCompose("Lyon", "Renne", 3, tab);
    (*t2).description();
    cout << endl;
    (*t).description();
    cout << endl;
    c.ajouterTrajet(t);
    c.ajouterTrajet(t2);
    c.ajouterTrajet(t1);
    c.afficherTrajet();*/
    
    return 0;
}

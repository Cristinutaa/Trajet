/*************************************************************************
 Main  -  Classe principale
 -------------------
 début                : 18/11/2016
 copyright            : (C) 2016 par GALLY Justin et ARHILIUC Cristina
 e-mail               : justin.gally@insa-lyon.fr ou cristina.arhiliuc@insa-lyon.fr
 *************************************************************************/

//---------- Réalisation du <main> (fichier main.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstdlib>
#include <limits>
#include <stdio.h>


//-------------------------------------------------------- Include personnel
#include "Catalogue.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"

using namespace std;



int main(int argc, const char * argv[]) {
    Catalogue c;
    bool boucle = true;
    int choix;
    while(boucle){  // La boucle principale du programme/ Le menu principal
        cout << "Que shouaitez vous faire ?" << endl;
        cout << "- Afficher le catalogue de voyage (1)." << endl;
        cout << "- Rechercher un trajet (2)." << endl;
        cout << "- Ajouter un nouveau trajet (3)." << endl;
        cout << "- Importer des trajets (4)" << endl;
        cout << "- Exporter des trajets (5)" << endl;
        cout << "- Quitter (6)." << endl;
        while (!(cin >> choix) || choix < 1 || choix > 6){  // On verrifie que l'entrée saisie est bien un entier et qu'il est compris entre 1 et 4.
            cerr << "Erreur de saisie." << endl;
            cin.clear(); // effacer les bits d'erreurs
            cin.ignore( numeric_limits<streamsize>::max(), '\n' ); // supprimer la ligne erronée dans le buffer
        }
        if(choix == 1)  // On affiche le catalogue.
        {
            
            c.afficherTrajet();
        }
        else if (choix == 2 && !c.isEmpty())    //On recherche un trajet.
        {
            char dep[255];
            char arr[255];
            
            cout << "Quelle trajet recherchez vous ?" << endl;
            cout << "Ecrivez de la forme : <depart> - <arrivée>" << endl;
            scanf("%255s - %255s",dep, arr);
            c.rechercherParcourV1(dep, arr);
            cout << "\n\n\rRecherche de niveau 2 pour les trajets au départ de " << dep << " arrivant à " << arr << " : " << endl;
            cout << c.rechercherParcourV2(dep, arr) << " trajet(s) trouvé(s)" << endl;
            
            
        }
        else if (choix == 2 && c.isEmpty())
        {
            cout << "Le catalogue est vide, recherche inutile." << endl;
        }
        else if (choix == 3) // On ajoute un trajet.
        {
            while(boucle){
                
                cout << "Quelle type de trajet voulez vous saisire ?" << endl;
                cout << "- Un trajet simple (1)." << endl;
                cout << "- Un trajet composé (2)." << endl;
                cout << "- Retour au menu (3)." << endl;
                
                while (!(cin >> choix) || choix < 1 || choix > 3){
                    cerr << "Erreur de saisie." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
                
                if(choix == 1)
                {
                    char dep[255];
                    char arr[255];
                    char mdt[255];
                    
                    cout << "Quelle est votre trajet ?" << endl;
                    cout << "Ecrivez de la forme : <depart> - <arrivée> - <moyen de transport>" << endl;
                    scanf("%255s - %255s - %255s",dep, arr, mdt);
                    
                    cout << "Le trajet :\n\r" << (c.ajouterTrajet(new TrajetSimple(dep, arr, mdt)))->description() <<"\n\rA été ajouté avec succès !\n\n\r" << endl;
                    
                    c.afficherTrajet();
                    
                }
                else if(choix == 2)
                {
                    
                    TabDynamique* tabD = new TabDynamique();
                    while(boucle)
                    {
                        cout << "Voulez vous ajouter un nouveau trajet ? (1: Oui | 2: Non)" << endl;
                        
                        while (!(cin >> choix) || choix < 1 || choix > 2){
                            cerr << "Erreur de saisie." << endl;
                            cin.clear();
                            cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                        }
                        if(choix == 1)
                        {
                            char arr[255];
                            char mdt[255];
                            
                            cout << "Quelle est votre trajet ?" << endl;
                            if(tabD->nbElement() == 0)
                            {
                                char dep[255];
                                cout << "Ecrivez de la forme : <depart> - <arrivée> - <moyen de transport>" << endl;
                                scanf("%255s - %255s - %255s",dep, arr, mdt);
                                tabD->ajouter(new TrajetSimple(dep, arr, mdt));
                            }
                            else{
                                char dep[255];
                                strcpy(dep, tabD->get(tabD->nbElement() -1)->getArrivee());
                                cout << "Ecrivez de la forme : <arrivée> - <moyen de transport> pour le trajet au départ de " << dep << endl;
                                scanf("%255s - %255s", arr, mdt);
                                tabD->ajouter(new TrajetSimple(dep, arr, mdt));
                            }
                                
                        }
                        else if (choix == 2)
                        {
                            boucle = false;
                        }
                    }
                    boucle = true;
                    if(tabD->nbElement() > 0)
                    {
                        cout << "Le trajet :\n\r" << (c.ajouterTrajet(new TrajetCompose(tabD)))->description() << "\n\rA été ajouté avec succès !\n\n\r" << endl;
                        
                        c.afficherTrajet();
                        
                    }
                    else{
                        cout << "Aucun trajet n'a été ajouté !" << endl;
                        delete tabD;
                    }
                }
                else if(choix == 3)
                {
                    boucle = false;
                }
                
            }
            boucle = true;
        }
        else if (choix == 4)    // Importer les trajets
        {
            cout << "Quelle type d'importation souhaitez-vous faire ?" << endl;
            cout << "- Importation total (1)" << endl;
            cout << "- Importation par type de trajet (2)" << endl;
            cout << "- Importation par ville de départ et/ou d'arrivée (3)" << endl;
            cout << "- Importation par borne (4)" << endl;
            cout << "- Annuler (5)" << endl;
            
            while (!(cin >> choix) || choix < 1 || choix > 5){
                cerr << "Erreur de saisie." << endl;
                cin.clear();
                cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            }
            string fichier;
            
            if(choix != 5)
            {
                cout << "Quelle fichier souhaitez vous importer (sans l'extension)?" << endl;
                cin >> fichier;
                fichier += ".txt";
                cout << "Placer le fichier " << fichier << " dans le dossier import puis entrez 1" << endl;
                int pause;
                cin >> pause;
            }
        
            if(choix == 1)  // Total
            {
                c.chargementTotal(fichier.c_str());
            }
            else if(choix == 2) // Par type
            {
                cout << "Quelle type de trajet voulez vous importer ? (S:Simple | C:Compose)" << endl;
                char rep;
                while (!(cin >> rep) || (rep != 'C' && rep != 'S')){
                    cerr << "Erreur de saisie." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
                
                c.chargementType(fichier, rep);
                
            }
            else if( choix == 3)    // Par villes
            {
                cout << "Renseignez une ville de départ ( [-] si vous ne souhaitez pas renseigner de ville de départ)" << endl;
                string depart;
                bool dep = true;
                cin >> depart;
                if(depart[0] == '-')
                {
                    dep = false;
                    cout << "Vous n'avez pas renseigné de ville de départ." << endl;
                }
                
                cout << "Renseignez une ville d'arrivée ( [-] si vous ne souhaitez pas renseigner de ville d'arrivée)" << endl;
                string arrivee;
                bool arr = true;
                cin >> arrivee;
                if(arrivee[0] == '-')
                {
                    arr = false;
                    cout << "Vous n'avez pas renseigné de ville d'arrivée." << endl;
                }
                
                if(dep && arr)
                    c.chargementVilleDA(fichier, depart, arrivee);
                
                else if(dep)
                    c.chargementVilleD(fichier, depart);
                
                else if(arr)
                    c.chargementVilleA(fichier, arrivee);
                
                else
                    cout << "Catalogue inchangé !" << endl;
            }
            else if( choix == 4)    // Par borne
            {
                int min, max;
                cout << "Entrez la borne inférieur (>= 1) :" << endl;
                while (!(cin >> min) || min < 1){
                    cerr << "Erreur de saisie";
                    if(min < 1)
                        cerr << " : Entrez une valeur supérieur ou égale à 1." << endl;
                    else
                        cerr << "." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }

                cout << "Entrez la borne supérieur :" << endl;
                while (!(cin >> max) || max < min){
                    cerr << "Erreur de saisie";
                    if(max < min)
                        cerr << " : Entrez une valeur supérieur ou égale à la valeur minimal." << endl;
                    else
                        cerr << "." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
                c.chargementIntervalle(fichier, --min, --max);
            }
        }
        else if (choix == 5 && !c.isEmpty())    // Exporter les trajets
        {
            cout << "Quelle type d'exportation souhaitez-vous faire ?" << endl;
            cout << "- Exportation total (1)" << endl;
            cout << "- Exportation par type de trajet (2)" << endl;
            cout << "- Exportation par ville de départ et/ou d'arrivée (3)" << endl;
            cout << "- Exportation par borne (4)" << endl;
            cout << "- Annuler (5)" << endl;
            
            while (!(cin >> choix) || choix < 1 || choix > 5){
                cerr << "Erreur de saisie." << endl;
                cin.clear();
                cin.ignore( numeric_limits<streamsize>::max(), '\n' );
            }
            string fichier;
            
            if(choix != 5)
            {
                cout << "Dans quelle fichier souhaitez-vous exporter le catalogue ? (sans l'extension)?" << endl;
                cin >> fichier;
                fichier += ".txt";
            }
        
            if(choix == 1)  // Total
            {
                c.sauvegardeTotal(fichier.c_str());
            }
            else if(choix == 2) // Par type
            {
                cout << "Quelle type de trajet voulez vous exporter ? (S:Simple | C:Compose)" << endl;
                char rep;
                while (!(cin >> rep) || (rep != 'C' && rep != 'S')){
                    cerr << "Erreur de saisie." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
                
                c.sauvegardeType(fichier, rep);
                
            }
            else if( choix == 3)    // Par villes
            {
                cout << "Renseignez une ville de départ ( [-] si vous ne souhaitez pas renseigner de ville de départ)" << endl;
                string depart;
                bool dep = true;
                cin >> depart;
                if(depart[0] == '-')
                {
                    dep = false;
                    cout << "Vous n'avez pas renseigné de ville de départ." << endl;
                }
                
                cout << "Renseignez une ville d'arrivée ( [-] si vous ne souhaitez pas renseigner de ville d'arrivée)" << endl;
                string arrivee;
                bool arr = true;
                cin >> arrivee;
                if(arrivee[0] == '-')
                {
                    arr = false;
                    cout << "Vous n'avez pas renseigné de ville d'arrivée." << endl;
                }
                
                if(dep && arr)
                    c.sauvegardeVilleDA(fichier, depart, arrivee);
                
                else if(dep)
                    c.sauvegardeVilleD(fichier, depart);
                
                else if(arr)
                    c.sauvegardeVilleA(fichier, arrivee);
                
                else
                    cout << "Catalogue inchangé !" << endl;
            }
            else if( choix == 4)    // Par borne
            {
                int min, max;
                cout << "Entrez la borne inférieur (>= 1) :" << endl;
                while (!(cin >> min) || min < 1){
                    cerr << "Erreur de saisie";
                    if(min < 1)
                        cerr << " : Entrez une valeur supérieur ou égale à 1." << endl;
                    else
                        cerr << "." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
                
                cout << "Entrez la borne supérieur :" << endl;
                while (!(cin >> max) || max < min){
                    cerr << "Erreur de saisie";
                    if(max < min)
                        cerr << " : Entrez une valeur supérieur ou égale à la valeur minimal." << endl;
                    else
                        cerr << "." << endl;
                    cin.clear();
                    cin.ignore( numeric_limits<streamsize>::max(), '\n' );
                }
                c.sauvegardeIntervalle(fichier, --min, --max);
            }
        }
        else if (choix == 5 && c.isEmpty())
        {
            cout << "Votre catalogue est vide, exportation inutile." << endl;
        }
        else if (choix == 6)    // On quitte le programme.
            boucle = false;
    }
    return 0;
}

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

void testTotal(Catalogue c)
{
    cout << "Sauvegarde totale" << endl;
    c.chargementTotal("Catalogue.txt");
    c.afficherTrajet();
    
    cout << "Ecriture total" << endl;
    c.sauvegardeTotal("EcritureTotal.txt");
}

void testType(Catalogue c, char type)
{
    cout << "Sauvegarde par type : " << type << endl;
    c.chargementType("Catalogue.txt", type);
    c.afficherTrajet();
    
    cout << "Ecriture type" << endl;
    c.sauvegardeType("EcritureType.txt", type);
}

void testD1(Catalogue c, string depart)
{
    cout << "Sauvegarde par depart : " << depart << endl;
    c.chargementVilleD("Catalogue.txt", depart);
    c.afficherTrajet();
    
    cout << "Ecriture Depart" << endl;
    c.sauvegardeVilleD(("EcritureDepart"+depart+".txt"), depart);
}


void testD2(Catalogue c, string depart)
{
    cout << "Sauvegarde total" << endl;
    c.chargementTotal("Catalogue.txt");
    c.afficherTrajet();
    
    cout << "Ecriture Depart" << endl;
    c.sauvegardeVilleD(("EcritureDepart"+depart+".txt"), depart);
}

void testA1(Catalogue c, string a)
{
    cout << "Sauvegarde par arrivee : " << a << endl;
    c.chargementVilleA("Catalogue.txt", a);
    c.afficherTrajet();
    
    cout << "Ecriture Arrivee" << endl;
    c.sauvegardeVilleA(("EcritureArrivee"+a+".txt"), a);
}


void testA2(Catalogue c, string a)
{
    cout << "Sauvegarde total" << endl;
    c.chargementTotal("Catalogue.txt");
    c.afficherTrajet();
    
    cout << "Ecriture Arrivee" << endl;
    c.sauvegardeVilleA(("EcritureArriveet"+a+".txt"), a);
}


void testDA1(Catalogue c, string depart, string a)
{
    cout << "Sauvegarde par depart et arrivée : " << depart << " - " << a << endl;
    c.chargementVilleDA("Catalogue.txt", depart, a);
    c.afficherTrajet();
    
    cout << "Ecriture Depart et Arrivee" << endl;
    c.sauvegardeVilleDA(("EcritureDepart"+depart+a+".txt"), depart, a);
}


void testDA2(Catalogue c, string depart, string a)
{
    cout << "Sauvegarde total" << endl;
    c.chargementTotal("Catalogue.txt");
    c.afficherTrajet();
    
    cout << "Ecriture Depart" << endl;
    c.sauvegardeVilleDA(("EcritureDepart"+depart+a+".txt"), depart, a);
}

void testIL(Catalogue c, int n, int m)
{
    cout << "Sauvegarde intervalle de " << n << " à " << m <<  endl;
    c.chargementIntervalle("Catalogue.txt", n, m);
    c.afficherTrajet();
}


void testIE(Catalogue c, int n, int m)
{
    cout << "Sauvegarde total" << endl;
    c.chargementTotal("Catalogue.txt");
    c.afficherTrajet();
    
    cout << "Ecriture Intervalle" << endl;
    c.sauvegardeIntervalle(("EcritureIntervalle.txt"), n, m);
}


int main(int argc, const char * argv[]) {
    Catalogue c;
    //testTotal(c);
    //testType(c, 'C');
    //testD1(c, "Lyon");
    //testD2(c, "Lyon");
    //testD2(c, "Paris");
    //testA2(c, "Paris");
    //testDA2(c,"Lyon", "Paris");
    //testIL(c, 2, 4);
    testIE(c, 2, 2);
    
    /*bool boucle = true;
    int choix;
    while(boucle){  // La boucle principale du programme/ Le menu principal
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
        if(choix == 1)  // On affiche le catalogue.
        {
            saut();
            c.afficherTrajet();
        }
        else if (choix == 2)    //On recherche un trajet.
        {
            char* dep = new char[255];
            char* arr = new char[255];
            saut();
            cout << "Quelle trajet recherchez vous ?" << endl;
            cout << "Ecrivez de la forme : <depart> - <arrivée>" << endl;
            scanf("%255s - %255s",dep, arr);
            c.rechercherParcourV1(dep, arr);
            cout << "\n\n\rRecherche de niveau 2 pour les trajets au départ de " << dep << " arrivant à " << arr << " : " << endl;
            cout << c.rechercherParcourV2(dep, arr) << " trajet(s) trouvé(s)" << endl;
            delete[] dep;
            delete[] arr;
            
            
        }
        else if (choix == 3) // On ajoute un trajet.
        {
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
                    char* dep = new char[255];
                    char* arr = new char[255];
                    char* mdt = new char[255];
                    saut();
                    cout << "Quelle est votre trajet ?" << endl;
                    cout << "Ecrivez de la forme : <depart> - <arrivée> - <moyen de transport>" << endl;
                    scanf("%255s - %255s - %255s",dep, arr, mdt);
                    saut();
                    cout << "Le trajet :\n\r" << (c.ajouterTrajet(new TrajetSimple(dep, arr, mdt)))->description() <<"\n\rA été ajouté avec succès !\n\n\r" << endl;
                    
                    c.afficherTrajet();
                    delete[] dep;
                    delete[] arr;
                    delete[] mdt;
                    
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
                            char* arr = new char[255];
                            char* mdt = new char[255];
                            saut();
                            cout << "Quelle est votre trajet ?" << endl;
                            if(tabD->nbElement() == 0)
                            {
                                char* dep = new char[255];
                                cout << "Ecrivez de la forme : <depart> - <arrivée> - <moyen de transport>" << endl;
                                scanf("%255s - %255s - %255s",dep, arr, mdt);
                                tabD->ajouter(new TrajetSimple(dep, arr, mdt));
                                delete[] dep;
                            }
                            else{
                                const char* dep = tabD->get(tabD->nbElement() -1)->getArrivee() ;
                                cout << "Ecrivez de la forme : <arrivée> - <moyen de transport> pour le trajet au départ de " << dep << endl;
                                scanf("%255s - %255s", arr, mdt);
                                tabD->ajouter(new TrajetSimple(dep, arr, mdt));
                            }
                            delete[] arr;
                            delete[] mdt;
                                
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
                else if(choix == 4)
                {
                    boucle = false;
                }
                
            }
            boucle = true;
        }
        else if (choix == 4)    // On quitte le programme.
            boucle = false;
    }*/
    return 0;
}








/*
 ofstream fichier;
 cout << "Ouverture de " << c << endl;
 fichier.open((c= "Documents/Programmation/Trajet/Trajet/"+c), ios::out);
 if(fichier.is_open())
 {
 cout << "Fichier ouvert, ecriture de : Test" << endl;
 fichier << "Test.\n";
 }
 else
 cout << "Impossible d'ouvrire " << c << endl;
 
 
 
 fichier.close();*/

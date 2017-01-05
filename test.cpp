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


//-------------------------------------------------------- Include personnel
#include "Catalogue.h"

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
    return 0;
}

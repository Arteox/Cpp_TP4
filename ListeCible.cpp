/*************************************************************************
                           ListeCible  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ListeCible> (fichier ListeCible.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeCible.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type ListeCible::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

/*void ListeCible::addToMap(Arc a)
{


    if (listeA.find(a.GetCible()) == listeN.end()){
        listeA.insert(make_pair(a.GetCible(),a.listeRef));
    }
    else
    {
        map<string, int>::iterator it = listeN.find(n);
        listeN[it->second]++;
    }
}*/

//------------------------------------------------- Surcharge d'opérateurs
ListeCible & ListeCible::operator = ( const ListeCible & unListeCible )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ListeCible::ListeCible ( const ListeCible & unListeCible )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeCible>" << endl;
#endif
} //----- Fin de ListeCible (constructeur de copie)


ListeCible::ListeCible ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeCible>" << endl;
#endif
    
} //----- Fin de ListeCible


ListeCible::~ListeCible ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeCible>" << endl;
#endif
} //----- Fin de ~ListeCible


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


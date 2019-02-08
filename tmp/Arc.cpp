/*************************************************************************
                           Cible  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Cible> (fichier Cible.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cible.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Cible::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Cible::Incremente()
{
    label++;
}

int Cible::GetCible()
{
    return cible.GetURL();
}


//------------------------------------------------- Surcharge d'opérateurs
Cible & Cible::operator = ( const Cible & unCible )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Cible::Cible ( const Cible & unCible )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Cible>" << endl;
#endif
} //----- Fin de Cible (constructeur de copie)*/


Cible::Cible (Noeud c, Noeud r ) : cible (c), referant(r), label(1)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Cible>" << endl;
#endif
} //----- Fin de Cible


Cible::~Cible ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Cible>" << endl;
#endif
} //----- Fin de ~Cible


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


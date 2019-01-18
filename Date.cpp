/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Date> (fichier Date.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Date.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Date::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Date & Date::operator = ( const Date & unDate )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Date::Date ( const Date & unDate )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Date>" << endl;
#endif
} //----- Fin de Date (constructeur de copie)


Date::Date ( string date_brute )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Date>" << endl;
#endif
    jour = stoi(date_brute.substr(1,2));

    switch (date_brute.subst(4,3)){
        case "Jan" :
            mois = Jan;
            break;
        case "Feb" :
            mois = Feb;
            break;
        case "Mar" :
            mois = Mar;
            break;
        case "Apr" :
            mois = Apr;
            break;
        case "May" :
            mois = May;
            break;
        case "Jun" :
            mois = Jun;
            break;
        case "Jul" :
            mois = Jul;
            break;
        case "Aug" :
            mois = Aug;
            break;
        case "Sep" :
            mois = Sep;
            break;
        case "Oct" :
            mois = Oct;
            break;
        case "Nov" :
            mois = Nov;
            break;
        case "Dec" :
            mois = Dec;
            break;
    }

    annee = stoi(date_brute.substr(8,4));

    heure = stoi(date_brute.substr(13,2));
    min = stoi(date_brute.substr(16,2));
    sec = stoi(date_brute.substr(19,2));

    GMT = stoi(date_brute.substr(22,5));
} //----- Fin de Date


Date::~Date ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Date>" << endl;
#endif
} //----- Fin de ~Date


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


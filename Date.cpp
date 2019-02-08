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

    if (date_brute.substr(4,3)=="Jan"){
		mois = Jan;
	}
	else if (date_brute.substr(4,3)=="Feb"){
		mois =Feb;
	}
	else if (date_brute.substr(4,3)=="Mar"){
		mois =Mar;
	}
	else if (date_brute.substr(4,3)=="Apr"){
		mois =Apr;
	}
	else if (date_brute.substr(4,3)=="May"){
		mois =May;
	}
	else if (date_brute.substr(4,3)=="Jun"){
		mois =Jun;
	}
	else if (date_brute.substr(4,3)=="Jul"){
		mois =Jul;
	}
	else if (date_brute.substr(4,3)=="Aug"){
		mois =Aug;
	}
	else if (date_brute.substr(4,3)=="Sep"){
		mois =Sep;
	}
	else if (date_brute.substr(4,3)=="Oct"){
		mois =Oct;
	}
	else if (date_brute.substr(4,3)=="Nov"){
		mois =Nov;
	}
	else if (date_brute.substr(4,3)=="Dec"){
		mois =Dec;
	}
    annee = stoi(date_brute.substr(8,4));

    heure = stoi(date_brute.substr(13,2));
    min = stoi(date_brute.substr(16,2));
    sec = stoi(date_brute.substr(19,2));

    GMT = stoi(date_brute.substr(22,5));
} //----- Fin de Date

Date::Date()
{
}

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


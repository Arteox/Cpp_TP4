/*************************************************************************
                           Date  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Date> (fichier Date.h) ----------------
#if ! defined ( Date_H )
#define Date_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <iostream>
using namespace std;

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef enum month {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

//------------------------------------------------------------------------
// Rôle de la classe <Date>
// Classe permettant de stocker les informations concernant la date
// à partir d'une ligne d'un fichier.log
//
//------------------------------------------------------------------------typedef enum TokenType

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    
	int GetHeure();


//------------------------------------------------- Surcharge d'opérateurs
    Date & operator = ( const Date & unDate);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Date ( const Date & unDate );
    // Mode d'emploi (constructeur de copie) :typedef enum TokenType
    //
    // Contrat :
    //

    Date ( string date_brute );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	Date ( );
    // Mode d'emploi : Constructeur sans paramètres
    //
    // Contrat :
    //

    virtual ~Date ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int sec;
    int min;
    int heure;
    int GMT;
    int jour;
    month mois;
    int annee;

};

//-------------------------------- Autres définitions dépendantes de <Date>

#endif // Date_H


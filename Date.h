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
// Classe permettant de stocker les informations concernant la date de la requête d'une URL
// à partir d'un extrait de ligne d'un fichier.log
//
//------------------------------------------------------------------------typedef enum TokenType

class Date
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    
	int GetHeure() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé heure
    // Contrat : Aucun
	
	int GetMin() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé min
    // Contrat : Aucun
	
	int GetSec() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé sec
    // Contrat : Aucun
	
	int GetGMT() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé GMT
    // Contrat : Aucun
	
	int GetJour() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé jour
    // Contrat : Aucun
	
	month GetMois() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé mois
    // Contrat : Aucun
	
	int GetAnnee() const;
	// Mode d'emploi : 
    // Renvoie l'attribut protégé annee
    // Contrat : Aucun
	
	
//------------------------------------------------- Surcharge d'opérateurs
    Date & operator = ( const Date & unDate );
    // Mode d'emploi :
    // RAS
    // Contrat : Aucun
    //
//-------------------------------------------- Constructeurs - destructeur
    Date ( const Date & unDate );
    // Mode d'emploi (constructeur de copie) :
    // RAS
    // Contrat : Aucun
    //

    Date ( string date_brute );
    // Mode d'emploi :
	// Dans une ligne d'un fichier log, on considère que 2 champs sont séparés par des espaces
    // Le paramètre date_brute correspond alors aux 4e champ et 5e champ
	// Par exemple : [08/Sep/2012 :11:16:02
    // Contrat :
    // Bien respecter la syntaxe du paramètre à envoyer, comme l'exemple ci-dessus
	
	Date ( );
    // Mode d'emploi : Constructeur sans paramètres, contenu vide
    //
    // Contrat : Ne pas mettre de paramètre
    //

    virtual ~Date ( );
    // Mode d'emploi : RAS, contenu vide
    //
    // Contrat : Aucun
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


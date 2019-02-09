/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#if ! defined ( Noeud_H )
#define Noeud_H

//--------------------------------------------------- Interfaces utilisées
#include "Date.h"
#include <string>
#include <algorithm>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// Contient toutes les informations d'un noeud, cad d'une URL d'un fichier point log
//
//------------------------------------------------------------------------

class Noeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
    string GetURL();
	// Mode d'emploi :
    //
    // Contrat :
    //
	
	bool NoeudValide();
	// Mode d'emploi : Renvoie vrai ssi statut = 200 et action = GET
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    //Noeud & operator = ( const Noeud & unNoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //Noeud ( const Noeud & unNoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Noeud (Date d, int s, string URL, string act, int don, string n, string ext, string IP, string u, string p);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Noeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Date date;
    int statut;
    string URL_local;
    string action;
    int donnee;
    string navi;
    string extension;
    string ip;
    string username;
    string pseudo;

};

//-------------------------------- Autres définitions dépendantes de <Noeud>

#endif // Noeud_H


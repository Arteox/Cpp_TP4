/*************************************************************************
                           ListeCible  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ListeCible> (fichier ListeCible.h) ----------------
#if ! defined ( ListeCible_H )
#define ListeCible_H

//--------------------------------------------------- Interfaces utilisées
#include "Arc.h"
#include <map>
#include <algorithm>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeCible>
//
//
//------------------------------------------------------------------------

class ListeCible
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void addToMap(Arc a);

//------------------------------------------------- Surcharge d'opérateurs
    ListeCible & operator = ( const ListeCible & unListeCible );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ListeCible ( const ListeCible & unListeCible );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeCible ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeCible ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    //clé : cible et valeur : map de ref et label
     map <string, map<string, int>> listeA;

};

//-------------------------------- Autres définitions dépendantes de <ListeCible>

#endif // ListeCible_H


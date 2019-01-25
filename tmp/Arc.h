/*************************************************************************
                           Arc  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Arc> (fichier Arc.h) ----------------
#if ! defined ( Arc_H )
#define Arc_H

//--------------------------------------------------- Interfaces utilisées
#include "Noeud.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Arc>
//
//
//------------------------------------------------------------------------

class Arc
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Incremente();
    int GetLabel();
    string GetCible();
    string GetRef();

//------------------------------------------------- Surcharge d'opérateurs
    Arc & operator = ( const Arc & unArc );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Arc ( const Arc & unArc );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Arc (Noeud c, Noeud r );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Arc ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Noeud cible;
    map <string, int> listeRef;
};

//-------------------------------- Autres définitions dépendantes de <Arc>

#endif // Arc_H


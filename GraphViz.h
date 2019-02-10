/*************************************************************************
                           GraphViz  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <GraphViz> (fichier GraphViz.h) ----------------
#if ! defined ( GraphViz_H )
#define GraphViz_H

//--------------------------------------------------- Interfaces utilisées
#include "ListeNoeud.h"
#include "ListeCible.h"
#include <string>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>
#include <sstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <GraphViz>
//
//
//------------------------------------------------------------------------

class GraphViz
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	void GenererFichierDot();
	void GenererFichierPng();

//------------------------------------------------- Surcharge d'opérateurs
    GraphViz & operator = ( const GraphViz & unGraphViz );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    GraphViz ( const GraphViz & unGraphViz );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    GraphViz (ListeNoeud& N, ListeCible& C, string& nomF);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~GraphViz ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	ListeNoeud listeNoeud;
	ListeCible listeCible;
	string nomFichier;

};

//-------------------------------- Autres définitions dépendantes de <GraphViz>

#endif // GraphViz_H


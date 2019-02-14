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
// Classe permettant de générer un fichier .dot et son graphe (png)
// à partir d'un fichier .log

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
	// Mode d'emploi :
    // Génère un fichier.dot à partir d'un fichier .log,
	// dont le nom est enregistré dans l'attribut nomFichier
    // Contrat : 
	// nomFichier doit être un chemin valide vers fichier.log
	
	void GenererFichierPng();
	// Mode d'emploi :
	// Génère un fichier png à partir d'un fichier dot
    // Contrat :
	// Le fichier dot doit être généré au préalable par la méthode GenererFichierDot

//-------------------------------------------- Constructeurs - destructeur

    GraphViz (ListeNoeud& N, ListeCible& C, string& nomF);
    // Mode d'emploi : RAS
    // Contrat : 
    // Respecter les paramètres

    virtual ~GraphViz ( );
    // Mode d'emploi : Vide
    // Contrat : Aucun

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


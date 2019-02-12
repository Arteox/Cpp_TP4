/*************************************************************************
                           ExtractionLog  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ExtractionLog> (fichier ExtractionLog.h) ----------------
#if ! defined ( ExtractionLog_H )
#define ExtractionLog_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Date.h"
#include "Noeud.h"
#include "ListeNoeud.h"
#include "ListeCible.h"
#include "GraphViz.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ExtractionLog>
//
//------------------------------------------------------------------------

class ExtractionLog
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	ListeNoeud* GetListeNoeud();
	ListeCible* GetListeCible();

//------------------------------------------------- Surcharge d'opérateurs
    //ExtractionLog & operator = ( const ExtractionLog & unExtractionLog );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    //ExtractionLog ( const ExtractionLog & unExtractionLog );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ExtractionLog (const string& nomF, const bool& optG, const bool& optE, const bool& optT, const int Td);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ExtractionLog ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	ifstream fichierLog;
	ListeNoeud listeNoeud;
	ListeCible listeCible;
	bool optionG;
	bool optionE;
	bool optionT;
	int Tdate;
	string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <ExtractionLog>

#endif // ExtractionLog_H


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
// Classe permettant d'extraire les informations utiles d'un fichier log
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
	// Mode d'emploi :
    // Renvoie l'attribut listeNoeud
    // Contrat : Aucun
	
	ListeCible* GetListeCible();
	// Mode d'emploi :
    // Renvoie l'attribut Cible
    // Contrat : Aucun
	
	int GetLignesLog() const;
	// Mode d'emploi :
    // Renvoie l'attribut nbLignesLog
    // Contrat : Aucun


//-------------------------------------------- Constructeurs - destructeur

    ExtractionLog (const string& nomF, const bool& optG, const bool& optE, const bool& optT, int filtreH=-1);
    // Mode d'emploi :
    // Copie les valeurs de tous les paramètres dans les attributs correspondants
	// puis procède à la lecture du fichier log indiqué par nomF
    // Contrat :
	// nomF doit correspondre à un chemin relatif vers un fichier log existant

    virtual ~ExtractionLog ( );
    // Mode d'emploi : vide
    //
    // Contrat : Aucun
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
	string nomFichier;
	int filtreHeure;
	int nbLignesLog;
};

//-------------------------------- Autres définitions dépendantes de <ExtractionLog>

#endif // ExtractionLog_H


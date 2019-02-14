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
// Contient toutes les informations d'un noeud, cad d'une URL d'un fichier .log
// Toutes les manipulations ou vérification de certaines valeurs des attributs d'un noeud se font ici
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
	
    string GetURL() const;
	// Mode d'emploi : Renvoie l'attribut URL_local
    //
    // Contrat : Aucun
	
	bool NoeudValide(const bool& optionE, const bool& optionT, int filtreHeure=-1);
	// Mode d'emploi :
	// Vérifie la validité du noeud courant : renvoie true s'il est valide, false sinon
	// Cette méthode renvoie vrai si le code réponse de la requête vaut 200 et si l'action effectuée est GET
	// Les paramètres optionE et optionT rajoutent des contraintes supplémentaires
	// sur la validation du noeud s'ils sont vrais
	//
    // Contrat : Aucun
	
	bool VerifExtensionOptionE() const;
	// Mode d'emploi :
	// Renvoie vrai si l'extension du noeud courant n'est de type js, css, png ou jpg
    //
    // Contrat : Aucun
	
	bool VerifHeureOptionT(int filtre) const;
	// Mode d'emploi :
	// Renvoie vrai l'heure est comprise entre filtre et filtre+1 exclus
    //
    // Contrat :
	// Le paramètre filtre est compris entre 0 et 23
    //


//-------------------------------------------- Constructeurs - destructeur

    Noeud (const Date& d, int s, string URL, string act, int don, string n, string ext, string IP, string u, string p);
    // Mode d'emploi :
	// Construction d'un noeud à partir des différentes informations extraites d'une ligne d'un fichier log
    //
    // Contrat :
	// Les paramètres doivent bien respecter la syntaxe d'un fichier log
    //

    virtual ~Noeud ( );
    // Mode d'emploi : vide
    //
    // Contrat : Aucun
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


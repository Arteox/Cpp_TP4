/*************************************************************************
                           ListeNoeud  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <ListeNoeud> (fichier ListeNoeud.h) ----------------
#if ! defined ( ListeNoeud_H )
#define ListeNoeud_H

//--------------------------------------------------- Interfaces utilisées
#include "Noeud.h"
#include <iterator>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeNoeud>
// Classe permettant de gérer une liste de Noeud nécessaire pour l'affichage du top 10 des noeuds/sites les plus consultés
// Pour cela, on utilise la structure de données fournie par la STL : map.
// Clé : nom de l'URL du noeud et valeur : nombre d'occurences
// Comme le but de la classe est d'afficher le top 10, on ne prendra que l'attribut URL_local de chaque Noeud.
// Attention : on n'ajoute pas les sites référents dans la liste, seulement les sites consultés.
//
//------------------------------------------------------------------------

class ListeNoeud
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void AjoutMap(const string &cible);
	// Mode d'emploi :
    // Méthode permettant d'ajouter à la liste l'URL_local d'un noeud
	// Si le noeud est déjà présent, on incrémente alors la valeur du nombre d'occurences
    // Contrat : Aucun
	
    void AfficherDixPremiers();
	// Mode d'emploi :
	// Affiche le top 10 des sites les plus consultés sur la sortie standard
    //
    // Contrat : Aucun
	
    pair <int, string> flip_pair(const pair<string, int> &p);
	// Mode d'emploi :
	// Prend en paramètre un couple <string, int> et renvoie le même couple inversé <int, string>
    // Contrat : Aucun
	
    multimap <int, string> flip_map(const map <string, int> &src);
	// Mode d'emploi :
	// Prend en paramètre une map <string, int> et renvoie une multimap avec les mêmes couples inversés <int, string>
    // Contrat : Aucun
	
	map <string,int> GetMap() const;
	// Mode d'emploi :
	// Renvoie l'attribut listeN
    // Contrat : Aucun
	
	bool MapEmpty();
	// Mode d'emploi :
	// Renvoie vrai si l'attribut de type map listeN est vide sinon faux
    // Contrat : Aucun


//------------------------------------------------- Surcharge d'opérateurs
    ListeNoeud & operator = ( const ListeNoeud & unListeNoeud );
    // Mode d'emploi :
	// Ecrase toutes les valeurs de l'attribut listeN par les valeurs de la listeN de unListeNoeud
    //
    // Contrat : Aucun

//-------------------------------------------- Constructeurs - destructeur
    ListeNoeud ( const ListeNoeud & unListeNoeud );
    // Mode d'emploi (constructeur de copie) :
    // Copies les valeurs de la listeN de unListeNoeud dans la listeN de l'instance courante
    // Contrat : Aucun

    ListeNoeud ( );
    // Mode d'emploi : Ne fait rien
    //
    // Contrat : Aucun

    virtual ~ListeNoeud ( );
    // Mode d'emploi : Vide
    //
    // Contrat : Aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	//cle : url local et valeur : nombre d'occurences
    map <string, int> listeN;

};

//-------------------------------- Autres définitions dépendantes de <ListeNoeud>

#endif // ListeNoeud_H


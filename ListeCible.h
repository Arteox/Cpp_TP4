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

#include <iterator>
#include <map>
#include <algorithm>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeCible>
// Classe permettant de créer et gérer une map qui associe chaque cible (site consulté)
// à la liste de tous ses sites référents et le nombre d'occurence pour chacun de ces référents
// Pour cela on utilisera une map <string cible, <string ref, int nb_occurence>>
// Participe à la réalisation de la génération du graphe avec l'option -g
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
	
    void AjoutMap(const string &cible, const string &ref);
	// Mode d'emploi :
    // Méthode permettant d'ajouter à la liste l'URL_local d'un site cible et son référent associé
	// Si le site cible est déjà présent, on vérifie si le référent associé existe déjà.
	// S'il n'existe pas on l'ajoute sinon on incrémente le nombre d'occurences associé
    // Contrat : Aucun
	
	map <string, map<string, int>> GetMap() const;
	// Mode d'emploi :
    // Renvoie l'attribut de type map listeC
    // Contrat : Aucun
	
//------------------------------------------------- Surcharge d'opérateurs
    ListeCible & operator = ( const ListeCible & unListeCible );
    // Mode d'emploi :
    // Ecrase toutes les valeurs de l'attribut listeC par les valeurs de la listeC de unListeCible
    // Contrat : Aucun


//-------------------------------------------- Constructeurs - destructeur
    ListeCible ( const ListeCible & unListeCible );
    // Mode d'emploi (constructeur de copie) :
    // Copies les valeurs de la listeC de unListeCible dans la listeC de l'instance courante
    // Contrat : Aucun

    ListeCible ();
    // Mode d'emploi : Ne fait rien
    //
    // Contrat : Aucun

    virtual ~ListeCible ( );
    // Mode d'emploi :
    //
    // Contrat : vide

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

    //clé : cible et valeur : map de ref et nombre d'occurences
    map <string, map<string, int>> listeC;

};

//-------------------------------- Autres définitions dépendantes de <ListeCible>

#endif // ListeCible_H


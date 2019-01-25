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
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ListeNoeud>
//
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

    void addToMap(Noeud, string);
    void Afficher();
    map <string, int> MapAssocieCible(string cible);
    pair <int, string> flip_pair(const pair<string, int> &p);
    multimap <int, string> flip_map(const map <string, int> &src);


//------------------------------------------------- Surcharge d'opérateurs
    ListeNoeud & operator = ( const ListeNoeud & unListeNoeud );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    ListeNoeud ( const ListeNoeud & unListeNoeud );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    ListeNoeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~ListeNoeud ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map <string, int> listeN;
    vector <Noeud> v;

};

//-------------------------------- Autres définitions dépendantes de <ListeNoeud>

#endif // ListeNoeud_H


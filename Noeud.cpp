/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Noeud::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

string Noeud::GetURL() const
// Algorithme : RAS
{
    return URL_local;
}

bool Noeud::VerifExtensionOptionE() const
// Algorithme : RAS
{
	if (extension == "jpg" || extension == "js" || extension == "png" || extension == "css") {
		return false;
	}
	else {
		return true;
	}
}

bool Noeud::VerifHeureOptionT(int filtre) const
// Algorithme : Il faut vérifier que l'heure appartienne à l'intervalle [filtre; filtre+1[
// Comme ce sont des entiers, cela revient à dire heure == filtre
{
	int heure = date.GetHeure();
	if (heure == filtre){
		return true;
	}
	else {
		return false;
	}
}

bool Noeud::NoeudValide(const bool& optionE, const bool& optionT, int filtreHeure)
// Algorithme : RAS
{	
	bool valide = false;
	if (statut == 200 && action == "GET"){
		valide = true;
	}
	else {
		return false;
	}
	
	if (optionE == true){
		valide = VerifExtensionOptionE();
		if (valide == false){
			return valide;
		}
	}
	
	if (optionT == true){
		valide = VerifHeureOptionT(filtreHeure);
		if (valide == false){
			return valide;
		}
	}
		
	return valide;
}

//-------------------------------------------- Constructeurs - destructeur

Noeud::Noeud (const Date& d, int s, string URL, string act, int don, string n, string ext, string IP, string u, string p)
// Algorithme : RAS
{
#ifdef MAP
    cout << "Appel au constructeur de <Noeud>" << endl;
#endif
	date =d;
	statut = s;
	URL_local = URL;
	action = act;
	donnee = don;
	navi = n;
	extension = ext;
	ip = IP;
	username = u;
	pseudo = p;
} //----- Fin de Noeud


Noeud::~Noeud ( )
// Algorithme : vide
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Noeud>" << endl;
#endif
} //----- Fin de ~Noeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


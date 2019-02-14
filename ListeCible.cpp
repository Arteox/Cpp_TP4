/*************************************************************************
                           ListeCible  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ListeCible> (fichier ListeCible.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeCible.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type ListeCible::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void ListeCible::AjoutMap(const string &cible, const string &ref)
// Algorithme : RAS
{
	//la cible n'est pas dans le map
	if (listeC.find(cible) == listeC.end()){
		map <string, int> refs;
		refs.insert(make_pair(ref,1));
		listeC.insert(make_pair(cible,refs));
	}
	
	//la cible déjà présente, 2 cass
	//vérifier si ref présent : non on l'ajoute dans map, oui on incrémente la valeur associée
	else {
		map <string, map<string, int>>::iterator it1;
		it1 = listeC.find(cible);
		if (it1->second.find(ref) == it1->second.end()){
			it1->second.insert(make_pair(ref,1));
		}
		else {
			map <string, int>::iterator it2;
			it2 = it1->second.find(ref);
			++it2->second;
		}
	}
}

map <string, map<string, int>> ListeCible::GetMap() const
// Algorithme : RAS
{
	return listeC;
}


//------------------------------------------------- Surcharge d'opérateurs
ListeCible & ListeCible::operator = ( const ListeCible & unListeCible )
// Algorithme : RAS
{
	listeC.clear();
	map <string, map<string,int>> nouvMap = unListeCible.GetMap();
	listeC.insert(nouvMap.begin(), nouvMap.end());
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ListeCible::ListeCible ( const ListeCible & unListeCible )
// Algorithme : RAS
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeCible>" << endl;
#endif
	map <string, map<string,int>> nouvMap = unListeCible.GetMap();
	listeC.insert(nouvMap.begin(), nouvMap.end());
} //----- Fin de ListeCible (constructeur de copie)


ListeCible::ListeCible ( )
// Algorithme : RAS
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeCible>" << endl;
#endif
    
} //----- Fin de ListeCible


ListeCible::~ListeCible ( )
// Algorithme : RAS
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeCible>" << endl;
#endif
} //----- Fin de ~ListeCible


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


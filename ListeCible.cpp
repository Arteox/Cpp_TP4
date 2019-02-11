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
{
	//la cible n'est pas dans le map
	if (listeC.find(cible) == listeC.end()){
		map <string, int> refs;
		refs.insert(make_pair(ref,1));
		listeC.insert(make_pair(cible,refs));
	}
	
	//la cible deja presente, 2 cas
	//verifier si ref present : non on l'ajoute dans map, oui on incremente
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
{
	return listeC;
}

void ListeCible::NettoyageMap(const map <string, int>& listeNoeud)
{
	map<string,map<string, int>>::iterator itCible;
	
	//on supprime les cibles qui n'ont pas de référents
	
	
	//on supprime les référents qui ne sont pas des noeuds
	for (itCible = listeC.begin(); itCible !=listeC.end(); ++itCible) {
		map <string, int>::iterator itRef;
		itRef = itCible->second.begin();
		while (itRef != itCible->second.end()){
			if (listeNoeud.find(itRef->first) == listeNoeud.end()){
				//itRef pointe vers l'élément suivant automatiquement
				itRef = itCible->second.erase(itRef);
			}
			else {
				++itRef;
			}
		}
	}
}

//------------------------------------------------- Surcharge d'opérateurs
ListeCible & ListeCible::operator = ( const ListeCible & unListeCible )
// Algorithme :
//
{
	listeC.clear();
	map <string, map<string,int>> nouvMap = unListeCible.GetMap();
	listeC.insert(nouvMap.begin(), nouvMap.end());
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
ListeCible::ListeCible ( const ListeCible & unListeCible )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeCible>" << endl;
#endif
} //----- Fin de ListeCible (constructeur de copie)


ListeCible::ListeCible ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeCible>" << endl;
#endif
    
} //----- Fin de ListeCible


ListeCible::~ListeCible ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeCible>" << endl;
#endif
} //----- Fin de ~ListeCible


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


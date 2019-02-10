/*************************************************************************
                           ListeNoeud  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ListeNoeud> (fichier ListeNoeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeNoeud.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ListeNoeud::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void ListeNoeud::AjoutMap(const string &cible)
{
	//si on ne trouve pas le noeud, on l'ajoute
    if (listeN.find(cible) == listeN.end()){
        listeN.insert(make_pair(cible, 1));
    }
    else
	//le noeud existe, on incrémente
    {
        map<string, int>::iterator it = listeN.find(cible);
        it->second++;
    }
}

pair<int, string> ListeNoeud::flip_pair(const pair<string, int> &p)
{
    return pair<int, string>(p.second, p.first);
}

multimap <int, string> ListeNoeud::flip_map(const map <string, int> &src)
{
    multimap <int, string> dst;
	map<string, int>::const_iterator it;
	for (it = src.begin(); it!=src.end(); ++it)
	{
		dst.insert(make_pair(it->second, it->first));
	}
    return dst;
}

void ListeNoeud::Afficher()
//flip puis multimap et enfin afficher les noeuds dans l'ordre décroissant des occurences
{
    multimap <int, string> affichage = flip_map(listeN);
    multimap<int, string>::reverse_iterator it;
    int index =0;
    for (it = affichage.rbegin(); (it != affichage.rend() && index <10) ; ++it)
    {
        cout <<it->second<< " : " <<it->first<< endl;
        ++index;
    }
}

map <string,int> ListeNoeud::GetMap() const
{
	return listeN;
}

//------------------------------------------------- Surcharge d'opérateurs
ListeNoeud & ListeNoeud::operator = ( const ListeNoeud & unListeNoeud )
// Algorithme :
//
{
	map <string, int> nouvMap = unListeNoeud.GetMap();
	listeN.clear();
	listeN.insert(nouvMap.begin(), nouvMap.end());
	return *this;
} //----- Fin de operator =

bool ListeNoeud::MapEmpty()
{
	return listeN.empty();
}

//-------------------------------------------- Constructeurs - destructeur
ListeNoeud::ListeNoeud ( const ListeNoeud & unListeNoeud )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ListeNoeud>" << endl;
#endif
} //----- Fin de ListeNoeud (constructeur de copie)


ListeNoeud::ListeNoeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ListeNoeud>" << endl;
#endif


} //----- Fin de ListeNoeud


ListeNoeud::~ListeNoeud ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ListeNoeud>" << endl;
#endif
} //----- Fin de ~ListeNoeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


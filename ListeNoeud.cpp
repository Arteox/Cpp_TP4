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

void ListeNoeud::ajoutMap(Noeud cible, string ref)
{
	//si on ne trouve pas le noeud, on l'ajoute
    if (listeN.find(cible.GetURL()) == listeN.end()){
        listeN.insert(make_pair(cible.GetURL(), 1));
    }
    else
	//le noeud existe, on incrémente
    {
        map<string, int>::iterator it = listeN.find(cible.GetURL());
        it->second++;
		//pour le graphe
        //it->first.refs.insert(ref); marche pas car first est un string, pas un noeud 
    }
}

map <string, int> ListeNoeud::MapAssocieCible(string cible)
{
    map<string, int>::iterator it = listeN.find(cible);
    map<string, int> mapReturn;
    map<string, int>::iterator it2;
    for (it2 = it; it2 != listeN.end(); it2++)
    {
        //comment recuperer la liste des ref du noeud cible
    }

}

pair<int, string> ListeNoeud::flip_pair(const pair<string, int> &p)
{
    return pair<int, string>(p.second, p.first);
}

multimap <int, string> ListeNoeud::flip_map(map <string, int> &src)
{
    multimap <int, string> dst;
    //transform(src.begin(), src.end(), inserter(dst, dst.begin()),flip_pair);
	map<string, int>::iterator it;
	for (it = src.begin(); it!=src.end(); ++it)
	{
		dst.insert(make_pair(it->second, it->first));
	}
    return dst;
}

void ListeNoeud::Afficher()
//afficher les noeuds dans l'ordre décroissant des occurences, flip puis multimap
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

//------------------------------------------------- Surcharge d'opérateurs
ListeNoeud & ListeNoeud::operator = ( const ListeNoeud & unListeNoeud )
// Algorithme :
//
{
} //----- Fin de operator =


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


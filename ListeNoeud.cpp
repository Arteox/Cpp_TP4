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

void ListeNoeud::addToMap(Noeud cible, string ref)
{
    if (listeN.find(cible.GetURL()) == listeN.end()){
        listeN.insert(make_pair(cible.GetURL(), 1));
    }
    else
    {
        map<string, int>::iterator it = listeN.find(cible.GetURL());
        listeN[it->second]++;
        listeN[it->first].refs.insert(ref);
    }
}

void ListeNoeud::Afficher()
{
    multimap <int, string> affi = flip_map(listeN);
    map<int, string>::iterator it;
    int index =0;
    for (it = affi.rbegin(); it != affi.rend() || index ==10 ; it++)
    {
        cout <<it->second<< " : " <<it->first<< endl;
        index++;
    }
}

map <string, int> ListeNoeud::MapAssocieCible(string cible)
{
    map<string, int>::iterator it = listeN.find(n.GetURL());
    map<string, int> mapReturn;
    map<string, int>::iterator it2;
    for (it2 = it->.begin(); it != listeN.end(); it++)
    {
        //comment recuperer la liste des ref du noeud cible
    }

}

pair<int, string> ListeNoeud:flip_pair(const pair<string, int> &p)
{
    return pair<int, string>(p.second, p.first);
}

multimap <int, string> ListeNoeud::flip_map(const map <string, int> &src)
{
    multimap <int, string> dst;
    transform(src.begin(), src.end(), inserter(dst, dst.begin()),flip_pair<int,string>);
    return dst;
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


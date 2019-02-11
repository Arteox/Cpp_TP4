/*************************************************************************
                           GraphViz  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <GraphViz> (fichier GraphViz.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "GraphViz.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC
//----------------------------------------------------- Méthodes publiques
// type GraphViz::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void GraphViz::GenererFichierDot()
{
	ofstream fichierDot;
	fichierDot.open(nomFichier);
	if (fichierDot){
		fichierDot << "digraph {" <<endl;
		//ecriture du nom des noeuds
		map <string, int> mapNoeud = listeNoeud.GetMap();
		map <string,int>::iterator itNoeud;

		for (itNoeud = mapNoeud.begin(); itNoeud != mapNoeud.end(); ++itNoeud){
			fichierDot << "\t" << "\"" << itNoeud->first <<"\";" <<endl;
		}
		
		//nettoyage de la liste des referents qui ne sont pas des noeuds
		listeCible.NettoyageMap(mapNoeud);
		
		//ecriture des fleches
		map <string, map<string, int>> mapCible = listeCible.GetMap();
		map<string, map<string,int>>::iterator itCible;
		map<string, int>::iterator itRef;
		
		for (itCible = mapCible.begin(); itCible != mapCible.end(); ++itCible){
			for (itRef = itCible->second.begin(); itRef != itCible->second.end(); ++itRef){
				fichierDot << "\t\"" << itRef->first << "\"" << " -> ";
				fichierDot << "\"" << itCible->first << "\"" << " [label=\"" << itRef->second << "\"];";
			}
			fichierDot << endl;
		}
		fichierDot << "}";
	}
	fichierDot.close();
}

void GraphViz::GenererFichierPng()
{
	string nomFichierPng = nomFichier.substr(0, nomFichier.length()-3) + "png";
	string commande = "dot -Tpng -o " + nomFichierPng + " " +nomFichier;
	system(commande.c_str());
}

//------------------------------------------------- Surcharge d'opérateurs
GraphViz & GraphViz::operator = ( const GraphViz & unGraphViz )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
GraphViz::GraphViz ( const GraphViz & unGraphViz )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <GraphViz>" << endl;
#endif
} //----- Fin de GraphViz (constructeur de copie)


GraphViz::GraphViz (ListeNoeud& N, ListeCible& C, string& nomF)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <GraphViz>" << endl;
#endif
	listeNoeud = N;
	listeCible = C;
	nomFichier = nomF;
	
} //----- Fin de GraphViz


GraphViz::~GraphViz ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphViz>" << endl;
#endif
} //----- Fin de ~GraphViz


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


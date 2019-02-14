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
// Algorithme :
// Ecriture du fichier .dot avec le format suivant :
// digraph {
// liste des noeuds
// liste des flèches
// }
{
	ofstream fichierDot;
	fichierDot.open(nomFichier);
	if (fichierDot){
		fichierDot << "digraph {" <<endl;
		
		//définition de toutes les variables nécessaires
		map <string, int> mapNoeud = listeNoeud.GetMap();
		map <string,int>::iterator itNoeud;
		map <string, map<string, int>> mapCible = listeCible.GetMap();
		map<string, map<string,int>>::iterator itCible;
		map<string, int>::iterator itRef;
		
		//on ajoute à la liste des noeuds tous les sites référents qui ne sont pas des sites cibles (sites extérieurs)
		for (itCible = mapCible.begin(); itCible != mapCible.end(); ++itCible){
			for (itRef = itCible->second.begin(); itRef != itCible->second.end(); ++itRef){
				if (mapNoeud.find(itRef->first) == mapNoeud.end()){
					mapNoeud.insert(make_pair(itRef->first,1));
				}
			}
		}
		
		//écriture dans le fichier
		for (itNoeud = mapNoeud.begin(); itNoeud != mapNoeud.end(); ++itNoeud){
			fichierDot << "\t" << "\"" << itNoeud->first <<"\";" <<endl;
		}	
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
// Algorithme :
// Simule l'exécution de la commande linux dot -Tpng -o fichier.png fichier.dot avec la fonction system()
{
	string nomFichierPng = nomFichier.substr(0, nomFichier.length()-3) + "png";
	string commande = "dot -Tpng -o " + nomFichierPng + " " +nomFichier;
	system(commande.c_str());
}

//-------------------------------------------- Constructeurs - destructeur

GraphViz::GraphViz (ListeNoeud& N, ListeCible& C, string& nomF)
// Algorithme : RAS
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
// Algorithme : RAS
//
{
#ifdef MAP
    cout << "Appel au destructeur de <GraphViz>" << endl;
#endif
} //----- Fin de ~GraphViz


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


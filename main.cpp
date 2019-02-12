/*************************************************************************
                           main  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

#include <iostream>
using namespace std;
#include <cstring>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Date.h"
#include "Noeud.h"
#include "ListeNoeud.h"
#include "ListeCible.h"
#include "GraphViz.h"
#include "ExtractionLog.h"

int main(int argc, char** argv){
	
    ifstream ficLog;
	string nomFichier = argv[argc-1];

    ListeNoeud* listeNoeud;
	ListeCible* listeCible;
	bool optionG = false;
	int indexG =0;
	
	//option -g
	if (argc >=4){
		for (int i =0; i<argc;i++){
			if (strcmp(argv[i],"-g")==0 && argv[i+1]!=NULL){
				string verifFichierDot (argv[i+1]);
				if(verifFichierDot.find(".dot") != string::npos){
					optionG = true;
					indexG = i;
					break;
				}
			}
		}
	}
	
	ExtractionLog eLog (nomFichier, optionG);
	listeNoeud = eLog.GetListeNoeud();
	listeCible = eLog.GetListeCible();
	
	listeNoeud->AfficherDixPremiers();
    
	//graphe
	if (optionG==true){
		string nomFichierDot = argv[indexG+1];
		GraphViz graphe(*listeNoeud, *listeCible, nomFichierDot);
		graphe.GenererFichierDot();
		graphe.GenererFichierPng();
	}
}

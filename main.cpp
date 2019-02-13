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
	bool optionE = false;
	bool optionT = false;
	int Tdate = 1000;
	int indexG =0;
	

	for (int i =0; i<argc;i++){

		// option -e 
		if (strcmp(argv[i], "-e")==0 && argv[i+1] != NULL && strcmp(argv[i-1],"./analog")==0) {
			string verifFichierLog(argv[i + 1]);
			if (verifFichierLog.find(".log") != string::npos) {
				optionE = true;
				break;
			}
		}

		// option -t Tdate
		if (strcmp(argv[i], "-t") == 0 && argv[i + 1] != NULL && argv[i + 2] != NULL && strcmp(argv[i - 1], "./analog") == 0) {
			string verifFichierLog(argv[i + 2]);
			if (verifFichierLog.find(".log") != string::npos) {
				optionT = true;
				Tdate = argv[i+1];
				break;
			}
		}

		// option -t Tdate -e
		if (strcmp(argv[i], "-e") == 0 && argv[i + 1] != NULL && strcmp(argv[i-2],"-t")==0 && strcmp(argv[i - 3], "./analog") == 0) {
			string verifFichierLog(argv[i + 2]);
			if (verifFichierLog.find(".log") != string::npos) {
				optionT = true;
				optionE = true;
				Tdate = argv[i-1];
				break;
			}
		}

		// option -g simple
		if (strcmp(argv[i],"-g")==0 && argv[i+1]!=NULL && strcmp(argv[i-1],"./analog")==0){
			string verifFichierDot (argv[i+1]);
			if(verifFichierDot.find(".dot") != string::npos){
				optionG = true;
				indexG = i;
				break;
			}
		}

		// option -e -g
		if (strcmp(argv[i],"-g")==0 && argv[i+1]!=NULL && strcmp(argv[i-1],"-e")==0 && strcmp(argv[i-1],"./analog")==0) {
			string verifFichierDot(argv[i + 1]);
			if (verifFichierDot.find(".dot") != string::npos) {
				optionG = true;
				optionE = true;
				indexG = i;
				break;
			}
		}

		// option -t Tdate -g
		if (strcmp(argv[i],"-g")==0 && argv[i + 1] != NULL && strcmp(argv[i - 2],"-t")==0 && strcmp(argv[i - 3],"./analog")==0) {
			string verifFichierDot(argv[i + 1]);
			if (verifFichierDot.find(".dot") != string::npos) {
				optionG = true;
				optionT = true;
				Tdate = argv[i - 1];
				indexG = i;
				break;
			}
		}

		// option -t Tdate -e -g
		if (strcmp(argv[i],"-g")==0 && argv[i+1] != NULL && strcmp(argv[i-1],"-e")==0 && strcmp(argv[i-3],"-t")==0 && strcmp(argv[i-4],"./analog")==0) {
			string verifFichierDot(argv[i + 1]);
			if (verifFichierDot.find(".dot") != string::npos) {
				optionG = true;
				optionE = true;
				optionT = true;
				Tdate = argv[i - 2];
				indexG = i;
				break;
			}
		}

	}
	
	
	ExtractionLog eLog (nomFichier, optionG, optionE, optionT, Tdate);
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

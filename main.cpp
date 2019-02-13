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
	
	if (argc <2){
		cerr << "Erreur : pas de fichier log précisé" << endl;
		return 1;
	}
	
	string nomFichier = argv[argc-1];
	if (nomFichier.substr(0,4) != "tmp/"){
		cerr << "Erreur : le fichier log ne provient pas du dossier tmp ou ordre invalide des arguments" << endl;
		return 1;
	}
	
	if (nomFichier.substr(nomFichier.length()-4, 4) != ".log"){
		cerr << "Erreur : fichier log non reconnaissable" << endl;
		return 1;
	}
	
    ListeNoeud* listeNoeud;
	ListeCible* listeCible;
	bool optionG = false;
	bool optionE = false;
	bool optionT = false;
	int Tdate = 1000;
	int indexG =0;
	
	//option -g

	for (int i =0; i<argc;i++){
		// option -g simple
		if (strcmp(argv[i],"-g")==0 && argv[i+1]!=NULL){
			string verifFichierDot (argv[i+1]);
			if(verifFichierDot.find(".dot") != string::npos){
				optionG = true;
				indexG = i;
				break;
			}
			else {
				cerr << "Erreur : -g pas de fichier dot précisé" <<endl;
				return 1;
			}
		}
	}
	
	ExtractionLog eLog (nomFichier, optionG, optionE, optionT, Tdate);
	
	int nbLignesLog = eLog.GetLignesLog();
	
	if (nbLignesLog ==0){
		cout << "Avertissement : fichier log vide" <<endl;
	}
	else if (nbLignesLog < 10){
		cout << "Avertissement : le fichier log fourni fait moins de 10 lignes" << endl;
	}
	
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
	
	return 0;
}

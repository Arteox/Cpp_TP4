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
#include <ctype.h>
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
	int indexG =0;
	int filtreHeure = -1;
	
	//options
	for (int i =0; i<argc;i++){
		
		//option -g fichier.dot
		if (strcmp(argv[i],"-g")==0){
			string verifFichierDot (argv[i+1]);
			if(verifFichierDot.find(".dot") != string::npos){
				optionG = true;
				indexG = i;
			}
			else {
				cerr << "Erreur : -g pas de fichier dot précisé" <<endl;
				return 1;
			}
		}
		
		//option -e
		if (strcmp(argv[i], "-e")==0){
			optionE = true;
		}
		
		//option -t heure
		if (strcmp(argv[i], "-t") == 0){
			
			//on vérifie que l'argument heure est un nombre
			for (int k =0; k<strlen(argv[i+1]); ++k){
				if (!isdigit(argv[i+1][k])){
					cerr << "Erreur : heure invalide" << endl;
					return 1;
				}
			}
			
			filtreHeure = strtol(argv[i+1], NULL, 10);
			
			//on vérifie que le nombre donné correspond à une heure
			if (filtreHeure < 0 || filtreHeure > 23){
				cerr << "Erreur : heure non comprise entre 0 et 23" <<endl;
				return 1;
			}
			
			optionT = true;
		}
	}
	
	
	ExtractionLog eLog (nomFichier, optionG, optionE, optionT, filtreHeure);
	
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

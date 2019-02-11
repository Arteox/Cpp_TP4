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

int main(int argc, char** argv){
	
    ifstream ficLog;
	string nomFichier = argv[argc-1];
    ficLog.open(nomFichier);
    string lect;
    ListeNoeud listeNoeud;
	ListeCible listeCible;
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
	
    if (ficLog)
    {
		//lecture du fichier log ligne par ligne
        for (lect; getline(ficLog, lect); )
        {
            istringstream iss(lect);
            vector <string> champIndiv {istream_iterator<string>{iss}, istream_iterator<string>{}};
            string ip = champIndiv[0];
            string username = champIndiv[1];
            string pseudo = champIndiv[2];
            string dateInfo = champIndiv[3] + champIndiv[4];
            string action = champIndiv[5].substr(1,3);

            string URL_local = champIndiv[6];
			string extension;
			
			//revoir le 2e param de substr qui correspond au nb de caractères à prendre
			if (champIndiv[6].find(".") != string::npos){
				int indice_debut = champIndiv[6].find(".")+1;
				extension = champIndiv[6].substr(indice_debut,champIndiv[6].length()-indice_debut);
			}
			else {
				extension = "-";
			}
			
			int statut =0;
			int donnee =0;
			if (champIndiv[8].find_first_not_of("0123456789") ==string::npos) {
				statut = stoi(champIndiv[8]);
			}
			if (champIndiv[9].find_first_not_of("0123456789") ==string::npos) {
				donnee = stoi(champIndiv[9]);
			}
			
            string ref;
			if (champIndiv[10].find("http://intranet-if.insa-lyon.fr") != string::npos){
				int indice_debut = champIndiv[10].find("http://intranet-if.insa-lyon.fr")+31;
				ref = champIndiv[10].substr(indice_debut, champIndiv[10].length()-1-indice_debut);
			}
			else {
				ref = champIndiv[10].substr(1,champIndiv[10].length()-2);
			}
            string navi = champIndiv[11].substr(1, champIndiv[11].length()-1);

            Date d(dateInfo);
            Noeud n (d, statut, URL_local, action, donnee, navi, extension, ip, username, pseudo);
			
			if (n.NoeudValide()){
				listeNoeud.AjoutMap(URL_local);
				if (optionG == true){
					listeCible.AjoutMap(URL_local, ref);
				}
			}
        }
		
    }
    ficLog.close();
    listeNoeud.Afficher();
	
	//graphe
	if (optionG==true){
		string nomFichierDot = argv[indexG+1];
		GraphViz graphe(listeNoeud, listeCible, nomFichierDot);
		graphe.GenererFichierDot();
		graphe.GenererFichierPng();
	}
}

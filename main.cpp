/*************************************************************************
                           main  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

#include <iostream>
using namespace std;
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Date.h"
#include "Noeud.h"
#include "ListeNoeud.h"

int main(int argc, char** argv){

    ifstream ficLog;
    ficLog.open("anonyme.log");
    string lect;
    ListeNoeud LN;

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
            string extension = champIndiv[6].substr(1,champIndiv[6].find("."));
			
			int statut =0;
			int donnee =0;
			if (champIndiv[8].find_first_not_of("0123456789") ==string::npos) {
				statut = stoi(champIndiv[8]);
			}
			if (champIndiv[9].find_first_not_of("0123456789") ==string::npos) {
				donnee = stoi(champIndiv[9]);
			}
			
            string ref = champIndiv[10].substr(1, champIndiv[10].length()-1);
            string navi = champIndiv[11].substr(1, champIndiv[11].length()-1);

            Date d(dateInfo);
            Noeud n (d, statut, URL_local, action, donnee, navi, extension, ip, username, pseudo, ref);
			
			if (n.NoeudValide()){
				LN.ajoutMap(n, ref);
			}
        }
    }
    ficLog.close();
    LN.Afficher();
}

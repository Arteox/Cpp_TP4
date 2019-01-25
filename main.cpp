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
#include <vector>
#include <algorithm>

int main(int argc, char** argv){

    ifstream courtLog;
    courtLog.open("court.log");
    string lect;
    ListeNoeud LN;

    if (courtLog)
    {
        for (lect; getline(fic, lect); )
        {
            istringstream iss(lect);
            vector <string> champIndiv {istream_iterator<string>{iss}, istream_iterator<string>{}};
            string ip = vector[0];
            string username = vector[1];
            string pseudo = vector[2];
            string dateInfo = vector[3] + vector[4];
            string action = vector[5].substr(1,3);

            string URL_local = vector[6];
            string extension = vector[6].substr(1,vector[6].find("."));

            int statut = stoi(vector[8]);
            int donnee = stoi(vector[9]);
            string ref = vector[10].substr(1, vecto[10].length()-1);
            string navi = vector[11].substr(1, vector[11].length()-1);

            Date d(dateInfo);
            Noeud n (d, statut, URL_local, action, donnee, navi, extension, ip, username, pseudo) ;
            LN.addToMap(n);

        }
    }
    courtLog.close();
    LN.Afficher();
}

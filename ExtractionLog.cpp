/*************************************************************************
                           ExtractionLog  -  description
                             -------------------
    début                : 18/01/2019
    copyright            : (C) 2019 par Alexandra LAFAILLE et Louis UNG
    e-mail               : alexandra.lafaille@insa-lyon.fr et louis.ung@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <ExtractionLog> (fichier ExtractionLog.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ExtractionLog.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ExtractionLog::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

ListeNoeud* ExtractionLog::GetListeNoeud()
{
	return &listeNoeud;
}

ListeCible* ExtractionLog::GetListeCible()
{
	return &listeCible;
}


//------------------------------------------------- Surcharge d'opérateurs
/*ExtractionLog & ExtractionLog::operator = ( const ExtractionLog & unExtractionLog )
// Algorithme :
//
{
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
/*ExtractionLog::ExtractionLog ( const ExtractionLog & unExtractionLog )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <ExtractionLog>" << endl;
#endif
} //----- Fin de ExtractionLog (constructeur de copie)*/


ExtractionLog::ExtractionLog (const string & nomF, const bool& optG, const bool& optE, const bool& optT, const int Td)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ExtractionLog>" << endl;
#endif
	optionG = optG;
	optionE = optE;
	optionT = optT;
	Tdate = Td;
	nomFichier = nomF;
	fichierLog.open(nomFichier);
	string lect;
	
	if (fichierLog)
    {
		//lecture du fichier log ligne par ligne
        for (lect; getline(fichierLog, lect); )
        {
            istringstream iss(lect);
            vector <string> champIndiv {istream_iterator<string>{iss}, istream_iterator<string>{}};
            string ip = champIndiv[0];
            string username = champIndiv[1];
            string pseudo = champIndiv[2];
            string dateInfo = champIndiv[3] + champIndiv[4];
            string action = champIndiv[5].substr(1,3);

            string URL_local;
			if (champIndiv[6].find("?") == string::npos){
				URL_local= champIndiv[6];
			}
			else {
				int indiceQ = champIndiv[6].find("?");
				URL_local = champIndiv[6].substr(0,indiceQ-1);
			}
			string extension;
			
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
			bool ref_est_local = false;
			if (champIndiv[10].find("http://intranet-if.insa-lyon.fr") != string::npos){
				int indice_debut = champIndiv[10].find("http://intranet-if.insa-lyon.fr")+31;
				ref = champIndiv[10].substr(indice_debut, champIndiv[10].length()-1-indice_debut);
				ref_est_local = true;
			}
			
			if (champIndiv[10].find("?") == string::npos && ref_est_local == false){
				ref = champIndiv[10].substr(1,champIndiv[10].length()-2);
			}
			else if (champIndiv[10].find("?") != string::npos && ref_est_local == false) {
				int indiceQ = champIndiv[10].find("?");
				ref = champIndiv[10].substr(1,indiceQ-1);
			}
			else if (champIndiv[10].find("?") != string::npos && ref_est_local == true) {
				int indiceQ = ref.find("?");
				ref = ref.substr(0,indiceQ-1);
			}
			
            string navi = champIndiv[11].substr(1, champIndiv[11].length()-1);

            Date d(dateInfo);
            Noeud n (d, statut, URL_local, action, donnee, navi, extension, ip, username, pseudo);
			
			if (n.NoeudValide()){
				if (optionE == false && optionT == false)
					listeNoeud.AjoutMap(URL_local);
				if (optionE == true && optionT == true) {
					if (strcmp(extension,"jpg") != 0 && strcmp(extension, "png") != 0 && strcmp(extension, "css") != 0 && strcmp(extension,"js") != 0))
						listeNoeud.AjoutMap(URL_local);
				}
				if (optionT == true && optionE == false) {
					if (d.GetHeure() == Tdate)
						listeNoeud.AjoutMap(URL_local);
				}

				if (optionG == true && optionE == false && optionT == false) {
					listeCible.AjoutMap(URL_local, ref);
				}
				if (optionG == true && optionE == true && optionT == false) {
					if (strcmp(extension, "jpg") != 0 && strcmp(extension, "png") != 0 && strcmp(extension, "css") != 0)
						listeCible.AjoutMap(URL_local, ref);
				}
				if (optionG == true && optionT == true && optionE == false) {
					if (d.GetHeure() == Tdate)
						listeCible.AjoutMap(URL_local, ref);
				}
			}
        }
    }
	fichierLog.close();

} //----- Fin de ExtractionLog


ExtractionLog::~ExtractionLog ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ExtractionLog>" << endl;
#endif
} //----- Fin de ~ExtractionLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


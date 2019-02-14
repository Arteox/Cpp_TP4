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
// Algorithme : RAS
{
	return &listeNoeud;
}

ListeCible* ExtractionLog::GetListeCible()
// Algorithme : RAS
{
	return &listeCible;
}

int ExtractionLog::GetLignesLog() const
// Algorithme : RAS
{
	return nbLignesLog;
}

//-------------------------------------------- Constructeurs - destructeur

ExtractionLog::ExtractionLog (const string & nomF, const bool& optG, const bool& optE, const bool& optT, int filtreH)
// Algorithme : Voir commentaires ci-dessous
//
{
#ifdef MAP
    cout << "Appel au constructeur de <ExtractionLog>" << endl;
#endif

	//définition des variables
	nbLignesLog =0;
	optionG = optG;
	optionE = optE;
	optionT = optT;
	filtreHeure = filtreH;
	nomFichier = nomF;
	fichierLog.open(nomFichier);
	string lect;
	
	if (fichierLog)
    {
		//lecture du fichier log ligne par ligne
        for (lect; getline(fichierLog, lect); )
        {
			++nbLignesLog;
			
			//récupération des informations ligne par ligne
			
            istringstream iss(lect);
            vector <string> champIndiv {istream_iterator<string>{iss}, istream_iterator<string>{}};
            string ip = champIndiv[0];
            string username = champIndiv[1];
            string pseudo = champIndiv[2];
            string dateInfo = champIndiv[3] + champIndiv[4];
            string action = champIndiv[5].substr(1,3);
            string URL_local;
			
			//si des paramètres de recherche sont présents dans l'URL, on l'enlève
			if (champIndiv[6].find("?") == string::npos){
				URL_local= champIndiv[6];
			}
			else {
				int indiceQ = champIndiv[6].find("?");
				URL_local = champIndiv[6].substr(0,indiceQ-1);
			}
			
			//on cherche l'extension
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
			//on vérifie que le champ ne contient que des nombres
			if (champIndiv[8].find_first_not_of("0123456789") ==string::npos) {
				statut = stoi(champIndiv[8]);
			}
			if (champIndiv[9].find_first_not_of("0123456789") ==string::npos) {
				donnee = stoi(champIndiv[9]);
			}
			
			//si l'url du site référent est local on supprime la partie locale (http://intranet-if.insa-lyon.fr)
            string ref;
			bool ref_est_local = false;
			if (champIndiv[10].find("http://intranet-if.insa-lyon.fr") != string::npos){
				int indice_debut = champIndiv[10].find("http://intranet-if.insa-lyon.fr")+31;
				ref = champIndiv[10].substr(indice_debut, champIndiv[10].length()-1-indice_debut);
				ref_est_local = true;
			}
			
			//si des paramètres de recherche sont présents dans l'url du site référent on les enlève
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
			
			//fin de la récupération des informations

            Noeud n (d, statut, URL_local, action, donnee, navi, extension, ip, username, pseudo);
			
			//vérification de la validité du noeud
			if (n.NoeudValide(optionE, optionT, filtreHeure)){
				listeNoeud.AjoutMap(URL_local);
				
				if (optionG ==true){
					listeCible.AjoutMap(URL_local, ref);
				}
			}
        }
    }
	fichierLog.close();

} //----- Fin de ExtractionLog


ExtractionLog::~ExtractionLog ( )
// Algorithme : RAS
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ExtractionLog>" << endl;
#endif
} //----- Fin de ~ExtractionLog


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


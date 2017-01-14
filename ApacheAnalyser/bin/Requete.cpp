/*************************************************************************
       	     Requete  -  Réalisation de la classe Requete
  La classe Requete offre une représentation simplifiée d'une Requete GET
				telle que présente dans une ligne de log Apache
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Requete> (fichier Requete.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <sstream>
//------------------------------------------------------ Include personnel
#include "Requete.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Requete::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = ( const Requete & unRequete )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Requete::Requete ( const Requete & unRequete )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
} //----- Fin de Requete (constructeur de copie)


Requete::Requete (string ligneDeLog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
	istringstream iss( ligneDeLog ); 
	string ipEtDate;
	getline(iss,ipEtDate,'"');
	string getEtRessource;
	getline(iss,getEtRessource,'"');
	string codeRequete;
	getline(iss,codeRequete,'"');
	string source;
	getline(iss,source,'"');	
	string informationsUtilisateur;
	getline(iss,informationsUtilisateur,'"');	//Ligne dupliquée en raison de la présence d'un espace
	getline(iss,informationsUtilisateur,'"');	
	cout<<codeRequete<<endl;
} //----- Fin de Requete


Requete::~Requete ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


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
#include <algorithm>
//------------------------------------------------------ Include personnel
#include "Requete.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

unsigned int Requete::ObtenirHeure() const
{
	return (dateEtHeure[12]-'0')*10+(dateEtHeure[13]-'0');
}//----- Fin de ObtenirHeure

bool Requete::AUneExtensionImgCssJS() const
{
	return !(extensionsImageJsCss.find(extensionRessource) == extensionsImageJsCss.cend());
}//----- Fin de AUneExtensionImgCssJs

string Requete::ObtenirURI() const
{
	return ressource;
}//----- Fin de ObtenirURI

string Requete::ObtenirReferent() const
{
	string referenceurARetourner;
	// Enleve la racine si elle est "http://intranet-if.insa-lyon.fr"
	if(referenceur.substr(0, adresseRacine.size()) == adresseRacine)
	{
		referenceurARetourner = referenceur.substr(adresseRacine.size());
	}
	// Garde que la racine si elle n'est pas "http://intranet-if.insa-lyon.fr"
	else if(referenceur.find("://") != referenceur.npos)
	{
		referenceurARetourner = referenceur.substr(referenceur.find("://") + 3);
		referenceurARetourner = referenceurARetourner.substr(0,referenceurARetourner.find("/"));
	}
	else
	{
		referenceurARetourner = referenceur;
	}
	
	return referenceurARetourner;
}//----- Fin de ObtenirReferent

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Requete::Requete (string ligneDeLog)
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
	string aDecouper;
	istringstream iss( ligneDeLog );
	getline(iss, ip, ' ');

	getline(iss, logname, ' ');

	getline(iss, username, ' ');

	getline(iss, dateEtHeure, ' ');
	dateEtHeure.erase(0,1);

	getline(iss, gmt, ' ');
	gmt.pop_back();

	getline(iss, typeDeRequete, ' ');
	typeDeRequete.erase(0,1);

	getline(iss, ressource, ' ');
	// enlever les parametres de la ressources s'ils y sont (apres '?' / ';')
	unsigned int interMark = ressource.find('?');
	unsigned int semicolonMark = ressource.find(';');
	unsigned int min = interMark < semicolonMark ? interMark : semicolonMark;
	unsigned int resLength = ressource.length();
	if (min < resLength)
	{
		ressource = ressource.substr(0, min);
		resLength = min + 1;
	}

	unsigned int pointMark = ressource.find('.');
	extensionRessource = ressource.substr(pointMark + 1, resLength - pointMark - 1);
	transform(extensionRessource.begin(), extensionRessource.end(),extensionRessource.begin(), ::toupper);

	getline(iss, protocol, ' ');
	protocol.pop_back();

	getline(iss, aDecouper, ' ');
	try 
	{
		codeHTTP = stoull(aDecouper);
	} 
	catch (exception e)
	{
		//cerr << "conversion of codeHTTP couldn't be performed: " << aDecouper << endl;
	}

	getline(iss, aDecouper, ' ');
	try 
	{
		dataSize = stoull(aDecouper);
	} 
	catch (exception e)
	{
		//cerr << "conversion of dataSize couldn't be performed: " << aDecouper << endl;
	}
	

	getline(iss, referenceur, ' ');
	referenceur.erase(0,1);
	referenceur.pop_back();

	getline(iss, navigateur);
	navigateur.erase(0,1);
	navigateur.pop_back();
} //----- Fin de Requete


Requete::~Requete ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Requete>" << endl;
#endif
} //----- Fin de ~Requete


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


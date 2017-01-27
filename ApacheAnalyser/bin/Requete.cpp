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
 string Requete::ObtenirIP() const
 {
 	return ip;
 }

unsigned int Requete::ObtenirHeure()const
{
	return (dateEtHeure[12]-'0')*10+(dateEtHeure[13]-'0');
}
bool Requete::AUneExtensionImgCssJS()const
{
	return extensionsImageJsCss.find(extensionRessource)!=extensionsImageJsCss.cend();

}


unsigned int Requete::ObtenirCodeHTTP()const
{
	return codeHTTP;
}

string Requete::ObtenirURI()const
{
	return ressource;
}

string Requete::ObtenirReferent()const
{
	string referenceurARetourner;
	unsigned int deuxPointsSlashSlash;
	if(referenceur.substr(0, adresseRacine.size()) == adresseRacine)
	{
		referenceurARetourner = referenceur.substr(adresseRacine.size());
	}
	//else if(referenceur.find("://") != referenceur.npos)
	else if((deuxPointsSlashSlash = referenceur.find("://")) != referenceur.npos)
	{
		//cout << deuxPointsSlashSlash << endl;
		referenceurARetourner = referenceur.substr(deuxPointsSlashSlash + 3);
		//referenceurARetourner = referenceur.substr(referenceur.find("://") + 3);
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
Requete::Requete ( const Requete & uneRequete )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Requete>" << endl;
#endif
	(*this)=uneRequete;

} //----- Fin de Requete (constructeur de copie)


Requete::Requete (string ligneDeLog)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Requete>" << endl;
#endif
    //cout << ligneDeLog << endl;
	string aDecouper;
	istringstream iss( ligneDeLog );
	getline(iss, ip, ' ');
	//cout << ip << endl;

	getline(iss, logname, ' ');
	//cout << logname << endl;

	getline(iss, username, ' ');
	//cout << username << endl;

	getline(iss, dateEtHeure, ' ');
	dateEtHeure.erase(0,1);
	//cout << dateEtHeure << endl;

	getline(iss, gmt, ' ');
	gmt.pop_back();
	//cout << gmt << endl;

	getline(iss, typeDeRequete, ' ');
	typeDeRequete.erase(0,1);
	//cout << typeDeRequete << endl;

	getline(iss, ressource, ' ');
	//cout << ressource << endl;
	// enlever les parametres de la ressources s'ils y sont (apres '?')
	unsigned int interMark = ressource.find('?');
	unsigned int resLength = ressource.length();
	if (interMark < resLength)
	{
		ressource = ressource.substr(0, interMark);
		resLength = interMark + 1;
	}
	//cout << ressource << endl;

	unsigned int pointMark = ressource.find('.');
	extensionRessource = ressource.substr(pointMark + 1, resLength - pointMark - 1);
	//cout << extensionRessource << endl;
	for(unsigned int i = 0; extensionRessource[i] != '\0'; i++)
	{
		if(extensionRessource[i] >= 'a' && extensionRessource[i] <= 'z')
		{
			extensionRessource[i] = extensionRessource[i] - 'a' + 'A';
		}
	}

	getline(iss, protocol, ' ');
	//cout << protocol << endl;
	protocol.pop_back();
	//cout << protocol << endl;

	getline(iss, aDecouper, ' ');
	try 
	{
		codeHTTP = stoull(aDecouper);
		//cout << codeHTTP << endl;
	} 
	catch (exception e)
	{
		//cerr << "conversion of codeHTTP couldn't be performed: " << aDecouper << endl;

	}

	getline(iss, aDecouper, ' ');
	try 
	{
		dataSize = stoull(aDecouper);
		//cout << dataSize << endl;
	} 
	catch (exception e)
	{
		//cerr << "conversion of dataSize couldn't be performed: " << aDecouper << endl;
	}
	

	getline(iss, referenceur, ' ');
	referenceur.erase(0,1);
	referenceur.pop_back();
	//cout << referenceur << endl;

	getline(iss, navigateur);
	navigateur.erase(0,1);
	navigateur.pop_back();
	//cout << navigateur << endl;

	// getline(iss,aDecouper,'"');
	
	// ip = aDecouper.substr(0, aDecouper.find(" - - "));
	// dateEtHeure=aDecouper.substr(aDecouper.find("[")+1, aDecouper.find("]")-aDecouper.find("[")-1);

	// getline(iss,aDecouper,'"');
	// typeDeRequete=aDecouper.substr(0, aDecouper.find(" "));
	// ressource=aDecouper.substr(aDecouper.find(" ")+1,aDecouper.find(" ",aDecouper.find(" ")+1)-aDecouper.find(" ")-1);
	
	// // enlever les parametres de la ressources s'ils y sont (apres '?')
	// unsigned int interMark = ressource.find('?');
	// if (interMark < ressource.length())
	// {
	// 	ressource = ressource.substr(0, interMark);
	// }

	// extensionRessource = ressource.substr(ressource.find(".") + 1, ressource.length() - ressource.find(".") - 1);
	// int i;
	// for(i=0;extensionRessource[i]!='\0';i++)
	// {
	// 	if(extensionRessource[i]>='a'&&extensionRessource[i]<='z')
	// 	{
	// 		extensionRessource[i]=extensionRessource[i]-'a'+'A';
	// 	}
	// }

	// getline(iss,aDecouper,'"');
	// codeHTTP=(aDecouper[1]-'0')*100+(aDecouper[2]-'0')*10+aDecouper[3]-'0';
	// getline(iss,aDecouper,'"');

	// referenceur=aDecouper;

	// getline(iss,aDecouper,'"');
	// getline(iss,aDecouper,'"');
	// navigateur=aDecouper;

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


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
	if(referenceur.substr(0,adresseRacine.size())==adresseRacine)
	{
		referenceurARetourner=referenceur.substr(adresseRacine.size(),adresseRacine.size());
	}
	else if(referenceur.find("://")!=referenceur.npos)//referenceur!="-")
	{
		referenceurARetourner=referenceur.substr(referenceur.find("://")+3,referenceur.size()-referenceur.find("://")-3);
		referenceurARetourner=referenceurARetourner.substr(0,referenceurARetourner.find("/"));
		
	}
	else
	{
		referenceurARetourner=referenceur;
	}
	
	return referenceurARetourner;
}//----- Fin de ObtenirReferent
//------------------------------------------------- Surcharge d'opérateurs
Requete & Requete::operator = ( const Requete & uneRequete )
// Algorithme :
//
{
   this->ressource=uneRequete.ressource;
	this->referenceur=uneRequete.referenceur;
	this->ip=uneRequete.ip;
	this->dateEtHeure=uneRequete.dateEtHeure;
	this->typeDeRequete=uneRequete.typeDeRequete;
	this->codeHTTP=uneRequete.codeHTTP;
	this->navigateur=uneRequete.navigateur;
	this->extensionRessource=uneRequete.extensionRessource;
	
	return *this;
} //----- Fin de operator =


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
	string aDecouper;
	istringstream iss( ligneDeLog );
	getline(iss,aDecouper,'"');
	
	ip = aDecouper.substr(0, aDecouper.find(" - - "));
	dateEtHeure=aDecouper.substr(aDecouper.find("[")+1, aDecouper.find("]")-aDecouper.find("[")-1);

	getline(iss,aDecouper,'"');
	typeDeRequete=aDecouper.substr(0, aDecouper.find(" "));
	ressource=aDecouper.substr(aDecouper.find(" ")+1,aDecouper.find(" ",aDecouper.find(" ")+1)-aDecouper.find(" ")-1);
	
	// enlever les parametres de la ressources s'ils y sont (apres '?')
	unsigned int interMark = ressource.find('?');
	if (interMark < ressource.length())
	{
		ressource = ressource.substr(0, interMark);
	}

	extensionRessource = ressource.substr(ressource.find(".") + 1, ressource.length() - ressource.find(".") - 1);
	int i;
	for(i=0;extensionRessource[i]!='\0';i++)
	{
		if(extensionRessource[i]>='a'&&extensionRessource[i]<='z')
		{
			extensionRessource[i]=extensionRessource[i]-'a'+'A';
		}
	}

	getline(iss,aDecouper,'"');
	codeHTTP=(aDecouper[1]-'0')*100+(aDecouper[2]-'0')*10+aDecouper[3]-'0';
	getline(iss,aDecouper,'"');

	referenceur=aDecouper;

	getline(iss,aDecouper,'"');
	getline(iss,aDecouper,'"');
	navigateur=aDecouper;

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


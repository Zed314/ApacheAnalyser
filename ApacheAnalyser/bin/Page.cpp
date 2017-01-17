/*************************************************************************
                 Page  - Réalisation de la classe Page
	La classe Page est conçue pour représenter une page du site internet 
		de maniére à mettre en évidence les visites et leurs origines.
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Page> (fichier Page.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <iterator>
#include <map>
//------------------------------------------------------ Include personnel
#include "Page.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Page::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

map < string,unsigned int >::const_iterator Page::ObtenirUnIterateurDeDebut() const
{
	return pagesReferentes.cbegin();
}//----- Fin de ObtenirUnIterateurDeDebut

map < string,unsigned int >::const_iterator Page::ObtenirUnIterateurDeFin() const
{
	return pagesReferentes.cend();
}//----- Fin de ObtenirUnIterateurDeFin

unsigned int Page::AjouterUnReferenceur(const string & urlDuReferenceur)
{
	//cout<<"On ajoute le référenceur "<<urlDuReferenceur<<endl;
	//cout<<"Il a deja ete ref"<<pagesReferentes.count(urlDuReferenceur)<<endl;
	 if(pagesReferentes.count(urlDuReferenceur)==1)
	 {
	 //	cout<<"++"<<endl;
	 	pagesReferentes[urlDuReferenceur]=pagesReferentes[urlDuReferenceur]+1;
	 }
	 else
	 {
	 //	cout<<"=1"<<endl;
	 	pagesReferentes[urlDuReferenceur]=1;
	 }
	// cout<<"Et désormais"<<pagesReferentes.count(urlDuReferenceur)<<endl;
	nbHitsTotal++;
	return nbHitsTotal;
}//----- Fin de AjouterUnReferenceur

//------------------------------------------------- Surcharge d'opérateurs
/*Page & Page::operator = ( const Page & unPage )
// Algorithme :
//
{
	
} //----- Fin de operator =*/


//-------------------------------------------- Constructeurs - destructeur
Page::Page ( const Page & unPage )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Page>" << endl;
#endif
} //----- Fin de Page (constructeur de copie)


Page::Page ( ):nbHitsTotal(0)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Page>" << endl;
#endif
} //----- Fin de Page


Page::~Page ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Page>" << endl;
#endif
} //----- Fin de ~Page


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


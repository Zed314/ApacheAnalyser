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
#include <utility>
#include <iostream>
#include <string>
#include <iterator>
#include <map>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Page.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
RefHits::const_iterator Page::ObtenirUnIterateurDeDebut() const
{
	return pagesReferentes.cbegin();
}//----- Fin de ObtenirUnIterateurDeDebut

RefHits::const_iterator Page::ObtenirUnIterateurDeFin() const
{
	return pagesReferentes.cend();
}//----- Fin de ObtenirUnIterateurDeFin

unsigned int Page::AjouterUnReferenceur(const std::string & urlDuReferenceur)
{
	if(pagesReferentes.count(urlDuReferenceur)==1)
	{
		pagesReferentes[urlDuReferenceur] = pagesReferentes[urlDuReferenceur] + 1;

	}
	else
	{
		pagesReferentes.insert(make_pair(urlDuReferenceur,1));
		
	}
	nbHitsTotal++;
	return nbHitsTotal;
}//----- Fin de AjouterUnReferenceur

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Page::Page ( ): nbHitsTotal(0)
{
#ifdef MAP
    cout << "Appel au constructeur de <Page>" << endl;
#endif
} //----- Fin de Page


Page::~Page ( )
{
#ifdef MAP
   cout << "Appel au destructeur de <Page>" << endl;
#endif
} //----- Fin de ~Page

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


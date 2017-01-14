/*************************************************************************
          EnsemblePages  -  Interface de la classe EnsemblePages
          
 				La classe EnsemblePages modélise une collection de 
 					pages web du nombre de visites associé
                             -------------------
    début                : 10/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <EnsemblePages> (fichier EnsemblePages.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <map>
//------------------------------------------------------ Include personnel
#include "EnsemblePages.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type EnsemblePages::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

const set <HitsParRessource,pageHitsComparator> EnsemblePages::ObtenirLesNPremiers(int n) const
{
	int i;
	set <HitsParRessource,pageHitsComparator>::const_iterator itDernierElementChoisi=pageHits.cbegin();
	for(i=0;i<n&&itDernierElementChoisi!=pageHits.cend();i++)
	{
		itDernierElementChoisi++;
	}
	
	const set <HitsParRessource,pageHitsComparator> classement (pageHits.cbegin(),itDernierElementChoisi);
	return classement;
	
}//----- Fin de ObtenirLesNPremiers

unsigned int EnsemblePages::AjouterRequete (const Requete& r)
{
	unsigned int nbDocumentsAjoutes=0;
	if(!r.AUneExtensionImgCssJS()||extensionsImgJsCssAutorisees)
	{
		if(r.ObtenirHeureRequete()>=hDebut&&r.ObtenirHeureRequete()<=hFin)
		{
			string URIDeLaRequete=r.ObtenirURI();
			string referenceur=r.ObtenirReferent();
			unsigned int nbHitsDocument;
			
			map <string,Page>::iterator iterateurPages=pages.find(URIDeLaRequete);

			if(iterateurPages==pages.end())//Si il n'existe pas d'objet Page associé à ce document dans pages 
			{
				Page pageAAjouter;
				nbHitsDocument=pageAAjouter.AjouterUnReferenceur(referenceur);
				pages[URIDeLaRequete]=pageAAjouter;
				pageHits.insert( HitsParRessource(nbHitsDocument,URIDeLaRequete));
				nbDocumentsAjoutes++;
				
			}
			else
			{
				nbHitsDocument=iterateurPages->second.AjouterUnReferenceur(referenceur);
				//Si le document a déjà été indexé dans pageHits.
				//Il peut arriver qu'il ne le soit pas et qu'il se trouve quand même dans pages.
				//Cela arrive si le document a auparavant uniquement étémentionné comme étant un référenceur.
				//Ainsi une page vide a été créé mais pas d'entrée dans pageHits. Dans ce cas, on n'a pas besoin de
				//Chercher à supprimer l'entrée dans pageHits.
				if(nbHitsDocument!=1)
				{

				
					pageHits.erase(  HitsParRessource(nbHitsDocument-1,URIDeLaRequete));
				}
				
				pageHits.insert(  HitsParRessource(nbHitsDocument,URIDeLaRequete));
			}
			iterateurPages=pages.find(referenceur);
			if(iterateurPages==pages.end())//Si il n'existe pas d'objet Page associé à ce référenceur dans pages 
			{
				Page pageAAjouter;
				pages[referenceur]=pageAAjouter;
				nbDocumentsAjoutes++;
			}
			
			
		}
	}
	return nbDocumentsAjoutes;
	
}//----- Fin de AjouterRequete

//------------------------------------------------- Surcharge d'opérateurs
EnsemblePages & EnsemblePages::operator = ( const EnsemblePages & unEnsemblePages )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EnsemblePages::EnsemblePages ( const EnsemblePages & unEnsemblePages )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EnsemblePages>" << endl;
#endif
} //----- Fin de EnsemblePages (constructeur de copie)


EnsemblePages::EnsemblePages (int heureDebut, int heureFin, bool restrictionsExtensions):extensionsImgJsCssAutorisees(!restrictionsExtensions)
// Algorithme :
//
{
	#ifdef MAP
    cout << "Appel au constructeur de <EnsemblePages>" << endl;
#endif
	if(heureDebut<0)
	{
		heureDebut=0;
	}
	else if(heureDebut>=24)
	{
		heureDebut=23;
	}
	if(heureFin>=24)
	{
		heureFin=23;
	}
	else if(heureFin<0)
	{
		heureFin=0;
	}
	
	if(heureFin<heureDebut)
	{
		int heureTemp=heureFin;
		heureFin=heureDebut;
		heureDebut=heureTemp;
		
	}

	hDebut=heureDebut;
	hFin=heureFin;

} //----- Fin de EnsemblePages


EnsemblePages::~EnsemblePages ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EnsemblePages>" << endl;
#endif
} //----- Fin de ~EnsemblePages


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


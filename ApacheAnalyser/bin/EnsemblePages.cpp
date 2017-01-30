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

#include <iostream>
#include <string>
#include <map>
#include <utility>
//------------------------------------------------------ Include personnel
#include "EnsemblePages.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

TMapNomPage::const_iterator EnsemblePages::ObtenirIterateurSur(const string & nomDeLaPage) const	
{
	return pages.find(nomDeLaPage);
}//----- Fin de ObtenirIterateurSur

TMapNomPage::const_iterator EnsemblePages::ObtenirDebutPages() const
{
	return pages.begin();
}//----- Fin de ObtenirDebutPages

TMapNomPage::const_iterator EnsemblePages::ObtenirFinPages() const
{
	return pages.end();
}//----- Fin de ObtenirFinPages

const TSetPagesHits EnsemblePages::ObtenirLesNPremiers(int n) const
{
	int i;
	TSetPagesHits::const_iterator itDernierElementChoisi=pageHits.cbegin();
	for(i=0;i<n&&itDernierElementChoisi!=pageHits.cend();i++)
	{
		itDernierElementChoisi++;
	}
	
	const TSetPagesHits classement (pageHits.cbegin(),itDernierElementChoisi);
	return classement;
	
}//----- Fin de ObtenirLesNPremiers

unsigned int EnsemblePages::AjouterRequete (const Requete& r)
{
	
	unsigned int nbDocumentsAjoutes = 0;
	if(!(r.AUneExtensionImgCssJS() && !extensionsImgJsCssAutorisees))  // Verifie que si on a la option -e alors les extensions ne sont pas prises en compte
	{
		unsigned int heureRequete = r.ObtenirHeure();
		
		if(heureRequete >= hDebut && heureRequete < hFin)  // Verifie que les requetes sont dans la bonne plage horaire
		{
			string URIDeLaRequete = r.ObtenirURI();
			string referenceur = r.ObtenirReferent();
			unsigned int nbHitsDocument;
			
			TMapNomPage::iterator iterateurPages = pages.find(URIDeLaRequete);

			if(iterateurPages == pages.end())  // Si il n'existe pas d'objet Page associé à ce document dans pages 
			{
				Page pageAAjouter;
				nbHitsDocument = pageAAjouter.AjouterUnReferenceur(referenceur);
				//pages[URIDeLaRequete] = pageAAjouter;
				pages.insert(make_pair(URIDeLaRequete,pageAAjouter));
				pageHits.insert( HitsParRessource(nbHitsDocument,URIDeLaRequete));
				nbDocumentsAjoutes++;	
			}
			else
			{
				nbHitsDocument=iterateurPages->second.AjouterUnReferenceur(referenceur);

		/*		if(nbHitsDocument != 1)//Si le document référent a déjà une entrée dans PageHits
				{			
					pageHits.erase(HitsParRessource(nbHitsDocument-1,URIDeLaRequete));
				}
				pageHits.insert( HitsParRessource(nbHitsDocument,URIDeLaRequete));*/
				
				
				if(nbHitsDocument != 1)//Si le document référent a déjà une entrée dans PageHits
				{			
					//Nous effectuons un iterateur pour faire la suppression afin de gagner du temps à la réinsertion
					//en étant en mesure de donner un "hint" à la fonction d'insertion
					//On est obligé d'utiliser le find car erase ne renvoie un iterateur que si on lui donne un iterateur en paramètre
					pageHits.insert(pageHits.erase(pageHits.find(HitsParRessource(nbHitsDocument-1,URIDeLaRequete))), 
					HitsParRessource(nbHitsDocument,URIDeLaRequete));
				}
				else
				{
					pageHits.insert(HitsParRessource(nbHitsDocument,URIDeLaRequete));
				}
		

			}

			iterateurPages = pages.find(referenceur);
			if(iterateurPages == pages.end())  // Si il n'existe pas d'objet Page associé à ce référenceur dans pages 
			{
				Page pageDuReferant;
				pages.insert(make_pair(referenceur,pageDuReferant));
				nbDocumentsAjoutes++;
			}
			
			
		}
	}
	return nbDocumentsAjoutes;
	
}//----- Fin de AjouterRequete

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
EnsemblePages::EnsemblePages (unsigned int heureDebut, unsigned int heureFin, bool restrictionsExtensions): hDebut(heureDebut), hFin(heureFin), extensionsImgJsCssAutorisees(!restrictionsExtensions) 
{
	#ifdef MAP
    cout << "Appel au constructeur de <EnsemblePages>" << endl;
	#endif
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


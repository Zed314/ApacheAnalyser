/*************************************************************************
    	EnsemblePagesDAO  - Réalisation de la classe EnsemblePagesDAO
    	
 				Classe chargée des échanges de la classe EnsemblePages 
 									avec le systeme de fichier.
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <EnsemblePagesDAO> (fichier EnsemblePagesDAO.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel
#include "EnsemblePagesDAO.h"
#include "EnsemblePages.h"
#include <string>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool EnsemblePagesDAO::ExporterUnGraphe( const EnsemblePages & ensembleARendre)
{
	TMapNomPage::const_iterator iterateurPages;
	RefHits::const_iterator iterateurRef;
	unsigned int i =0;

	fichierSortie<<"digraph {"<<endl;
	// Ecrire les noeuds
	for(iterateurPages= ensembleARendre.ObtenirDebutPages(); iterateurPages!=ensembleARendre.ObtenirFinPages(); iterateurPages++)
	{
		
		fichierSortie << "node" <<i << " [label=\"" << iterateurPages->first << "\"];" << endl;
		i++;
	}
	// Fin de ecrire les noeuds

	// Ecrire les arcs
	i =0;
	for(iterateurPages= ensembleARendre.ObtenirDebutPages();iterateurPages!=ensembleARendre.ObtenirFinPages();iterateurPages++)
	{
	
		for(iterateurRef = iterateurPages->second.ObtenirUnIterateurDeDebut(); iterateurRef != iterateurPages->second.ObtenirUnIterateurDeFin(); iterateurRef++)
		{
		
			fichierSortie << "node"<<distance(ensembleARendre.ObtenirDebutPages(),ensembleARendre.ObtenirIterateurSur(iterateurRef->first))
			<<"-> node"<<i<< "[label=\""<<iterateurRef->second<<"\"];" << endl;
		}
		i++;
	}
	// Fin de ecrire les arcs
	fichierSortie<<"}"<<endl;
	
	return true;
}//----- Fin de ExporterUnGraphe

bool EnsemblePagesDAO::ExisteEtNonProtegeEnLecture() const
{
	ifstream fluxEntree(nomFichierSortie);
	
	return !fluxEntree.fail();
}//----- Fin de ExisteEtNonProtegeEnLecture

bool EnsemblePagesDAO::EstVide() const
{
	if(!this->ExisteEtNonProtegeEnLecture())
	{
		return true;
	}
	
	ifstream fluxEntree(nomFichierSortie);
	fluxEntree.clear();
	fluxEntree.seekg(0, ios::beg);
	streampos diff=fluxEntree.tellg();
	fluxEntree.seekg(0, ios::end);
	diff=fluxEntree.tellg()-diff;
    if(diff!=0)
    {
   		return false;
    }
    return true;	
}//----- Fin de EstVide

bool EnsemblePagesDAO::EcriturePossible() const
{
	if(fichierSortie)
	{
		return true;
	}
	return false;

}//----- Fin de EcriturePossible

//------------------------------------------------- Surcharge d'opérateurs
EnsemblePagesDAO & EnsemblePagesDAO::operator = ( const EnsemblePagesDAO & unEnsemblePagesDAO )
{
	this->nomFichierSortie = unEnsemblePagesDAO.nomFichierSortie;
    this->fichierSortie = ofstream(nomFichierSortie,ios::app);
    return *this;
}//----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
EnsemblePagesDAO::EnsemblePagesDAO (const EnsemblePagesDAO& unEnsemblePagesDAO)
{
#ifdef MAP
    cout << "Appel au constructeur de copie <EnsemblePagesDAO>" << endl;
#endif
    this->nomFichierSortie = unEnsemblePagesDAO.nomFichierSortie;
    this->fichierSortie = ofstream(nomFichierSortie,ios::app);
}//----- Fin de EnsemblePagesDAO (constructeur copie)


EnsemblePagesDAO::EnsemblePagesDAO (string & nomFichier): nomFichierSortie(nomFichier)
{
#ifdef MAP
    cout << "Appel au constructeur de <EnsemblePagesDAO>" << endl;
#endif
	fichierSortie = ofstream(nomFichierSortie,ios::app);
} //----- Fin de EnsemblePagesDAO


EnsemblePagesDAO::~EnsemblePagesDAO ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <EnsemblePagesDAO>" << endl;
#endif
} //----- Fin de ~EnsemblePagesDAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


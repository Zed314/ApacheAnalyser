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
//#include "EnsemblePages.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type EnsemblePagesDAO::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


bool EnsemblePagesDAO::ExporterUnGraphe( const EnsemblePages & ensembleARendre)
{
	fichierSortie<<"digraph {"<<endl;
	//TMapNomPage::const_iterator ObtenirDebutPages() const;
	TMapNomPage::const_iterator iterateurPages;
	map <string, unsigned int>::const_iterator iterateurRef;
	unsigned int i =0;
	for(iterateurPages= ensembleARendre.ObtenirDebutPages();iterateurPages!=ensembleARendre.ObtenirFinPages();iterateurPages++)
	{
		
		fichierSortie<<"node"<<to_string(i)<<" [label=\""<<iterateurPages->first<<"\"];"<<endl;
	i++;
	}
	i =0;
	for(iterateurPages= ensembleARendre.ObtenirDebutPages();iterateurPages!=ensembleARendre.ObtenirFinPages();iterateurPages++)
	{
	
		for(iterateurRef= iterateurPages->second.ObtenirUnIterateurDeDebut();iterateurRef!=iterateurPages->second.ObtenirUnIterateurDeFin();iterateurRef++)
		{
		
			cout<<iterateurRef->first<<endl;
			cout<<iterateurRef->second<<endl;
			fichierSortie<<"node"+to_string(distance(ensembleARendre.ObtenirDebutPages(),ensembleARendre.ObtenirIterateurSur(iterateurRef->first)))
			+"-> node"+to_string(i)
			<<"[label=\""+to_string(iterateurRef->second)+
			"\"];"<<endl;
		}
		i++;
		//fichierSortie<<"node"+to_string(distance(iterateurPages..begin,pages.find()))
		//fichierSortie<<"node"<<to_string(i)<<" [label=\""<<iterateurPages.first<<"\"];"<<endl;
	}//distance
	
	fichierSortie<<"}"<<endl;
	
	return true;
}//----- Fin de ExporterUnGraphe





bool EnsemblePagesDAO::ExisteEtNonProtegeEnLecture() const
{
	ifstream fluxEntree(nomFichierSortie);
	
	return !fluxEntree.fail();
}
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
	
}



bool EnsemblePagesDAO::EcriturePossible() const
{
	if(fichierSortie)
	{
		return true;
	}
	return false;
}
//------------------------------------------------- Surcharge d'opérateurs
EnsemblePagesDAO & EnsemblePagesDAO::operator = ( const EnsemblePagesDAO & unEnsemblePagesDAO )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EnsemblePagesDAO::EnsemblePagesDAO ( const EnsemblePagesDAO & unEnsemblePagesDAO )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EnsemblePagesDAO>" << endl;
#endif
} //----- Fin de EnsemblePagesDAO (constructeur de copie)


EnsemblePagesDAO::EnsemblePagesDAO (string nomFichier):nomFichierSortie(nomFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <EnsemblePagesDAO>" << endl;
#endif
fichierSortie=ofstream(nomFichierSortie,ios::app);
} //----- Fin de EnsemblePagesDAO


EnsemblePagesDAO::~EnsemblePagesDAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EnsemblePagesDAO>" << endl;
#endif
} //----- Fin de ~EnsemblePagesDAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


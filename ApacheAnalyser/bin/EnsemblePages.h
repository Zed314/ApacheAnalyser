/*************************************************************************
          EnsemblePages  -  Interface de la classe EnsemblePages
          
 				La classe EnsemblePages modélise une collection de 
 					pages web du nombre de visites associé
 	
                             -------------------
    début                : 10/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EnsemblePages> (fichier EnsemblePages.h) ----------------
#if ! defined ( EnsemblePages_H )
#define EnsemblePages_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <unordered_map>
#include <set>
#include "Page.h"
#include "Requete.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types



struct  HitsParRessource{
	unsigned int nbHits;
	string localisationDeLaRessource;
	
	HitsParRessource(unsigned nombreHits=0,string localisation=""):nbHits(nombreHits),localisationDeLaRessource(localisation)
	{
	}
	 
	string ToString() const
	{
		return localisationDeLaRessource + " (" + to_string(nbHits) + " hits)"; 
	} 
};

struct pageHitsComparator
{
  bool operator()(const HitsParRessource & a,const HitsParRessource & b) const
  {
  		if(a.nbHits == b.nbHits)
  		{
  			return a.localisationDeLaRessource < b.localisationDeLaRessource;
  		}
    	else
    	{
    		return a.nbHits > b.nbHits;
		}
  }
  
};
typedef set <HitsParRessource,pageHitsComparator> TSetPagesHits;

//typedef unordered_map <string, Page> TMapNomPage;
typedef map <string, Page> TMapNomPage;

//------------------------------------------------------------------------
// Rôle de la classe <EnsemblePages>
//	La classe EnsemblePages est chargée du stockage en mémoire d'informations 
// relatives au visites des documents webs à partir d'objets "Requete". 
// La classe EnsemblePages est également chargée d'extraire et de restituer 
// des informations à partir des données sur les visites des documents
// webs, telles qu'une collection ordonnée des pages les plus visitées.
//------------------------------------------------------------------------

class EnsemblePages 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	TMapNomPage::const_iterator ObtenirIterateurSur(const string & nomDeLaPage) const;	
	
	TMapNomPage::const_iterator ObtenirDebutPages() const;
	
	TMapNomPage::const_iterator ObtenirFinPages() const;
	
	const TSetPagesHits ObtenirLesNPremiers (int n = 10) const;
	// Mode d'emploi : 
	//	renvoie les N premieres paires de nombres de hits total et pages tries par ordre decroissant de nombre de hits
	// Contrat :
	//
	
	unsigned int AjouterRequete (const Requete& r);
	// Mode d'emploi :
	// Utilise l'URL du document et l'URL du document référent pour les ajouter aux différents ensembles de la classe.
	// L'ajout de la requête ne s'effectue que si elle convient aux contraintes fixées à la création de la classe.
	// Si il n'existe pas d'Objet Page associé aux URL, ils seront créés.
	// Dans tous les cas l'URL du document référent est ajouté à la liste des URL référentes du document chargé.
	// De plus, on ajoute l'URL du document chargé au classement si elle n'y est pas.
	// Le nombre de Hits associé au document chargé est incrémenté.
	//	Renvoie le nombre d'objet Page créé (maximum 2)
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    EnsemblePages ( const EnsemblePages & unEnsemblePages );
    // Mode d'emploi (constructeur de copie) :
    //	construit une copie de l'objet EnsemblePages
    // Contrat :
    //

    EnsemblePages  (int heureDebut = 0, int heureFin = 24, bool restrictionsExtensions = false);
    // Mode d'emploi :
    //cree un nouveau ensemble de pages pour de pages avec un heure comprise entre hdebut et hfin, 
	//	et avec ou sans les extensions d'image, css, javascript en dependence de ext
    // Contrat :
    //

    virtual ~EnsemblePages ( );
    // Mode d'emploi :
    //	detruit l'objet EnsemblePages
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées


protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

 	unsigned int hDebut;
	unsigned int hFin;
	bool extensionsImgJsCssAutorisees;

	TSetPagesHits pageHits;
	TMapNomPage pages;
	
	

//---------------------------------------------------------- Classes amies

//friend class EnsemblePagesDAO;

//-------------------------------------------------------- Classes privées


//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <EnsemblePages>

#endif // EnsemblePages_H


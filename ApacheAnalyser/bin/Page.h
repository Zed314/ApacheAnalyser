/*************************************************************************
                    	Page-Interface de la classe Page
	La classe Page est conçue pour représenter une page du site internet 
		de maniére à mettre en évidence les visites et leurs origines.

                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Page> (fichier Page.h) ----------------
#if ! defined ( PAGE_H )
#define PAGE_H

//--------------------------------------------------- Interfaces utilisées
#include <iterator>
#include <map>
#include <unordered_map>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
typedef std::map <std::string,unsigned int > RefHits;

//------------------------------------------------------------------------
// Rôle de la classe <Page>
//  La classe Page est chargé de stoquer et mettre a jour les differents 
//  referenceurs d'une page et son nombre total de hits.
//------------------------------------------------------------------------

class Page
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	unsigned int AjouterUnReferenceur(const std::string & urlDuReferenceur);
	// Mode d'emploi :
    //  Ajoute dans la liste des URL référençant l'URL du
	//  document internet passé en paramétre. Si l'URL est déjà enregistrée,
	//  on incrémente le nombre de "Hits" associé à cette URL référente.
	//  Dans les deux cas, on incrémente le nombre de Hits associé à l'objet Page
	//  courant. 
	//  Retourne le nombre de Hits associé à la Page après incrémentation
    // Contrat :
    //
	
	RefHits::const_iterator ObtenirUnIterateurDeDebut() const;
	// Mode d'emploi : 
    //  Retourne un const_iterator pointant sur le début de la
	//  liste des URL référençant la page
    // Contrat :
    //
	
	RefHits::const_iterator ObtenirUnIterateurDeFin() const;
	// Mode d'emploi : 
    //  Retourne un const_iterator pointant sur la fin de la
	//  liste des URL référençant la page
    // Contrat :
    //
    
//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Page ( );
    // Mode d'emploi :
    //  Construit une page vide avec nbHitsTotal = 0
    // Contrat :
    //

    virtual ~Page ( );
    // Mode d'emploi :
    //  Detruit la page
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

RefHits pagesReferentes;

unsigned int nbHitsTotal;

};

//-------------------------------- Autres définitions dépendantes de <Page>

#endif // Page_H


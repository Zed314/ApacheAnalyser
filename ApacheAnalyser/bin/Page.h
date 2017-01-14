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
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <iterator>
#include <map>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Page>
//
//
//------------------------------------------------------------------------

class Page
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
	unsigned int AjouterUnReferenceur(const string & urlDuReferenceur);
	 // Mode d'emploi :Ajoute dans la liste des URL référençant l'URL du
	 // document internet passé en paramétre. Si l'URL est déjà enregistrée,
	 // on incrémente le nombre de "Hits" associé à cette URL référente.
	 // Dans les deux cas, on incrémente le nombre de Hits associé à l'objet Page
	 //courant. 
	 // Retourne le nombre de Hits associé à la Page après incrémentation
    // Contrat :
    //
	
	map <string,unsigned int >::const_iterator ObtenirUnIterateurDeDebut() const;
	 // Mode d'emploi : Retourne un const_iterator pointant sur le début de la
	 // liste des URL référençant la page
    // Contrat :
    //
	
	map <string,unsigned int >::const_iterator ObtenirUnIterateurDeFin() const;
	 // Mode d'emploi : Retourne un const_iterator pointant sur la fin de la
	 // liste des URL référençant la page
    // Contrat :
    //
//------------------------------------------------- Surcharge d'opérateurs
    Page & operator = ( const Page & unPage );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Page ( const Page & unPage );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Page ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Page ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

map <string, unsigned int> pagesReferentes;

unsigned int nbHitsTotal;


};

//-------------------------------- Autres définitions dépendantes de <Page>

#endif // Page_H


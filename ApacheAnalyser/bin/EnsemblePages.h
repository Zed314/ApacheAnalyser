/*************************************************************************
                           EnsemblePages  -  un ensemble de documents web 
                             -------------------
    début                : 10/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EnsemblePages> (fichier EnsemblePages.h) ----------------
#if ! defined ( EnsemblePages_H )
#define EnsemblePages_H

//--------------------------------------------------- Interfaces utilisées
#include <Page.h>
#include <Requete.h>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EnsemblePages>
//	la classe modelise une collection de documents web (Pages)
//	elle permets aussi de trier les pages en fonction de nombre de hits de chacune
//------------------------------------------------------------------------

class EnsemblePages :
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
	
	multimap <int, string> GetTopN (int n = 10) const;
	// Mode d'emploi : 
	//	renvoie les N premieres paires de nombres de hits total et pages tries par ordre decroisant de nombre de hits
	// Contrat :
	//
	
	int AjouterRequete (const Requete& r);
	// Mode d'emploi :
	//	ajoute les pages referante et cible de la Requete r dans l'ensemble s'elles ne sont pas deja presents
	//	renvoie le nombre de pages ajoutees
	// Contrat :
	//

//------------------------------------------------- Surcharge d'opérateurs
    EnsemblePages & operator = ( const EnsemblePages & unEnsemblePages );
    // Mode d'emploi :
    //	surcharge l'operator reference pour la classe EnsemblePages
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EnsemblePages ( const EnsemblePages & unEnsemblePages );
    // Mode d'emploi (constructeur de copie) :
    //	construit une copie de l'objet EnsemblePages
    // Contrat :
    //

    EnsemblePages (int hdebut = 0, int hfin = 24, bool ext = false);
    // Mode d'emploi :
    //	cree un nouveau ensemble de pages pour de pages avec un heure comprise entre hdebut et hfin, 
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
	int hdebut;
	int hfin;
	bool sansExtImgJsCss;
	multimap <int, string> pageHits;
	multimap <string, Page> pages;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//---------------------------------------------- Types dépendants de <EnsemblePages>

#endif // EnsemblePages_H


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

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Page>
//
//
//------------------------------------------------------------------------

class Page : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
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

};

//-------------------------------- Autres définitions dépendantes de <Page>

#endif // Page_H


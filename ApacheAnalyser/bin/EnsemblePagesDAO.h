/*************************************************************************
    	EnsemblePagesTDAO  - Interface de la classe EnsemblePagesTDAO
    	
		 Classe chargée des échanges de la classe EnsemblePages 
							 avec le systeme de fichier.
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EnsemblePagesTDAO> (fichier EnsemblePagesTDAO.h) ----------------
#if ! defined ( ENSEMBLEPAGESTDAO_H )
#define ENSEMBLEPAGESTDAO_H

//--------------------------------------------------- Interfaces utilisées
#include "EnsemblePages.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EnsemblePagesTDAO>
// Classe chargée des échanges de la classe EnsemblePages 
// avec le systeme de fichier. Permet l'extraction des données depuis 
// un objet EnsemblePages pour générer un fichier .dot 
// lisible par l'outil GraphViz.
//
//------------------------------------------------------------------------

class EnsemblePagesTDAO
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
    EnsemblePagesTDAO & operator = ( const EnsemblePagesTDAO & unEnsemblePagesTDAO );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EnsemblePagesTDAO ( const EnsemblePagesTDAO & unEnsemblePagesTDAO );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EnsemblePagesTDAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EnsemblePagesTDAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <EnsemblePagesTDAO>

#endif // ENSEMBLEPAGESTDAO_H


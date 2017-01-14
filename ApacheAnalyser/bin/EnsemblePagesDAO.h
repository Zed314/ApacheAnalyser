/*************************************************************************
    	EnsemblePagesDAO  - Interface de la classe EnsemblePagesDAO
    	
		 Classe chargée des échanges de la classe EnsemblePages 
							 avec le systeme de fichier.
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <EnsemblePagesDAO> (fichier EnsemblePagesDAO.h) ----------------
#if ! defined ( ENSEMBLEPAGESDAO_H )
#define ENSEMBLEPAGESDAO_H
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
//#include "EnsemblePages.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <EnsemblePagesDAO>
// Classe chargée des échanges de la classe EnsemblePages 
// avec le systeme de fichier. Permet l'extraction des données depuis 
// un objet EnsemblePages pour générer un fichier .dot 
// lisible par l'outil GraphViz.
//
//------------------------------------------------------------------------

class EnsemblePagesDAO
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool ExisteEtNonProtegeEnLecture() const;
    // Mode d'emploi : Permet de savoir s'il existe un fichier portant
    // le nom "nomFichierSortie". On ne fait pas la différence entre un
    // fichier n'existant pas et un fichier protégé en lecture.
    
    bool EstVide() const;
    // Mode d'emploi : Permet de savoir s'il existe un fichier portant
    // le nom "nomFichierSortie" et si il est vide.
    //Si le fichier n'existe pas ou qu'il est protégé en lecture, il est considéré
    //comme vide.
    bool EcriturePossible()const;
     // Mode d'emploi : Permet de savoir si on peut écrire dans le fichier, c'est
     // à dire si il n'est pas protégé en écriture
//------------------------------------------------- Surcharge d'opérateurs
    EnsemblePagesDAO & operator = ( const EnsemblePagesDAO & unEnsemblePagesDAO );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    EnsemblePagesDAO ( const EnsemblePagesDAO & unEnsemblePagesDAO );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    EnsemblePagesDAO (string nomFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~EnsemblePagesDAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
string nomFichierSortie;
ofstream fichierSortie;

};

//-------------------------------- Autres définitions dépendantes de <EnsemblePagesDAO>

#endif // ENSEMBLEPAGESDAO_H


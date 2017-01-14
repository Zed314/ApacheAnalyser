/*************************************************************************
                 	Requete - Interface de la classe Requete
	La classe Requete offre une représentation simplifiée d'une Requete GET
				telle que présente dans une ligne de log Apache
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/


//---------- Interface de la classe <Requete> (fichier Requete.h) ----------------
#if ! defined ( REQUETE_H )
#define REQUETE_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//
//
//------------------------------------------------------------------------

class Requete
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    bool AUneExtensionImgCssJS()const;
    // Mode d'emploi : Renvoit Vrai si la requete porte sur un document Web
    //	au format Image, CSS ou Javascript
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Requete & operator = ( const Requete & unRequete );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Requete ( const Requete & unRequete );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Requete (string ligneDeLog);
    // Mode d'emploi : Permet de construire l'objet Requete 
    // à partir d'une ligne de log Apache fournie en paramétre
    //
    // Contrat : La ligne de log doit être valide 
    //

    virtual ~Requete ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	bool aUneExtensionImgCssJS;
};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // Requete_H


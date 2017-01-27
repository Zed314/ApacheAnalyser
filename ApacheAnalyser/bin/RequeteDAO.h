/*************************************************************************
             RequeteDAO  -  Interface de la classe RequeteDAO
	RequeteDAO est une classe permettant l'extraction des requetes depuis 
		un fichier ainsi que son utilisation par la classe EnsemblePages
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <RequeteDAO> (fichier RequeteDAO.h) ----------------
#if ! defined ( REQUETEDAO_H )
#define REQUETEDAO_H
using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <fstream>
#include "Requete.h"
#include "EnsemblePages.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <RequeteDAO>
//	RequeteDAO est une classe permettant l'extraction des requetes depuis 
// un fichier ainsi que son utilisation par la classe EnsemblePages.
// Pour cela, elle est en mesure de lire un fichier à partir de son nom
// et de transmettre à un objet Requete une ligne de logs
//------------------------------------------------------------------------

class RequeteDAO
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    int ExtraireLesDonnees(EnsemblePages & EnsemblePagesACompleter);
    // Mode d'emploi : Extraits les données en provenance de flux fichier et créé les
    // requetes associées pour les insérer dans un EnsemblePages.L'objet EnsemblePages
    // choisira si il doit accepter ou non les informations en provenances des requetes
    // en fonction de ses contraintes.
    // Retourne le nombre de lignes lues et -1 si une erreur est survenue lors de la lecture
    
    bool EstLisible() const;
    // Mode d'emploi : Renvoie true si le fichier ayant comme nom 
    // l'attribut fichierSource est lisible et false sinon.
    // Lisible signifie que le fichier existe et qu'on a 
    // les droits de lecture dessus
    
    bool EstVide() const;
    // Mode d'emploi : Renvoie true si le fichier ayant comme nom 
    // l'attribut fichierSource est vide et false sinon
    // Si on n'a pas les droit en lecture, renvoie true
	

//------------------------------------------------- Surcharge d'opérateurs
    RequeteDAO & operator = ( const RequeteDAO & unRequeteDAO );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    RequeteDAO ( const RequeteDAO & uneRequeteDAO );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    RequeteDAO (string nomDuFichier);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~RequeteDAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	string nomFichierSource;
	ifstream fichierSource;

};

//-------------------------------- Autres définitions dépendantes de <RequeteDAO>

#endif // REQUETEDAO_H


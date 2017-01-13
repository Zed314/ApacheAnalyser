/*************************************************************************
                           RequeteTDAO  -  description
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <RequeteTDAO> (fichier RequeteTDAO.h) ----------------
#if ! defined ( REQUETETDAO_H )
#define REQUETETDAO_H

//--------------------------------------------------- Interfaces utilisées
#include Requete.h
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <RequeteTDAO>
//
//
//------------------------------------------------------------------------

class RequeteTDAO
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
    RequeteTDAO & operator = ( const RequeteTDAO & unRequeteTDAO );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    RequeteTDAO ( const RequeteTDAO & unRequeteTDAO );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    RequeteTDAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~RequeteTDAO ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <RequeteTDAO>

#endif // REQUETETDAO_H


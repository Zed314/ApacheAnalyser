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

using namespace std;
//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <set>
//------------------------------------------------------------- Constantes
const std::string adresseRacine = "http://intranet-if.insa-lyon.fr";
const std::set <string> extensionsImageJsCss = {"ICO", "JPG", "PNG", "BMP","GIF","TIF","CSS","JS", "ICS"};


//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Requete>
//  stoquer les differents informations presents dans une ligne de log 
//  Apache
//------------------------------------------------------------------------

class Requete
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    unsigned int ObtenirHeure() const;
    // Mode d'emploi : 
    //  Renvoie l'heure à laquelle a été passée la Requete
   
    std::string ObtenirURI() const;	
    // Mode d'emploi : 
    //  Renvoie une chaine de caractere correspondant à la 
	//  page consernée par la requête.

	std::string ObtenirReferent() const;
	// Mode d'emploi : 
    //  Renvoie une chaine de caractere correspondant à la 
	//  page référente de la page consernée par la requête. Si la page est située
	//  sur un autre site, on ne renvoie que le nom de domaine du site, sinon que 
	//  son emplacement par rapport à la racine
    // Contrat :
    //  
        
    bool AUneExtensionImgCssJS() const;
    // Mode d'emploi : 
    //  Renvoie Vrai si la requete porte sur un document Web
    //  au format Image, CSS ou Javascript. Les extensions en questions sont
    //  contenus dans le set extensionsImageJsCss
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs


//-------------------------------------------- Constructeurs - destructeur
    Requete (std::string ligneDeLog);
    // Mode d'emploi : 
    //  Permet de construire l'objet Requete 
    //  à partir d'une ligne de log Apache fournie en paramétre
    // Contrat : La ligne de log doit être valide 
    //

    virtual ~Requete ( );
    // Mode d'emploi : 
    //  permet de detruire un objet de type Requete
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    std::string logname;
    std::string username;
    std::string gmt;
	std::string ressource;
	std::string referenceur;
	std::string ip;
	std::string dateEtHeure;
	std::string typeDeRequete;
    std::string protocol;
	unsigned int codeHTTP;
    unsigned int dataSize;
	std::string navigateur;
	std::string extensionRessource;
	
};

//-------------------------------- Autres définitions dépendantes de <Requete>

#endif // Requete_H


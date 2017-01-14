/*************************************************************************
    	EnsemblePagesTDAO  - Réalisation de la classe EnsemblePagesTDAO
    	
 				Classe chargée des échanges de la classe EnsemblePages 
 									avec le systeme de fichier.
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <EnsemblePagesTDAO> (fichier EnsemblePagesTDAO.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "EnsemblePagesTDAO.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type EnsemblePagesTDAO::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
EnsemblePagesTDAO & EnsemblePagesTDAO::operator = ( const EnsemblePagesTDAO & unEnsemblePagesTDAO )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EnsemblePagesTDAO::EnsemblePagesTDAO ( const EnsemblePagesTDAO & unEnsemblePagesTDAO )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EnsemblePagesTDAO>" << endl;
#endif
} //----- Fin de EnsemblePagesTDAO (constructeur de copie)


EnsemblePagesTDAO::EnsemblePagesTDAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <EnsemblePagesTDAO>" << endl;
#endif
} //----- Fin de EnsemblePagesTDAO


EnsemblePagesTDAO::~EnsemblePagesTDAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EnsemblePagesTDAO>" << endl;
#endif
} //----- Fin de ~EnsemblePagesTDAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


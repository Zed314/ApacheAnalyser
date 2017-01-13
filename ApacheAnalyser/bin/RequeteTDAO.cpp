/*************************************************************************
                           RequeteTDAO  -  description
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <RequeteTDAO> (fichier RequeteTDAO.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "RequeteTDAO.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RequeteTDAO::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
RequeteTDAO & RequeteTDAO::operator = ( const RequeteTDAO & unRequeteTDAO )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
RequeteTDAO::RequeteTDAO ( const RequeteTDAO & unRequeteTDAO )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <RequeteTDAO>" << endl;
#endif
} //----- Fin de RequeteTDAO (constructeur de copie)


RequeteTDAO::RequeteTDAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <RequeteTDAO>" << endl;
#endif
} //----- Fin de RequeteTDAO


RequeteTDAO::~RequeteTDAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RequeteTDAO>" << endl;
#endif
} //----- Fin de ~RequeteTDAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


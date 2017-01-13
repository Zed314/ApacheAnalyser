/*************************************************************************
                 Page  - Réalisation de la classe Page
	La classe Page est conçue pour représenter une page du site internet 
		de maniére à mettre en évidence les visites et leurs origines.
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Page> (fichier Page.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Page.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Page::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Page & Page::operator = ( const Page & unPage )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Page::Page ( const Page & unPage )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Page>" << endl;
#endif
} //----- Fin de Page (constructeur de copie)


Page::Page ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Page>" << endl;
#endif
} //----- Fin de Page


Page::~Page ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Page>" << endl;
#endif
} //----- Fin de ~Page


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


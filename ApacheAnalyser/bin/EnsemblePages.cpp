/*************************************************************************
          EnsemblePages  -  Interface de la classe EnsemblePages
          
 				La classe EnsemblePages modélise une collection de 
 					pages web du nombre de visites associé
                             -------------------
    début                : 10/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <EnsemblePages> (fichier EnsemblePages.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <string>
#include <map>
//------------------------------------------------------ Include personnel
#include "EnsemblePages.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type EnsemblePages::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

map <unsigned int, string> EnsemblePages::ObtenirLesNPremiers(int n) const
{
	map <unsigned int, string> a; return a;
	
}//----- Fin de ObtenirLesNPremiers

unsigned int EnsemblePages::AjouterRequete (const Requete& r)
{
	return 0;
}//----- Fin de AjouterRequete

//------------------------------------------------- Surcharge d'opérateurs
EnsemblePages & EnsemblePages::operator = ( const EnsemblePages & unEnsemblePages )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
EnsemblePages::EnsemblePages ( const EnsemblePages & unEnsemblePages )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <EnsemblePages>" << endl;
#endif
} //----- Fin de EnsemblePages (constructeur de copie)


EnsemblePages::EnsemblePages (int heureDebut, int heureFin, bool restrictionsExtensions):hDebut(heureDebut),hFin(heureFin),sansExtensionsImgJsCss(restrictionsExtensions)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <EnsemblePages>" << endl;
#endif
} //----- Fin de EnsemblePages


EnsemblePages::~EnsemblePages ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <EnsemblePages>" << endl;
#endif
} //----- Fin de ~EnsemblePages


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées


/*************************************************************************
             RequeteDAO  -  Réalisation de la classe RequeteDAO
	RequeteDAO est une classe permettant l'extraction des requetes depuis 
		un fichier ainsi que son utilisation par la classe EnsemblePages
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <RequeteDAO> (fichier RequeteDAO.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <fstream>
#include <string>

//------------------------------------------------------ Include personnel
#include "RequeteDAO.h"
#include "EnsemblePages.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type RequeteDAO::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
int RequeteDAO::ExtraireLesDonnees(EnsemblePages & EnsemblePagesACompleter)
{
	if(!this->EstLisible())
	{
		return -1;
	}
	fichierSource.clear();
	fichierSource.seekg(0, ios::beg);
	string ligneLue;
	int nbLignesLues=0;
   while(getline(fichierSource,ligneLue))
   {
   	nbLignesLues++;
   	EnsemblePagesACompleter.AjouterRequete(Requete(ligneLue));
   }
   return nbLignesLues;


} //----- Fin de ExtraireLesDonnees


bool RequeteDAO::EstLisible() const
{
	 return !fichierSource.fail(); 
} //----- Fin de EstLisible

//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur



RequeteDAO::RequeteDAO (string nomDuFichier)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <RequeteDAO>" << endl;
#endif
nomFichierSource=nomDuFichier;
fichierSource.open(nomFichierSource);
} //----- Fin de RequeteDAO


RequeteDAO::~RequeteDAO ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <RequeteDAO>" << endl;
#endif
fichierSource.close();
} //----- Fin de ~RequeteDAO


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


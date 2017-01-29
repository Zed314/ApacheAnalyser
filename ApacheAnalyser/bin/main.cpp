/*************************************************************************
                 					ApacheAnalyser
Application permettant l'analyse de logs Apache pour générer des 
statistiques, telles que le nombre de visites par document, 
ainsi que la génération d'un graphe au format .dot lisible par l'outil GraphViz
                             -------------------
    début                : 13/01/2017
    copyright            : (C) 2017 par Horia-Cristian Burca et Ziggy Vergne
    e-mail               : horia-cristian.burca@insa-lyon.fr et ziggy.vergne@insa-lyon.fr
*************************************************************************/

#include <iostream>
#include <map>
#include <string>
#include <iterator>



#include "RequeteDAO.h"
#include "EnsemblePagesDAO.h"
#include "EnsemblePages.h"

using namespace std;

const string MAN = "Regardez le manuel pour plus apprendre à utiliser la commande.";

//Fonction qui transforme un element du set <HitsParRessource,pageHitsComparator> en un string et le renvoie
string HitsParRessourceSetToString (set <HitsParRessource,pageHitsComparator> hitsSet)
{
	string output = "";
	TSetPagesHits::const_iterator it;
	for (it = hitsSet.cbegin(); it != hitsSet.cend(); it++)
	{
		output += (*it).ToString() + "\r\n";	
	}

	return output;
}//----- Fin de HitsParRessourceSetToString

int main(int argc, char** argv)
{	
	int i = 0;
	bool restrictionExtensions = false;
	bool restrictionHoraires = false;
	int heureDebut = 0;
	int heureFin = 24;
	string nomFichierSortie;
	string nomFichierEntree;

	string * parametres = new string[argc];
	for(i=0;i<argc;i++)
	{
		parametres[i]=argv[i];
	}

	// Gerer les differents parametres
	for(i = 1; i < argc-1; i++)
	{
		if(parametres[i]=="-e")
		{
			restrictionExtensions = true;
			
		}
		else if(parametres[i]=="-t")
		{
			if(i<argc-2)
			{
				try 
				{
					heureDebut = stoi(parametres[i+1]);
					if (heureDebut < 0 || heureDebut > 24)
					{
						cerr << "Erreur dans la lecture du parametre t: temps plus grand que 24 ou négatif." << endl;
						cerr << MAN << endl;
						return EXIT_FAILURE;
					}
					
					heureDebut %= 24;//Pour mettre l'heure à 0 si elle vaut 24.
					
					heureFin = heureDebut + 1;
					restrictionHoraires = true;
					i++;
				}
				catch (exception e)
				{
					cerr << "Erreur dans la lecture du paramétre t." << endl;
					cerr << MAN << endl;
					return EXIT_FAILURE;
				}
				
			}
			else
			{
				cerr<<"Erreur, veuillez indiquer le temps."<<endl;
				cerr << MAN << endl;
				return EXIT_FAILURE;
			}
		}
		else if(parametres[i]=="-g")
		{
			if(i<argc-2)
			{
				nomFichierSortie = parametres[i+1];
				i++;
			}	
			else
			{
					cerr<<"Erreur dans la lecture du paramétre g."<<endl;
					cerr << MAN << endl;
					return EXIT_FAILURE;
			}		
		}
		else
		{
			cerr<<"Erreur dans la lecture des paramétres, paramétre \""<<parametres[i]<<"\" inconnu."<<endl;
			cerr << MAN << endl;
			return EXIT_FAILURE;
		}
		
	}
	//----- Fin de gerer les differents parametres

	// Gerer le nom de fichier log
	if(argc == 1)
	{
		cerr<<"Erreur : Fichier d'entrée manquant"<<endl;
		cerr << MAN << endl;
		return EXIT_FAILURE;
	}
	else
	{
		nomFichierEntree = parametres[i];
	}
	//----- Fin de gerer le nom de fichier log
	
	EnsemblePages ensPages( heureDebut,heureFin, restrictionExtensions);
	RequeteDAO reqDAO(nomFichierEntree);
	
	if(!reqDAO.EstLisible())
	{
		cerr<<"Erreur : Le fichier "+nomFichierEntree+" est illisible."<<endl;
		return EXIT_FAILURE;
	}
	else if(reqDAO.EstVide())
	{
		cerr<<"Erreur : Le fichier "+nomFichierEntree+" est vide."<<endl;
		return EXIT_FAILURE;
	}
	else
	{
		

		
		
		// Verifier si l'option "-g" a ete utilise et generer le fichier .dot dans le cas echeant
		if(nomFichierSortie != "")  
		{	
			EnsemblePagesDAO ensPagesDAO(nomFichierSortie);
			if(ensPagesDAO.EcriturePossible() && ensPagesDAO.EstVide())
			{
				if (restrictionHoraires)
				{
					cout<<"Attention! Seules les requêtes entre "<<heureDebut<<"h et "<<heureFin<<"h ont été prises en compte."<<endl;
				}
				reqDAO.ExtraireLesDonnees(ensPages);
				cout << HitsParRessourceSetToString(ensPages.ObtenirLesNPremiers(10));
				ensPagesDAO.ExporterUnGraphe(ensPages);
				cout<<"Fichier graphe généré"<<endl;
			}
			else if(!ensPagesDAO.EstVide())
			{
		
				cerr<<"On ne peut pas écrire dans le fichier \""<<nomFichierSortie<<"\", il est non vide."<<endl;
				return EXIT_FAILURE;
			}
			else
			{
				cerr<<"Impossible d'écrire dans le fichier \""<<nomFichierSortie<<"\", il est protégé en écriture!"<<endl;
				return EXIT_FAILURE;
			}

		}
		else
		{
			if (restrictionHoraires)
			{
				cout<<"Attention! Seules les requêtes entre "<<heureDebut<<"h et "<<heureFin<<"h ont été prises en compte."<<endl;
			}
			reqDAO.ExtraireLesDonnees(ensPages);
			cout << HitsParRessourceSetToString(ensPages.ObtenirLesNPremiers(10));
		}
	}
	
	delete[] parametres;
	
	return EXIT_SUCCESS;
}


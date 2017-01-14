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

#include "Page.h"
#include "Requete.h"
#include "RequeteDAO.h"
#include "EnsemblePagesDAO.h"
#include "EnsemblePages.h"

using namespace std;

void testRequete()
{
	string texteDeTest="192.168.0.0 - - [08/Sep/2012:11:16:06 +0200] \"GET /temps/4IF18.html HTTP/1.1\" 200 5192 \"http://intranet-if.insa-lyon.fr/temps/4IF17.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";
	Requete requeteDeTest(texteDeTest);
	cout<<"Referent:"<<requeteDeTest.ObtenirReferent()<<endl;
	cout<<"URI:"<<requeteDeTest.ObtenirURI()<<endl;
	cout<<"Heure:"<<requeteDeTest.ObtenirHeure()<<endl;
	cout<<"Code HTTP:"<<requeteDeTest.ObtenirCodeHTTP()<<endl;
	cout<<"Est une image/JS/CSS?:"<<requeteDeTest.AUneExtensionImgCssJS()<<endl;
	cout<<"IP:"<<requeteDeTest.ObtenirIP()<<endl;
}


/*
void testPage()
{
	Page p;
	p.AjouterUnReferenceur("index.html");
	p.AjouterUnReferenceur("index.html");
	p.AjouterUnReferenceur("index.html");
	p.AjouterUnReferenceur("index2.html");
	p.AjouterUnReferenceur("a.html");
	p.AjouterUnReferenceur("-");
	for(map <string, unsigned int>::const_iterator it=p.ObtenirUnIterateurDeDebut();it!=p.ObtenirUnIterateurDeFin();it++)
	{
		cout<<it->first<<":"<<it->second<<endl;
	}

	
}
*/


void testEnsemblePages()
{
string texteDeTest="192.168.0.0 - - [08/Sep/2012:11:16:06 +0200] \"GET /temps/4IF18.html HTTP/1.1\" 200 5192 \"http://intranet-if.insa-lyon.fr/temps/4IF17.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";
	Requete requeteDeTest(texteDeTest);
	EnsemblePages ens;
	cout<<"Ajout requete"<<endl;
	ens.AjouterRequete(requeteDeTest);
}
void testRequeteDAO()
{
	RequeteDAO req("../c");
	EnsemblePages ens;
	req.ExtraireLesDonnees(ens);
	
		
}
void testEnsemblePagesDAO()
{
	EnsemblePagesDAO a("fichierProtEcriture");
	cout<<a.EstVide();
	cout<<a.ExisteEtNonProtegeEnLecture();
	cout<<a.EcriturePossible();
	EnsemblePagesDAO b("fichierProtLecture");
	cout<<b.EstVide();
	cout<<b.ExisteEtNonProtegeEnLecture();
	cout<<b.EcriturePossible();
	EnsemblePagesDAO c("fichierNonExistant");
	cout<<c.EstVide();
	cout<<c.ExisteEtNonProtegeEnLecture();
	cout<<c.EcriturePossible();
	EnsemblePagesDAO d("fichierNonVide");
	cout<<d.EstVide();
	cout<<d.ExisteEtNonProtegeEnLecture();
	cout<<d.EcriturePossible();
}
bool peutEtreConvertie(const string &stringAVerifier)
{
	

		return((stringAVerifier[0]>='0'&&stringAVerifier[0]<='9')||(stringAVerifier[0]=='-'&&(stringAVerifier[1]>='0'&&stringAVerifier[1]<='9')));
	
}
int main(int argc, char** argv)
{

		//cout<<"Erreur, merci de renseigner un fichier de log"<<endl;
	
	int i=0;
	bool restrictionExtensions=false;
	bool restrictionHoraires=false;
	int heureDebut=0;
	string nomFichierSortie;
	string nomFichierEntree;
	string * parametres = new string[argc];
	for(i=0;i<argc;i++)
	{
		parametres[i]=argv[i];
		cout<<parametres[i]<<endl;
	}

	for(i=1;i<argc-1;i++)
		{
			if(parametres[i]=="-e")
			{
				restrictionExtensions=true;
			}
			else if(parametres[i]=="-t")
			{
				if(i<argc-2)
				{
					if(peutEtreConvertie(parametres[i+1]))
					{
						heureDebut=stoi( parametres[i+1]);
						restrictionHoraires=true;
						i++;
					}
					else
					{
						cout<<"Erreur dans la lecture du paramétre t"<<endl;
					}

					
				}
				else
				{
					cout<<"Erreur, veuillez indiquer le temps"<<endl;
				}
			}
			else if(parametres[i]=="-g")
			{
				if(i<argc-2)
				{
					nomFichierSortie=parametres[i+1];
					i++;
				}	
				else
				{
						cout<<"Erreur dans la lecture du paramétre g"<<endl;
				}		
			}
			else
			{
				cout<<"Erreur dans la lecture des parametres, parametre\""<<parametres[i]<<"\"inconnu"<<endl;
			}
			
		}
		if(argc==1)
		{
			cout<<"Erreur: Fichier d'entrée manquant"<<endl;
			nomFichierEntree="";
		}
		else
		{
			nomFichierEntree=parametres[i];
		}
		cout<<"RestExt="<<restrictionExtensions<<endl;
		cout<<"ResH="<<restrictionHoraires<<endl;
		cout<<"HDebut="<<heureDebut<<endl;
		cout<<"nFs="<<nomFichierSortie<<endl;
		cout<<"nFe="<<nomFichierEntree<<endl;
	delete[] parametres;
	
	//testPage();
	//testRequete();
	testRequeteDAO();
	//testEnsemblePages();
	return 0;
}


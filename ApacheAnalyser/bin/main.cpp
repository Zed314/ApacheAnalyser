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

string HitsParRessourceSetToString (set <HitsParRessource,pageHitsComparator> hitsSet)
{
	string output = "";
	set <HitsParRessource,pageHitsComparator>::const_iterator it;
	for (it = hitsSet.cbegin(); it != hitsSet.cend(); it++)
	{
		output += (*it).ToString() + "\r\n";	
	}

	return output;
}

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
	RequeteDAO req("../anonyme.log");
	EnsemblePages ens;
	req.ExtraireLesDonnees(ens);
	cout << HitsParRessourceSetToString(ens.ObtenirLesNPremiers(10));	
		
}
void testEnsemblePagesDAO()
{
/*	EnsemblePagesDAO a("fichierProtEcriture");
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
	cout<<d.EcriturePossible();*/
	string texteDeTest="192.168.0.0 - - [08/Sep/2012:11:16:06 +0200] \"GET /temps/4IF18.html HTTP/1.1\" 200 5192 \"http://intranet-if.insa-lyon.fr/temps/4IF17.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";
	Requete requeteDeTest(texteDeTest);
	EnsemblePages ens;
	cout<<"Ajout requete"<<endl;
	ens.AjouterRequete(requeteDeTest);
	EnsemblePagesDAO a("fichierExport");
	a.ExporterUnGraphe(ens);
	
}
void testAll()
{
	//RequeteDAO req("../anonyme.log");
	RequeteDAO req("b");
	EnsemblePages ens;
	req.ExtraireLesDonnees(ens);
		EnsemblePagesDAO a("fichierExport");
	a.ExporterUnGraphe(ens);
}
bool peutEtreConvertie(const string &stringAVerifier)
{
	

		return((stringAVerifier[0]>='0'&&stringAVerifier[0]<='9')||(stringAVerifier[0]=='-'&&(stringAVerifier[1]>='0'&&stringAVerifier[1]<='9')));
	
}
void affichageRestrictionsHoraires(int hdebut,int hfin, bool restrictionsHoraires)
{
	if(restrictionsHoraires)
	{
		if(hdebut<0)
		{
			hdebut=0;
		}
		else if(hdebut>=24)
		{
			hdebut=23;
		}
		if(hfin>=24)
		{
			hfin=23;
		}
		else if(hfin<0)
		{
			hfin=0;
		}
	
		if(hfin<hdebut)
		{
			int heureTemp=hfin;
			hfin=hdebut;
			hdebut=heureTemp;
		
		}
		cout<<"Attention! Seuls les hits entre "<<hdebut<<"h et "<<hfin+1<<"h (exclu) ont été pris en compte"<<endl;
	}
	
}
int main(int argc, char** argv)
{
	//testRequete();
		//cout<<"Erreur, merci de renseigner un fichier de log"<<endl;
	
	int i=0;
	bool restrictionExtensions=false;
	bool restrictionHoraires=false;
	int heureDebut=0;
	int heureFin=24;
	bool uneErreurEstArrivee=false;
	string nomFichierSortie;
	string nomFichierEntree;
	string * parametres = new string[argc];
	for(i=0;i<argc;i++)
	{
		parametres[i]=argv[i];
		cout<<parametres[i]<<endl;
	}

	for(i=1;i<argc-1&&uneErreurEstArrivee==false;i++)
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
						heureFin=heureDebut;
						restrictionHoraires=true;
						i++;
					}
					else
					{
						cerr<<"Erreur dans la lecture du paramétre t"<<endl;
						uneErreurEstArrivee=true;
					}

					
				}
				else
				{
					cerr<<"Erreur, veuillez indiquer le temps"<<endl;
					uneErreurEstArrivee=true;
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
						cerr<<"Erreur dans la lecture du paramétre g"<<endl;
						uneErreurEstArrivee=true;
				}		
			}
			else
			{
				cerr<<"Erreur dans la lecture des parametres, parametre\""<<parametres[i]<<"\"inconnu"<<endl;
				uneErreurEstArrivee=true;
			}
			
		}
		if(argc==1)
		{
			cerr<<"Erreur: Fichier d'entrée manquant"<<endl;
			uneErreurEstArrivee=true;
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
		
		if(uneErreurEstArrivee)
		{
			cerr<<"Regardez le manuel pour plus apprendre à utiliser la commande."<<endl;
			
			
		}
		else
		{
			
			EnsemblePages ensPages( heureDebut,heureFin, restrictionExtensions);
			RequeteDAO reqDAO(nomFichierEntree);
			if(!reqDAO.EstLisible())
			{
				cerr<<"Le fichier "+nomFichierEntree+" est illisible."<<endl;
			}
			else
			{
				if(nomFichierSortie!="")
				{
					EnsemblePagesDAO ensPagesDAO(nomFichierSortie);
					if(ensPagesDAO.EcriturePossible()&&ensPagesDAO.EstVide())
					{
						reqDAO.ExtraireLesDonnees(ensPages);
						affichageRestrictionsHoraires(heureDebut,heureFin,restrictionHoraires);
						cout<<HitsParRessourceSetToString(ensPages.ObtenirLesNPremiers(10));
						ensPagesDAO.ExporterUnGraphe(ensPages);
						cout<<"Fichier graphe généré"<<endl;
					}
					else if(!ensPagesDAO.EstVide())
					{
				
						cerr<<"On ne peut pas écrire dans ce fichier, il est non vide."<<endl;
						
					}
					else
					{
						cerr<<"Impossible d'écrire dans ce fichier!"<<endl;
					}
	
				}
				else
				{
					reqDAO.ExtraireLesDonnees(ensPages);
					affichageRestrictionsHoraires(heureDebut,heureFin,restrictionHoraires);
					cout<<HitsParRessourceSetToString(ensPages.ObtenirLesNPremiers(10));
				}
			}
			
			
			
			
		}
		
	
	//testPage();
	//testRequete();
	//testRequeteDAO(); 
	//testEnsemblePagesDAO();
	//testEnsemblePages();
	//testAll();
	
	delete[] parametres;
	
	return 0;
}


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

using namespace std;

void testRequete()
{
	string texteDeTest="192.168.0.0 - - [08/Sep/2012:11:16:06 +0200] \"GET /temps/4IF18.html HTTP/1.1\" 200 5192 \"http://intranet-if.insa-lyon.fr/temps/4IF17.html\" \"Mozilla/5.0 (Windows NT 6.1; WOW64; rv:14.0) Gecko/20100101 Firefox/14.0.1\"";
	Requete requeteDeTest(texteDeTest);
	
}



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

int main(int argc, char** argv)
{
	//testPage();
	testRequete();
	return 0;
}


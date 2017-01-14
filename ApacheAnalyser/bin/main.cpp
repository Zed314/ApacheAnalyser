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



#include "Page.cpp"
#include <map>
#include <string>
#include <iterator>



using namespace std;

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
	testPage();
	return 0;
}


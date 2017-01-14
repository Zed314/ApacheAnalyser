OBJ= main.o Page.o EnsemblePages.o EnsemblePagesTDAO.o RequeteTDAO.o Requete.o
COMP= g++
COMPFLAG = -Wall -std=c++11 -DMAP

analog : $(OBJ)
	$(COMP) $(COMPFLAG) -o analog $(OBJ)
	
main.o : main.cpp EnsemblePages.h EnsemblePagesTDAO.h RequeteTDAO.h Requete.h
	$(COMP) $(COMPFLAG) -c main.cpp 

Page.o : Page.h Page.cpp
	$(COMP) $(COMPFLAG) -c Page.cpp

EnsemblePagesTDAO.o: Page.h EnsemblePages.h EnsemblePagesTDAO.h EnsemblePagesTDAO.cpp
	$(COMP) $(COMPFLAG) -c EnsemblePagesTDAO.cpp

EnsemblePages.o : Page.h Requete.h EnsemblePages.h EnsemblePages.cpp
	$(COMP) $(COMPFLAG) -c EnsemblePages.cpp

RequeteTDAO.o : RequeteTDAO.h Requete.h EnsemblePages.h RequeteTDAO.cpp
	$(COMP) $(COMPFLAG) -c RequeteTDAO.cpp
	
Requete.o : Requete.h Requete.cpp
	$(COMP) $(COMPFLAG) -c Requete.cpp

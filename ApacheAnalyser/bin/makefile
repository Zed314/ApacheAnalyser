OBJ= main.o Page.o EnsemblePages.o EnsemblePagesDAO.o RequeteDAO.o Requete.o
COMP= g++
COMPFLAG = -Wall -std=c++11 

#COMPFLAG = -Wall -std=c++11 -DMAP
analog : $(OBJ)
	$(COMP) $(COMPFLAG) -o analog $(OBJ)
	
main.o : main.cpp EnsemblePages.h EnsemblePagesDAO.h RequeteDAO.h Requete.h
	$(COMP) $(COMPFLAG) -c main.cpp 

Page.o : Page.h Page.cpp
	$(COMP) $(COMPFLAG) -c Page.cpp

EnsemblePagesDAO.o: Page.h EnsemblePages.h EnsemblePagesDAO.h EnsemblePagesDAO.cpp
	$(COMP) $(COMPFLAG) -c EnsemblePagesDAO.cpp

EnsemblePages.o : Page.h Requete.h EnsemblePages.h EnsemblePages.cpp
	$(COMP) $(COMPFLAG) -c EnsemblePages.cpp

RequeteDAO.o : RequeteDAO.h Requete.h EnsemblePages.h RequeteDAO.cpp
	$(COMP) $(COMPFLAG) -c RequeteDAO.cpp
	
Requete.o : Requete.h Requete.cpp
	$(COMP) $(COMPFLAG) -c Requete.cpp

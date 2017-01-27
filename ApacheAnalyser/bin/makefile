# Declaration de variables
CC = g++
CC_FLAGS = -Wall -std=c++11
CC_EXFLAGS = # -DMAP
VAL_FLAGS = --leak-check=yes

# Noms de fichiers
EXEC = analog
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# Cible principale
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)
	
# Pour les fichiers objet
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $(CC_EXFLAGS) $< -o $@
	
# Pour eviter les conflicts 
.PHONY: clean valgrind
	
# Pour effacer les fichiers generés
clean:
	rm -f $(EXEC) $(OBJECTS)
	
# Pour valgrind
valgrind:
	valgrind $(VAL_FLAGS) ./$(EXEC)

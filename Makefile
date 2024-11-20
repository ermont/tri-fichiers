# Compilateur à utiliser
CC=gcc

# Les programmes à compiler 
PROGRAMMES = trier trier-mt

# Les options de compilation : toutes les erreurs sont importantes
CFLAGS = -D_REENTRANT -I. -Wextra -pedantic -Wall -O3

# Options pour l'édition de lien, ici : -lpthread pour utiliser la librairie POSIX threads
LDFLAGS = -lpthread 

all: $(PROGRAMMES)

tri-fichier.o: SAVE/tri-fichier.o
	cp SAVE/tri-fichier.o .

trier : trier.o liste-noms.o liste-triee-noms.o tri-fichier.o

trier-mt : trier-mt.o liste-noms-mt.o liste-triee-noms.o tri-fichier.o

clean :
	\rm -f *.o *.~ 
	\rm -f $(PROGRAMMES)

archive: clean
	(cd .. ; tar cvf tri-fichiers-`whoami`.tar tri-fichiers)


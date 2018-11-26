CXXFLAGS=-Wall -pedantic -std=c++11 -g -Wno-sign-compare
LINK.o = $(LINK.cc)

PROGRAMS=eau-total eau-moyen eau-max eau-tout-en-un \
	dechets \
	dechets-tableau \
	tableau-donnees-test eau-tout-en-un2 dechets-tableau2 \
	getline-exemple \
	eau-moyen-csv eau-total-csv eau-max-csv \
	tableau-donnees-csv-test \
	arbres-hauteur

all: $(PROGRAMS)

tableau-donnees-test:     tableau-donnees.o tableau-donnees-test.o
tableau-donnees-csv-test: tableau-donnees-csv.o tableau-donnees-csv-test.o

dechets-tableau2: dechets-tableau2.o tableau-donnees.o
eau-tout-en-un2: eau-tout-en-un2.o tableau-donnees.o

arbres-hauteur: tableau-donnees-csv.o tableau-donnees.o arbres-hauteur.o

# eau-max eau-max-csv doivent être comparés à la main

test: all
	@testeq() { echo -n "Cohérence $$1 $$2:\t"; if [ "`$$1`" = "`$$2`" ]; then echo "OK"; else echo "FAILED"; fi }; \
	testeq eau-tout-en-un eau-tout-en-un2
	tableau-donnees-test
	tableau-donnees-csv-test

doc:
	doxygen -g
	doxygen

clean:
	-rm *.o
	-rm $(PROGRAMS)

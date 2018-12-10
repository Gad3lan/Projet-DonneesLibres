CXXFLAGS= -std=c++11 -Wall -pedantic -g -Wno-sign-compare
LINK.o = $(LINK.cc)

PROGRAMS=eau-total eau-moyen eau-max eau-tout-en-un \
	dechets \
	dechets-tableau \
	tableau-donnees-test eau-tout-en-un2 dechets-tableau2 \
	getline-exemple \
	eau-moyen-csv eau-total-csv eau-max-csv \
	tableau-donnees-csv-test \
	arbres-hauteur \
	dechets-csv \
	velib \
	conso-voitures

all: $(PROGRAMS)

tableau-donnees-test: tableau-donnees.o tableau-donnees-test.o
tableau-donnees-csv-test: tableau-donnees-csv.o tableau-donnees-csv-test.o

dechets-tableau2: dechets-tableau2.o tableau-donnees.o
eau-tout-en-un2: eau-tout-en-un2.o tableau-donnees.o

dechets-tableau: dechets-tableau.o
eau-tout-en-un: eau-tout-en-un.o

eau-max: eau-max.o
eau-max-csv: eau-max-csv.o
eau-moyen: eau-moyen.o
eau-moyen-csv: eau-moyen-csv.o
eau-total: eau-total.o
eau-total-csv: eau-total-csv.o

arbres-hauteur: tableau-donnees-csv.o tableau-donnees.o arbres-hauteur.o
dechets-csv: tableau-donnees-csv.o dechets-csv.o
velib: tableau-donnees-csv.o velib.o
conso-voitures: tableau-donnees-csv.o conso-voitures.o


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
	-rm *.dSYM/Contents/Info.plist
	-rm *.dSYM/Contents/Resources/DWARF/*
	-rmdir *.dSYM/Contents/Resources/DWARF
	-rmdir *.dSYM/Contents/*
	-rmdir *.dSYM/*
	-rmdir *.dSYM

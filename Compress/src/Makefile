CC=g++
CFLAGS=

IDIR = ../include
_DEPS = classeArbre.hpp classeListe.hpp classeNoeud.hpp 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

ODIR = obj
_OBJ = main.o classeArbre.o classeListe.o classeNoeud.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

compress: $(OBJ)
	$(CC) -o $@ $^

.PHONY: clean

clean:
	rm -f $(OBJ)
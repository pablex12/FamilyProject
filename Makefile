.PHONY: all clean

BANDERAS = -std=c++11 -Wall -g
SALIDA = family_project

all: code

code:
	g++ $(BANDERAS) main.cpp Person/person.cpp Reader/reader.cpp HeapTree/heap.cpp BinarySearchTree/bst.cpp Menu/menu.cpp -o $(SALIDA)

clean:
	rm -r *.dSYM $(SALIDA)
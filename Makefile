FLAG = -g -Wall -std=c99

all:
	gcc $(FLAG) -c libraries-TADs/libpilha.c
	gcc $(FLAG) -c libraries-TADs/libfila.c
	gcc $(FLAG) -c libraries-TADs/liblista.c
	gcc $(FLAG) -c libraries-Restaurant/pessoa.c
	gcc $(FLAG) -c libraries-Restaurant/contabilidade.c
	gcc $(FLAG) -c ru_na_pandemia.c
	gcc contabilidade.o pessoa.o libpilha.o libfila.o liblista.o ru_na_pandemia.o -o ru_na_pandemia
clean:
	rm -f *.o *.gch ru_na_pandemia


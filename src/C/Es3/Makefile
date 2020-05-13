Esercizio3 : Esercizio3.o hash_map.o arrayDyn.o array.o quick_sort.o
	gcc  Esercizio3.o hash_map.o arrayDyn.o array.o quick_sort.o -o Esercizio3

Esercizio3.o : Esercizio3.c
	gcc  -g -ggdb -c  Esercizio3.c

arrayDyn.o : ../../../Resources/C/HashMap/arrayDyn.c
	gcc -g -ggdb -c ../../../Resources/C/HashMap/arrayDyn.c

array.o : ../../../Resources/C/Array/array.c
	gcc -g -ggdb -c ../../../Resources/C/Array/array.c

quick_sort.o : ../../../Resources/C/QuickSort/quick_sort.c
	gcc -g -ggdb -c ../../../Resources/C/QuickSort/quick_sort.c

hash_map.o : ../../../Resources/C/HashMap/hash_map.c
	gcc -g -ggdb -c ../../../Resources/C/HashMap/hash_map.c

clean:
	del -f *.o

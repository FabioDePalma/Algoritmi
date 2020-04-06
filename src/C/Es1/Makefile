Esercizio1 : Esercizio1.o array.o insertion_sort.o quick_sort.o
	gcc Esercizio1.o array.o insertion_sort.o quick_sort.o -o Esercizio1

Esercizio1.o : Esercizio1.c
	gcc -c Esercizio1.c

array.o : ../../../Resources/C/Array/array.c
	gcc -c ../../../Resources/C/Array/array.c

insertion_sort.o : ../../../Resources/C/InsertionSort/insertion_sort.c
	gcc -c ../../../Resources/C/InsertionSort/insertion_sort.c

quick_sort.o : ../../../Resources/C/QuickSort/quick_sort.c
	gcc -c ../../../Resources/C/QuickSort/quick_sort.c

clean:
	rm -f *.o

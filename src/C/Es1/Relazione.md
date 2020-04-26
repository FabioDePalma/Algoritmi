
# Esercizio1
---
## Prefazione


L'esercizio è stato suddiviso in due parti:
   - l'implementazione dei due algoritmi InsertionSort e QuickSort e i relativi test;
   - l'applicazione degli algoritmi e la misurazione dei tempi di risposta.
* * *

L’applicativo agisce su un file contenente 20 milioni di records da ordinare composti dai seguenti campi:

- id: (tipo intero) identificatore univoco del record;
- field1: (tipo stringa) contiene parole estratte dalla divina commedia;
- field2: (tipo intero);
- field3: (tipo floating point);
* * *

Ogni algoritmo è implementato in modo tale da poter essere utilizzato su un tipo generico e ripete l'ordinamento tre volte, un volta per ciascun field;

I tempi di risposta di questi algoritmi sono stati ricavati tramite la funzione clock() una
funzione che ritorna il CPU time. Ogni valore raccolto è il risultato di due
misurazioni effettuate su due macchine aventi le seguenti caratteristiche:

	1. Intel Core i7-4510U @2.00GHz
	2. AMD Ryzen 5-3500U @2.10GHz
	3. RAM 8GB

* * *
Terminato l'ordinamento dei tre campi il risultato verrà scritto su un nuovo file "ordinato".
#
## Dati

I seguenti dati si riferiscono a frammenti del file records.csv, in quanto si è preferito analizzare più a fondo il funzionamento dei due algoritmi.
La situazione presentata di seguito è espressa dopo l’avvenuto caricamento dell’array e prima della scrittura su file del ordinamento ottenuto, ovvero il tempo effettivo di ordinamento svolto dagli algoritmi.
Sono stati riscontrati problemi con l'esecuzione sul file completo da 20.000.000 di records
causati da un comportamento anomalo delle macchine sul field 1
##
### Insertion Sort:

|n    | Tempo (s) Macchina 1 | Tempo (s) Macchina 2 |
|-----|---------------------|----------------------|
|1000 |0,024507				|0,019000				|
|10000|1,916148				|1,933000				|
|100000|414,610410			|221,825000				|

##


I dati ottenuti sono quelli che effettivamente mi aspettavo in quanto l'algoritmo del InsertionSort ha una complessità media di $Θ(n^2)$


### Quick Sort:
|n    | Tempo (s) Macchina 1 | Tempo (s) Macchina 2 |
|-----|---------------------|----------------------|
|1000 |0,002878				|0,001000				|
|10000|0,013542				|0,016000				|
|100000|0,353761			|0,388000				|
|1000000|25,748877			|25,252000				|

##

I dati ottenuti sono quelli attesi in quanto l'algoritmo ha complessità temporale media
di $Θ(n\  \log n)$.


## Conclusione
L'algoritmo di ordinamento più veloce è stato il Quicksort, mentre
l'Insertion Sort supera i 10 minuti già a partire da 1 milione di record.

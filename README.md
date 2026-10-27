### Somme distinte (13/10/26)

Scrivere una funzione C

    int *somme_distinte(int a[], int n, int *size)
che dato un array  di interi  `a[]` di lunghezza `n>0` alloca e restituisce un nuovo array `b[]` contenente tutti gli interi distinti che si possono ottenere sommando tra loro due elementi di `a` (compreso un elemento sommato a se stesso). Ad esempio

		input: 1 2
		output: 2 3 4   [infatti: 2=1+1, 3=1+2, 4=2+2] 
		input: 1 0 0 1 0 0 1 
		output: 2 1 0   [l'ordine nell'array di output non è importante]
		input: -2 3 1 10 
		output: -4 1 -1 8 6 4 13 2 11 20

Dato che non è possibile stabilire a priori quale sarà la lunghezza dell'array risultato, tale lunghezza deve essere passata per riferimento utilizzando il puntatore `*size`. Non vi preoccupate dell'efficienza della soluzione da voi proposta.  

Si scriva poi un programma che invoca `somme_distinte` passandogli l'array ottenuto convertendo in interi i valori forniti sulla linea di comando e successivamente stampa su `stderr` l'array restituito da `somme_distinte`. Infine il programma deve stampare su `stdout` la somma dei valori contenuti nell'array restituito da `somme_distinte`. (Nota: per stampare su `stdout` si può usare `fprintf(stdout,...)` oppure semplicemente `printf`). Il programma deve deallocare tutta la memoria utilizzata (verificare con valgrind). 

### Multipli (20/10/26)

Scrivere un programma `multipli` che invocato scrivendo
```
multipli nomefile n1 n2 n3 ....
```
dove `nomefile` il nome di un file di testo e `n1 n2 n3 ...` sono interi positivi.
Il programma deve leggere gli interi da `nomefile` e memorizzarli in un array di interi `a[ ]` allocato dinamicamente.
Successivamente, per ogni intero positivo `N` sulla linea di comando, il programma deve creare il file `nomefile.N` contenente gli interi di `a[ ]` che sono multipli di `N` nello stesso ordine in cui appaiono nel file di input. 
Ad esempio, scrivendo
```
multipli interi.txt 4 3  1 10
```
se il file `interi.txt` contiene 
```
9
8
7
4
3
2
1
4
6
7
8
```
devono essere generato il file `interi.txt.4` contenente:
```
8
4
4
8
```
il file `interi.txt.3` contenente:
```
9
3
6
```
il file `interi.txt.1` con esattamente lo stesso contenuto di `interi.txt` (tutti gli interi sono multipli di 1), e il file `interi.txt.10` vuoto (nessun dei numeri del file è multiplo di 10). 

Utilizzare la funzione `asprintf` per costruire i nomi dei file richiesti.


Verificate con valgrind il corretto uso e deallocazione della memoria.

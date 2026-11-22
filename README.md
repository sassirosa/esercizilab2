### ABR Città Sud America (17/11/26)

Questo esercizio richiede di creare un ABR contenente le città del Sud America predendole da file `sudAmerica.txt`. Si proceda nel seguente modo. Nel programma `abr_capitali` si cambi la definizione di `capitale` nella seguente
```c
typedef struct capit {
  char *nome;
  char *nazione;
  int kpop;
  struct capit *left, *right;
} capitale;
```
e si modifichino di conseguenza le funzioni `capitale_stampa`, `capitale_crea`, e `capitale_distruggi`. Si cancelli la funzione `capitale_leggi` e si modifichi la funzione `crea_abr` in modo che il ciclo `while` legga il file utilizzando `getline` ad ogni iterazione e per ogni linea utilizzando `strtok` crei e inserisca nell'ABR un nodo contenente i dati della città letta (si veda `legginomi.c` per un esempio). 

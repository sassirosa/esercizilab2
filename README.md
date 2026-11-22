### Ricerca su ABR (17/11/26)

Aggiungere al programma `abr_capitali` una funzione
```
int abr_ricerca_range(capitale *r, char *smin, char *smax)
```
che date due stringhe `smin` e `smax` visualizza su stdout tutte le città contenuto nell'albero di radice `r` il cui nome è compreso lessicograficamente tra `smin` e `smax`. La funzione deve visualizzare le città in 
ordine lessicografico e deve esplorare solamente le parti dell'albero che possono contenere città nel range assegnato. La funzione deve resituire il numero di nodi esplorati (cioè quelli il cui nome di città viene confrontato con `smin` e/o `smax`); questo serve per verificare che non venga visitato tutto l'abero.

Modificare poi la funzione `main` in modo che dopo la costruzione dell'albero venga invocata la funzione 
`abr_ricerca_range` con parametri `argv[2]` e `argv[3]`.   

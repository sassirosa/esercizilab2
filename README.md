### Confronta stringhe (9/10/26)

Scrivere una funzione `int confrontas(const char *s, const char *q)` che prende in input due stringhe e restituisce:

* -1 se la prima è lessicograficamente minore della seconda (ad esempio `s`=camino, `q`=cane)
*  1 se la prima è lessicograficamente maggiore della seconda (ad esempio `s`=gatto, `q`=cane)
* 0 se le due stringhe sono uguali

Si ricordi che per convenzione se una stringa è un prefisso proprio dell'altra allora quella lessicograficamente minore è quella più corta (quindi `porta` è minore di `portale`).

Si scriva poi un un programma `minimo` che calcola e la stampa la stringa più piccola tra `argv[1]`, `argv[2]`, ...

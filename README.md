### Ribalta elenco (13/10/26)

Scrivere un programma che invocato dalla linea di comando scrivendo

    main infile outfile

legge tutte le stringhe dal file di testo *infile* e le riscrive su *outfile* **in ordine inverso**. Ad esempio, se *infile* contiene
```
Mattarella
Napolitano
Ciampi
Scalfaro
Cossiga
Pertini
```
il file *outfile* deve contenere
```
Pertini
Cossiga
Scalfaro
Ciampi
Napolitano
Mattarella
```
Leggere le stringhe del file di input utilizzando `fscanf` for formato `%ms` in modo da non preoccuparvi della loro lunghezza. Dato però che non ci sono limitazioni al numero totale di stringhe, per poterle scrivere in ordine inverso dovete prima memorizzarle in un array di stringhe la cui dimensione deve aumentare dinamicamente. 

Verificate con valgrind il corretto uso e deallocazione della memoria.

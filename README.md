### Reverse di stringhe (2/10/26)

Scrivere un programma `reverse` che stampa sullo schermo gli argomenti passati sulla linea di comando (escluso il nome del programma) con i caratteri in ordine inverso. Ad esempio, scrivendo
```
reverse sole azzurro 123
```
l'output dovrebbe essere
```
elos
orruzza
321
```
Si noti che per stampare i caratteri in ordine inverso potete: 1. creare la stringa ribaltata e poi stamparla con `printf` con modificatore `%s`, oppure  2.  stampare i caratteri da destra a sinistra uno alla volta con il modificatore `%c`. Notate che nell'esempio precedente i primi due caratteri di `sole`, quindi `s` e `o`, sono `argv[1][0]` e `argv[1][1]`

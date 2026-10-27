### Concatena stringhe (2/10/26)

Scrivere un programma `concatena` che costruisce la stringa ottenuta concatenando tra loro le stringhe passate sulla linea di comando. Ad esempio, scrivendo
```
concatena sole azzurro 123
```
l'output dovrebbe essere
```
Stringa concatenata: soleazzurro123
```
In dettaglio il vostro programma deve 

1. calcolare la lunghezza `lun` della stringa risultato, come somma delle lunghezze delle stringhe `argv[1]` ... `argv[argc-1]`
2. allocare con `malloc` un blocco di `lun+1` byte (il `+1` serve per il byte 0 finale)
3. copiare i singoli caratteri dalle stringhe `argv[i]`  nella stringa appena allocata, seguiti dal terminatore 0
4. stampare la stringa ottenuta e deallocarla con `free`

Eseguire il programma anche utilizzando `valgrind` verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio 
```
HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks

#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe
#include <ctype.h> // per usare toupper()

void maiuscole(char *s){
    int l = strlen(s);
    for(int i=0; i<l; i++){
        s[i] = toupper(s[i]);
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2){
	printf("Uso: %s boomer.c\n", argv[0]);
	return 1;
	}

    for(int i=1; i<argc; i++){
        maiuscole(argv[i]);
        printf("%s \n",argv[i]);
    }


    return 0;
}	

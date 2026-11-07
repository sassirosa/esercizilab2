#define _GNU_SOURCE // avverte che usiamo le estensioni GNU
#include <stdio.h> // permette di usare scanf printf etc ...
#include <stdlib.h> // conversioni stringa/numero exit() etc ...
#include <stdbool.h> // gestisce tipo bool (per variabili booleane)
#include <assert.h> // permette di usare la funzione assert
#include <string.h> // funzioni di confronto/copia/etc di stringhe

void termina(char *messaggio){
    perror(messaggio);
    exit(1);
}

typedef struct duetto {
    int primo;
    int secondo;
} coppia;

/*
// scorro a[] e c[] e copio il minore in b[]
  while(i<na && j<nc) {
    if(a[i].primo-a[i].secondo <
       c[j].primo-c[j].secondo) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = c[j];
      j++;
    }
    k++;
  }
*/
int vconfronta(const void *aa, const void *bb){
	const struct duetto *a = aa;
    const struct duetto *b = bb;
	if((((*a).primo)-((*a).secondo)) < (((*b).primo)-((*b).secondo))) return -1;
	else return 1;
	//return 0;
}

int main(int argc, char *argv[]){

    if ((argc-1)%2!=0) {
        termina(" mettere un numero di input pari. Uso: ./programma file_input [N1 N2 ...]");
    }

    //creo l'array delle coppie
    coppia *a = malloc(((argc-1)/2) * sizeof(coppia));
    if(a==NULL) termina("allocazione fallita");
    
    for(int i=0; i<((argc-1)/2); i++){
        a[i].primo = atoi(argv[2*i+1]);
        a[i].secondo = atoi(argv[2*i+2]);
    }

    //qsort(a,((argc-1)/2),sizeof(coppia),(__compar_fn_t) &vconfronta); con mac il casting non va
    qsort(a,((argc-1)/2),sizeof(coppia), &vconfronta);

    for(int i=0;i<((argc-1)/2);i++)
        printf("(%d, %d)\n", a[i].primo, a[i].secondo);

    return 0;
}


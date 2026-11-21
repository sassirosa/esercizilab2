#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno
#include <math.h>

void termina(const char *messaggio)
{
  if(errno==0) 
     fprintf(stderr,"%s\n",messaggio);
  else 
    perror(messaggio);
  exit(1);
}

typedef struct _intero {
  int valore;
  struct _intero *next;
} intero;


int confronta_lunghezza(intero *lis1, intero *lis2){
    /*
    che date due liste di interi lis1 e lis2 (possibilemente anche vuote) 
    restituisce -1 se lis1 ha meno elementi di lis2,
     1 se lis1 ha più elementi di lis2, 
     0 se hanno lo stesso numero di elementi 
     (le liste vuote si considerano avere 0 elementi).
    */
   

   //caso base
   if(lis1 == NULL && lis2 == NULL) return 0;
   if(lis1 == NULL) return -1;
   if(lis2 == NULL) return 1;

   //caso iterativo
   intero *n1 = lis1;
   intero *n2 = lis2;
   while(true){
    if((n1 == NULL) && (n2 == NULL)){return 0;}
    if(n1 == NULL){ return -1; }
    if(n2 == NULL){ return 1; }
    n1 = n1->next;
    n2 = n2->next;
   }
}

intero *intero_crea(int s)
{
  intero *a  = malloc(sizeof(*a));
  if(a==NULL) termina("Allocazione capitale fallita");
  a->valore = s; 
  a->next = NULL;
  return a;
}

void stampa_lista(const intero*lis){
	while (lis != NULL){
		printf("%d\n",lis->valore);
		lis = lis -> next; 
	}
	return;
}

int somma(intero *lis){
    int s=0;
    while(lis != NULL){
        s = s+ lis->valore;
        lis = lis->next;
    }
    return s;
}

void lista_distruggi(intero *lis)
{
  while(lis!=NULL) {
    intero *tmp = lis->next; // necessario
    free(lis);
    lis = tmp;
  }
  return;
}

int main(int argc, char *argv[]){

    /*
    Si scriva poi un main che legge dalla linea di comando
     un numero qualsiasi di interi e crea due liste contenenti 
     rispettivamente gli interi pari e gli interi dispari passati 
     sulla linea di comando (si noti che le liste possono essere vuote).
    */
   intero *pari = NULL;
   intero *dispari = NULL;

   intero *p = pari;
   intero *d = dispari;

   for(int i=1; i<argc; i++){
    int z = atoi(argv[i]);
    if(z%2==0){
        intero *n = intero_crea(z);
        if(pari == NULL){
            pari = p = n;
        }else{
            p->next = n;
            p = n;
        }
        
    }else{
        intero *n = intero_crea(z);
        if(dispari == NULL){
            dispari = d = n;
        }else{
            d->next = n;
            d = n;
        }
        
    }
   }

   /*
   Successivamente il main deve invocare confronta_lunghezza 
   e stampare la lista più lunga; se le liste hanno 
   la stessa lughezza deve stampare quella la cui somma degli elementi è maggiore,
    se anche la somma degli elementi è la stessa non deve stampare nulla.
   */
  int ris= confronta_lunghezza(pari,dispari);
   if(ris == (-1)){
    stampa_lista(dispari);
   }else if(ris== (1)){
    stampa_lista(pari);
   }else{
    int sommapari = somma(pari);
    int sommadispari =somma(dispari);
    if(sommadispari<sommapari){ 
        stampa_lista(pari);
    }else if(sommadispari>sommapari) {
        stampa_lista(dispari);
    }
   }
   
    
   
   lista_distruggi(pari);
   lista_distruggi(dispari);

    return 0;
}
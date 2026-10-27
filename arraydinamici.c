#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe

/*
Scrivere un programma C che legge un intero N e costruisce i seguenti due array di interi:

l'array a[] contente i numeri tra 1 e N che sono multipli 3 ma non di 5: 3, 6, 9, 12, 18, 21, 24, 27, 33, ...

l'array b[] contente i numeri tra 1 e N che sono multipli 5 ma non di 3: 5, 10, 20, 25, 35, 40, 50, ...

Al termine della costruzione deve stampare lunghezza e la somma gli elementi degli array a e b, deve poi deallocarli e terminare.


*/
void termina(char *messaggio){
	perror(messaggio);
	exit(1);
}

int main(int argc, char *argv[])
{	
  int n; // definisco variabile intera di nome n

  // spiego cosa voglio leggere e lo leggo con scanf  
  puts("Inserisci il numero di elementi: ");
  int e;
  e = scanf("%d",&n); // il motivo della & lo vedremo più avanti 
  // controlli sulla lettura
  if(e!=1) {
    puts("Valore da tastiera non trovato");
    exit(1);
  }
  
  //array 3
  int *arr3;
	arr3 = malloc(n*sizeof(int));
	if(arr3==NULL){
	puts("Malloc fallita");
	exit(3);
	}
  
  //array 5
  int *arr5;
	arr5 = malloc(n*sizeof(int));
	if(arr5==NULL){
	puts("Malloc fallita");
	exit(3);
	}
	
	//cerco i multipli e li metto negli array
	int j=0;
	int z=0;
	for(int i=1; i<=n; i++) { 
		if(i%3==0 && i%5!=0){
			arr3[j] = i;
			j++;
		}
		if(i%5==0 && i%3!=0){
			arr5[z]=i;
			z++;
		}
	}
	
	//ridimensiono gli array
	arr3 = realloc(arr3, j*sizeof(int));
	if(arr3==NULL) termina ("Realloc fallita");
	
	arr5 = realloc(arr5, z*sizeof(int));
	if(arr5==NULL) termina ("Realloc fallita");
	
	//somma arr3
	int sumarr3=0;
	for(int i=0; i<j; i++){
		sumarr3 += arr3[i];
	}
	
	//somma arr5
	int sumarr5=0;
	for(int i=0; i<z; i++){
		sumarr5 += arr5[i];
	}
	
	//stampo a video
	  printf("Somma multipli 3 non di 5 %d\n",sumarr3);
	  printf("Somma multipli 5 non di 3 %d\n",sumarr5);
	  printf("La lunghezza dell'array arr3 è: %d\n", j);
	  printf("La lunghezza dell'array arr5 è: %d\n", z);
	  
	//termino gli array
	free(arr3);
	free(arr5);
	
  
 }

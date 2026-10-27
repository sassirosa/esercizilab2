#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa/numero exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // funzioni di confronto/copia/etc di stringhe


int main(int argc, char *argv[]){
	
	if(argc != 6){
	printf("Uso: %s intero_pos nome_file\n", argv[0]);
	return 1;
	}
	

//qua creo il file pari
    FILE *fp;
    fp = fopen("pari.txt", "w");
    if (fp == NULL) {
        printf("Errore durante la creazione del file.\n");
        return 1;
    }
    
    FILE *fpp;
    fpp = fopen("dispari.txt", "w");
    if (fpp == NULL) {
        printf("Errore durante la creazione del file.\n");
        return 1;
    }

//array pari e dispari
int *pari;
pari = malloc(6*sizeof(int));
if(pari==NULL){
	puts("Malloc fallita");
	exit(3);
}
int *dispari;
dispari = malloc(6*sizeof(int));
if(dispari==NULL){
	puts("Malloc fallita");
	exit(3);
}
int z =0;
int j=0;
for(int i =1; i<6; i++){
	if(atoi(argv[i])%2==0){
		pari[z]=atoi(argv[i]);
		fprintf(fp, "%d", atoi(argv[i]));
		z++;
	}else{
		dispari[j]=atoi(argv[i]);
		fprintf(fpp, "%d", atoi(argv[i]));
		j++;
	}
}

pari = realloc(pari, z*sizeof(int));
if(pari==NULL){
	printf("Errore durante malloc.\n");
        return 1;
}

dispari = realloc(dispari, j*sizeof(int));
if(dispari==NULL){
	printf("Errore durante malloc.\n");
        return 1;
}

// calcola e stampa la somma pari
  int sommapari=0;
  for(int i=0;i<z;i++)  { // ciclo for:  (inizializ; test; aggiornamento)
    sommapari += pari[i]; // somma = somma + a[i]
  }
  
  printf("%d\n",sommapari);
  
  // calcola e stampa la somma dispari
  int sommadispari=0;
  for(int i=0;i<j;i++)  { // ciclo for:  (inizializ; test; aggiornamento)
    sommadispari += dispari[i]; // somma = somma + a[i]
  }
  
  printf("%d\n",sommadispari);
  
   // 5. Chiude il file
    fclose(fp);
  
  // 5. Chiude il file
    fclose(fpp);
  
  return 0;
}
	


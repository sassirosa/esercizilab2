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


int *leggi_file(FILE *f, int *num_elementi){
	assert (f!= NULL); // il file deve essere valido
	int capacita = 10; // dimensione attuale dell'array
	int messi = 0; // numero di elemnti attualmente dentro l'array
	int *a = malloc(capacita*sizeof(int));
	if(a ==NULL) {termina("memoria insufficiente");}
	
	while(true){
		int n;
		int e = fscanf(f,"%d", &n);
		if (e == EOF) break; // fine lettura file
		if(e!=1) termina("contenuto illegale nel file");
		//ho letto un intero dal file ed è stato messo in n 
		//questa parte della realocazione dell'array
		//stessa part ein scrivi_primi
		
		if(messi==capacita) {
        // ingrandisco l'array
        capacita = capacita*2;
        a = realloc(a,capacita*sizeof(int));
        if(a==NULL) termina("realloc fallita");
        }
    
    assert(capacita>messi);
    a[messi] = n;
    messi += 1;
  }
  // ho letto tutti gli elementi
  capacita = messi;
  a = realloc(a,capacita*sizeof(int));
  if(a==NULL) termina("realloc fallita");  
  // salvo il numero di elementi e restituisco l'array  
  *num_elementi = messi;
  return a;  
}

int main(int argc, char *argv[]){

    if (argc < 2) {
        termina("Uso: ./programma file_input [N1 N2 ...]");
    }

    FILE *input = fopen(argv[1],"r+");
    int lunghA = 0;
    int *arrayA = leggi_file(input,&lunghA);

    /*
    Successivamente, per ogni intero positivo N sulla linea di comando, 
    il programma deve creare il file nomefile.N contenente gli interi di a[ ] 
    che sono multipli di N nello stesso ordine in cui appaiono nel file di input.
    */
   char *nomefile = argv[1];
   for(int i=2; i<argc; i++){ //fai attenzione agli indici di argc !! 
     int numero = atoi(argv[i]);
     if (numero <= 0) continue;
     //creo il file
     char *nomefileN;
     char *num = argv[i];
     asprintf(&nomefileN,"%s.%s",nomefile,num);
     FILE *f = fopen(nomefileN, "w+");
     if(f == NULL) termina ("Apertura del file fallita");

     for(int j=0; j<lunghA; j++){
        if(arrayA[j]%numero ==0){
            fprintf(f,"%d\n",arrayA[j]);
        }
     }
     fclose(f);
   }

   free(arrayA);
   fclose(input);

    return 0;
}
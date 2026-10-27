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
void merge(coppia a[], int na, coppia c[], int nc, coppia b[])
{
  assert(a!=NULL);
  assert(c!=NULL);
  assert(b!=NULL);
  assert(na>0 );
  assert(nc>0);
  
  int i=0; // indice per a[]
  int j=0; // indice per c[]
  int k=0; // indice per b[]
  
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
  
  // copio il resto di a[] in b[]
  while(i<na) {
    b[k] = a[i];
    i++;
    k++;
  }
  
  // copio il resto di c[] in b[]
  while(j<nc) {
    b[k] = c[j];
    j++;
    k++;
  }
  assert(i==na);
  assert(j==nc);
  assert(k==na+nc); 
}

// funzione mergesort ricorsiva
void mymergesort(coppia *a, int n)
{
  assert(a!=NULL);
  assert(n>0);
  
  // caso base
  if(n==1) return;
  
  int n1 = n/2;       // dimensione prima parte
  int n2 = n - n1 ;   // dimensione seconda parte
  assert(n1+n2==n);   // verifico che sto considerando tutti gli elementi
  
  // ordino a[0...n1-1]
  mymergesort(a,n1);
  // ordino a[n1...n-1]
  mymergesort(&a[n1],n2); 
  
  // ora ho le due metà ordinate devo fare il merge
  coppia *b = malloc(n*sizeof(*b));
  if(b==NULL) termina("malloc fallita nel merge");
  merge(a,n1,&a[n1],n2,b);  
  // copio il risultato da b[] ad a[]
  for(int i=0;i<n;i++)
    a[i] = b[i];
  
  free(b); // dealloco array temporaneo b[]
}

int main(int argc, char *argv[]){

    if ((argc-1)%2!=0) {
        termina(" mettere un numero di input pari. Uso: ./programma file_input [N1 N2 ...]");
    }

    //creo l'array delle coppie
    coppia *a = malloc(sizeof(coppia));
    if(a==NULL) termina("allocazione fallita");
    
    for(int i=0; i<((argc-1)/2); i++){
        a[i].primo = atoi(argv[2*i+1]);
        a[i].secondo = atoi(argv[2*i+2]);
    }

    mymergesort(a,((argc-1)/2));
    for(int i=0;i<((argc-1)/2);i++)
        printf("(%d, %d)\n", a[i].primo, a[i].secondo);

    return 0;
}


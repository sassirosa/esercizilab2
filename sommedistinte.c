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

int *somme_distinte(int a[], int n, int *size){

    int *b;
    int max_possibili = n * (n + 1) / 2; //non posso esistere più di questi elementi (anche doppi)
    b = malloc(max_possibili*sizeof(int));
    if(b==NULL){
	    puts("Malloc fallita");
	    exit(3);
    }
    int somme =0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int somma = a[i] + a[j];

            //controllo la presenza della somma nell'array b
            int presente=0;
            for(int k=0; k<somme; k++){
                if(somma == b[k]){
                    presente =1;
                    break;
                }
            }
            if(!presente){
                b[somme] = somma;
                somme++;
            }
        }
    }

    *size = somme; //nuovo valore della grandezza dell'array
    //faccio la realloc per ridimensionarlo

    int *c = realloc(b, (*size)*sizeof(int));
    if(c==NULL) termina ("Realloc fallita");
    b=c;

    return b;
}


int main(int argc, char *argv[]){
    if (argc < 2) return 0;

        //converto i valori da input
        int *a;
        a = malloc((argc-1)*sizeof(int));
        if(a==NULL){
            puts("Malloc fallita");
            exit(3);
        }
        for(int i =0; i<argc-1; i++){
            a[i]= atoi(argv[i+1]);
        }

        int dim_b =0;
        int *b= somme_distinte(a,(argc-1),&dim_b);

        //stampo l'array con stderr
        for(int i=0; i<dim_b; i++){
            fprintf(stderr, "%d\n", b[i]);
        }

        //stampo la somma totale con stdout
        int sommatot = 0;
        for (int i = 0; i < dim_b; i++) {
            sommatot += b[i];
        }
        printf("Somma totale: %d\n", sommatot);

        // deallocazione memoria
        free(a);
        free(b);

    return 0;
}
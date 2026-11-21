#define _GNU_SOURCE   // avverte che usiamo le estensioni GNU 
#include <stdio.h>    // permette di usare scanf printf etc ...
#include <stdlib.h>   // conversioni stringa exit() etc ...
#include <stdbool.h>  // gestisce tipo bool
#include <assert.h>   // permette di usare la funzione ass
#include <string.h>   // funzioni per stringhe
#include <errno.h>    // rischiesto per usare errno
#include <math.h>

// prototipi delle funzioni che appaiono dopo il main()
void termina(const char *messaggio);


// definzione struct che rappresenta
// una città con nome, e coordinate 
// + campo next per formare la lista 
typedef struct capit {
  char *nome;
  double lat;
  double lon;
  struct capit *next;
} capitale;

void capitale_stampa(const capitale *a, FILE *f){
	fprinf(f,"%20s (%f,%f)\n", a->nome, a->lat,a->lon);
}

void lista_capitale_stampa(const capitale *lis, FILE *f){
	while (lis != NULL){
		capitale_stampa(lis,f);
		lis = lis -> next;
	}
	return;
}
int confronta_capitali(capitale *a, capitale *b){
    return strcmp(a->nome,b->nome);
}
// inserisce capitale "c" in lista "testa" 
// mantenendo ordinamento per latitudine decrescente
capitale *inserisci_lat_ric(capitale *testa, capitale *c, int *f(capitale *a, capitale *b))
{

  assert(c!=NULL);
  // base riscorsione, lista vuota
  if(testa==NULL) {
    c->next=NULL;
    return c; //  la nuova lista contiene solo c
  }
  // la lista non è vuota
  if(f(c,testa)<0) {
    // inserisco c in cima
    c->next = testa;
    return c;
  }
  else { // c va inserito "in mezzo" alla lista  
    testa->next = inserisci_lat_ric(testa->next,c,f);
    return testa;
  }
}
capitale *capitale_crea(char *s, double lat, double lon)
{
  capitale *a  = malloc(sizeof(*a));
  if(a==NULL) termina("Allocazione capitale fallita");
  a->lat = lat;
  a->lon = lon;
  a->nome = strdup(s); // creo una copia di s e l'assegno al nome
  a->next = NULL;
  return a;
}

capitale *capitale_leggi(FILE *f)
{
  assert(f!=NULL);
  char *s;
  double lat, lon;
  int e = fscanf(f,"%ms %lf %lf",&s,&lat,&lon);
  if(e!=3) {
    if(e==EOF) return NULL; // finito il file non ci sono altri dati
    else termina("Formato input file non valido");
  }
  capitale *c = capitale_crea(s,lat,lon);
  free(s);
  return c;
}

capitale *crea_lista_lat(FILE *f)
{
  // costruzione lista leggendo capitali dal file
  capitale *testa=NULL;
  while(true) {
    capitale *b = capitale_leggi(f);
    if(b==NULL) break;
    // inserisco b in testa alla lista    
    testa = inserisci_lat_ric(testa,b,&confronta_capitali);
  }
  return testa;
}
void lista_capitale_distruggi(capitale *lis)
{
  while(lis!=NULL) {
    capitale *tmp = lis->next; // necessario
    capitale_distruggi(lis);
    lis = tmp;
  }
  return;
}

int main(int argc, char *argv[])
{
  if(argc!=2) {
    printf("Uso: %s nomefile\n",argv[0]);
    exit(1);
  } 
  FILE *f = fopen(argv[1],"r");
  if(f==NULL) termina("Errore apertura file");

  capitale *testa=crea_lista_lat(f);
  puts("--- inizio lista (inserimento per latitudine) ---");
  // stampa lista capitali appena ri-creata
  lista_capitale_stampa(testa,stdout);  
  puts("--- fine lista ---");
  
  if(fclose(f)==EOF)
    termina("Errore chiusura");
  // dealloca la memoria usata dalla lista 
  lista_capitale_distruggi(testa);
  
  return 0;
}
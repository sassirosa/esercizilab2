capitale *inserisci_lat_iter(capitale *testa, capitale *c)
{
  assert(c!=NULL);
  c->next = NULL;

  if(testa==NULL || c->lat >testa->lat) {
    c->next=testa;
    return c; //  la nuova lista contiene solo c
  }

  capitale *p = testa -> next;
  capitale *prec = testa;

  while(p!=NULL) {
     if(p->lat > c->lat){
        prec = p;
        p = p->next;
     }else{
      c->next = p;
      prec ->next = c;         
      return testa;
     }

    // l'elemento c deve essere inserito dopo quelli
    // che hanno latitudine maggiore di c->lat e
    // prima di quelli che hanno latitudine minore di c->lat
  }
  prec ->next = c;         
  return testa; 
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        printf("Uso: %s <stringa1> <stringa2> ...\n", argv[0]);
        return 1;
    }

    // Calcolo la lunghezza totale della stringa finale
    int l = 0;
    for (int i = 1; i < argc; i++) {
        l += strlen(argv[i]);
    }

    // Dichiaro e alloco il nuovo array (+1 per il carattere nullo di fine stringa '\0')
    char *a = malloc((l + 1) * sizeof(char));
    if (a == NULL) {
        puts("Malloc fallita");
        exit(3);
    }

    // Copio i caratteri di ciascuna stringa nel nuovo array
    int z = 0;
    for (int i = 1; i < argc; i++) {
        char *stringa = argv[i];
        int len = strlen(stringa);
        for (int j = 0; j < len; j++) {
            a[z] = stringa[j];
            z++;
        }
    }

    // Inserisco il terminatore di stringa nell'indice corretto
    a[z] = '\0';

    // Stampo la nuova stringa aggiungendo \n finale
    printf("Stringa concatenata: %s\n", a);

    // Libero la memoria allocata
    free(a);

    return 0;
}

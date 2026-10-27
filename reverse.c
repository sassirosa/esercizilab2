#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int len = strlen(argv[i]);
        
        // Allocazione dinamica con malloc (+1 byte per il terminatore '\0')
        char *reversed = (char *)malloc((len + 1) * sizeof(char));
        
        // Controllo della corretta allocazione della memoria
        if (reversed == NULL) {
            fprintf(stderr, "Errore di allocazione della memoria\n");
            return 1;
        }
        
        // Copia dei caratteri in ordine inverso
        for (int j = 0; j < len; j++) {
            reversed[j] = argv[i][len - 1 - j];
        }
        reversed[len] = '\0'; // Inserimento del terminatore di stringa
        
        // Stampa della stringa ribaltata
        printf("%s\n", reversed);
        
        // Liberazione della memoria allocata
        free(reversed);
    }
    
    return 0;
}
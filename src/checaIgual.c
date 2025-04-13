#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {
  
    if (argc != 3) {
        printf("Uso: %s arquivo1 arquivo2\n", argv[0]);
        return 1;
    }
    
    FILE * arq1 = fopen(argv[1],"rb");
    FILE * arq2 = fopen(argv[2],"rb");

    if (arq1 == NULL || arq2 == NULL) {
        printf("Um erro inesperado aconteceu.\n");
        return 1;
    }

    
    int c = fgetc(arq1);
    int c2 = fgetc(arq2);
    int contador = 0;
    while(!feof(arq1) && !feof(arq2)) {
        contador++;
        c = fgetc(arq1);
        c2 = fgetc(arq2);

        if (c != c2) {
            printf("Não é igual.\n");
            printf("c1 ->%c\nc2 ->%c\n",c,c2);
            printf("Caracteres lidos: %d", contador);
            return 0;
        }
    }
    printf("Igual.\n");
    return 0;
}
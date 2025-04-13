#include <stdio.h>
#include <stdlib.h>

int main ( void ) 
{
    FILE * fPtr;
    
    fPtr = fopen("data/cep_ordenado.dat","rb");
    if(fPtr == NULL) {
        printf("Erro desconhecido.\n");
        return 1;
    }
    int qt[256] = {0};

    int c = fgetc(fPtr);
    
    while(!feof(fPtr)) {
        qt[c]++;
        c = fgetc(fPtr);
    }  

    for(int i = 0; i < 255; i++) {
        if(qt[i] > 0 && i != '\n') {
            printf("Byte %c ocorre %d vezes\n", i, qt[i]);
        } else if (i == '\n') 
        {
            printf("Quebra de linha ocorre %d vezes\n", i);
        }
        
    }
    return 0;
}
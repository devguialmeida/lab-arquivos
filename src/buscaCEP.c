#include <stdio.h>
#include <string.h>
#include "../include/endereco.h"

// typedef struct _Endereco Endereco;

// struct _Endereco {
//     char logradouro[72];
//     char bairro[72];
//     char cidade [72];
//     char uf[72];
//     char sigla[2];
//     char cep[8];
//     char lixo[2]; // espaço + quebra de linha ao final de cada registro
// };

int main (int argc, char ** argv) {
  
    FILE * fPtr;
    Endereco e;
    int qt;
    int c;

    if (argc != 2)  {
        fprintf(stderr, "USO: %s [CEP]", argv[0]);
        return 1;
    }

    c = 0;

    printf("Tamanho da Estrutura: %ld\n\n", sizeof(Endereco));
    if((fPtr = fopen("data/cep.dat","rb")) == NULL) {
        printf("Erro ao abrir o arquivo. O programa será abortado.\n");
        return 1;
    }
    qt = fread(&e, sizeof(Endereco), 1 ,fPtr);
    while(qt > 0) 
    {
        c++;
        e.logradouro[71] = '\0'; // torna ele null terminated?

        if(strncmp(argv[1], e.cep, 8) == 0) {
            printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n", e.logradouro, e.bairro, e.cidade, e.uf, e.sigla, e.cep);
            break;
        }
        qt = fread(&e, sizeof(Endereco), 1 ,fPtr);
    }
    printf("Total lido: %d\n", c);
    fclose(fPtr);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/endereco.h"


int compara ( const void * e1, const void * e2 ) {
    return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

int main (int argc, char ** argv)
{
    FILE * fPtr;
    Endereco * e;
    int qtdParcelas;
    long qtdEnderecos, posicao, parcela;

    if (argc != 3) {
        fprintf(stderr, "USO: %s [caminho/para/entrada] [caminho/para/saida]\n", argv[0]);
        return 1;
    }

    fPtr = fopen(argv[1], "rb");
    fseek(fPtr,0,SEEK_END);
    posicao = ftell(fPtr);
    qtdEnderecos = posicao / sizeof(Endereco);
    parcela = qtdEnderecos / qtdParcelas;
    e = (Endereco *) malloc(sizeof(Endereco) * parcela);
    rewind(fPtr);
    
    if (fread(e,sizeof(Endereco),parcela, fPtr) == parcela) {
        printf("Lido = OK!");
    }

    char nomeArq[100];

    for (int i = 0; i < qtdParcelas; i++) {
        FILE * iParcelaPtr;
        sprintf(nomeArq, "a%d.dat", i);
        iParcelaPtr = fopen(nomeArq,"wb");
        qsort(e, parcela, sizeof(Endereco), compara);
        // to be continued

    }
    
    



}
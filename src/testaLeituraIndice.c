#include <stdio.h>
#include "../include/endereco.h"
#include "../include/indiceCEP.h"
#include <string.h>


int main() {

    FILE * fPtr;
    IndiceCEP indice;
    int x;
    scanf("%d", &x);
    if((fPtr = fopen("data/CEP_indices.dat", "rb")) == NULL) {
        printf("Erro ao abrir o arquivo. O programa será abortado.");
        return 1;
      }
  
    fseek(fPtr, x * sizeof(IndiceCEP), SEEK_SET);
    fread(&indice, sizeof(IndiceCEP), 1, fPtr);
    printf("%.8s\n", indice.cep);


}
#include <stdio.h>
#include <stdlib.h>

typedef struct _HashElement HashElement;

struct _HashElement {
    int uf;
    float soma;
    int qtd;    
    HashElement * next;
};


HashElement tabela[31];

void acumula(HashElement tabela[], int uf, float peso) {
    int pos = uf % 31;
    HashElement * x = &tabela[pos];

    while(x) {
        if(x->uf == uf) {
            x->soma += peso;
            x->qtd++;
            return;
        }
        x = x->next;
    }
    if(tabela[pos].uf == 0) {
        tabela[pos].uf = uf;
        tabela[pos].soma = peso;
        tabela[pos].qtd = 1;
    }
    else {
        x = (HashElement * ) malloc(sizeof(HashElement));
        x->uf = uf;
        x->soma = peso;
        x->qtd = 1;
        x->next = tabela[pos].next;
        tabela[pos].next = x;
    }

}
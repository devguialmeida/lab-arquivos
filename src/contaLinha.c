#include <stdio.h>

int main ( void ) 
{
    FILE * fPtr;
    fPtr = fopen("data.txt", "rb");
    int lines = 1;

    int c = fgetc(fPtr);
    
    while(!feof(fPtr)) {
        c = fgetc(fPtr);
        if(c == '\n') {
            lines++;
        }
    }

    printf("%d linhas no arquivo \"data.txt\".\n", lines);
}
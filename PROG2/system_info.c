#include <stdio.h>
#include <stdlib.h>

int main(){

    char c;
    FILE *f;

    f = fopen("program2_part1.txt", "r"); 

    if(f == NULL){
        printf("Cannot open file!");
        exit(1);
    }

    while ((c = fgetc(f)) != EOF)
    {
        printf("%c", c);
    }

    printf("\n");

    fclose(f);
    exit(0);
    
}
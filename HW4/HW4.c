#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


int main(){

    printf("malloc_stats() test HW4 \n");

    void* ptr = malloc(512);

    if(ptr == NULL){
        printf("Memory allocation failed\n");
        exit(0);
    }

    ptr = realloc(ptr, 1024);
    printf("pointer 1024 is in %p\n", ptr);
    malloc_stats();

    ptr = realloc(ptr, 128);
    printf("pointer 128 is in %p\n", ptr);
    malloc_stats();

    ptr = realloc(ptr, 1024 * 1024);
    printf("pointer 1MB is in %p\n", ptr);
    malloc_stats();

    free(ptr);
}
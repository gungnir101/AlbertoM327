#include <stdio.h>
#include <stdlib.h>
#include "list_library.h" 

int main() {
    
    void* a = malloc(sizeof(int));
    void* b = malloc(sizeof(int));
    void* c = malloc(sizeof(int));
    void* d = malloc(sizeof(int));
    
    a = 5;
    b = 4;
    c = 3;
    d = 2;
    
    list_append(a);
    list_append(d);
    list_insert_at(b,2);
    list_insert_at(c,2);
    
    //list_remove_at(2);
    //list_remove(5);

    list_to_array();

    printf("Size of list is %d", list_size());
}
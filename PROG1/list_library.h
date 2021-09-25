#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


extern void *list_append(void* element);
extern unsigned int list_insert_at(void* element, unsigned int location);
extern void *list_remove_at(unsigned int location);
extern void *list_remove(void *element);
extern unsigned int list_size();
extern void *list_to_array();
extern bool list_is_empty();

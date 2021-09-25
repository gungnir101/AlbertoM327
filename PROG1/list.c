#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    struct node* nextnode;
    void* nodevalue;
};

struct node* _firstnode == NULL;


struct node *create_node(void) {
  return (struct node *) malloc(sizeof(struct node));
}


//append the element at the end of the list
void *list_append(void* element){
    struct node* aux1 = create_node();
    struct node* aux2;

    aux1->nodevalue = element;
    aux1->nextnode  = NULL;

    if(_firstnode == NULL){
        _firstnode = aux1;
    }
    else{
        aux2 = _firstnode;
        while (aux2 != NULL)
        {
            aux2 = aux2->nextnode;
        }

        aux2->nextnode = aux1;
    }
}

/*append the element at a particular position
  if location is beyond the end of the list, append the item
  at the end of the list
  returns the location of the new element*/
unsigned int list_insert_at(void* element, unsigned int location){
    unsigned int _index = 0;
    struct node* aux1 = create_node();
    struct node* aux2, prev;

    aux1->nodevalue = element;
    aux1->nextnode  = NULL;

    if(_firstnode == NULL){
        _firstnode = aux1;
    }
    else{
        prev = NULL;
        aux2 = _firstnode;
        _index = 1;

        while (aux2 != NULL && _index != location)
        {
            prev = aux2;
            aux2 = aux2->nextnode;
            _index++;
        }

        if(prev == NULL){
            aux1->nextnode = _firstnode;
            _firstnode = aux1;
            return 1;
        }
        prev->nextnode = aux1;
        aux1->nextnode = aux2;

        return index;
    }

}

//remove the element at location from the list
//returns pointer to element removed, null if there is no element
void *list_remove_at(unsigned int location){

    unsigned int _index = 1;
    struct node* aux = _firstnode;

    while(_index != location && aux != NULL){
        _index++;
        aux = aux->nextnode;
    }

    if(aux == NULL){
        return NULL;
    }

    aux->nodevalue = NULL;
    return aux*;
}

//remove the element from the list
//returns pointer to element removed, null if there is no element 
void *list_remove(void *element){

    struct node* aux = _firstnode;

    while(aux->nodevalue != element && aux != NULL){
        aux = aux->nextnode;
    }
    if(aux == NULL){
        return NULL;
    }
    
    aux->nodevalue = NULL;
    return aux*;
}

//returns the number of elements in the list
unsigned int list_size(){
    unsigned int n = 0;
    struct node* aux = _firstnode;
    while(aux != NULL){
        n++;
        aux = aux->nextnode;
    }
    return n;
}

//returns the list of pointers as array
void *list_to_array(){
    void* array[list_size()];
    struct node* aux = firstitem;
    for(int i = 0; i < list_size(); i++){
        array[i] = aux;
        aux = aux->nextnode; 
    }
    return array;
}

//returns true if empty, false otherwise
bool list_is_empty(){
    if(_firstnode == NULL){
        return true;
    } 
    return false;
}


int main() {

    list_append(5);
    list_append(4);
    list_append(3);

    printf("Size of list is", list_size());
}
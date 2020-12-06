//CS2211a 2020
//Assignment 4
//Jeffrey Wang
//251023789
//jwan869
//Nov 16th 2020

#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED

typedef struct{
    void * head;
    void * tail;
    int size;
} linked_list;


void linked_list_add(linked_list * ll, void * node){ // add a new sentence to the linked list
    ll->size ++;
    if (ll->size ==0){ // add the first node
        ll->head = node;
        ll->tail = node;
    } else {
        ll->tail->next = node;
        ll->tail - node;
    }
}

#endif // DEFINITIONS_H_INCLUDED
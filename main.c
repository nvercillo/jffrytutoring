//CS2211a 2020
//Assignment 4
//Jeffrey Wang
//251023789
//jwan869
//Nov 16th 2020


#include "headers.h"



int main(){
    
    linked_list * ll; 
    ll = malloc(sizeof(linked_list));
    initLinkedList(ll);
    searchContinuously(ll);
    deleteContinuously(ll);
    free(ll);



    // free(ll);
    return 0;
}



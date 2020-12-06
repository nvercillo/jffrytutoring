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
    // deleteContinuously(ll);
    free(ll);



    // free(ll);
    return 0;
}



bool deleteNode(linked_list * ll, int pos ){  // True -> success 
    printf("Delete Node %d\n", line_num);

    if ( pos > ll->size  || pos < 1 ){
        // printf("Endterewer werwer er");
        return false;    
    } 

    // return true;
    void  * head = ll->head;
    void * prev =NULL;

    if (ll->size ==1){
        //delete first node()
        deallocSentence(ll->head);
        ll->head = NULL;
        ll->size--;
        return true;
    }

    if (line_num ==1){
        // printf("1 111 1 1 1" );
        sentence_node * to_delete = head;
        head = head->next;
        ll->head = head;
        ll->size --;
        deallocSentence(to_delete);
        printList(ll);
        return true;
        
    }

    --ll->size;
    for (int i=0; i<line_num-1; i++){
        prev = head;
        head = head->next;
    }
    

    if (prev != NULL ){  
        sentence_node * to_delete = prev->next;
        if (head !=NULL)
            prev->next = head->next;

        deallocSentence(to_delete);
    }


    for (int i = line_num; i < ll->size +1; i++){
        head->whichLine --;
        head = head->next;
    }
    printList(ll);
    return true;
}

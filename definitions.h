//CS2211a 2020
//Assignment 4
//Jeffrey Wang
//251023789
//jwan869
//Nov 16th 2020

#ifndef DEFINITIONS_H_INCLUDED
#define DEFINITIONS_H_INCLUDED


typedef struct word_node_t
{
    char *charPtr;
    int size;
    int position;
    struct word_node_t * next;

}word_node;

typedef struct sentence_node_t
{
    word_node *wordPtr;
    int whichLine;
    int numOfWords;
    struct sentence_node_t * next;
}sentence_node;


typedef struct{
    sentence_node * first;
    sentence_node * last;
    int count;
    bool initialized;
} linked_list;



void linked_list_add(linked_list * ll, sentence_node * sent){ // add a new sentence to the linked list
    if (!ll->initialized){ // add the first node

    } else { // any subsequent node

    }
}

#endif // DEFINITIONS_H_INCLUDED
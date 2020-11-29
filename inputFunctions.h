//CS2211a 2020
//Assignment 4
//Jeffrey Wang
//251023789
//jwan869
//Nov 16th 2020

void printSentence(sentence_node * sn);
void printList(linked_list * ll );
word_position * searchWord(linked_list * ll, char * toSearch);

bool deleteSetence(linked_list * ll, int line_num ){  // True -> success 

    printf("Delete Node !\n");
    if ( line_num > ll->count  || line_num < 1 ) return false;    
    sentence_node * head = ll->head;
    sentence_node * prev =NULL;

    // printf(ll->count);

    if (ll->count ==1){
        //delete first node()
        printf("line removed ");
        ll->head = NULL;
        return true;
    }

    for (int i=0; i<line_num+1; i++){
        if (i == line_num-1){
            if(i ==0){
                printf("whooops");
                sentence_node * to_delete = ll->head->next;
                ll->head = ll->head->next;
                if (to_delete != NULL){
                    // to delete 
                }
                break; 
            } else {
                prev = head;
            }
        }
        head = head->next;
    }
    
    if (prev != NULL ){   // occurs when deleting line 1;
        sentence_node * to_delete = prev->next;
        prev->next = head;

        if (to_delete != NULL ){
            // delete to_delete
        }
    }

    for (int i = line_num; i < ll->count +1; i++){
        head->whichLine --;
        head = head->next;
    }
    printList(ll);
}

void printList(linked_list * ll ){
    sentence_node * sn = ll->head;

    printf("\nThis is all the words printed out one line at a time \n");
    if (ll->head == NULL){
        
        return;
    }
    while(sn != NULL){
        printSentence(sn);
        printf("\n");
        sn = sn->next;
    }
}

void printSentence(sentence_node * sn){
    word_node * wn = sn->wordPtr;
    while(wn != NULL){
        printf(wn->charPtr );
        printf(" ");
        wn = wn->next;
    }
} 

int  stringParser( char *inputStr, char ***w_array) {
    int size = 0;
    char *temp = inputStr;

    while ( *temp ){
        while ( isspace( ( unsigned char )*temp ) ){
            temp++;
        }
        size += *temp != '\0';
        while ( *temp && !isspace( ( unsigned char )*temp ) ){
            temp++;
        } 
    }

    if ( size ) {
        int iter = 0;

        *w_array = malloc( size * sizeof( char * ) ); 
        temp = inputStr;

        while ( *temp ){
            while ( isspace( ( unsigned char )*temp ) ) ++temp;
            if ( *temp ){
                char *q = temp;
                while ( *temp && !isspace( ( unsigned char )*temp ) ){
                    temp ++;
                }

                int len = temp - q;
                ( *w_array )[iter] = ( char * )malloc( len + 1 );

                strncpy( ( *w_array )[iter], q, len );
                ( *w_array )[iter][len] = '\0';

                iter ++;
            }
        }           
    }

    return size;
}  

void searchContinuously(linked_list * ll){
    char inputStr[1000];

    int max_limit = 100;
    while (max_limit-- > 0){
        printf("\nEnter a word to search: ");
        gets(inputStr);
        word_position * wp = searchWord(ll, inputStr);
        if (wp == NULL){
            printf("Unable to find word: %s", inputStr); 
        } else {
            printf("Word %s found at sentence position: %d, word position: %d \n", inputStr, wp->sentence_pos, wp->word_pos);
            free(wp);
        }
    }   
}

word_position * searchWord(linked_list * ll, char *toSearch){
    sentence_node * sn = NULL;
    sn = ll->head;
    
    while(sn != NULL){
        word_node * wn = sn->wordPtr;
        while(wn != NULL){
            
            if (strcmp(wn->charPtr, toSearch) == 0){
                word_position * wp = malloc(sizeof(word_position));
                wp->sentence_pos = sn->whichLine; 
                wp->word_pos = wn->position;
                return wp;
            }
            wn = wn->next;
        }
        sn = sn->next;
    }
    return NULL;
}

void initLinkedList(linked_list * ll){

    int lineNum = -1; 

    sentence_node * first_sentence = NULL;
    sentence_node *  prev_sentence = NULL;
    int max_limit =100;
    
    while(max_limit-- >0){
        lineNum ++;
        char inputStr[1000];
        printf("Enter a string: ");
        gets(inputStr);
        
        if (strlen(inputStr) ==0 ){
            break;
        }
        
        sentence_node * sn = malloc(sizeof(sentence_node));
        sn->whichLine = lineNum;

        char ** w_array = NULL;

        int n = stringParser( inputStr, &w_array );

        word_node * wn_arr [n];

        for ( int i = 0; i < n; i++ ){
            word_node * wn = malloc(sizeof(word_node));
            wn->charPtr = w_array[i];
            wn->size = strlen(w_array[i]);
            wn->position =  i;
            wn->next = NULL;
            wn_arr[i] = wn;   
        }

        for ( int i = 0; i < n-1; i++ ){
            wn_arr[i]->next = wn_arr[i+1];
        }

        free( w_array ); // free array of word_nodes
        
        sn->wordPtr = wn_arr[0];
        sn->numOfWords = n;
        sn->next = NULL;

        if(first_sentence == NULL){
            first_sentence = sn;
        }
        
        if (prev_sentence != NULL){
            prev_sentence->next = sn;
        }
        prev_sentence = sn;
    }
    ll->count = lineNum;
    ll->head = first_sentence;
}

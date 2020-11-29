//CS2211a 2020
//Assignment 4
//Jeffrey Wang
//251023789
//jwan869
//Nov 16th 2020

void printSentence(sentence_node * sn);
void printList(linked_list * ll );

bool deleteSetence(linked_list * ll, int line_num ){  // True -> success 

    printf("Delete Node !\n");
    if ( line_num > ll->count  || line_num < 1 ) return false;    
    sentence_node * head = ll->first;
    sentence_node * prev =NULL;

    // printf(ll->count);

    if (ll->count ==1){
        //delete first node()
        printf("line removed ");
        ll->first = NULL;
        return true;
    }

    for (int i=0; i<line_num+1; i++){
        if (i == line_num-1){
            if(i ==0){
                printf("whooops");
                sentence_node * to_delete = ll->first->next;
                ll->first = ll->first->next;
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
    sentence_node * sn = ll->first;

    // printf("\n This is all the words printed out one line at a time \n");
    // if (ll->first == NULL){
        
    //     return;
    // }
    // while(sn != NULL){
    //     printSentence(sn);
    //     printf("\n");
    //     sn = sn->next;
    // }
}

void printSentence(sentence_node * sn){
    word_node * wn = sn->wordPtr;
    while(wn != NULL){
        printf(wn->charPtr );
        printf(" ");
        wn = wn->next;
    }
} 



int  parse_input ( char *input, char ***word_array) 
{
    int n = 0;
    const char *p = input;

    while ( *p )
    {
        while ( isspace( ( unsigned char )*p ) ) ++p;
        n += *p != '\0';
        while ( *p && !isspace( ( unsigned char )*p ) ) ++p;
    }

    if ( n !=0 ) {
        size_t i = 0;

        *word_array = malloc( n * sizeof( char * ) ); 

        p = input;

        while ( *p )
        {
            while ( isspace( ( unsigned char )*p ) ) ++p;
            if ( *p )
            {
                const char *q = p;
                while ( *p && !isspace( ( unsigned char )*p ) ) ++p;

                size_t length = p - q;

                ( *word_array )[i] = ( char * )malloc( length + 1 );

                strncpy( ( *word_array )[i], q, length );
                ( *word_array )[i][length] = '\0';

                ++i;
            }
        }           
    }

    return n;
}  


void processsInput(linked_list * ll){

    int lineNum = -1; 

    sentence_node * first_sentence = NULL;
    sentence_node *  prev_sentence = NULL;

    while(1){
        lineNum ++;
        char inputStr[1000];
        printf("Enter a string: ");
        gets(inputStr);
        
        if (strlen(inputStr) ==0 ){
            break;
        }
        
        char * word = malloc(strlen(inputStr)+1);
    
        int n = strlen(inputStr);
        int s=0;
        int word_pos = 0; 
        word_node * past = NULL;

        word_node * first_word = NULL;


        sentence_node * sn = malloc(sizeof(sentence_node));
        
        sn->whichLine = lineNum;



        // for (int i =0; i<n; i++){
        //     if (inputStr[i] == ' '){
        //         if (strlen(word) != 0){
        //             char * w = malloc(strlen(word) +1);
        //             strcpy(w, word);
        //             strcat(w, "\0");

        //             // printf(inputStr);
        //             printf(word);
        //             printf("\n");
        //             word_node * wn = malloc(sizeof(word_node));
        //             wn->charPtr = w;
        //             wn->size = strlen(w);
        //             wn->position =  word_pos;
        //             wn->next = NULL;

        //             if( past != NULL){
        //                 past->next = wn;
        //             }
                    
        //             if (first_word == NULL) {
        //                 first_word = wn;
        //             }
        //             past = wn;
        //             word_pos ++;
        //             s =0;
        //             memset(word, 0, strlen(inputStr)+1);
                   
        //         }
        //     } else if (inputStr[i] != '\0'){
        //         word[s] = inputStr[i];
        //         s++;
        //     }
        // }
        // if (strlen(word) != 0){
        //     char * w = malloc(strlen(word) +1);
        //     strcpy(w, word);
        //     strcat(w, "\0");

        //     word_node * wn = malloc(sizeof(word_node));
        //     wn->charPtr = w;
        //     wn->size = strlen(w);
        //     wn->position =  word_pos;
        //     word_pos ++;
            
        //     if( past != NULL){
        //         past->next = wn;
        //     }

        //     if (first_word == NULL) {
        //         first_word = wn;
        //     }

        //     past = wn;
        //     s =0;
        //     memset(word, 0 , n +1) ;
        // }
        
        sn->wordPtr = first_word;
        sn->numOfWords = word_pos;
        sn->next = NULL;

        if(first_sentence == NULL){
            first_sentence = sn;
        }
        
        if (prev_sentence != NULL){
            prev_sentence->next = sn;
        }
        prev_sentence = sn;

        free(word);
    }
    ll->count = lineNum;
    ll->first = first_sentence;

}



// int sentenceOutput(sentences *myString, char inputStr[]){
    
//     int currentLine = 0;
//     int currentWord = 0;
//     int currentChar = 0;
//     int lineMemory = 0;
//     int wordMemory = 0;
//     int charMemory = 0;
//     int numOfLines = 0;
//     int count = 0;
    
    
//     while(1){
//     printf("please enter a string:  ");
//     gets(inputStr);
//     numOfLines++;
//     for(int i = 0; i<strlen(inputStr);i++){
//         if(inputStr[i] != ' '){
//             count++;
//         }
//     }
//     if(count == 0){
//         break;
//     }
//     else if(count != 0 && numOfLines ==1){
        
//         lineMemory++;
//         wordMemory++;
//         charMemory++;
//         myString = (sentences *) calloc (lineMemory,sizeof(sentences));
//         for(int i=0;i<wordMemory;i++){// for  every time it's less than the wordMermeory
//             myString[i].wordPtr = (words *) calloc (wordMemory,sizeof(words)); //we allocate the the array element of mystring 
//             for(int m=0;m<charMemory;m++){
//                 myString[i].wordPtr[m].charPtr = (char *) calloc (charMemory,sizeof(char));
//             }
//         }
//     }
    

//     for(int i=0;i<strlen(inputStr);i++){
        
//         if(inputStr[i] != ' '){
//             myString[currentLine].wordPtr[currentWord].charPtr[currentChar] = inputStr[i];
//             currentChar++;
            
//             if(currentChar == charMemory){
//                myString[currentLine].wordPtr[currentWord].charPtr = realloc (myString[currentLine].wordPtr[currentWord].charPtr,(charMemory*sizeof(char)));
//             }
            
            
//             if(inputStr[i+1]==' '){
//                 myString[currentLine].wordPtr[currentWord].size = (currentChar );
//                 myString[currentLine].wordPtr[currentWord].position = (currentWord + 1);
//                 currentChar = 0;
//                 currentWord++;
//                 if(currentWord == wordMemory){
//                     //getting memory for new word
//                     wordMemory++;
//                     myString[currentLine].wordPtr = realloc (myString[currentLine].wordPtr,(wordMemory*sizeof(words)));
//                     for(int k=0;k<wordMemory;k++){
//                         myString[currentLine].wordPtr[k].charPtr = realloc (myString[currentLine].wordPtr[k].charPtr,(charMemory*sizeof(char)));
//                     }
//                 }
//             }
            
           
//             else if(i == (strlen(inputStr)-1)){
//                 myString[currentLine].wordPtr[currentWord].size = (currentChar );
//                 myString[currentLine].wordPtr[currentWord].position = (currentWord + 1);
//                 currentChar = 0;
//                 currentWord++;
//                 if(currentWord == wordMemory){
//                     //getting memory for new word
//                     wordMemory++;
//                     myString[currentLine].wordPtr = realloc (myString[currentLine].wordPtr,(wordMemory*sizeof(words)));
//                 }
//             }
//         }
        
//     }
//     myString[currentLine].numOfWords = (currentWord + 1);
//     currentLine++;
//     currentWord = 0;
//     currentChar = 0;
//     count = 0;
    
   
//     if(currentLine == lineMemory){
//         lineMemory++;
//         myString = realloc(myString,(lineMemory*sizeof(sentences)));
//         myString[(lineMemory-1)].wordPtr = realloc (myString[(lineMemory-1)].wordPtr,(wordMemory*sizeof(words)));
//         for(int k=0;k<wordMemory;k++){
//             myString[(lineMemory-1)].wordPtr[k].charPtr = realloc (myString[(lineMemory-1)].wordPtr[k].charPtr,(charMemory*sizeof(char)));
//         }
        
//     }
// }
    

//     for(int i=0;i<1000;i++){
//         inputStr[i] = '\0';
//     } 
//     printf("this is all the words printed out one line at a time:   \n");    
//     printsentence(myString,numOfLines);



//     printf("\nthis is all the words printed out on the same line as entered:   \n");
//     printOgSentence(myString,numOfLines);

    
//  //this is the search function//
//     int newCounter=0;
//     int match = 0;
//     int wordFinder = 0; 
//     while(1){
//         printf("enter a word you are searching:   \n");
//         gets(inputStr); // we get the search word and place  into the inputStr
    
//         for(int i = 0; i<strlen(inputStr);i++){
//             if(inputStr[i] != ' '){
//                 newCounter++;// here we increment the counter every time the inputStr has a blank spot
//             }
//         }
//         if(newCounter == 0){
//             break; // if there is nothing in the sentence we break
//         }
//         newCounter = 0; // and we reset the counter in case
    
//         for(int i=0; i<numOfLines;i++){
//             for(int m=0;m<myString[i].numOfWords;m++){
//                 int newCounter=0;// we set the counter and the match to zero at first
//                 match = 0;
//                 for(int n=0; n<myString[i].wordPtr[m].size;n++){
//                     if(myString[i].wordPtr[m].charPtr[n]==inputStr[newCounter]){
//                         match++;// for every time the char address of the word of the sentence is equal to the array element of the counter
//                     }// it increases the match and counter
//                     newCounter++;
//                 }
//                 if(match == strlen(inputStr)){
//                     int line = i+1;
//                     int position = m+1;
                
//                     printInArray(inputStr);
//                     printf("  is found in line %d position %d\n",line,position);
//                     wordFinder++;
//                 }
//                 else if(m==numOfLines && match != strlen(inputStr)){
//                     if(wordFinder == 0){
//                         printInArray(inputStr);
//                         printf("  is not found in this line.\n");
//                     }
//                     if(wordFinder != 0){
//                         printInArray(inputStr);
//                         printf("  is not found in the rest of this file.\n");
//                     }
//                 }
//             }
//         }
//     }

//     return 0;
// }
#include "list.h"
#include <stddef.h> 
#include <stdio.h>


static Node nodeArray[LIST_MAX_NUM_NODES]; 
static Node listHeadArray[LIST_MAX_NUM_HEADS]; 

static int listNum = 0 ; 
 

List* List_create() {
   if(listHeadArray[listNum] == NULL){
    listHeadArray[0] = nodeArray; 
   }
}
int main () {
    printf("hello world") ; 
}
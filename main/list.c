#include "list.h"
#include <stddef.h> 



int List_count(List* pList) {
    if (pList == NULL) {
        return LIST_FAIL;
    }
    return pList->size; // Assuming you have a size field in your List structure
}

int main () {
    printf("hello world") ; 
}
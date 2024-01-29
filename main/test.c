#include "list.h"
#include <stdio.h>





int main() {
    // Try to create more lists than the maximum number allowed to ensure that it fails correctly.
    List* listArray[LIST_MAX_NUM_HEADS + 1];

    // Create the maximum number of lists allowed.
    for (int i = 0; i < LIST_MAX_NUM_HEADS; i++) {
        listArray[i] = List_create();
        if (listArray[i] == NULL) {
            printf("Failed to create new list at index %d\n", i);
            return -1;
        }
    }
    printf("Successfully created the maximum number of lists (%d).\n", LIST_MAX_NUM_HEADS);

    // Try to create one more list, which should fail.
    listArray[LIST_MAX_NUM_HEADS] = List_create();
    if (listArray[LIST_MAX_NUM_HEADS] != NULL) {
        printf("Error: Was able to create more than the maximum number of lists.\n");
        return -1;
    }
    printf("Correctly failed to create a list beyond the maximum number allowed.\n");

    // Optionally, you can now test the deletion of a list and the creation of a new one to make sure recycling works.
    // List_free(listArray[0], freeFunction); // Assuming you have a function to free the items.
    // listArray[0] = List_create();
    // if (listArray[0] == NULL) {
    //     printf("Failed to create a new list after deleting one.\n");
    //     return -1;
    // }
    // printf("Successfully recycled a list head for a new list.\n");

    return 0;
}
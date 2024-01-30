

#include "list.h"

#include <stdio.h>

int main()
{
    List *list1 = List_create();
    printf("%d \n", List_count(list1));
    int integer1 = 1;
    int integer2 = 2;
    int integer3 = 3;
    int integer4 = 4;
    int integer5 = 5;
    int integer6 = 6;
    int success1 = List_append(list1, &integer1);
    int success2 = List_append(list1, &integer2);
    int success3 = List_append(list1, &integer3);
    int success4 = List_append(list1, &integer4);
    int success5 = List_append(list1, &integer5);
    int success6 = List_append(list1, &integer6);
    List_print(list1);
    printf("%d \n", List_count(list1));
    void *listCurrTest1 = List_curr(list1);
    if (listCurrTest1 != NULL)
    {
        printf("this is current number : %d \n", *(int *)listCurrTest1);
    }
    else
    {
        printf("Current item is NULL or out of bounds.\n");
    }

    void *firstElement = List_first(list1);
    if (firstElement != NULL)
    {
        printf("this is first item : %d \n", *(int *)firstElement);
    }
    else
    {
        printf("first item is not accessible");
    }

    void *listCurrTest2 = List_curr(list1);
    if (listCurrTest2 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest2);
    else
        printf("Current item is NULL or out of bounds.\n");

    // testing next item
    void *nextItemTest1 = List_next(list1);
    if (nextItemTest1 != NULL)
        printf("this is current number : %d \n", *(int *)nextItemTest1);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *listCurrTest3 = List_curr(list1);
    if (listCurrTest3 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest3);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *nextItemTest2 = List_next(list1);
    if (nextItemTest2 != NULL)
        printf("this is current number : %d \n", *(int *)nextItemTest2);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *listCurrTest4 = List_curr(list1);
    if (listCurrTest4 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest4);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *nextItemTest3 = List_next(list1);
    if (nextItemTest3 != NULL)
        printf("this is current number : %d \n", *(int *)nextItemTest3);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *listCurrTest5 = List_curr(list1);
    if (listCurrTest5 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest5);
    else
        printf("Current item is NULL or out of bounds.\n");

    // testing previous ite m
    void *previousItemTest1 = List_prev(list1);
    if (previousItemTest1 != NULL)
        printf("this is current number : %d \n", *(int *)previousItemTest1);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *listCurrTest6 = List_curr(list1);
    if (listCurrTest6 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest6);
    else
        printf("Current item is NULL or out of bounds.\n");

    // testing list_last
    void *testingListLast = List_last(list1);
    if (testingListLast != NULL)
        printf("this is current number : %d \n", *(int *)testingListLast);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *listCurrTest7 = List_curr(list1);
    if (listCurrTest7 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest7);
    else
        printf("Current item is NULL or out of bounds.\n");

    // testing list_insert_after
    printf("Testing list_insert_after");

    void *firstElement100 = List_first(list1);
    int integer7 = 7;

    int n = List_insert_after(list1, &integer7);
    List_print(list1);

    void *testingListLast1 = List_last(list1);
    if (testingListLast1 != NULL)
        printf("this is current number : %d \n", *(int *)testingListLast1);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *listCurrTest8 = List_curr(list1);
    if (listCurrTest8 != NULL)
        printf("this is current number : %d \n", *(int *)listCurrTest8);
    else
        printf("Current item is NULL or out of bounds.\n");

    void *firstElement1 = List_first(list1);
    if (firstElement1 != NULL)
    {
        printf("this is first item : %d \n", *(int *)firstElement1);
    }
    else
    {
        printf("first item is not accessible");
    }   


    void *currItem = List_curr(list1);
    if (currItem != NULL)
    {
        printf("this is current item : %d \n", *(int *)currItem);
    }
    else
    {
        printf("current item is not accessible");
    } 

    
    

    int number = 200 ;

    int n30 = List_insert_after(list1,&number ) ; 

    void* firstItem = List_first(list1) ; 
    void* secondItem = List_next(list1) ;
    void* thirdItem = List_next(list1) ;
    void* fourthItem = List_next(list1) ;
    void* fifthItem = List_next(list1) ;
    void* sixthItem = List_next(list1) ;
    void* seventhItem = List_next(list1) ;
    void* eightItem = List_next(list1) ;
    printf("first item : %d \n", *(int*)firstItem);
    printf("second item : %d \n", *(int*)secondItem);
    printf("third item : %d \n", *(int*)thirdItem);
    printf("fourth item : %d \n", *(int*)fourthItem);
    printf("fifth item : %d \n", *(int*)fifthItem);
    printf("sixth item : %d \n", *(int*)sixthItem);
    printf("seventh item : %d \n", *(int*)seventhItem);
    printf("eighth item : %d \n", *(int*)eightItem);



    

    return 0;
}

// #include "list.h"

// #include <stdio.h>

// void testCreateList();
// void test_List_count();
// void test_List_next_List_prev();
// void test_List_insert_after_before();
// void test_List_Trim_Remove();

// int integer1 = 1;
// int integer2 = 2;
// int integer3 = 3;
// int integer4 = 4;
// int integer5 = 5;
// int integer6 = 6;
// List *list1;
// List *list2;

// void printList(List* pList) {
//     if (pList == NULL) {
//         printf("List is NULL.\n");
//         return;
//     }

//     Node* currentNode = pList->head;
//     while (currentNode != NULL) {
//         // Assuming that the data is a pointer to an integer
//         printf("%d ", (int)(currentNode->item));
//         currentNode = currentNode->next;
//     }
//     printf("\n");
// }
// int main()
// {
//     list1 = List_create();
//     list2 = List_create();
//     int success1 = List_append(list1, &integer1);
//     int success2 = List_append(list1, &integer2);
//     int success3 = List_append(list1, &integer3);
//     int success4 = List_append(list1, &integer4);
//     int success5 = List_append(list1, &integer5);
//     int success6 = List_append(list1, &integer6);
//     test_List_count();
//     test_List_next_List_prev();
//     test_List_insert_after_before();
//     test_List_Trim_Remove();
//     return 0;
// }

// void testCreateList() {
//     printf("Testing List_create(): \n");
//     List *list1 = List_create();
//     List *list2 = List_create();
//     List *list3 = List_create();
//     List *list4 = List_create();
//     List *list5 = List_create();
//     List *list6 = List_create();
//     List *list7 = List_create();
//     List *list8 = List_create();
//     List *list9 = List_create();
//     List *list10 = List_create();
//     List_free(list1, NULL);
//     List_free(list2, NULL);
//     List_free(list3, NULL);
//     List_free(list4, NULL);
//     List_free(list5, NULL);
//     List_free(list6, NULL);
//     List_free(list7, NULL);
//     List_free(list8, NULL);
//     List_free(list9, NULL);
//     List_free(list10, NULL);
//     if (list10 == NULL)
//     {
//         printf("Test Failed! \n");
//     }
//     else
//     {
//         printf("Test Passed!\n");
//     }

//     List *list11 = List_create();
//     if (list11 == NULL)
//     {
//         printf("Test Failed! \n");
//     }
//     else
//     {
//         printf("Test Passed! \n");
//     }

//     if (List_create() == NULL)
//     {
//         printf("Test Failed! \n");
//     }
//     else
//     {
//         printf("Test Passed! \n");
//     }

//     return;
// }

// void test_List_count() {
//     // printf("size of list1 : %d", List_count(list1));
//     printf("Test List_count(): \n");
//     if (List_count(list1) == 6)
//         printf("Test PASSED  \n");
//     else
//         printf("Test FAILED  \n");

//      if (List_count(list1) == 6 && List_count(list2) == 0){
//         printf("Test PASSED \n") ;
//      } else{
//         printf("Test FAILED \n") ;
//      }
// }

// void test_List_next_List_prev() {
//     printf("Testing List_next() and List_prev():\n");

//     // Test List_next
//     List_first(list1); // Set current to first item
//     printf("List_next(): ");
//     for (int i = 0; i < 6; i++) { // Assuming list has 6 items
//         void *item = List_curr(list1);
//         if (*(int *)item != integer1 + i) {
//             printf("TEST FAILED at index %d\n", i);
//             break;
//         }
//         if (i < 5) { // Move to next only if not at the last item
//             List_next(list1);
//         }
//     }
//     printf("TEST PASSED\n");

//     // Test List_prev
//     List_last(list1); // Set current to last item
//     printf("List_prev(): ");
//     for (int i = 5; i >= 0; i--) { // Assuming list has 6 items
//         void *item = List_curr(list1);
//         if (*(int *)item != integer1 + i) {
//             printf("TEST FAILED at index %d\n", i);
//             break;
//         }
//         if (i > 0) { // Move to previous only if not at the first item
//             List_prev(list1);
//         }
//     }
//     printf("TEST PASSED\n");
// }

// void test_List_insert_after_before() {
//     printf("Test List_insert_after() and List_insert_before():\n");

//     // Test List_insert_after
//     List_first(list1); // Set current to first item
//     int newAfterItem = 7;
//     List_insert_after(list1, &newAfterItem);

//     List_next(list1); // Move current to the newly inserted item
//     printf("List_insert_after():\n");
//     if (*(int *)List_curr(list1) == newAfterItem) {
//         printf("TEST PASSED\n");
//     } else {
//         printf("TEST FAILED\n");
//     }

//     // Test List_insert_before
//     List_first(list1); // Reset current to first item
//     int newBeforeItem = 8;
//     List_insert_before(list1, &newBeforeItem);
//     printf("List_insert_before():\n");
//     if (*(int *)List_curr(list1) == newBeforeItem) {
//         printf("TEST PASSED\n");
//     } else {
//         printf("TEST FAILED\n");
//     }
// }

// void test_List_Trim_Remove() {
//     List* pList = List_create();

//     int numbers[] = {1, 2, 3, 4, 5};
//     for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++) {
//         List_append(pList, &numbers[i]);
//     }

//     printf("Original list: ");
//     printList(pList);

//     // Set the current item to the second node and remove it
//     List_first(pList);
//     List_next(pList);
//     int* removedItem = (int*)List_remove(pList);
//     if (removedItem) {
//         printf("TEST PASSED: Removed item: %d\n", *removedItem);
//     } else {
//         printf("TEST FAILED: No item was removed.\n");
//     }
//     printf("List after removal: ");
//     printList(pList);

//     // Trim the last item
//     int* trimmedItem = (int*)List_trim(pList);
//     if (trimmedItem) {
//         printf("TEST PASSED: Trimmed item: %d\n", *trimmedItem);
//     } else {
//         printf("TEST FAILED: No item was trimmed.\n");
//     }
//     printf("List after trim: ");
//     printList(pList);

//     // Clean up the list
//     List_free(pList, NULL);
// }

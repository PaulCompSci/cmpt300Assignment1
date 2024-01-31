

// #include "list.h"

// #include <stdio.h>

// bool comparator(void *pItem, void *pComparisonArg) {
//     int *itemValue = (int *)pItem;
//     int *comparisonValue = (int *)pComparisonArg;
//     return (*itemValue == *comparisonValue);
// }

// int main()
// {
//     List *list1 = List_create();
//     if (List_curr(list1) == 0)
//         printf("List_curr test1 passed \n");
//     else
//         printf("List_curr test2 failed \n");

//     // inserting element into the lsit
//     int integer1 = 1;
//     int integer2 = 2;
//     int integer3 = 3;
//     int integer4 = 4;
//     int integer5 = 5;
//     int integer6 = 6;
//     int success1 = List_append(list1, &integer1);
//     int success2 = List_append(list1, &integer2);
//     int success3 = List_append(list1, &integer3);
//     int success4 = List_append(list1, &integer4);
//     int success5 = List_append(list1, &integer5);
//     int success6 = List_append(list1, &integer6);

//     void *testing = List_curr(list1);
//     // 1 -> 2 -> 3 ->4 ->5 ->6

//     if (testing != NULL && *(int *)testing == 6)
//     {
//         printf("List_curr test2 passed \n");
//     }
//     else
//     {
//         printf("List_curr test2 failed \n");
//     }

//     void *listFirst = List_first(list1);
//     if (listFirst != NULL && *(int *)listFirst == 1)
//         printf("List_first test1 passed \n");
//     else
//         printf("List_first test1 failed \n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 1)
//         printf("List_curr test3 Passed \n ");
//     else
//         printf("List_curr test3 Failed \n");

//     void *listLast = List_last(list1);
//     if (listLast != NULL && *(int *)listLast == 6)
//         printf("List_last test 1 Passed \n");
//     else
//         printf("List_last test1 Failed \n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 6)
//         printf("List_curr test4 Passed \n ");
//     else
//         printf("List_curr test4 Failed \n");

//     void *listPrev = List_prev(list1);
//     if (listPrev != NULL && *(int *)listPrev == 5)
//         printf("List_prev test 1 Passed \n");
//     else
//         printf("List_prev test1 Failed \n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 5)
//         printf("List_curr test5 Passed \n ");
//     else
//         printf("List_curr test5 Failed \n");

//     /*
//         testing insert after
//         expected : 1 -> 2 -> 3 -> 4 -> 5 -> 200 -> 6

//     */

//     int integer200 = 200;
//     int success200 = List_insert_after(list1, &integer200);

//     List_print(list1);
//     printf("print statement above should produce 1->2->3->4->5->200->6\n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 200)
//         printf("List_curr test6 Passed \n ");
//     else
//         printf("List_curr test6 Failed \n");

//     /*
//         testing insert before
//         expected : 1 ->2 -> 3-> 4-> 5 -> 999 -> 200 ->6
//     */

//     int integer999 = 999;
//     int success999 = List_insert_before(list1, &integer999);
//     List_print(list1);
//     printf("print statement above should produce 1->2->3->4->5->999->200->6\n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 999)
//         printf("List_curr test7 Passed \n ");
//     else
//         printf("List_curr test7 Failed \n");

//     /*
//         testing list_insert_prepend
//         expected : 444 -> 1 ->2 -> 3-> 4-> 5 -> 999 -> 200 ->6
//     */

//     int integer444 = 444;
//     int success444 = List_prepend(list1, &integer444);
//     List_print(list1);
//     printf("print statement above should produce 444->1->2->3->4->5->999->200->6\n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 444)
//         printf("List_curr test8 Passed \n ");
//     else
//         printf("List_curr test8 Failed \n");

//     /*
//         testing : List_remove
//         expected : 1 ->2 -> 3-> 4-> 5 -> 999 -> 200 ->6
//         removed : 444
//         current : 1
//     */
//     void *removed = List_remove(list1);
//     if (removed != NULL && *(int *)removed == 444)
//         printf("List_remove test1 passed \n");
//     else
//         printf("List_remove test1 Failed \n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 1)
//         printf("List_curr test9 Passed \n ");
//     else
//         printf("List_curr test9 Failed \n");

//     if (List_count(list1) == 8)
//         printf("List_count test1 Passed ! \n ");
//     else
//         printf("List count test1 Failed! \n");

//     /*
//         testing : List_remove (this time from the second element)
//         expected : 1 -> 3 -> 4-> 5 -> 999 -> 200 ->6
//         current : 3
//     */
//     void *nextItem = List_next(list1);
//     void *removed1 = List_remove(list1);
//     if (removed1 != NULL && *(int *)removed1 == 2)

//         printf("List_removed test2 Passed \n");

//     else

//         printf("List_removed test2 Failed \n");

//     // Additional checks for List_curr and List_count as needed
//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 3)
//     {
//         printf("List_curr test10 Passed \n");
//     }
//     else
//     {
//         printf("List_curr test10 Failed \n");
//     }

//     if (List_count(list1) == 7)
//     {
//         printf("List_count test2 Passed ! \n");
//     }
//     else
//     {
//         printf("List count test2 Failed! \n");
//     }

//     List_print(list1);
//     printf("list above should look like 1 -> 3 -> 4-> 5 -> 999 -> 200 ->6 \n ");

//     /*
//         testing : List_trim function
//         expected  : 1 -> 3 -> 4-> 5 -> 999 -> 200
//         current : 200
//         removed : 6

//     */
//     void *trim = List_trim(list1);
//     if (trim != NULL && *(int *)trim == 6)
//         printf("List_trim test1 Passed  ! \n");
//     else
//         printf("List_trim test1 Failed  ! \n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 200)
//     {
//         printf("List_curr test11 Passed \n");
//     }
//     else
//     {
//         if (List_curr(list1) == NULL)
//             printf("List_curr test11 Failed \n");
//     }

//     if (List_count(list1) == 6)
//     {
//         printf("List_count test3 Passed ! \n");
//     }
//     else
//     {
//         printf("List count test3 Failed! \n");
//     }

//     void *lastItemTest1 = List_last(list1);
//     if (lastItemTest1 != NULL && *(int *)lastItemTest1 == 200)
//         printf("List_last test1 Passed ");
//     else
//         printf("List_last test1 failed");

//     List_print(list1);
//     printf("list above should look like 1 -> 3 -> 4-> 5 -> 999 -> 200 \n");

//     /*
//         testing : List_trim function
//         expected : 1 -> 3 -> 4-> 5 -> 999 ;
//         current : 999
//         removed : 200
//     */
//     void *trim2 = List_trim(list1);
//     if (trim2 != NULL && *(int *)trim2 == 200)
//         printf("List_trim test2 Passed  ! \n");
//     else
//         printf("List_trim test2 Failed  ! \n");

//     if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 999)
//     {
//         printf("List_curr test12 Passed \n");
//     }
//     else
//     {
//         printf("this is the number that current pointing : %d", *(int *)List_curr(list1));
//         printf("List_curr test12 Failed \n");
//     }

//     if (List_count(list1) == 5)
//     {
//         printf("List_count test4 Passed ! \n");
//     }
//     else
//     {
//         printf("List count test4 Failed! \n");
//     }

//     void *lastItemTest2 = List_last(list1);
//     if (lastItemTest2 != NULL && *(int *)lastItemTest2 == 999)
//         printf("List_last test2 Passed ");
//     else
//         printf("List_last test2 failed");

//     printf("\n");
//     List_print(list1);
//     printf("list above should look like 1 -> 3 -> 4 -> 5 -> 999 \n");

//     /*
//         testing list_concat
//         list2 = 333 -> 111 -> 687
//         expected :
//         1 -> 3 -> 4 -> 5 -> 999 -> 333 -> 111 -> 687
//         Number of list = 2
//         Number of node  = 8
//         Number of free node = 92
//         Number of freeList = 8

//     */
//     // Prepare list2 with elements 333, 111, 687
//     List *list2 = List_create();
//     int integer333 = 333, integer111 = 111, integer687 = 687;
//     List_append(list2, &integer333);
//     List_append(list2, &integer111);
//     List_append(list2, &integer687);

//     // Concatenate list2 to list1
//     List_concat(list1, list2); // After this, list2 should be empty and part of list1

//     // Print list1 to verify the concatenation
//     printf("After concatenation, list1 contains: \n");
//     List_print(list1);

//     // Verification steps
//     if (List_count(list1) == 8)
//     {
//         printf("List_count after concat Passed! Number of nodes = 8\n");
//     }
//     else
//     {
//         printf("List_count after concat Failed! Expected 8, found %d\n", List_count(list1));
//     }

//     if (freeNodeCount == 92)
//         printf("number of free node in the system is CORRECT \n ");
//     else
//         printf("number of free node in the system is WRONG \n");
//     // Assuming you have a way to track available list heads
//     printf("Number of List = %d \n", listCount);

//     // Ensure list2 is cleared correctly
//     if (list2->head == NULL && list2->tail == NULL && list2->current == NULL && List_count(list2) == 0)
//     {
//         printf("list2 cleared correctly after concat.\n");
//     }
//     else
//     {
//         printf("Error: list2 not cleared correctly after concat.\n");
//     }

//     /*
//         testing list_free
//         create a new list -> list3
//         list3 = 23 -> 55 -> 99
//         expecting :
//         Number of list = 2
//         Number of free list = 8
//         Number of node total in the system : 11
//         Number of free node in the system : 89
//         after the function call :
//         Number of list = 1
//         Number of free list = 9
//         Number of node total in the system : 8
//         Number of free node in the system : 92
//     */
//     List *list3 = List_create();
//     int item1 = 23, item2 = 55, item3 = 99;
//     List_append(list3, &item1);
//     List_append(list3, &item2);
//     List_append(list3, &item3);

//     printf("Before freeing list3:\n");
//     // Print list3 for visual confirmation
//     List_print(list3);
//     // Display the counts before freeing
//     if (listCount == 2)
//         printf("you havve the CORRECT number of list \n ");

//     else
//         printf("you have the WRONG number of list \n");

//     List_free(list3, NULL) ;
//     if(listCount == 1  && freeNodeCount == 92)
//         printf("list_free test1 Passed ! \n") ;
//     else
//         printf("list_free test1 Failed ! \n") ;

//     printf("-------------------------------------------------\n");
//     printf("listcount : %d \n", listCount);
//     printf("freeNodeCount : %d \n", freeNodeCount);
//     printf("-------------------------------------------------\n");
//     List_print(list1) ;
//     void* listfirst = List_first(list1) ;
//     void* listNext = List_next(list1) ;
//     int searchValue = 5;
//     void *searchResult = List_search(list1, comparator, &searchValue);

//     if (searchResult != NULL && *(int *)searchResult == searchValue) {
//         printf("List_search test Passed! Found: %d\n", *(int *)searchResult);
//     } else {

//         printf("List_search test Failed! Value not found.\n");

//     }
// }

#include "list.h"
#include <string.h>
#include <stdio.h>

void test_List_create_free();
void test_List_count();
void test_List_next_List_prev();
void test_List_insert_after_before();
void test_List_Trim_Remove();
void test_List_Append_Prepend();
void test_List_Concat();
void test_node_pool_exhaustion();
void resetAndInitializeLists();
void test_List_Search();
void e2e_test();

int integer1 = 1;
int integer2 = 2;
int integer3 = 3;
int integer4 = 4;
int integer5 = 5;
int integer6 = 6;
int integer7 = 7;
int integer8 = 8;
int integer9 = 9;
int integer10 = 10;

List *list1;
List *list2;
List *list3;

const char *getOOBString(enum ListOutOfBounds value)
{
    // Helper function
    switch (value)
    {
    case LIST_OOB_START:
        return "LIST_OOB_START";
    case LIST_OOB_END:
        return "LIST_OOB_END";
    default:
        return "LIST IB";
    }
}

void printList(List *pList)
{
    if (pList == NULL)
    {
        printf("List is NULL.\n");
        return;
    }

    Node *currentNode = pList->head;
    while (currentNode != NULL)
    {
        // Assuming that the data is a pointer to an integer
        printf("%d ", (int)(currentNode->item));
        currentNode = currentNode->next;
    }
    printf("\n");
}
int main()
{
    printf("Starting unit tests:...\n");

    printf("-------------------------------------------------\n");
    test_List_create_free();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_count();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_next_List_prev();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_insert_after_before();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_Trim_Remove();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_Append_Prepend();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_Concat();

    printf("-------------------------------------------------\n");
    // resetAndInitializeLists();
    // test_node_pool_exhaustion();

    printf("-------------------------------------------------\n");
    resetAndInitializeLists();
    test_List_Search();

    printf("-------------------------------------------------\n");
    printf("Running e2e test\n");
    resetAndInitializeLists();
    e2e_test();

    return 0;
}

void test_List_create_free()
{
    printf("Testing List_create() and List_free(): \n");

    // Creating a fixed number of lists (less than the maximum)
    List *lists[10];
    for (int i = 0; i < 10; i++)
    {
        lists[i] = List_create();
        if (lists[i] == NULL)
        {
            printf("TEST FAILED: Could not create list %d\n", i);
        }
    }
    // Check if available list head size decreased correctly
    if (listHeadCount() != LIST_MAX_NUM_HEADS - 10)
    {
        printf("TEST FAILED: Available list head size not updated correctly after creation\n");
    }

    // Test creating one more list which should fail as we reach the limit
    List *list11 = List_create();
    if (list11 != NULL)
    {
        printf("TEST FAILED: Created more than 10 lists\n");
    }
    else
    {
        printf("TEST PASSED: Could not create 11th list\n");
    }

    // Test freeing some of the lists
    for (int i = 0; i < 5; i++)
    {
        List_free(lists[i], NULL);
        if (lists[i]->flag == true)
        {
            printf("TEST FAILED: Could not free list %d\n", i);
        }
    }
    // Check if available list head size increased correctly
    if (listHeadCount() != LIST_MAX_NUM_HEADS - 5)
    {
        printf("TEST FAILED: Available list head size not updated correctly after freeing\n");
    }

    // Recreate the lists after freeing
    for (int i = 0; i < 5; i++)
    {
        lists[i] = List_create();
        if (lists[i] == NULL)
        {
            printf("TEST FAILED: Could not recreate list %d after freeing\n", i);
        }
    }
    // Check if available list head size decreased correctly after recreation
    if (listHeadCount() != 0)
    {
        printf("TEST FAILED: Available list head size not updated correctly after recreating\n");
    }

    // Free all lists and check if the available list head size is reset correctly
    for (int i = 0; i < 10; i++)
    {
        List_free(lists[i], NULL);
    }
    if (listHeadCount() == LIST_MAX_NUM_HEADS)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED: Available list head size not reset correctly after freeing all lists\n");
    }

    for (int i = 0; i < 9; i++)
    {
        lists[i] = List_create();
        if (lists[i] == NULL)
        {
            printf("TEST FAILED: Could not recreate list %d after freeing\n", i);
        }
    }
    if (listHeadCount() == 1)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_free(lists[1], NULL);
    if (listHeadCount() == 2)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List *dummyList1 = List_create();
    List *dummyList2 = List_create();
    List *dummyList3 = List_create();
    if (listHeadCount() == 0)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    if (dummyList1 != NULL && dummyList2 != NULL && dummyList3 == NULL)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    for (int i = 0; i < 9; i++)
    {
        List_free(lists[i], NULL);
    }
    List_free(dummyList1, NULL);
    List_free(dummyList2, NULL);
    List_free(dummyList3, NULL);
}
void test_List_count()
{
    // printf("size of list1 : %d", List_count(list1));
    printf("Test List_count(): \n");
    if (List_count(list1) == 6)
        printf("Test PASSED  \n");
    else
        printf("Test FAILED  \n");

    if (List_count(list1) == 6 && List_count(list2) == 0)
    {
        printf("Test PASSED \n");
    }
    else
    {
        printf("Test FAILED \n");
    }
}

void test_List_First_Last_Curr()
{
    printf("Testing List_first(), List_last(), and List_curr():\n");

    // Test List_first
    void *item = List_first(list1);
    printf("List_first(): ");
    if (item == &integer1 && list1->outOfBounds != LIST_OOB_END && list1->outOfBounds != LIST_OOB_START)
    { // Assuming 0 means not out-of-bounds
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    // Test List_last
    item = List_last(list1);
    printf("List_last(): ");
    if (item == &integer6 && list1->outOfBounds != LIST_OOB_END && list1->outOfBounds != LIST_OOB_START)
    { // Assuming integer6 is the last item
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    printf("List_curr()");
    List_first(list2); // Attempt to set current to first item in an empty list
    item = List_curr(list2);
    if (item == NULL && list2->outOfBounds == LIST_OOB_START)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    printf("Combined test: \n");
    // Test navigating to the end and checking outOfBounds
    List_last(list1); // Move to last valid item
    if (List_curr(list1) == integer6)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_next(list1); // Attempt to move beyond the last item
    if (List_curr(list1) == NULL && list1->outOfBounds == LIST_OOB_END)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
}

void test_List_next_List_prev()
{
    printf("Testing List_next() and List_prev():\n");

    // Test List_next
    List_first(list1); // Set current to first item
    printf("List_next():\n");
    // printf("%d\n", list1->current->item);
    // printf("%s\n", getOOBString(list1->outOfBounds));
    for (int i = 0; i < 6; i++)
    { // Assuming list has 6 items
        void *item = List_curr(list1);
        if (*(int *)item != integer1 + i)
        {
            printf("TEST FAILED at index %d\n", i);
            break;
        }
        if (i < 5)
        { // Move to next only if not at the last item
            List_next(list1);
        }
    }
    printf("TEST PASSED\n");
    List_last(list1);
    List_next(list1);
    if (list1->outOfBounds == LIST_OOB_END)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    // Test List_prev
    List_last(list1); // Set current to last item
    printf("List_prev(): \n");
    for (int i = 5; i >= 0; i--)
    { // Assuming list has 6 items
        void *item = List_curr(list1);
        if (*(int *)item != integer1 + i)
        {
            printf("TEST FAILED at index %d\n", i);
            break;
        }
        if (i > 0)
        { // Move to previous only if not at the first item
            List_prev(list1);
        }
    }
    printf("TEST PASSED\n");
    List_first(list1);
    List_prev(list1);
    if (list1->outOfBounds == LIST_OOB_START)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
}

void test_List_insert_after_before()
{
    printf("Test List_insert_after() and List_insert_before():\n");
    // Test List_insert_after
    List_first(list1); // Set current to first item
    int newAfterItem = 7;
    List_insert_after(list1, &newAfterItem);
    printf("List_insert_after(): \n");
    if (*(int *)List_curr(list1) == newAfterItem)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_prev(list1);
    if (*(int *)List_curr(list1) == 1)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_next(list1);
    List_next(list1);
    if (*(int *)List_curr(list1) == 2)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    // Test List_insert_before
    List_first(list1); // Reset current to first item
    int newBeforeItem = 8;
    List_insert_before(list1, &newBeforeItem);
    printf("List_insert_before():\n");
    if (*(int *)List_curr(list1) == newBeforeItem)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_next(list1);
    if (*(int *)List_curr(list1) == 1)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_next(list1);
    if (*(int *)List_curr(list1) == 7)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    // Current list1 after this test: 8 1 7 2 3 4 5 6

    printf("Combined test: \n");
    int dummy_start = 10;
    int dummy_end = 11;
    List_insert_before(list2, &dummy_start);
    List_insert_after(list2, &dummy_end);

    int headValue = *(int *)(list2->head->item);
    int tailValue = *(int *)(list2->tail->item);
    // printf("%d", *(int *)(list2->tail->item));
    void *currentItem = List_curr(list2);
    int currValue = currentItem ? *(int *)currentItem : -1;

    if (currValue == dummy_end && headValue == dummy_start && tailValue == dummy_end)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    int dummy_new_start = 12;
    List_insert_before(list2, &dummy_new_start);
    headValue = *(int *)(list2->head->item);
    tailValue = *(int *)(list2->tail->item);

    if (*(int *)(list2->current->item) == dummy_new_start && headValue == dummy_start && tailValue == dummy_end)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
}

void test_List_Append_Prepend()
{
    printf("Testing List_append() and List_prepend():\n");

    int prependItem = 0;
    int appendItem = 7;

    // Prepend and append operations
    List_prepend(list1, &prependItem);
    List_append(list1, &appendItem);

    // Check if the prepend operation succeeded
    int headValue = *(int *)(list1->head->item);
    printf("List_prepend(): \n");
    if (headValue == prependItem)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    int tailValue = *(int *)(list1->tail->item);
    printf("List_append(): \n");
    if (tailValue == appendItem)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    printf("Combined test: \n");
    List_first(list1);
    if (*(int *)List_curr(list1) == prependItem && *(int *)List_last(list1) == appendItem)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    int values[21];
    // Append values from 11 to 20
    for (int i = 11; i <= 20; i++)
    {
        values[i] = i;
        List_append(list2, &values[i]);
    }

    // Prepend values from 0 to 10 in reverse order to maintain sequence
    for (int i = 10; i >= 0; i--)
    {
        values[i] = i;
        List_prepend(list2, &values[i]);
    }

    // Check if the list is in the correct order
    bool correct = true;
    headValue = *(int *)list2->head->item;
    tailValue = *(int *)list2->tail->item;
    List_first(list2);

    for (int i = 0; i <= 20; i++)
    {
        int currValue = *(int *)List_curr(list2);
        if (currValue != i)
        {
            correct = false;
            break;
        }
        List_next(list2);
    }

    if (correct && headValue == 0 && tailValue == 20)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
}
void test_List_Trim_Remove()
{
    List_first(list1); // Set current to first item
    List_next(list1);  // Move to the second item
    void *removedItem = List_remove(list1);
    printf("List_remove():\n");
    if (removedItem && *(int *)removedItem == integer2)
    {
        printf("TEST PASSED (Removed: %d)\n", *(int *)removedItem);
    }
    else
    {
        printf("List_remove(): TEST FAILED\n");
    }

    if (*(int *)list1->current->item == integer3)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    if (List_remove(list2) == NULL)
    {
        printf("TEST PASSED (Removing from empty list)\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    printf("List_trim():\n");
    void *trimmedItem = List_trim(list1);
    if (trimmedItem && *(int *)trimmedItem == integer6)
    { // Assuming integer6 is at the end
        printf("TEST PASSED (Trimmed: %d)\n", *(int *)trimmedItem);
    }
    else
    {
        printf("TEST FAILED\n");
    }

    if (*(int *)list1->tail->item == integer5 && *(int *)list1->current->item == integer5)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    // Test trimming from an empty list
    if (List_trim(list2) == NULL)
    {
        printf("TEST PASSED (Trimming from empty list)\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    printf("Combined test():\n");
    List_remove(list1);
    List_trim(list1);
    List_trim(list1);

    trimmedItem = List_trim(list1);
    if (trimmedItem && *(int *)trimmedItem == integer1)
    { // Assuming integer1 is left
        printf("TEST PASSED (Trimmed from one-item list: %d)\n", *(int *)trimmedItem);
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_append(list1, integer1);
    List_remove(list1);
    if (list1->head == NULL && list1->tail == NULL && list1->outOfBounds == LIST_OOB_END && list1->size == 0)
    {
        printf("TEST PASSED: clear list 1\n");
    }
    else
    {
        printf("TEST FAILED: clear list 1\n");
    }
}

void test_List_Concat()
{
    printf("Testing List_concat():\n");
    List_first(list1);
    List_next(list1);
    List_next(list1);
    int initialCurrValue = *(int *)list1->current->item;
    List_concat(list1, list3);
    List_concat(list1, list2);
    int headValue = list1->head ? *(int *)list1->head->item : -1;
    int tailValue = list1->tail ? *(int *)list1->tail->item : -1;

    if (headValue == 1 && tailValue == 10)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    // Check if list1 contains all elements from both lists in the correct order
    bool correct = true;
    int expectedValues[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Node *currentNode = list1->head;
    for (int i = 0; i < 10; i++)
    {
        if (*(int *)currentNode->item != expectedValues[i])
        {
            correct = false;
            break;
        }
        currentNode = currentNode->next;
    }

    // Check if list3 is empty after concatenation
    if (list3->head != NULL || list3->tail != NULL || list3->size != 0)
    {
        correct = false;
    }
    if (list2->head != NULL || list2->tail != NULL || list2->size != 0)
    {
        correct = false;
    }
    if (*(int *)list1->current->item != initialCurrValue)
    {
        correct = false;
    }

    if (correct)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
}

// Comparator function for integers
bool intComparator(void *pItem, void *pComparisonArg)
{
    int itemValue = *(int *)pItem;
    int comparisonValue = *(int *)pComparisonArg;
    return itemValue == comparisonValue;
}

void test_List_Search()
{
    printf("Testing List_search():\n");
    List_first(list1);
    // Search for a specific value in the list
    int searchValue = 5;
    void *foundItem = List_search(list1, intComparator, &searchValue);
    // Check if the correct item was found
    if (foundItem != NULL && *(int *)foundItem == searchValue)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    if (*(int *)list1->current->item == searchValue)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    // Search for a value not in the list
    int notFoundValue = 11;
    foundItem = List_search(list1, intComparator, &notFoundValue);
    if (foundItem == NULL)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    List_first(list1);
    List_prev(list1); // Now current is before the start
    searchValue = 3;
    foundItem = List_search(list1, intComparator, &searchValue);
    // Check if the correct item was found
    if (foundItem != NULL && *(int *)foundItem == searchValue)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    searchValue = 2;
    foundItem = List_search(list1, intComparator, &searchValue);
    if (foundItem == NULL)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
}

void test_node_pool_exhaustion()
{
    List *myList = List_create();
    int data = 1;

    // Try to add one more node than the pool can handle
    for (int i = 0; i <= LIST_MAX_NUM_NODES; i++)
    {
        if (List_append(myList, &data) == LIST_FAIL)
        {
            // List1 have 6 nodes and List3 have 4 nodes => 10
            if (i == LIST_MAX_NUM_NODES - 10)
            {
                printf("TEST PASSED\n");
            }
            else
            {
                printf("TEST FAILED\n");
            }
            break;
        }
    }
}

void e2e_test()
{

    // Insert new items after and before specific items in list1
    int integer11 = 11;
    int integer12 = 12;
    List_first(list1);
    List_insert_after(list1, &integer11);
    List_insert_before(list1, &integer12);

    // Check state after insertions
    printf("Insert After and Before in List1: \n");
    List_first(list1);
    List_next(list1);
    if (*(int *)List_curr(list1) == integer12)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    List_next(list1);
    if (*(int *)List_curr(list1) == integer11)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }

    List_prev(list1);
    List_next(list1);
    List_next(list1);

    if (*(int *)List_curr(list1) == integer2)
    {
        printf("TEST PASSED\n");
    }
    else
    {
        printf("TEST FAILED\n");
    }
    // List1: [1, 12, 11, 2, 3, 4, 5, 6]; curr = 2

    // Append items to list1 and list3
    int integer13 = 13, integer14 = 14;
    List_append(list1, &integer13);
    List_append(list3, &integer14);
    // List1: [1, 12, 11, 2, 3, 4, 5, 6, 13]; curr = 13
    // List3: [7, 8, 9, 10, 14]; curr = 14

    // Check state of list1 after appending
    int tailValueList1 = *(int *)list1->tail->item;
    if (tailValueList1 == integer13)
    {
        printf("Append to List1: PASSED\n");
    }
    else
    {
        printf("Append to List1: FAILED\n");
    }

    // Remove the second item of list3
    List_first(list3);
    List_next(list3);
    void *removedItem = List_remove(list3);
    if (*(int *)removedItem == 8)
    {
        printf("Remove Item from List3: PASSED\n");
    }
    else
    {
        printf("Remove Item from List3: FAILED\n");
    }
    // List3: [7, 9, 10, 14]; curr = 9

    List_concat(list1, list3);
    // List1: [1, 12, 11, 2, 3, 4, 5, 6, 13, 7, 9, 10, 14]; curr =13

    // Search for a specific value in list1
    List_first(list1);
    int searchValue = 4;
    void *foundItem = List_search(list1, intComparator, &searchValue);
    if (foundItem != NULL && *(int *)foundItem == searchValue && *(int *)list1->current->item == searchValue)
    {
        printf("Search Item in List1: PASSED\n");
    }
    else
    {
        printf("Search Item in List1: FAILED\n");
    }
    // List1: curr = 4

    // Append a new item at the end of list1
    int integer15 = 15;
    List_append(list1, &integer15);
    // List1: [1, 12, 11, 2, 3, 4, 5, 6, 13, 7, 9, 10, 14, 15]; curr =15

    void *trimmedItem = List_trim(list1);
    if (*(int *)trimmedItem == 15)
    {
        printf("Trim Last Item from List1: PASSED\n");
    }
    else
    {
        printf("Trim Last Item from List1: FAILED\n");
    }
    // List1: [1, 12, 11, 2, 3, 4, 5, 6, 13, 7, 9, 10, 14]; curr =14

    // Check current item, size, and outOfBounds status after trimming
    void *currentItem = List_curr(list1);
    int currentSize = List_count(list1);
    const char *outOfBoundsStatus = getOOBString(list1->outOfBounds);

    if (*(int *)currentItem == 14 && currentSize == 13)
    {
        printf("Final State Check of List1: PASSED\n");
    }
    else
    {
        printf("Final State Check of List1: FAILED\n");
    }

    // Test edge case: Attempt to remove item from an empty list2
    List_free(list2, NULL);
    if (List_remove(list2) == NULL)
    {
        printf("Remove from Empty List2: PASSED\n");
    }
    else
    {
        printf("Remove from Empty List2: FAILED\n");
    }

    // Test edge case: Navigating beyond end and start of list1
    List_last(list1);
    List_next(list1); // Attempt to move beyond the last item
    if (List_curr(list1) == NULL && list1->outOfBounds == LIST_OOB_END)
    {
        printf("Navigate Beyond End of List1: PASSED\n");
    }
    else
    {
        printf("Navigate Beyond End of List1: FAILED\n");
    }
    List_first(list1);
    List_prev(list1); // Attempt to move before the first item
    if (List_curr(list1) == NULL && list1->outOfBounds == LIST_OOB_START)
    {

        printf("Navigate Before Start of List1: PASSED\n");
    }
    else
    {
        printf("Navigate Before Start of List1: FAILED\n");
    }

    List_last(list1);
    List_next(list1);

    int integer16 = 16;

    if (List_insert_after(list1, &integer16) == LIST_SUCCESS && *(int *)List_last(list1) == integer16)
    {

        printf("Insert After at OOB_END: PASSED\n");
    }
    else
    {
        printf("Insert After at OOB_END: FAILED\n");
    }

    // Test insert before when current is OOB_START
    List_first(list1);
    List_prev(list1);
    int integer17 = 17;
    if (List_insert_before(list1, &integer17) == LIST_SUCCESS && *(int *)List_first(list1) == integer17)
    {
        printf("Insert Before at OOB_START: PASSED\n");
    }
    else
    {
        printf("Insert Before at OOB_START: FAILED\n");
    }

    List_first(list1);
    List_prev(list1);
    // Test remove when current is OOB
    if (List_remove(list1) == NULL)
    {
        printf("Remove at OOB: PASSED\n");
    }
    else
    {
        printf("Remove at OOB: FAILED\n");
    }
}

void resetAndInitializeLists()
{
    // Free the lists, if they have been created
    if (list1 != NULL)
    {
        List_free(list1, NULL); // Replace 'freeItemFunction' with the appropriate function or NULL
        list1 = NULL;
    }
    if (list2 != NULL)
    {
        List_free(list2, NULL); // Replace 'freeItemFunction' with the appropriate function or NULL
        list2 = NULL;
    }
    if (list3 != NULL)
    {
        List_free(list3, NULL); // Replace 'freeItemFunction' with the appropriate function or NULL
        list3 = NULL;
    }

    // Re-create the lists
    list1 = List_create();
    list2 = List_create();
    list3 = List_create();

    // Re-populate list1 with initial data
    List_append(list1, &integer1);
    List_append(list1, &integer2);
    List_append(list1, &integer3);
    List_append(list1, &integer4);
    List_append(list1, &integer5);
    List_append(list1, &integer6);

    List_append(list3, &integer7);
    List_append(list3, &integer8);
    List_append(list3, &integer9);
    List_append(list3, &integer10);
}
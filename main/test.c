

#include "list.h"

#include <stdio.h>




bool comparator(void *pItem, void *pComparisonArg) {
    int *itemValue = (int *)pItem;
    int *comparisonValue = (int *)pComparisonArg;
    return (*itemValue == *comparisonValue);
}

int main()
{
    List *list1 = List_create();
    if (List_curr(list1) == 0)
        printf("List_curr test1 passed \n");
    else
        printf("List_curr test2 failed \n");

    // inserting element into the lsit
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

    void *testing = List_curr(list1);
    // 1 -> 2 -> 3 ->4 ->5 ->6

    if (testing != NULL && *(int *)testing == 6)
    {
        printf("List_curr test2 passed \n");
    }
    else
    {
        printf("List_curr test2 failed \n");
    }

    void *listFirst = List_first(list1);
    if (listFirst != NULL && *(int *)listFirst == 1)
        printf("List_first test1 passed \n");
    else
        printf("List_first test1 failed \n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 1)
        printf("List_curr test3 Passed \n ");
    else
        printf("List_curr test3 Failed \n");

    void *listLast = List_last(list1);
    if (listLast != NULL && *(int *)listLast == 6)
        printf("List_last test 1 Passed \n");
    else
        printf("List_last test1 Failed \n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 6)
        printf("List_curr test4 Passed \n ");
    else
        printf("List_curr test4 Failed \n");

    void *listPrev = List_prev(list1);
    if (listPrev != NULL && *(int *)listPrev == 5)
        printf("List_prev test 1 Passed \n");
    else
        printf("List_prev test1 Failed \n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 5)
        printf("List_curr test5 Passed \n ");
    else
        printf("List_curr test5 Failed \n");

    /*
        testing insert after
        expected : 1 -> 2 -> 3 -> 4 -> 5 -> 200 -> 6

    */

    int integer200 = 200;
    int success200 = List_insert_after(list1, &integer200);

    List_print(list1);
    printf("print statement above should produce 1->2->3->4->5->200->6\n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 200)
        printf("List_curr test6 Passed \n ");
    else
        printf("List_curr test6 Failed \n");

    /*
        testing insert before
        expected : 1 ->2 -> 3-> 4-> 5 -> 999 -> 200 ->6
    */

    int integer999 = 999;
    int success999 = List_insert_before(list1, &integer999);
    List_print(list1);
    printf("print statement above should produce 1->2->3->4->5->999->200->6\n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 999)
        printf("List_curr test7 Passed \n ");
    else
        printf("List_curr test7 Failed \n");

    /*
        testing list_insert_prepend
        expected : 444 -> 1 ->2 -> 3-> 4-> 5 -> 999 -> 200 ->6
    */

    int integer444 = 444;
    int success444 = List_prepend(list1, &integer444);
    List_print(list1);
    printf("print statement above should produce 444->1->2->3->4->5->999->200->6\n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 444)
        printf("List_curr test8 Passed \n ");
    else
        printf("List_curr test8 Failed \n");

    

    /*
        testing : List_remove
        expected : 1 ->2 -> 3-> 4-> 5 -> 999 -> 200 ->6
        removed : 444
        current : 1
    */
    void *removed = List_remove(list1);
    if (removed != NULL && *(int *)removed == 444)
        printf("List_remove test1 passed \n");
    else
        printf("List_remove test1 Failed \n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 1)
        printf("List_curr test9 Passed \n ");
    else
        printf("List_curr test9 Failed \n");

    if (List_count(list1) == 8)
        printf("List_count test1 Passed ! \n ");
    else
        printf("List count test1 Failed! \n");

    

    /*
        testing : List_remove (this time from the second element)
        expected : 1 -> 3 -> 4-> 5 -> 999 -> 200 ->6
        current : 3
    */
    void *nextItem = List_next(list1);
    void *removed1 = List_remove(list1);
    if (removed1 != NULL && *(int *)removed1 == 2)

        printf("List_removed test2 Passed \n");

    else

        printf("List_removed test2 Failed \n");

    // Additional checks for List_curr and List_count as needed
    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 3)
    {
        printf("List_curr test10 Passed \n");
    }
    else
    {
        printf("List_curr test10 Failed \n");
    }

    if (List_count(list1) == 7)
    {
        printf("List_count test2 Passed ! \n");
    }
    else
    {
        printf("List count test2 Failed! \n");
    }

    List_print(list1);
    printf("list above should look like 1 -> 3 -> 4-> 5 -> 999 -> 200 ->6 \n ");

   

    /*
        testing : List_trim function
        expected  : 1 -> 3 -> 4-> 5 -> 999 -> 200
        current : 200
        removed : 6

    */
    void *trim = List_trim(list1);
    if (trim != NULL && *(int *)trim == 6)
        printf("List_trim test1 Passed  ! \n");
    else
        printf("List_trim test1 Failed  ! \n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 200)
    {
        printf("List_curr test11 Passed \n");
    }
    else
    {
        if (List_curr(list1) == NULL)
            printf("List_curr test11 Failed \n");
    }

    if (List_count(list1) == 6)
    {
        printf("List_count test3 Passed ! \n");
    }
    else
    {
        printf("List count test3 Failed! \n");
    }

    void *lastItemTest1 = List_last(list1);
    if (lastItemTest1 != NULL && *(int *)lastItemTest1 == 200)
        printf("List_last test1 Passed ");
    else
        printf("List_last test1 failed");

    List_print(list1);
    printf("list above should look like 1 -> 3 -> 4-> 5 -> 999 -> 200 \n");

    

    

    /*
        testing : List_trim function
        expected : 1 -> 3 -> 4-> 5 -> 999 ;
        current : 999
        removed : 200
    */
    void *trim2 = List_trim(list1);
    if (trim2 != NULL && *(int *)trim2 == 200)
        printf("List_trim test2 Passed  ! \n");
    else
        printf("List_trim test2 Failed  ! \n");

    if (List_curr(list1) != NULL && *(int *)List_curr(list1) == 999)
    {
        printf("List_curr test12 Passed \n");
    }
    else
    {
        printf("this is the number that current pointing : %d", *(int *)List_curr(list1));
        printf("List_curr test12 Failed \n");
    }

    if (List_count(list1) == 5)
    {
        printf("List_count test4 Passed ! \n");
    }
    else
    {
        printf("List count test4 Failed! \n");
    }

    void *lastItemTest2 = List_last(list1);
    if (lastItemTest2 != NULL && *(int *)lastItemTest2 == 999)
        printf("List_last test2 Passed ");
    else
        printf("List_last test2 failed");

    printf("\n");
    List_print(list1);
    printf("list above should look like 1 -> 3 -> 4 -> 5 -> 999 \n");


    

  
    /*
        testing list_concat
        list2 = 333 -> 111 -> 687
        expected :
        1 -> 3 -> 4 -> 5 -> 999 -> 333 -> 111 -> 687
        Number of list = 2
        Number of node  = 8
        Number of free node = 92
        Number of freeList = 8

    */
    // Prepare list2 with elements 333, 111, 687
    List *list2 = List_create();
    int integer333 = 333, integer111 = 111, integer687 = 687;
    List_append(list2, &integer333);
    List_append(list2, &integer111);
    List_append(list2, &integer687);
    
    

    // Concatenate list2 to list1
    List_concat(list1, list2); // After this, list2 should be empty and part of list1

  
    // Print list1 to verify the concatenation
    printf("After concatenation, list1 contains: \n");
    List_print(list1);

    // Verification steps
    if (List_count(list1) == 8)
    {
        printf("List_count after concat Passed! Number of nodes = 8\n");
    }
    else
    {
        printf("List_count after concat Failed! Expected 8, found %d\n", List_count(list1));
    }

  

   

    if (freeNodeCount == 92)
        printf("number of free node in the system is CORRECT \n ");
    else
        printf("number of free node in the system is WRONG \n");
    // Assuming you have a way to track available list heads
    printf("Number of List = %d \n", listCount);

    // Ensure list2 is cleared correctly
    if (list2->head == NULL && list2->tail == NULL && list2->current == NULL && List_count(list2) == 0)
    {
        printf("list2 cleared correctly after concat.\n");
    }
    else
    {
        printf("Error: list2 not cleared correctly after concat.\n");
    }

    /*
        testing list_free
        create a new list -> list3
        list3 = 23 -> 55 -> 99
        expecting :
        Number of list = 2
        Number of free list = 8
        Number of node total in the system : 11
        Number of free node in the system : 89
        after the function call :
        Number of list = 1
        Number of free list = 9
        Number of node total in the system : 8
        Number of free node in the system : 92
    */
    List *list3 = List_create();
    int item1 = 23, item2 = 55, item3 = 99;
    List_append(list3, &item1);
    List_append(list3, &item2);
    List_append(list3, &item3);

     


    printf("Before freeing list3:\n");
    // Print list3 for visual confirmation
    List_print(list3);
    // Display the counts before freeing
    if (listCount == 2)
        printf("you havve the CORRECT number of list \n ");

    else
        printf("you have the WRONG number of list \n");

    List_free(list3, NULL) ;
    if(listCount == 1  && freeNodeCount == 92) 
        printf("list_free test1 Passed ! \n") ;
    else 
        printf("list_free test1 Failed ! \n") ;

    

    printf("-------------------------------------------------\n");
    printf("listcount : %d \n", listCount);
    printf("freeNodeCount : %d \n", freeNodeCount);
    printf("-------------------------------------------------\n");
    List_print(list1) ;
    void* listfirst = List_first(list1) ;
    void* listNext = List_next(list1) ;
    int searchValue = 5;
    void *searchResult = List_search(list1, comparator, &searchValue);

    if (searchResult != NULL && *(int *)searchResult == searchValue) {
        printf("List_search test Passed! Found: %d\n", *(int *)searchResult);
    } else {
        
        printf("List_search test Failed! Value not found.\n");

    
    }
}

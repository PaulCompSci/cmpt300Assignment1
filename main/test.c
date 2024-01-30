#include "list.h"
#include <stdio.h>

void testCreateList();
void testListCount();
void testListAppend();

int main()
{

    printf("\n");
    testCreateList();

    printf("\n");
    testListCount();

    printf("\n");

    return 0;
}

void testCreateList()
{

    printf("Testing List_create function : \n");
    List *list1 = List_create();
    List *list2 = List_create();
    List *list3 = List_create();
    List *list4 = List_create();
    List *list5 = List_create();
    List *list6 = List_create();
    List *list7 = List_create();
    List *list8 = List_create();
    List *list9 = List_create();
    List *list10 = List_create();
    List_free(list1, NULL);
    List_free(list2, NULL);
    List_free(list3, NULL);
    List_free(list4, NULL);
    List_free(list5, NULL);
    List_free(list6, NULL);
    List_free(list7, NULL);
    List_free(list8, NULL);
    List_free(list9, NULL);
    List_free(list10, NULL);
    if (list10 == NULL)
    {
        printf("Test Failed! \n");
    }
    else
    {
        printf("Test Passed!\n");
    }

    List *list11 = List_create();
    if (list11 == NULL)
    {
        printf("Test Failed! \n");
    }
    else
    {
        printf("Test Passed! \n");
    }

    if (List_create() == NULL)
    {
        printf("Test Failed! \n");
    }
    else
    {
        printf("Test Passed! \n");
    }

    return;
}

void testListCount()
{

    List *list1 = List_create();
    List *list2 = List_create();
    
    printf("Address of list1: %p\n", (void*)list1);
    printf("Address of list2: %p\n", (void*)list2);

    int integer1 = 1;
    int integer2 = 2;
    int integer3 = 3;
    int integer4 = 4;
    int integer5 = 5;
    int success1 = List_append(list1, &integer1);
    printf("success1 %d" ,success1) ;
    int success2 = List_append(list1, &integer2);
    int success3 = List_append(list1, &integer3);
    int success4 = List_append(list1, &integer4);
    int success5 = List_append(list1, &integer5);

    printf("size of list1 : %d \n", List_count(list1));

    if (List_count(list1) == 5)
        printf("Test PASSED! \n");
    else
        printf("Test FAILED! \n");
   

    if (List_count(list1) == 5 && List_count(list2) == 0)
        printf("Test Passed ! \n");
    else
    {

        printf("size of list 1 : %d \n", List_count(list1));
        printf("size of list 2 : %d \n", List_count(list2));
        printf("Test FAILED ! \n");
    }
}

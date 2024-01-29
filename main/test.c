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
    printf("testing List_count function : \n");
    List *list1 = List_create();
    List *list2 = List_create();
    printf("%d", List_count(list1));

    if (List_count(list1) == 0)
    {

        printf("Test Passed! \n");
    }
    else
    {

        printf("Test Failed! \n");
    }

    if (List_count(list2) == 0)
    {
        printf("Test Passed! \n");
    }
    else
    {
        printf("Test Failed! \n");
    }
}

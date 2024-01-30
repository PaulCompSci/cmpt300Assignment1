#include "list.h"

#include <stdio.h>

void testCreateList();
void test_List_count();
void test_List_next_List_prev();
void test_List_insert_after_before();
void test_List_Trim_Remove();
void test_node_pool_exhaustion();

int integer1 = 1;
int integer2 = 2;
int integer3 = 3;
int integer4 = 4;
int integer5 = 5;
int integer6 = 6;
List *list1;
List *list2;

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
    list1 = List_create();
    list2 = List_create();
    int success1 = List_append(list1, &integer1);
    int success2 = List_append(list1, &integer2);
    int success3 = List_append(list1, &integer3);
    int success4 = List_append(list1, &integer4);
    int success5 = List_append(list1, &integer5);
    int success6 = List_append(list1, &integer6);
    // test_List_count();
    // test_List_next_List_prev();
    test_List_insert_after_before();
    // test_List_Trim_Remove();
    test_node_pool_exhaustion();
    return 0;
}

void testCreateList()
{
    printf("Testing List_create(): \n");
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

void test_List_next_List_prev()
{
    printf("Testing List_next() and List_prev():\n");

    // Test List_next
    List_first(list1); // Set current to first item
    printf("List_next(): ");
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

    // Test List_prev
    List_last(list1); // Set current to last item
    printf("List_prev(): ");
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
}

void test_List_insert_after_before()
{
    printf("Test List_insert_after() and List_insert_before():\n");

    // Test List_insert_after
    List_first(list1); // Set current to first item
    printf("%s", list1->current);
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
    // List_prev(list1);
    // printf("%d\n",*(int *)List_curr(list1));

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
}

void test_List_Trim_Remove()
{
    List *pList = List_create();

    int numbers[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); i++)
    {
        List_append(pList, &numbers[i]);
    }

    printf("Original list: ");
    printList(pList);

    // Set the current item to the second node and remove it
    List_first(pList);
    List_next(pList);
    int *removedItem = (int *)List_remove(pList);
    if (removedItem)
    {
        printf("TEST PASSED: Removed item: %d\n", *removedItem);
    }
    else
    {
        printf("TEST FAILED: No item was removed.\n");
    }
    printf("List after removal: ");
    printList(pList);

    // Trim the last item
    int *trimmedItem = (int *)List_trim(pList);
    if (trimmedItem)
    {
        printf("TEST PASSED: Trimmed item: %d\n", *trimmedItem);
    }
    else
    {
        printf("TEST FAILED: No item was trimmed.\n");
    }
    printf("List after trim: ");
    printList(pList);

    // Clean up the list
    List_free(pList, NULL);
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
            printf("TEST PASSED: Node pool exhausted after %d nodes\n", i);
            break;
        }
    }
}
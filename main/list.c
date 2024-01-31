#include "list.h"
#include <stddef.h>
#include <stdio.h>

static Node nodeArray[LIST_MAX_NUM_NODES];
static List listHeadArray[LIST_MAX_NUM_HEADS];
static Node *freeNodes[LIST_MAX_NUM_NODES];
static int listHeadInitialized = 0;
int freeNodeCount = 0;
int listCount = 0;

void pushToFreeNodeStack(Node *node)
{
    if (freeNodeCount < LIST_MAX_NUM_NODES)
    {
        // Reset the node before pushing it back to the free node stack
        node->item = NULL;
        node->next = NULL;
        node->previous = NULL;
        freeNodes[freeNodeCount++] = node;
    }
}

// Makes a new, empty list, and returns its reference on success.
// Returns a NULL pointer on failure.
List *List_create()
{
    // Initialize list heads only once
    if (!listHeadInitialized)
    {
        for (int i = 0; i < LIST_MAX_NUM_HEADS; i++)
        {
            listHeadArray[i].flag = 0; // Mark as unused
            // Other initializations are not necessary here
        }
        // Initialize free nodes
        for (int i = 0; i < LIST_MAX_NUM_NODES; i++)
        {
            freeNodes[i] = &nodeArray[i];
        }
        freeNodeCount = LIST_MAX_NUM_NODES;
        listHeadInitialized = 1;
    }

    // Find an unused list head
    for (int i = 0; i < LIST_MAX_NUM_HEADS; i++)
    {
        if (listHeadArray[i].flag == 0)
        {
            listHeadArray[i].flag = 1; // Mark as used
            listHeadArray[i].size = 0;
            listHeadArray[i].head = NULL;
            listHeadArray[i].tail = NULL;
            listHeadArray[i].current = NULL;
            listHeadArray[i].outOfBounds = LIST_OOB_START;
            listCount++;
            return &listHeadArray[i];
        }
    }

    // No available list heads
    return NULL;
}

// Returns the number of items in pList.
int List_count(List *pList)
{
    // Check if the provided List pointer is NULL
    if (pList == NULL)
    {
        // If pList is NULL, we cannot access its members,
        // so return an error code. Here, I am using -1 to indicate an error.
        return -1;
    }

    // If pList is not NULL, it is safe to access its members.
    // Return the size of the list, which indicates how many items are in the list.
    return pList->size;
}

// Returns a pointer to the first item in pList and makes the first item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void *List_first(List *pList)
{

    // Check if the list is valid and not NULL
    if (pList == NULL)
    {

        return NULL;
    }

    // Check if the list is empty
    if (pList->head == NULL)
    {
        // List is empty, set current to NULL and indicate that current is before the start

        pList->current = NULL;
        pList->outOfBounds = LIST_OOB_START;
        return NULL;
    }

    // Set the current item to the head (first item) of the list

    pList->current = pList->head;
    // Reset the outOfBounds flag as current is now a valid item within the list
    pList->outOfBounds = LIST_OOB_END;

    // Return the item stored in the head node
    return pList->head->item;
}

// Returns a pointer to the last item in pList and makes the last item the current item.
// Returns NULL and sets current item to NULL if list is empty.
void *List_last(List *pList)
{
    if (pList == NULL)
    {
        return NULL; // List is NULL
    }

    if (pList->tail == NULL)
    {
        // The list is empty, set current to NULL
        pList->current = NULL;
        pList->outOfBounds = LIST_OOB_END;
        return NULL; // Return NULL as the list is empty
    }

    // Set current to the last item
    pList->current = pList->tail;
    pList->outOfBounds = LIST_OOB_END; // Reset outOfBounds as current is now a valid item

    return pList->tail->item; // Return the item at the tail of the list
}

// Advances pList's current item by one, and returns a pointer to the new current item.
// If this operation advances the current item beyond the end of the pList, a NULL pointer
// is returned and the current item is set to be beyond end of pList.
void *List_next(List *pList)
{
    if (pList == NULL)
    {
        return NULL; // List is NULL
    }

    if (pList->current == NULL)
    {
        // Current is NULL. Check if it's because we're at the start or beyond the end.
        if (pList->outOfBounds == LIST_OOB_START)
        {
            pList->current = pList->head; // Move to the first element
        }
        else
        {
            return NULL; // We're beyond the end or the list is empty
        }
    }
    else
    {
        // Move to the next element
        pList->current = pList->current->next;
    }

    // Set outOfBounds appropriately
    if (pList->current == NULL)
    {
        pList->outOfBounds = LIST_OOB_END; // We've moved beyond the end
        return NULL;
    }
    else
    {
        pList->outOfBounds = LIST_OOB_END; // We're within the list bounds
        return pList->current->item;       // Return the item
    }
}

// Backs up pList's current item by one, and returns a pointer to the new current item.
// If this operation backs up the current item beyond the start of the pList, a NULL pointer
// is returned and the current item is set to be before the start of pList.
void *List_prev(List *pList)
{
    if (pList == NULL)
    {
        return NULL; // List is NULL
    }

    if (pList->current == NULL)
    {
        // Current is NULL. Check if it's because we're at the end or before the start.
        if (pList->outOfBounds == LIST_OOB_END)
        {
            pList->current = pList->tail; // Move to the last element
        }
        else
        {
            return NULL; // We're already before the start
        }
    }
    else
    {
        // Move to the previous element
        pList->current = pList->current->previous;
    }

    // Set outOfBounds appropriately
    if (pList->current == NULL)
    {
        pList->outOfBounds = LIST_OOB_START; // We've moved before the start
        return NULL;
    }
    else
    {
        pList->outOfBounds = LIST_OOB_END; // We're within the list bounds
        return pList->current->item;       // Return the item
    }
}

// Returns a pointer to the current item in pList.
// Returns a pointer to the current item in pList.
void *List_curr(List *pList)
{
    // Ensure list is not NULL
    if (pList == NULL)
    {
        return NULL;
    }

    // Ensure current is not NULL and is within bounds
    if (pList->current == NULL || pList->outOfBounds != LIST_OOB_END)
    {
        return NULL;
    }

    return pList->current->item;
}

// Adds the new item to pList directly after the current item, and makes item the current item.
// If the current pointer is before the start of the pList, the item is added at the start. If
// the current pointer is beyond the end of the pList, the item is added at the end.
// Returns 0 on success, -1 on failure.
int List_insert_after(List *pList, void *pItem)
{
    // Check for valid list and item
    if (pList == NULL || pItem == NULL)
    {
        return LIST_FAIL;
    }

    // Check if there are available free nodes
    if (freeNodeCount <= 0)
    {
        return LIST_FAIL;
    }

    // Retrieve a free node
    Node *newNode = freeNodes[--freeNodeCount];
    newNode->item = pItem;

    // Handle the case when the list is empty
    if (pList->head == NULL)
    {
        newNode->next = NULL;
        newNode->previous = NULL;
        pList->head = newNode;
        pList->tail = newNode;
    }
    // Normal case: insert after the current node
    else
    {
        newNode->next = pList->current->next;
        newNode->previous = pList->current;
        if (pList->current->next != NULL)
        {
            pList->current->next->previous = newNode;
        }
        else
        {
            // If the current node was the tail, update the tail to new node
            pList->tail = newNode;
        }
        pList->current->next = newNode;
    }

    // Make the new node the current one
    pList->current = newNode;
    pList->outOfBounds = LIST_OOB_END; // Ensure current is within bounds
    pList->size++;

    return LIST_SUCCESS;
}

// Adds item to pList directly before the current item, and makes the new item the current one.
// If the current pointer is before the start of the pList, the item is added at the start.
// If the current pointer is beyond the end of the pList, the item is added at the end.
// Returns 0 on success, -1 on failure.
int List_insert_before(List *pList, void *pItem)
{
    if (pList == NULL || freeNodeCount <= 0)
    {
        return LIST_FAIL;
    }

    // Pop a free node from the stack
    Node *newNode = freeNodes[--freeNodeCount];
    newNode->item = pItem;

    // Insertion logic
    if (pList->head == NULL)
    {
        // List is empty; add the new node as the only item in the list
        pList->head = newNode;
        pList->tail = newNode;
        newNode->next = NULL;
        newNode->previous = NULL;
    }
    else if (pList->outOfBounds == LIST_OOB_START || pList->current == NULL || pList->current == pList->head)
    {
        // Current pointer is before the start of the list, or at the head
        newNode->next = pList->head;
        newNode->previous = NULL;
        if (pList->head != NULL)
        {
            pList->head->previous = newNode;
        }
        pList->head = newNode;
        if (pList->tail == NULL)
        {
            pList->tail = newNode;
        }
    }
    else
    {
        // Normal insertion before the current item
        newNode->next = pList->current;
        newNode->previous = pList->current->previous;
        pList->current->previous = newNode;
        if (newNode->previous != NULL)
        {
            newNode->previous->next = newNode;
        }
    }

    // Update the current pointer and list size
    pList->current = newNode;
    pList->size++;
    pList->outOfBounds = LIST_OOB_END;

    return LIST_SUCCESS;
}

// Adds item to the end of pList, and makes the new item the current one.
// Returns 0 on success, -1 on failure.
// Adds item to the end of pList, and makes the new item the current one.
// Returns 0 on success, -1 on failure.
int List_append(List *pList, void *pItem)
{
    // Check for valid list and item
    if (pList == NULL || pItem == NULL)
    {
        return LIST_FAIL;
    }

    // Check if there are available free nodes
    if (freeNodeCount <= 0)
    {
        return LIST_FAIL;
    }

    // Retrieve a free node
    Node *newNode = freeNodes[--freeNodeCount];
    newNode->item = pItem;
    newNode->next = NULL; // New node will be at the end, so next is NULL

    if (pList->head == NULL)
    {
        // List is empty, new node becomes head and tail
        pList->head = newNode;
        pList->tail = newNode;
        newNode->previous = NULL; // No previous node since it's the first node
    }
    else
    {
        // List is not empty, append to the end
        newNode->previous = pList->tail;
        pList->tail->next = newNode;
        pList->tail = newNode;
    }

    // Update the current pointer to the new node
    pList->current = newNode;
    pList->outOfBounds = LIST_OOB_END;
    pList->size++; // Increment the list size

    return LIST_SUCCESS;
}

// Adds item to the front of pList, and makes the new item the current one.
// Returns 0 on success, -1 on failure.
int List_prepend(List *pList, void *pItem)
{
    if (pList == NULL || freeNodeCount <= 0)
    {
        return LIST_FAIL;
    }

    // Pop a free node from the stack
    Node *newNode = freeNodes[--freeNodeCount];
    newNode->item = pItem;
    newNode->next = pList->head;
    newNode->previous = NULL;

    if (pList->head != NULL)
    {
        pList->head->previous = newNode;
    }
    else
    {
        // The list was empty, so this new node is also the tail
        pList->tail = newNode;
    }

    pList->head = newNode;
    pList->current = newNode;
    pList->size++;
    pList->outOfBounds = LIST_OOB_END;

    return LIST_SUCCESS;
}

// Return current item and take it out of pList. Make the next item the current one.
// If the current pointer is before the start of the pList, or beyond the end of the pList,
// then do not change the pList and return NULL.
void *List_remove(List *pList)
{
    if (pList == NULL || pList->current == NULL || pList->outOfBounds != LIST_OOB_END)
    {
        return NULL;
    }

    void *itemToRemove = pList->current->item;
    Node *nodeToRemove = pList->current;

    if (pList->head == pList->current && pList->tail == pList->current)
    {
        // Removing the only node in the list
        pList->head = NULL;
        pList->tail = NULL;
        pList->current = NULL;
        pList->outOfBounds = LIST_OOB_START;
    }
    else if (pList->head == pList->current)
    {
        // Removing the head node
        pList->head = pList->current->next;
        if (pList->head)
        {
            pList->head->previous = NULL;
        }
        pList->current = pList->head;
    }
    else if (pList->tail == pList->current)
    {
        // Removing the tail node
        pList->tail = pList->current->previous;
        if (pList->tail)
        {
            pList->tail->next = NULL;
        }
        pList->current = pList->tail;
    }
    else
    {
        // Removing a middle node
        pList->current->previous->next = pList->current->next;
        pList->current->next->previous = pList->current->previous;
        pList->current = pList->current->next;
    }

    // Clear the removed node
    nodeToRemove->item = NULL;
    nodeToRemove->next = NULL;
    nodeToRemove->previous = NULL;

    // Return the node to the free pool
    pushToFreeNodeStack(nodeToRemove);

    // Update the size of the list
    pList->size--;

    return itemToRemove;
}

// Return last item and take it out of pList. Make the new last item the current one.
// Return NULL if pList is initially empty.
void *List_trim(List *pList)
{
    if (pList == NULL || pList->head == NULL)
    {
        // If the list is NULL or empty, return NULL.
        return NULL;
    }

    // Store the item to remove.
    void *itemToRemove = pList->tail->item;

    // If there's only one item in the list.
    if (pList->head == pList->tail)
    {
        // Free or reset the node, if necessary.
        // Assuming there's a function to handle freeing or resetting nodes, like:
        pushToFreeNodeStack(pList->tail);
        pList->head = NULL;
        pList->tail = NULL;
        pList->current = NULL; // After trimming, there's no current item.
    }
    else
    {
        // More than one item in the list.
        Node *newTail = pList->tail->previous;
        newTail->next = NULL;

        // Free or reset the old tail node.
        // Assuming there's a function to handle freeing or resetting nodes, like:
        pushToFreeNodeStack(pList->tail);

        // Update the list's tail and current to the new last item.
        pList->tail = newTail;
        pList->current = newTail; // Make the new last item the current one.
    }

    // Decrease the size of the list.
    pList->size--;

    // Return the removed item.
    return itemToRemove;
}

// Adds pList2 to the end of pList1. The current pointer is set to the current pointer of pList1.
// pList2 no longer exists after the operation; its head is available
// for future operations.
void List_concat(List *pList1, List *pList2)
{
    if (pList1 == NULL || pList2 == NULL)
        return;

    if (pList2->head == NULL)
        return; // pList2 is empty, nothing to do.

    if (pList1->head == NULL)
    {
        // If pList1 is empty, just set its head and tail to pList2's.
        pList1->head = pList2->head;
        pList1->tail = pList2->tail;
    }
    else
    {
        // Attach pList2 at the end of pList1.
        pList1->tail->next = pList2->head;
        pList2->head->previous = pList1->tail;
        pList1->tail = pList2->tail;
    }

    // Update the size of pList1 to include the nodes from pList2.
    pList1->size += pList2->size;

    // Clear pList2 as it's now empty.
    pList2->head = NULL;
    pList2->tail = NULL;
    pList2->current = NULL;
    pList2->size = 0;
    pList2->outOfBounds = LIST_OOB_START;

    // Decrement listCount if pList2 is no longer considered an active list.
    listCount--;

    // freeNodeCount remains unchanged as nodes are transferred, not freed.
}

// Delete pList. pItemFreeFn is a pointer to a routine that frees an item.
// It should be invoked (within List_free) as: (*pItemFreeFn)(itemToBeFreedFromNode);
// pList and all its nodes no longer exists after the operation; its head and nodes are
// available for future operations.
typedef void (*FREE_FN)(void *pItem);
void List_free(List *pList, FREE_FN pItemFreeFn)
{
    if (pList == NULL)
        return;

    Node *currentNode = pList->head;
    while (currentNode != NULL)
    {
        Node *nextNode = currentNode->next;

        if (pItemFreeFn != NULL && currentNode->item != NULL)
        {
            pItemFreeFn(currentNode->item);
        }

        currentNode->item = NULL;
        currentNode->next = NULL;
        currentNode->previous = NULL;
        pushToFreeNodeStack(currentNode); // This will increment freeNodeCount.

        currentNode = nextNode;
    }

    pList->size = 0;
    pList->head = NULL;
    pList->tail = NULL;
    pList->current = NULL;
    pList->outOfBounds = LIST_OOB_START;
    pList->flag = 0; // Assuming this marks the list as "unused"
    listCount--;     // Decrement active list count.
}

// void pushToFreeNodeStack(Node *node)
// {
//     if (freeNodeCount < LIST_MAX_NUM_NODES)
//     {
//         freeNodes[freeNodeCount++] = node;
//     }
// }

// Search pList, starting at the current item, until the end is reached or a match is found.
// In this context, a match is determined by the comparator parameter. This parameter is a
// pointer to a routine that takes as its first argument an item pointer, and as its second
// argument pComparisonArg. Comparator returns 0 if the item and comparisonArg don't match,
// or 1 if they do. Exactly what constitutes a match is up to the implementor of comparator.
//
// If a match is found, the current pointer is left at the matched item and the pointer to
// that item is returned. If no match is found, the current pointer is left beyond the end of
// the list and a NULL pointer is returned.
//
// If the current pointer is before the start of the pList, then start searching from
// the first node in the list (if any).
typedef bool (*COMPARATOR_FN)(void *pItem, void *pComparisonArg);
void *List_search(List *pList, COMPARATOR_FN pComparator, void *pComparisonArg)
{
    // Ensure the list and the comparator function are not NULL.
    if (pList == NULL || pComparator == NULL)
    {
        printf("I am here");
        return NULL;
    }

    // If the current pointer is before the start of the list, start from the first node.
    if (pList->outOfBounds == LIST_OOB_START || pList->current == NULL)
    {
        pList->current = pList->head;
        pList->outOfBounds = LIST_OOB_END; // Reset outOfBounds status.
    }

    // Iterate through the list starting from the current item.
    while (pList->current != NULL)
    {
        // Check if the current item matches the comparison argument.
        if (pComparator(pList->current->item, pComparisonArg))
        {
            return pList->current->item; // Match found, return the item.
        }

        // Move to the next item.
        pList->current = pList->current->next;
    }

    // No match found, set current pointer beyond the end of the list.

    pList->outOfBounds = LIST_OOB_END;
    return NULL;
}

// Function to print all elements in the list
// Function to print all elements in the list
void List_print(List *pList)
{

    if (pList == NULL)
    {
        printf("List is NULL.\n");
        return;
    }

    Node *node = pList->head; // Start from the head of the list

    if (node == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("List elements: ");
        while (node != NULL)
        {
            printf("%d ", *((int *)node->item)); // Assuming the item is a pointer to an integer
            node = node->next;                   // Move to the next node
        }
        printf("\n");
    }

    // The current pointer of the list remains unchanged
}

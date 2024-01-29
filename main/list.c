#include "list.h"
#include <stddef.h>
#include <stdio.h>

static Node nodeArray[LIST_MAX_NUM_NODES];
static List listHeadArray[LIST_MAX_NUM_HEADS];

static int listHeadInitialized = 0;

static Node *freeNodes[LIST_MAX_NUM_NODES];
static int freeNodeCount = 0;

void pushToFreeNodeStack(Node *node);

static void initializeListHeads()
{
    for (int i = 0; i < LIST_MAX_NUM_HEADS; i++)
    {
        listHeadArray[i].size = 0;
        listHeadArray[i].head = NULL;
        listHeadArray[i].tail = NULL;
        listHeadArray[i].current = NULL;
        listHeadArray[i].outOfBounds = LIST_OOB_START;
    }
    for (int i = 0; i < LIST_MAX_NUM_NODES; i++)
    {
        freeNodes[i] = &nodeArray[i];
    }
    freeNodeCount = LIST_MAX_NUM_NODES;
}

// Makes a new, empty list, and returns its reference on success.
// Returns a NULL pointer on failure.
List *List_create()
{
    // Initialize the list heads on first call
    if (!listHeadInitialized)
    {
        initializeListHeads();
        listHeadInitialized = 1;
    }

    // Find an available list head
    for (int i = 0; i < LIST_MAX_NUM_HEADS; i++)
    {
        if (listHeadArray[i].size == 0 && listHeadArray[i].head == NULL)
        {
            listHeadArray[i].size = 0;
            listHeadArray[i].head = NULL;
            listHeadArray[i].tail = NULL;
            listHeadArray[i].current = NULL;
            listHeadArray[i].outOfBounds = LIST_OOB_START;
            return &listHeadArray[i];
        }
    }

    // Return NULL if no available list head is found
    return NULL;
}

int List_count(List *pList)
{
    return pList->size;
}

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
        pList->current = NULL;
        pList->outOfBounds = LIST_OOB_START; // Indicate that the current item is before the start
        return NULL;
    }

    // If the list is not empty, set the current item to the head of the list
    pList->current = pList->head;
    pList->outOfBounds = LIST_OOB_END; // Reset the out of bounds status

    // Return the item stored in the head node
    return pList->head->item;
}

void *List_last(List *pList)
{
    // Check if the list is valid and not NULL
    if (pList == NULL)
    {
        return NULL;
    }

    // Check if the list is empty
    if (pList->tail == NULL)
    {
        pList->current = NULL;
        pList->outOfBounds = LIST_OOB_END; // Indicate that the current item is beyond the end
        return NULL;
    }

    // If the list is not empty, set the current item to the tail of the list
    pList->current = pList->tail;
    pList->outOfBounds = LIST_OOB_START; // Reset the out of bounds status

    // Return the item stored in the tail node
    return pList->tail->item;
}

void *List_next(List *pList)
{
    // Check if the list is valid and not NULL
    if (pList == NULL)
    {
        return NULL;
    }

    // Check if the current item is NULL or beyond the end of the list
    if (pList->current == NULL || pList->outOfBounds == LIST_OOB_END)
    {
        pList->outOfBounds = LIST_OOB_END; // Set the out of bounds status to end
        return NULL;
    }

    // Check if the current item is before the start of the list
    if (pList->outOfBounds == LIST_OOB_START)
    {
        pList->current = pList->head;      // Set the current item to the head
        pList->outOfBounds = LIST_OOB_END; // Reset the out of bounds status
        return pList->current != NULL ? pList->current->item : NULL;
    }

    // Move the current item to the next node
    pList->current = pList->current->next;

    // Check if the current item has moved beyond the end of the list
    if (pList->current == NULL)
    {
        pList->outOfBounds = LIST_OOB_END;
        return NULL;
    }

    // Return the item stored in the new current node
    return pList->current->item;
}

// Backs up pList's current item by one, and returns a pointer to the new current item.
// If this operation backs up the current item beyond the start of the pList, a NULL pointer
// is returned and the current item is set to be before the start of pList.
void *List_prev(List *pList)
{
    // Check if the list is valid and not NULL
    if (pList == NULL)
    {
        return NULL;
    }

    // Check if the current item is NULL or before the start of the list
    if (pList->current == NULL || pList->outOfBounds == LIST_OOB_START)
    {
        pList->outOfBounds = LIST_OOB_START; // Set the out of bounds status to start
        return NULL;
    }

    // Check if the current item is beyond the end of the list
    if (pList->outOfBounds == LIST_OOB_END)
    {
        pList->current = pList->tail;      // Set the current item to the tail
        pList->outOfBounds = LIST_OOB_END; // Reset the out of bounds status
        return pList->current != NULL ? pList->current->item : NULL;
    }

    // Move the current item to the previous node
    pList->current = pList->current->previous;

    // Check if the current item has moved before the start of the list
    if (pList->current == NULL)
    {
        pList->outOfBounds = LIST_OOB_START;
        return NULL;
    }

    // Return the item stored in the new current node
    return pList->current->item;
}

// Returns a pointer to the current item in pList.
void *List_curr(List *pList)
{
    // Check if the list is valid and not NULL
    if (pList == NULL)
    {
        return NULL;
    }

    // Check if the current item is NULL or if the current pointer is out of bounds
    if (pList->current == NULL || pList->outOfBounds == LIST_OOB_START || pList->outOfBounds == LIST_OOB_END)
    {
        return NULL;
    }

    // Return the item stored in the current node
    return pList->current->item;
}

// Adds the new item to pList directly after the current item, and makes item the current item.
// If the current pointer is before the start of the pList, the item is added at the start. If
// the current pointer is beyond the end of the pList, the item is added at the end.
// Returns 0 on success, -1 on failure.
int List_insert_after(List *pList, void *pItem)
{
    if (pList == NULL || freeNodeCount <= 0)
    {
        return LIST_FAIL;
    }

    // Pop a free node from the stack
    Node *newNode = freeNodes[--freeNodeCount];
    newNode->item = pItem;

    if (pList->head == NULL)
    {
        // List is empty; new node becomes the only node in the list
        newNode->next = NULL;
        newNode->previous = NULL;
        pList->head = newNode;
        pList->tail = newNode;
    }
    else if (pList->current == NULL || pList->outOfBounds == LIST_OOB_END)
    {
        // Current pointer is beyond the end of the list or list is empty
        newNode->next = NULL;
        newNode->previous = pList->tail;
        if (pList->tail != NULL)
        {
            pList->tail->next = newNode;
        }
        pList->tail = newNode;
    }
    else
    {
        // Normal insertion after the current item
        newNode->next = pList->current->next;
        newNode->previous = pList->current;
        pList->current->next = newNode;
        if (newNode->next != NULL)
        {
            newNode->next->previous = newNode;
        }
    }

    pList->current = newNode;
    pList->size++;
    pList->outOfBounds = LIST_OOB_END;

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
int List_append(List *pList, void *pItem)
{
    if (pList == NULL || freeNodeCount <= 0)
    {
        return LIST_FAIL;
    }

    // Pop a free node from the stack
    Node *newNode = freeNodes[--freeNodeCount];
    newNode->item = pItem;
    newNode->next = NULL;
    newNode->previous = pList->tail;

    if (pList->head == NULL)
    {
        pList->head = newNode;
    }
    else
    {
        pList->tail->next = newNode;
    }

    pList->tail = newNode;
    pList->current = newNode;
    pList->size++;
    pList->outOfBounds = LIST_OOB_END;

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
    // Check if the list is valid, not NULL, and if the current item is within bounds
    if (pList == NULL || pList->current == NULL || pList->outOfBounds != LIST_OOB_END)
    {
        return NULL;
    }

    // Store the item to be removed
    void *itemToRemove = pList->current->item;

    // If the node to be removed is the only node in the list
    if (pList->head == pList->current && pList->tail == pList->current)
    {
        pList->head = NULL;
        pList->tail = NULL;
        pList->current = NULL;
    }
    else if (pList->head == pList->current)
    { // If the node to be removed is the head
        pList->head = pList->current->next;
        pList->head->previous = NULL;
        pList->current = pList->head;
    }
    else if (pList->tail == pList->current)
    { // If the node to be removed is the tail
        pList->tail = pList->current->previous;
        pList->tail->next = NULL;
        pList->current = NULL;
        pList->outOfBounds = LIST_OOB_END;
    }
    else
    { // If the node is in the middle of the list
        pList->current->previous->next = pList->current->next;
        pList->current->next->previous = pList->current->previous;
        pList->current = pList->current->next;
    }

    // Clear the removed node
    // Note: Depending on how you manage free nodes, you may want to add it back to the pool of free nodes.
    pList->current->item = NULL;
    pList->current->next = NULL;
    pList->current->previous = NULL;

    // Update the size of the list
    pList->size--;

    return itemToRemove;
}

// Return last item and take it out of pList. Make the new last item the current one.
// Return NULL if pList is initially empty.
void *List_trim(List *pList)
{
    // Check if the list is valid and not NULL, and if the list is not empty
    if (pList == NULL || pList->head == NULL || pList->tail == NULL)
    {
        return NULL;
    }

    // Store the item to be removed
    void *itemToRemove = pList->tail->item;

    // If the node to be removed is the only node in the list
    if (pList->head == pList->tail)
    {
        pList->head = NULL;
        pList->current = NULL;
    }
    else
    {
        // Update the tail and current pointer
        pList->tail = pList->tail->previous;
        pList->tail->next = NULL;
    }

    // Clear the removed node
    // Note: Depending on how you manage free nodes, you may want to add it back to the pool of free nodes.
    pList->current->item = NULL;
    pList->current->next = NULL;
    pList->current->previous = NULL;

    // Update the current pointer and list size
    pList->current = pList->tail;
    pList->size--;

    return itemToRemove;
}

// Adds pList2 to the end of pList1. The current pointer is set to the current pointer of pList1.
// pList2 no longer exists after the operation; its head is available
// for future operations.
void List_concat(List *pList1, List *pList2)
{
    // Check if both lists are valid and not NULL
    if (pList1 == NULL || pList2 == NULL)
    {
        return;
    }

    // Check if pList2 is empty
    if (pList2->head == NULL)
    {
        return; // Nothing to concatenate if pList2 is empty
    }

    // If pList1 is empty, set its head and tail to those of pList2
    if (pList1->head == NULL)
    {
        pList1->head = pList2->head;
        pList1->tail = pList2->tail;
    }
    else
    {
        // Concatenate pList2 to the end of pList1
        pList1->tail->next = pList2->head;
        pList2->head->previous = pList1->tail;
        pList1->tail = pList2->tail;
    }

    // Update the size of pList1
    pList1->size += pList2->size;

    // Clear and make pList2's head available for future use
    pList2->head = NULL;
    pList2->tail = NULL;
    pList2->current = NULL;
    pList2->size = 0;
    pList2->outOfBounds = LIST_OOB_START;
}

// Delete pList. pItemFreeFn is a pointer to a routine that frees an item.
// It should be invoked (within List_free) as: (*pItemFreeFn)(itemToBeFreedFromNode);
// pList and all its nodes no longer exists after the operation; its head and nodes are
// available for future operations.
typedef void (*FREE_FN)(void *pItem);
void List_free(List *pList, FREE_FN pItemFreeFn)
{
    // Check if the list is valid and not NULL
    if (pList == NULL)
    {
        return;
    }

    // Iterate through the list and free each item
    Node *currentNode = pList->head;
    while (currentNode != NULL)
    {
        // If a free function is provided, use it to free the item
        if (pItemFreeFn != NULL && currentNode->item != NULL)
        {
            (*pItemFreeFn)(currentNode->item);
        }

        Node *temp = currentNode;
        currentNode = currentNode->next;

        // Clear the current node
        temp->item = NULL;
        temp->next = NULL;
        temp->previous = NULL;

        // Push the node back to the free node stack
        pushToFreeNodeStack(temp);
    }

    // Clear and make pList's head available for future use
    pList->head = NULL;
    pList->tail = NULL;
    pList->current = NULL;
    pList->size = 0;
    pList->outOfBounds = LIST_OOB_START;
}

void pushToFreeNodeStack(Node *node)
{
    if (freeNodeCount < LIST_MAX_NUM_NODES)
    {
        freeNodes[freeNodeCount++] = node;
    }
}

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
    // Check if the list and comparator function are valid and not NULL
    if (pList == NULL || pComparator == NULL)
    {
        return NULL;
    }

    // If the current pointer is before the start of the list, start from the first node
    if (pList->outOfBounds == LIST_OOB_START || pList->current == NULL)
    {
        pList->current = pList->head;
        pList->outOfBounds = LIST_OOB_END; // Reset the out of bounds status
    }

    // Iterate through the list starting from the current item
    while (pList->current != NULL)
    {
        // Check if the current item matches the comparison argument
        if (pComparator(pList->current->item, pComparisonArg))
        {
            return pList->current->item; // Match found, return the item
        }

        // Move to the next item
        pList->current = pList->current->next;
    }

    // No match found, set current pointer beyond the end of the list
    pList->outOfBounds = LIST_OOB_END;
    return NULL;
}

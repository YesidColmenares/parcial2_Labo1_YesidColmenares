/*
 * LinkedList.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	void *pElement;
	struct Node *pNextNode;
}typedef Node;

struct LinkedList
{
	Node *pFirstNode;
	int size;
}typedef LinkedList;

/**
 * @brief Create a new Linked List in memory dynamically
 *
 * @return LinkedList * Returns (NULL) in the case of not getting memory space
 *         or the pointer to the reserved space
 */
LinkedList* ll_newLinkedList(void);

/**
 * @brief Returns the number of elements in the list
 *
 * @param LinkedList pointer to list
 * @return int Returns (-1) if the pointer is NULL or the number of elements in the list
 */
int ll_len(LinkedList *LinkedList);

/**
 * @brief Gets a node from the list
 *
 * @param LinkedList pointer to list
 * @param indexNode int index of the node to obtain
 * @return Node * Returns (NULL) Error: if the pointer to the list is NULL
 *         or (if the index is less than 0 or greater than the list's len)
 *         (pNode) If it worked correctly
 */
Node* getNode(LinkedList *LinkedList, int indexNode);

/**
 * @brief Add and bind a new node to the list
 *
 * @param LinkedList pointer to list
 * @param indexNode location where the new node will be added
 * @param pElement pointer to the element to be contained by the new node
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         or if the index is less than 0 or great than the list's len, (0)
 *         if it worked correctly
 */
int addNode(LinkedList *LinkedList, int indexNode, void *pElement);

/**
 * @brief Add an element to the list
 *
 * @param this pointer to list
 * @param pElement void* poiter to the element to be added
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         (0) if it worked correctly
 */
int ll_add(LinkedList *this, void *pElement);

/**
 * @brief Get an element from the list
 *
 * @param this pointer to list
 * @param index int index of the element to obtain
 *
 * @return void* returns (NULL) Error: if the pointer to the list is NULL
 *         or if the index is less than 0 or greater than list's len
 *         pElement if it worked correctly
 */
void* ll_get(LinkedList *this, int index);

/**
 * @brief Modify an element in the list
 *
 * @param this pointer to the list
 * @param index int index of the element to modify
 * @param pElement pointer to the new element
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         or (if the index is less than 0 or greater than the list's len)
 *         (0) if it worked correctly
 */
int ll_set(LinkedList *this, int index, void *pElement);

/**
 * @brief Remove an element in the list
 *
 * @param this pointer to the list
 * @param index int index of the element to delete
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         or (if the index is less than 0 or greater than the list's len)
 *         (0) if it  worked correctly
 */
int ll_remove(LinkedList *this, int index);

/**
 * @brief Remove all elements from the list
 *
 * @param this pointer to the list
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         (0) if it worked corrctly
 */
int ll_clear(LinkedList *this);

/**
 * @brief remove all elements from the list and the list
 *
 * @param this pointer to the list
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         (0) if it worked correctly
 */
int ll_deleteLinkedList(LinkedList *this);

/**
 * @brief Look for the index of the firts occurrence of the element
 *        passed as a parameter
 *
 * @param this pointer to the list
 * @param pElement pointer to the element
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         (Element index) if it worked correctly
 */
int ll_indexOf(LinkedList *this, void *pElement);

/**
 * @brief Indicates if the list is empty or not
 *
 * @param this pointer to the list
 * @return int returns (-1) Error: if the pointer to the list is NULL
 * (0) if the list is NOT empty
 * (1) if the list is empty
 */
int ll_isEmpty(LinkedList *this);

/**
 * @brief Insert a new element in the list in the indicated position
 *
 * @param this pointer to the list
 * @param index int location where the new element will be added
 * @param pElement pointer to the new element
 * @return int returns (-1) Error: if the pointer to the list is NULL
 *         or if the index is less than 0 or greater than the list's len
 *         (0) if it worked correctly
 */
int ll_push(LinkedList *this, int index, void *pElement);

/**
 * @brief Delete the element from the indicated position and return its pointer
 *
 * @param this pointer to the list
 * @param index location of the element to be removed
 *
 * @return void* returns (NULL) Error: if the pointer to the list is NULL
 *         or if the index is less than 0 or greater than the list's len
 *         pElement if it worked correctly
 */
void* ll_pop(LinkedList *this, int index);

/**
 * @brief Determinates wether or not the list contains the element passed as a parameter
 *
 * @param this pointer to the list
 * @param pElement pointer to the element to check
 * @return int returns (-1) Error if the pointer to the list is NULL
 *         or (1) if it contains the element
 *         (0) if it dows not contain the element
 */
int ll_contains(LinkedList *this, void *pElement);

/**
 * @brief Determinates if all elements of the list (this2) are
 *        contained int the list (this)
 *
 * @param this pointer to the list
 * @param this2 pointer to the list
 * @return int returns (-1) Error: if any of the pointers to the list are NULL
 *         (1) if the elements of (this2) are contained in the list (this)
 *         (0) if the elements of (this2) are not contained in the list (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2);

/**
 * @brief Create and return a new list with the indicated elements
 *
 * @param this pointer to the list
 * @param from Index from which the elements are copied into the new list
 * @param to up to which the elements are copied into the new list
 * @return LinkedList* returns (NULL) Error: if the pointer to the lists is NULL
 *         or if the from index is less than 0 or greater than the list's len
 *         or if the index to is less than or equal to from or greater than the list's len
 *         pointer to new list if it worked correctly
 */
LinkedList* ll_subList(LinkedList *this, int from, int to);

/**
 * @brief Create and returns a new list with the elements of the list passed as a parameter
 *
 * @param this pointer to the list
 * @return LinkedList* Returns (NULL) Error if the pointer to the list is NULL or
 *         pointer to new list if it worked correctly
 */
LinkedList* ll_clone(LinkedList *this);

/**
 * @brief sort the elements of the list using the criterion function received
 *        as a parameter
 *
 * @param this pointer to the list
 * @param pFunc pointer to the criterion function
 * @param order int (1) indicate ascending order or
 *        (0) indicates descending order
 * @return int returns (-1) Error if the pointer to the list is NULL
 *         (0) if it worked correctly
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order);

/**
 * @brief iterate all elements of the list passed as parameter
 *
 * @param this pointer to the list
 * @param pFunc pointer to the critetion function
 * @return int returns (-1) Error if the pointer to the list is NULL
 *         (0) if it worked correctly
 */
int ll_map(LinkedList *this, int (*pFunc)(void*));


#endif /* LINKEDLIST_H_ */

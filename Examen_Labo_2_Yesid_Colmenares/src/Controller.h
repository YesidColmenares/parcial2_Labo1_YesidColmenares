/*
 * Controller.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"
#include "Auxiliary.h"
#include "dataEntry/input.h"
#include "Parser.h"
#include "eBook.h"

/**
 * @brief load book data (text mode)
 *
 * @param path char*, path to file
 * @param listBooks LinkedList* pointer to the list
 * @return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_LoadFromText(char *path, LinkedList *listBooks);

/**
 * @brief organize the book list
 *
 * @param listBooks LinkedList* pointer to the list
 * @return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_SortBook(LinkedList *listBooks);

/**
 * @brief print the book list
 *
 * @param listBooks LinkedList* pointer to the list
 * @return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_ListBook(LinkedList *listBooks);

/**
 * @brief make discounts on the book list
 *
 * @param listBooks LinkedList* pointer to the list
 * @return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_Discounts(LinkedList *listBooks);

/**
 * @brief save the book data in the mapeado.csv (text mode)
 *
 * @param path char*, path to file
 * @param listBooks LinkedList* pointer to the list
 * @return int, 0 if it is correct or -1 if there is an error
 */
int controller_SaveAsText(LinkedList *listBooks);

#endif /* CONTROLLER_H_ */

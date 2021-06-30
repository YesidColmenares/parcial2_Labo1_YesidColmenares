/*
 * Auxiliary.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */

#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "eBook.h"

/**
 * @brief save the linkedlist data to a file
 *
 * @param pFile pointer to File
 * @param listBooks pointer to the list
 * @return return 0 if it worked correctly or -1 if an error ocurred
 */
int auxiliary_SaveAsText(FILE *pFile, LinkedList *listBooks);

/**
 * @brief convert editorial id to name
 *
 * @param book pointer to book
 * @param nameEditorial editorial name
 * @return return 0 if it worked correctly or -1 if an error ocurred
 */
int auxiliary_IdToEditorialName(eBook *book, char *nameEditorial);

/**
 * @brief print the book list
 *
 * @param listBooks, pointer to the list
 * @return return 0 if it worked correctly or -1 if an error ocurred
 */
int auxiliary_PrintBook(LinkedList *listBooks);

/**
 * @brief converts the editorial name to the corresponding id number
 *
 * @param editorial name
 * @return return 0 if it worked correctly or -1 if an error ocurred
 */
int auxiliary_EditorialNameToId(char *name);

/**
 * @brief print main menu options
 *
 */
void auxiliary_PrintMainMenu(void);

#endif /* AUXILIARY_H_ */

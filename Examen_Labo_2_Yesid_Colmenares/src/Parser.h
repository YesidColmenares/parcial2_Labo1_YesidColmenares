/*
 * Parser.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include "LinkedList.h"

/**
 * @brief parse book data (text mode).
 *
 * @param pFile FILE* pointer to file
 * @param listBooks LinkedList* pointer to the list
 * @return int, 0 if it is correct or -1 if there is an error
 *
 */
int parser_BookFromText(FILE *pFile, LinkedList *listBooks);

#endif /* PARSER_H_ */

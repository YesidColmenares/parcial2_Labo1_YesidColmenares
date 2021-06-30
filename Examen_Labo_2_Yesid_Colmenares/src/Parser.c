/*
 * Parser.c
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */
#include "Parser.h"
#include "eBook.h"
#include "Auxiliary.h"
#define FALSE -1
#define TRUE 0
#define SIZE 200

int parser_BookFromText(FILE *pFile, LinkedList *listBooks)
{
	int returnValue;
	eBook *newBook;
	char id[SIZE];
	char title[SIZE];
	char author[SIZE];
	char price[SIZE];
	char editorialId[SIZE];

	returnValue = FALSE;
	if (pFile != NULL && listBooks != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, title, author, price, editorialId);
		while (!feof(pFile))
		{
			if (fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, title, author, price, editorialId) != 5)
			{
				returnValue = FALSE;
				ll_clear(listBooks);
				break;
			}
			auxiliary_EditorialNameToId(editorialId);
			newBook = book_NewParameters(id, title, author, price, editorialId);
			ll_add(listBooks, newBook);
			returnValue = TRUE;
		}
	}
	return returnValue;
}

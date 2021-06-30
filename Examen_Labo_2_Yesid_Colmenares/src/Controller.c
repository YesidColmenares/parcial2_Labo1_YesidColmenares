/*
 * Controller.c
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */
#include "Controller.h"
#define FALSE -1
#define TRUE 0

int controller_LoadFromText(char *path, LinkedList *listBooks)
{
	int returnValue;
	FILE *pFile;

	returnValue = FALSE;
	if (validatePath(path, ".csv") == TRUE)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL && listBooks != NULL)
		{
			returnValue = parser_BookFromText(pFile, listBooks);
		}
		fclose(pFile);
	}
	return returnValue;
}

int controller_SortBook(LinkedList *listBooks)
{
	int returnValue;
	LinkedList *auxListBook;

	returnValue = FALSE;
	if (listBooks != NULL)
	{
		auxListBook = ll_clone(listBooks);
		if (ll_sort(auxListBook, book_SortByAuthor, 0) == TRUE)
		{
			system("cls");
			controller_ListBook(auxListBook);
		}
		ll_deleteLinkedList(auxListBook);
	}
	return returnValue;
}

int controller_ListBook(LinkedList *listBooks)
{
	int returnValue;

	returnValue = FALSE;
	if (listBooks != NULL)
	{
		returnValue = auxiliary_PrintBook(listBooks);
	}
	return returnValue;
}

int controller_Discounts(LinkedList *listBooks)
{
	int returnValue;

	returnValue = FALSE;
	if (listBooks != NULL)
	{
		if (ll_map(listBooks, book_DiscountsPlaneta) == TRUE && ll_map(listBooks, book_DiscountsSigloXXIE) == TRUE)
		{
			returnValue = TRUE;
		}
	}

	return returnValue;
}

int controller_SaveAsText(LinkedList *listBooks)
{
	int returnValue;
	FILE *pFile;

	pFile = fopen("mapeado.csv", "w");
	returnValue = FALSE;
	if (listBooks != NULL && pFile != NULL)
	{
		returnValue = auxiliary_SaveAsText(pFile, listBooks);
	}
	fclose(pFile);
	return returnValue;
}


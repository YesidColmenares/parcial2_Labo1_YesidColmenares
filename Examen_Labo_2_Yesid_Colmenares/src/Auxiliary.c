/*
 * Auxiliary.c
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */

#include "Auxiliary.h"
#include "Controller.h"
#define TRUE 0
#define FALSE -1

int auxiliary_SaveAsText(FILE *pFile, LinkedList *listBooks)
{
	eBook *book;
	int returnValue;
	int i;
	int lenList;
	int id;
	char title[128];
	char author[128];
	char editorialId[128];
	int price;

	book = NULL;
	returnValue = FALSE;
	if (pFile != NULL && listBooks != NULL)
	{
		lenList = ll_len(listBooks);
		fprintf(pFile, "id,title,author,price,editorialId\n");

		for (i = 0; i < lenList; i++)
		{
			book = (eBook*) ll_get(listBooks, i);

			book_GetId(book, &id);
			book_GetTitle(book, title);
			book_GetAuthor(book, author);
			book_GetPrice(book, &price);
			auxiliary_IdToEditorialName(book, editorialId);
			fprintf(pFile, "%d,%s,%s,%d,%s\n", id, title, author, price, editorialId);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int auxiliary_IdToEditorialName(eBook *book, char *nameEditorial)
{
	int returnValue;
	int editorialId;

	returnValue = FALSE;
	if (book != NULL)
	{
		book_GetEditorialId(book, &editorialId);
		switch (editorialId)
		{
			case 1:
				strcpy(nameEditorial, "PLANETA");
				break;

			case 2:
				strcpy(nameEditorial, "SIGLO XXI EDITORES");
				break;

			case 3:
				strcpy(nameEditorial, "PEARSON");
				break;

			case 4:
				strcpy(nameEditorial, "MINOTAURO");
				break;

			case 5:
				strcpy(nameEditorial, "SALAMANDRA");
				break;

			case 6:
				strcpy(nameEditorial, "PENGUIN BOOKS");
				break;

			default:
				strcpy(nameEditorial, "...");
				break;
		}
	}
	returnValue = TRUE;

	return returnValue;
}

int auxiliary_PrintBook(LinkedList *listBooks)
{
	int returnValue;
	int i;
	int sizeList;
	eBook *book;

	returnValue = FALSE;
	if (listBooks != NULL)
	{
		sizeList = ll_len(listBooks);
		printf("ID                                             TITLE               AUTHOR      PRICE          EDITORIALID");
		for (i = 0; i < sizeList; i++)
		{
			book = ll_get(listBooks, i);
			book_Show(book);
		}
		returnValue = TRUE;
	}

	return returnValue;
}

int auxiliary_EditorialNameToId(char *name)
{
	int returnValue;

	returnValue = FALSE;
	if (name != NULL)
	{
		if (strcasecmp(name, "PLANETA") == 0)
		{
			strcpy(name, "1");
		}
		else
		{
			if (strcasecmp(name, "SIGLO XXI EDITORES") == 0)
			{
				strcpy(name, "2");
			}
			else
			{
				if (strcasecmp(name, "PEARSON") == 0)
				{
					strcpy(name, "3");
				}
				else
				{
					if (strcasecmp(name, "MINOTAURO") == 0)
					{
						strcpy(name, "4");
					}
					else
					{
						if (strcasecmp(name, "SALAMANDRA") == 0)
						{
							strcpy(name, "5");
						}
						else
						{
							if (strcasecmp(name, "PENGUIN BOOKS") == 0)
							{
								strcpy(name, "6");
							}
							else
							{
								strcpy(name, "0");
							}
						}
					}
				}
			}
		}
		returnValue = TRUE;
	}
	return returnValue;
}

void auxiliary_PrintMainMenu(void)
{
	printf("\n------------------ WELCOME TO THE SYSTEM ------------------");
	printf("\n1. Load book data");
	printf("\n2. Sort book");
	printf("\n3. List book");
	printf("\n4. Make discounts");
	printf("\n5. Save book data");
	printf("\n6. Exit");
}

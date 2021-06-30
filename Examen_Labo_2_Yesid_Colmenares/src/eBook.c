/*
 * eBook.c
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */
#include "eBook.h"
#include "Auxiliary.h"

#define FALSE -1
#define TRUE 0

eBook* book_New(void)
{
	eBook *newBook;

	newBook = (eBook*) malloc(sizeof(eBook));
	if (newBook != NULL)
	{
		newBook->id = 0;
		strcmp(newBook->title, "\0");
		strcmp(newBook->author, "\0");
		newBook->price = 0;
		newBook->editorialId = 0;
	}
	return newBook;
}

eBook* book_NewParameters(char *id, char *title, char *author, char *price, char *editorialId)
{
	eBook *newBook;

	newBook = book_New();
	if (newBook != NULL)
	{
		book_SetId(newBook, atoi(id));
		book_SetTitle(newBook, title);
		book_SetAuthor(newBook, author);
		book_SetPrice(newBook, atoi(price));
		book_SetEditorialId(newBook, atoi(editorialId));
	}
	return newBook;
}

int book_Delete(eBook *this)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		free(this);
		returnValue = TRUE;
	}
	return returnValue;
}

void book_Show(eBook *this)
{
	int id;
	char title[128];
	char author[128];
	char editorialId[128];
	int price;

	if (this != NULL)
	{
		book_GetId(this, &id);
		book_GetTitle(this, title);
		book_GetAuthor(this, author);
		book_GetPrice(this, &price);
		auxiliary_IdToEditorialName(this, editorialId);
		printf("\n%2d %50s %20s %10d %20s", id, title, author, price, editorialId);
	}
}

int book_SetId(eBook *this, int id)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->id = id;
		returnValue = TRUE;
	}

	return returnValue;
}

int book_SetTitle(eBook *this, char *title)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->title, title);
		returnValue = TRUE;
	}

	return returnValue;
}

int book_SetAuthor(eBook *this, char *author)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->author, author);
		returnValue = TRUE;
	}

	return returnValue;
}

int book_SetPrice(eBook *this, int price)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->price = price;
		returnValue = TRUE;
	}

	return returnValue;
}

int book_SetEditorialId(eBook *this, int editoriaId)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->editorialId = editoriaId;
		returnValue = TRUE;
	}

	return returnValue;
}

int book_GetId(eBook *this, int *id)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*id = this->id;
		returnValue = TRUE;
	}

	return returnValue;
}

int book_GetTitle(eBook *this, char *title)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(title, this->title);
		returnValue = TRUE;
	}

	return returnValue;
}

int book_GetAuthor(eBook *this, char *author)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(author, this->author);
		returnValue = TRUE;
	}

	return returnValue;
}

int book_GetPrice(eBook *this, int *price)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*price = this->price;
		returnValue = TRUE;
	}

	return returnValue;
}
int book_GetEditorialId(eBook *this, int *editoriaId)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*editoriaId = this->editorialId;
		returnValue = TRUE;
	}

	return returnValue;
}

int book_SortByAuthor(void *book1, void *book2)
{
	int returnValue;
	char author1[128];
	char author2[128];
	eBook *aux1;
	eBook *aux2;

	aux1 = (eBook*) book1;
	aux2 = (eBook*) book2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		book_GetAuthor(aux1, author1);
		book_GetAuthor(aux2, author2);

		if (strcasecmp(author1, author2) < 0)
		{
			returnValue = 1;
		}
		else
		{
			if (strcasecmp(author1, author2) > 0)
			{
				returnValue = -1;
			}
		}

	}
	return returnValue;
}

int book_DiscountsPlaneta(void *book)
{
	int returnValue;
	char editorialName[128];
	eBook *auxBook;
	int price;

	auxBook = (eBook*) book;
	returnValue = FALSE;
	if (auxBook != NULL)
	{
		auxiliary_IdToEditorialName(auxBook, editorialName);

		if (strcasecmp(editorialName, "PLANETA") == 0)
		{
			book_GetPrice(auxBook, &price);
			if (price >= 300)
			{
				book_SetPrice(auxBook, price - (0.20 * price));
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

int book_DiscountsSigloXXIE(void *book)
{
	int returnValue;
	char editorialName[128];
	eBook *auxBook;
	int price;

	auxBook = (eBook*) book;
	returnValue = FALSE;
	if (auxBook != NULL)
	{
		auxiliary_IdToEditorialName(auxBook, editorialName);

		if (strcasecmp(editorialName, "SIGLO XXI EDITORES") == 0)
		{
			book_GetPrice(auxBook, &price);
			if (price <= 200)
			{
				book_SetPrice(auxBook, price - (0.10 * price));
			}
		}
		returnValue = TRUE;
	}
	return returnValue;
}

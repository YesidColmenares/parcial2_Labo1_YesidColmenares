/*
 * eBook.h
 *
 *  Created on: 27 jun. 2021
 *      Author: Yesid
 */

#ifndef EBOOK_H_
#define EBOOK_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char title[128];
	char author[128];
	int price;
	int editorialId;
} eBook;

/**
 * @brief create a new book
 *
 * @return, NULL if the book was not created or the pointer to the new book.
 */
eBook* book_New(void);

/**
 * @brief create a new book with parameters
 *
 * @param id char*
 * @param title char*
 * @param author char*
 * @param price char*
 * @param editorialId char*
 * @return NULL if the book was not created or the pointer to the new book.
 */
eBook* book_NewParameters(char *id, char *title, char *author, char *price, char *editorialId);

/**
 * @brief remove a book
 *
 * @param this book to remove
 * @return -1 if the pointer is NULL or 0 if it was removed
 */
int book_Delete(eBook *this);

/**
 * @brief print a book
 *
 * @param this book to print
 */
void book_Show(eBook *this);

/**
 * @brief set the id to the indicated book
 *
 * @param this book
 * @param id value to set
 * @return -1 if the pointer is NULL or 0 if value was set
 */
int book_SetId(eBook *this, int id);

/**
 * @brief set the title to the indicated book
 *
 * @param this book
 * @param title value to set
 * @return -1 if the pointer is NULL or 0 if value was set
 */
int book_SetTitle(eBook *this, char *title);

/**
 * @brief set the author to the indicated book
 *
 * @param this book
 * @param author value to set
 * @return -1 if the pointer is NULL or 0 if value was set
 */
int book_SetAuthor(eBook *this, char *author);

/**
 * @brief set the price to the indicated book
 *
 * @param this book
 * @param price value to set
 * @return -1 if the pointer is NULL or 0 if value was set
 */
int book_SetPrice(eBook *this, int price);

/**
 * @brief set the EditorialId to the indicated book
 *
 * @param this book
 * @param editoriaId value to set
 * @return -1 if the pointer is NULL or 0 if value was set
 */
int book_SetEditorialId(eBook *this, int editoriaId);

/**
 * @brief return by parameter the id of the indicated book
 *
 * @param this book
 * @param id pointer that returns the id
 * @return -1 if the pointer is NULL or 0 if value was returned
 */
int book_GetId(eBook *this, int *id);

/**
 * @brief return by parameter the title of the indicated book
 *
 * @param this book
 * @param title pointer that returns the title of the book
 * @return -1 if the pointer is NULL or 0 if value was returned
 */
int book_GetTitle(eBook *this, char *title);

/**
 * @brief return by parameter the author of the indicated book
 *
 * @param this book
 * @param author pointer that returns the author of the book
 * @return -1 if the pointer is NULL or 0 if value was returned
 */
int book_GetAuthor(eBook *this, char *author);

/**
 * @brief return by parameter the price of the indicate book
 *
 * @param this book
 * @param price pointer that returns the price of the book
 * @return -1 if the pointer is NULL or 0 if value was returned
 */
int book_GetPrice(eBook *this, int *price);

/**
 * @brief return by parameter the EditorialID of the indicate book
 *
 * @param this book
 * @param editoriaId pointer that returns the EditorialID of the book
 * @return -1 if the pointer is NULL or 0 if value was returned
 */
int book_GetEditorialId(eBook *this, int *editoriaId);

/**
 * @brief compare the author's name of two books
 *
 * @param book1 void*
 * @param book2 void*
 * @return 0 if the pointer is NULL or
 *         1 if author 2 is greater than author 1,
 *        -1 if author 1 is greater than author 2
 */
int book_SortByAuthor(void *book1, void *book2);

/**
 * @brief make a discount on a book with the Planeta editorial
 *
 * @param book, void*
 * @return -1 if the pointer is NULL or 0 if it worked correctly
 */
int book_DiscountsPlaneta(void *book);

/**
 * @brief  make a discount on a book with the Siglo XXIE editorial
 *
 * @param book, void*
 * @return -1 if the pointer is NULL or 0 if it worked correctly
 */
int book_DiscountsSigloXXIE(void *book);

#endif /* EBOOK_H_ */

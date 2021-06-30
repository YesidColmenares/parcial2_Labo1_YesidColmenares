/*
 ============================================================================
 Name        : Examen_Labo_2_Yesid_Colmenares.c
 Author      : Yesid Colmenares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "dataEntry/input.h"
#include "Controller.h"
#include "Auxiliary.h"
#define SIZEP 100
#define TRUE 0
#define FALSE -1

int main(void)
{
	setbuf(stdout, NULL);
	LinkedList *listBooks;
	int option;
	char path[SIZEP];

	listBooks = ll_newLinkedList();
	do
	{
		auxiliary_PrintMainMenu();
		inputIntR(&option, "\nEnter option: ", "Error, enter option: ", 1, 6);
		switch (option)
		{
			case 1:
				system("cls");
				inputString(path, "Enter path file: ", "Error, enter path file: ", SIZEP);
				if (controller_LoadFromText(path, listBooks) == TRUE)
				{
					system("cls");
					printf("%s file uploaded successfully", path);
				}
				else
				{
					system("cls");
					printf("! Error loading %s, the file may be corrupted or the path is wrong !", path);

				}
				break;

			case 2:
				if (!ll_isEmpty(listBooks))
				{
					system("cls");
					if (controller_SortBook(listBooks) != TRUE)
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no books in the system !");
				}
				break;

			case 3:
				if (!ll_isEmpty(listBooks))
				{
					system("cls");
					if (controller_ListBook(listBooks) == FALSE)
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no books in the system !");
				}
				break;

			case 4:
				if (!ll_isEmpty(listBooks))
				{
					system("cls");
					if (controller_Discounts(listBooks) != TRUE)
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
					else
					{
						system("cls");
						printf("Discounts applied successfully");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no books in the system !");
				}
				break;

			case 5:
				system("cls");
				if (!ll_isEmpty(listBooks))
				{
					if (controller_SaveAsText(listBooks) == TRUE)
					{
						system("cls");
						printf("Successfully saved");

					}
					else
					{
						system("cls");
						printf("Error saving file");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no books in the system !");
				}
				break;

			case 6:
				ll_deleteLinkedList(listBooks);
				break;
		}
	} while (option != 6);
}

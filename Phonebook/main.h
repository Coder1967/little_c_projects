#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * person: defines a person
 * @number: stores phone number of contact
 * @name: name of contact
 */
typedef struct person
{
	char *number;
	char *name;
} contact;
void search_contact(int content);
void add_contact();
void  format_result(char *token);
#endif

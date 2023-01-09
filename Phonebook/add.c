#include "main.h"
/**
 * add_contact - adds a new contact info to csv file
 */
void add_contact()
{
	contact person;
	FILE *file = fopen("contacts.csv", "a");
	getchar();

	person.name = malloc(30 * sizeof(char));
	person.number = malloc(30 * sizeof(char));
	printf("Enter contact name: ");
	fgets(person.name, 40, stdin);
	printf("Enter number: ");
        fgets(person.number, 40, stdin);
	person.name[strcspn(person.name, "\n")] = 0;
	person.number[strcspn(person.number, "\n")] = 0;
	fprintf(file, "%s, %s\n", person.name, person.number);
	fclose(file);
	free(person.name);
	free(person.number);
}

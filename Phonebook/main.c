#include "main.h"
/**
 * main - driver function. gets called on running the application
 *
 */

int main(void)
{
	FILE *file = fopen("contacts.csv", "a");
	int content = 0;
	char answer = '\0';

	/* checks if the file is empty or doesn't exist. creates the file
	 * and adds the number and phone top columns
	 */
	fseek(file, 0, SEEK_END);
	content = ftell(file);
	fseek(file, 0, SEEK_SET);

	if (content == 0)
	{
		fprintf(file, "name, phone\n");
		fclose(file);
	}
	else
	{
		fclose(file);
	}
	printf("Enter 's' to search for a number or 'a' to add a new one: ");
	scanf("%c", &answer);

	if (answer == 'a' || answer == 'a' - 32)
	{
		add_contact();
	}
	else if (answer == 's' || answer == 's' - 32)
	{
		search_contact(content);
	}
	else
	{
		dprintf(2, "Could not understand command\n");
		exit(1);
	}
	return (0);
}

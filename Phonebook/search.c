#include "main.h"
/**
 * search_contact - takes a query from stdin and searches 
 * the contacts.csv file for the name. if the name isn't in the
 * file, it prints out the appropriate error otherwise
 * it prints out the person and their number
 * @content: number of characters in file
 */
void search_contact(int content)
{
	char query[31] = "";
	int check = 0;
	char c;
	char *token_str;
	int i = 0;
	char *token;
	FILE *file = fopen("contacts.csv", "r");
	char result[content + 5];
	int length = 0;
	const char *delim = "\n";
	
	if (content == 0)
	{
		dprintf(2, "phonebook is empty/n");
		fclose(file);
		exit(1);
	}
	getchar();
	printf("Enter name to search: ");
	fgets(query, 30, stdin);
	query[strcspn(query, "\n")] = 0;

	if (strlen(query) == 0)
	{
		dprintf(2, "No name was entered");
		fclose(file);
		exit(1);
	}
	length = strlen(query);
	printf("\n---------------------------\n");
	printf("|Name       |    Number\n");
	printf("---------------------------\n");

	while ((c = fgetc(file)) != EOF)
	{
		result[i] = c;
		i++;
	}
	result[i] = '\0';
	token = strtok(result, delim);
	token = strtok(NULL, delim);
	while( token != NULL )
	{
		token_str = strdup(token);
		token = strtok(NULL, delim);
		if (strncmp(token_str, query, length) == 0)
		{
			check++;

			format_result(token_str);
		}
		free(token_str);
	}

	token = strtok(NULL, delim);
	if (check == 0)
		puts("None matches your query");
	fclose(file);
}
/**
 * format_result - prints the search result in a nice format
 * @token: token represeting a user and their number
 */
void  format_result(char *token)
{
	const char *delim = ",";
	char *name;
	char *number;

	name = strtok(token, delim);
	number = strtok(NULL, delim);

        printf("%s       |    %s\n", name, number);
        printf("----------------------------\n");
}

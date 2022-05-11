#include "main.h"

/**
 * verify - tokenizes, calls function
 * @line: line from file
 * @line_number: line number
 */
void verify(char *line, int line_number)
{
	char *tokencitoMain;
	char *tokencitoDato;
	tokencitoMain = strtok(line, " ");


	tokencitoDato = strtok(NULL, " ");
	
	printf("main: %s\n", tokencitoMain);
	printf("dato: %s\n", tokencitoDato);
	printf("%i\n", line_number);

}

/** readFile -  opens and reads file
 * @name: argv[1]
 */
void readFile(char* name)
{
	FILE *file;
	char *line;
	int line_number = 1;
	size_t t = 0;

	file = fopen(name, "r");

	while ((getline(&line, &t, file) != -1))
	{
			verify(line, line_number);
			line_number++;
	}
}

/**
 *main - main function
 * @argc: arg count
 * @argv: args
 * Return: 0 if success
 */
int main(int argc, char **argv)
{
	FILE *file;

	/*more or less than two arguments case */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*opens file read only*/
	file = fopen(argv[1], "r");

	/*if file doesn't open*/
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (file)
		fclose(file);
	readFile(argv[1]);
	return(0);
}

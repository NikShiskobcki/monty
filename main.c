#include "monty.h"


/**
 *
 *
 *
 *
 *
 */
int is_number(char *data)
{
	int i = 0;
	int flag = 0;

	while (data[i] != '\0' && flag != 1)
	{
		if (data[i] >= '0' && data[i] <= '9')
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (flag);
}

/**
 *
 *
 */
void search(char *mainToken, stack_t **stack, unsigned int line_number)
{
	int j = 0;

	instruction_t func[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	while (func[j].opcode != NULL)
	{
		if (strcmp(func[j].opcode, mainToken) == 0)
		{
			func[j].f(stack, line_number);
			break;
		}
		j++;
		
	}	
	if (func[j].opcode == NULL)
	{
		fprintf(stderr, "L%i: unknown instruction %s\n", line_number, mainToken);
		exit(EXIT_FAILURE);
	}	
	
	

}



/** readFile -  opens and reads file
 * @name: argv[1]
 */
void readFile(char* name)
{
	FILE *file;
	char *line, *mainToken;
	unsigned int line_number = 1;
	size_t t = 0;
	stack_t *stack = NULL;

	file = fopen(name, "r");

	while ((getline(&line, &t, file) != -1))
	{
		mainToken = strtok(line, " \n\t");
		if (mainToken != NULL)
			search(mainToken, &stack, line_number);
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

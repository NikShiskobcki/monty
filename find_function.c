#include "main.h"

/**
 *
 *
 */
instruction_t find_function(char *str)
{
	int j = 0;
	instruction_t func[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};

	for (j = 0; func[j].opcode; j++)
		if (strcmp(str, func[j].opcode) == 0)
			break;
	return (func[j]);

}

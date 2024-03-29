#include "monty.h"

/**
 * openf - function
 * @fname: argument
 * Return: void
 */

void openf(char *fname)
{
	FILE *filede = fopen(fname, "r");

	if (fname == NULL || filede == NULL)
		errer(2, fname);

	rf(filede);
	fclose(filede);
}


/**
 * rf - function
 * @filede: pointer
 * Return: return
 */

void rf(FILE *filede)
{
	int line_number, frmt = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, filede) != -1; line_number++)
	{
		frmt = pl(buffer, line_number, frmt);
	}
	free(buffer);
}


/**
 * pl - function
 * @buffer: pointer
 * @line_number: argument
 * @frmt:  argument
 * Return: return
 */

int pl(char *buffer, int line_number, int frmt)
{
	char *o, *v;
	const char *delim = "\n ";

	if (buffer == NULL)
		errer(4);

	o = strtok(buffer, delim);
	if (o == NULL)
		return (frmt);
	v = strtok(NULL, delim);

	if (strcmp(o, "stack") == 0)
		return (0);
	if (strcmp(o, "queue") == 0)
		return (1);

	ff(o, v, line_number, frmt);
	return (frmt);
}

/**
 * ff - function
 * @o: pointer
 * @v: argument
 * @frmt:  argument
 * @ln: argument
 * Return: return
 */
void ff(char *opcode, char *v, int ln, int frmt)
{
	int n;
	int j;

	instruction_t func_list[] = {
		{"push", as},
		{"pall", ps},
		{"pint", pt},
		{"pop", ptp},
		{"nop", np},
		{"swap", swn},
		{"add", an},
		{"sub", sno},
		{"div", dvn},
		{"mul", mln},
		{"mod", mon},
		{"pchar", prch},
		{"pstr", prst},
		{"rotl", rtl},
		{"rotr", rtr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (j = 1, n = 0; func_list[n].opcode != NULL; n++)
	{
		if (strcmp(opcode, func_list[n].opcode) == 0)
		{
			cf(func_list[n].f, opcode, v, ln, frmt);
			j = 0;
		}
	}
	if (j == 1)
		errer(3, ln, opcode);
}


/**
 * cf - function
 * @f: pointer
 * @o: argument
 * @v: argument
 * @ln: argument
 * @frmt: argument
 * if 1 nodes will be entered as a queue.
 */
void cf(open_function f, char *o, char *v, int ln, int frmt)
{
	stack_t *node;
	int flg;
	int i;

	flg = 1;
	if (strcmp(o, "push") == 0)
	{
		if (v != NULL && v[0] == '-')
		{
			v = v + 1;
			flg = -1;
		}
		if (v == NULL)
			errer(5, ln);
		for (i = 0; v[i] != '\0'; i++)
		{
			if (isdigit(v[i]) == 0)
				errer(5, ln);
		}
		node = cr(atoi(v) * flg);
		if (frmt == 0)
			f(&node, ln);
		if (frmt == 1)
			aq(&node, ln);
	}
	else
		f(&head, ln);
}

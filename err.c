#include "monty.h"

/**
 * errer - function
 * @errc: argument
 */
void errer(int errc, ...)
{
	va_list aa;
	char *oop;
	int lnm;

	va_start(aa, errc);
	switch (errc)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(aa, char *));
			break;
		case 3:
			lnm = va_arg(aa, int);
			oop = va_arg(aa, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", lnm, oop);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(aa, int));
			break;
		default:
			break;
	}
	fn();
	exit(EXIT_FAILURE);
}

/**
 * merr - function
 * @errc: argument
 */
void merr(int errc, ...)
{
	va_list aa;
	char *oop;
	int lnm;

	va_start(aa, errc);
	switch (errc)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(aa, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(aa, int));
			break;
		case 8:
			lnm = va_arg(aa, unsigned int);
			oop = va_arg(aa, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", lnm, oop);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(aa, unsigned int));
			break;
		default:
			break;
	}
	fn();
	exit(EXIT_FAILURE);
}

/**
 * sterr - handles errors.
 * @errc: argument
 */
void sterr(int errc, ...)
{
	va_list aa;
	int lnm;

	va_start(aa, errc);
	lnm = va_arg(aa, int);
	switch (errc)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", lnm);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", lnm);
			break;
		default:
			break;
	}
	fn();
	exit(EXIT_FAILURE);
}

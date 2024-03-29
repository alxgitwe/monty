#include "monty.h"
stack_t *head = NULL;

/**
 * main - function
 * @argc: argument
 * @argv: argument
 * Return: return
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	openf(argv[1]);
	fn();
	return (0);
}

/**
 * cr - function
 * @i: argument
 * Return: return
 */
stack_t *cr(int i)
{
	stack_t *nde;

	nde = malloc(sizeof(stack_t));
	if (nde == NULL)
		errer(4);
	nde->next = NULL;
	nde->prev = NULL;
	nde->n = i;
	return (nde);
}

/**
 * fn - function
 */
void fn(void)
{
	stack_t *tmmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmmp = head;
		head = head->next;
		free(tmmp);
	}
}


/**
 * aq - function
 * @nn: pointer
 * @ln: argument
 */
void aq(stack_t **nn, __attribute__((unused))unsigned int ln)
{
	stack_t *tmmp;

	if (nn == NULL || *nn == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nn;
		return;
	}
	tmmp = head;
	while (tmmp->next != NULL)
		tmmp = tmmp->next;

	tmmp->next = *nn;
	(*nn)->prev = tmmp;

}

#include "monty.h"


/**
 * aas - function
 * @nn: pointer
 * @ln: argument
 */
void as(stack_t **nn, __attribute__((unused))unsigned int ln)
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
	head = *nn;
	head->next = tmmp;
	tmmp->prev = head;
}


/**
 * ps - function
 * @s: pointer
 * @ln: argument
 */
void ps(stack_t **s, unsigned int ln)
{
	stack_t *tmmp;

	(void) ln;
	if (s == NULL)
		exit(EXIT_FAILURE);
	tmmp = *s;
	while (tmmp != NULL)
	{
		printf("%d\n", tmmp->n);
		tmmp = tmmp->next;
	}
}

/**
 * ptp - function
 * @stack: pointer
 * @line_number: argument
 */
void ptp(stack_t **stack, unsigned int line_number)
{
	stack_t *tmmp;

	if (stack == NULL || *stack == NULL)
		merr(7, line_number);

	tmmp = *stack;
	*stack = tmmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmmp);
}

/**
 * pt - function
 * @stack: pointer
 * @line_number: argument
 */
void pt(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		merr(6, line_number);
	printf("%d\n", (*stack)->n);
}

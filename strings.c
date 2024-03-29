#include "monty.h"

/**
 * prch - function
 * @stack: pointer
 * @line_number: argument
 */
void prch(stack_t **stack, unsigned int line_number)
{
	int asccii;

	if (stack == NULL || *stack == NULL)
		sterr(11, line_number);

	asccii = (*stack)->n;
	if (asccii < 0 || asccii > 127)
		sterr(10, line_number);
	printf("%c\n", asccii);
}

/**
 * prst - function
 * @stack: pointer
 * @ln: argument
 */
void prst(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asccii;
	stack_t *tmmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmmp = *stack;
	while (tmmp != NULL)
	{
		asccii = tmmp->n;
		if (asccii <= 0 || asccii > 127)
			break;
		printf("%c", asccii);
		tmmp = tmmp->next;
	}
	printf("\n");
}

/**
 * rtl - function
 * @stack: pointer
 * @ln: argument
 */
void rtl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmmp = *stack;
	while (tmmp->next != NULL)
		tmmp = tmmp->next;

	tmmp->next = *stack;
	(*stack)->prev = tmmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rtr - function
 * @stack: pointer
 * @ln: argument
 */
void rtr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmmp = *stack;

	while (tmmp->next != NULL)
		tmmp = tmmp->next;

	tmmp->next = *stack;
	tmmp->prev->next = NULL;
	tmmp->prev = NULL;
	(*stack)->prev = tmmp;
	(*stack) = tmmp;
}

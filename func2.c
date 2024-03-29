#include "monty.h"

/**
 * np - function
 * @stack: pointer
 * @line_number: argument
 */
void np(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swn - function
 * @stack: pointer
 * @line_number: argument
 */
void swn(stack_t **stack, unsigned int line_number)
{
	stack_t *tmmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		merr(8, line_number, "swap");
	tmmp = (*stack)->next;
	(*stack)->next = tmmp->next;
	if (tmmp->next != NULL)
		tmmp->next->prev = *stack;
	tmmp->next = *stack;
	(*stack)->prev = tmmp;
	tmmp->prev = NULL;
	*stack = tmmp;
}

/**
 * an - function
 * @stack: pointer
 * @line_number: argument
 */
void an(stack_t **stack, unsigned int line_number)
{
	int suum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		merr(8, line_number, "add");

	(*stack) = (*stack)->next;
	suum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = suum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sno - function
 * @stack: pointer
 * @line_number: argument
 */
void sno(stack_t **stack, unsigned int line_number)
{
	int suum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		merr(8, line_number, "sub");


	(*stack) = (*stack)->next;
	suum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = suum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * dvn - function
 * @stack: pointer
 * @line_number: argument
 */
void dvn(stack_t **stack, unsigned int line_number)
{
	int suum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		merr(8, line_number, "div");

	if ((*stack)->n == 0)
		merr(9, line_number);
	(*stack) = (*stack)->next;
	suum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = suum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

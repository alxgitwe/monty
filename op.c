#include "monty.h"

/**
 * mln - function
 * @stack: pointer
 * @line_number: argument
 */
void mln(stack_t **stack, unsigned int line_number)
{
	int suum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		merr(8, line_number, "mul");

	(*stack) = (*stack)->next;
	suum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = suum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mon - function
 * @stack: pointer
 * @line_number: argument
 */
void mon(stack_t **stack, unsigned int line_number)
{
	int suum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		merr(8, line_number, "mod");


	if ((*stack)->n == 0)
		merr(9, line_number);
	(*stack) = (*stack)->next;
	suum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = suum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

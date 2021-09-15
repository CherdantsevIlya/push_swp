#include "push_swap.h"

void stack_clear(t_stack **stack)
{
	t_stack *temp;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = 0;
}

void stack_add_front(t_stack **stack, t_stack *new)
{
	if (*stack != NULL)
		new->next = *stack;
	*stack = new;
}

void stack_add_back(t_stack **stack, t_stack *new)
{
	if (*stack != NULL)
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		(*stack)->next = new;
	}
	else
		(*stack) = new;
}




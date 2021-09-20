#include "push_swap.h"

void rrr(t_stack **a, t_stack **b, int n)
{
	rra(a, 0);
	rrb(b, 0);
	if (n == 1)
		write(1, "rrr\n", 4);
}

int stack_sorted(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int stack_length(t_stack **stack)
{
	int i;
	t_stack *temp;

	i = 0;
	temp = *stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

//int stack_max(t_stack **stack)
//{
//	t_stack *temp;
//	int max;
//
//	temp = *stack;
//	max = temp->value;
//	while (temp->next != NULL)
//	{
//		if (temp->value < temp->next->value)
//			max = temp->next->value;
//		temp = temp->next;
//	}
//	(*stack)->max = max;
//	return (max);
//}
//
//int stack_min(t_stack **stack)
//{
//	t_stack *temp;
//	int min;
//
//	temp = *stack;
//	min = temp->value;
//	while (temp->next != NULL)
//	{
//		if (temp->value > temp->next->value)
//			min = temp->next->value;
//		temp = temp->next;
//	}
//	(*stack)->min = min;
//	return (min);
//}
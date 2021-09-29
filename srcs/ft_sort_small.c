#include "../includes/push_swap.h"

void ft_sort_three(t_stack **a)
{
	while (!(stack_sorted(a)))
	{
		if (((*a)->value > (*a)->next->value)
			&& ((*a)->value > (*a)->next->next->value)
			&& (*a)->next->value < (*a)->next->next->value)
			ra(a, 1);
		else if (((*a)->value < (*a)->next->value)
				 && ((*a)->value > (*a)->next->next->value)
				 && (*a)->next->value > (*a)->next->next->value)
			rra(a, 1);
		else if (((*a)->value > (*a)->next->value)
				 || ((*a)->value < (*a)->next->value))
			sa(a, 1);
	}
}

void ft_sort_four(t_stack **a, t_stack **b, t_data **data)
{
	while (stack_length(a) != 3)
	{
		if ((*a)->value == (*data)->max || (*a)->value == (*data)->min)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	ft_sort_three(a);
	pa(a, b, 1);
	if ((*a)->value == (*data)->max)
		ra(a, 1);
}

void ft_sort_five(t_stack **a, t_stack **b, t_data **data)
{
	while (stack_length(a) != 3)
	{
		if ((*a)->value == (*data)->max || (*a)->value == (*data)->min)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	ft_sort_three(a);
	while (*b != NULL)
	{
		pa(a, b, 1);
		if ((*a)->value == (*data)->max)
			ra(a, 1);
	}
}
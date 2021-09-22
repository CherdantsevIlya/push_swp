#include "../includes/push_swap.h"

void ft_sort_three(t_stack **a)
{
	while (!(stack_sorted(a)))
	{
		if (((*a) > (*a)->next) && ((*a) > (*a)->next->next)
			&& (*a)->next < (*a)->next->next)
			ra(a, 1);
		else if (((*a) < (*a)->next) && ((*a) > (*a)->next->next)
			&& (*a)->next > (*a)->next->next)
			rra(a, 1);
		else if (((*a) > (*a)->next) || ((*a) < (*a)->next))
			sa(a, 1);
	}
}

void ft_sort_four(t_stack **a, t_stack **b)
{
	while (stack_length(a) != 3)
	{
		if ((*a)->value == (*a)->max || (*a)->value == (*a)->min)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	ft_sort_three(a);
	pa(a, b, 1);
	if ((*a)->value == (*a)->max)
		ra(a, 1);
}

void ft_sort_five(t_stack **a, t_stack **b)
{
	while (stack_length(a) != 3)
	{
		if ((*a)->value == (*a)->max || (*a)->value == (*a)->min)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	ft_sort_three(a);
	while (*b != NULL)
	{
		pa(a, b, 1);
		if ((*a)->value == (*a)->max)
			ra(a, 1);
	}
}
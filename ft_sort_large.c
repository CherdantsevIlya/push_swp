#include "push_swap.h"

void sort_a_helper(t_stack **a, t_stack **b, t_data **data)
{
	if ((*a)->index == (*data)->index)
	{
		(*a)->step = -1;
		ra(a, b, 1);
		(*data)->index++;
	}
	else if (((*a)->next->index == (*data)->index)
			 && ((*a)->index == (*data)->index + 1))
	{
		sa(a, 1);
		(*a)->step = -1;
		ra(a, 1);
		(*a)->step = -1;
		ra(a, 1);
		(*data)->index += 2;
	}
	else
		pb(a, b, 1);
}

void sort_a(t_stack **a, t_stack **b, t_data **data)
{
	int temp;

	temp = (*a)->step;
	if (stack_length(a) <= (*data)->index)
		return ;
	while ((*a)->step == temp)
		sort_a_helper(a, b, data);
	if (stack_length(b))
		sort_b(a, b, data);
	sort_a(a, b, data);
}

void sort_b_helper(t_stack **a, t_stack **b, t_data **data)
{
	if ((*b)->index == (*data)->index)
	{
		(*b)->step = -1;
		pa(a, b, 1);
		ra(a, 1);
		(*data)->index++;
	}
	else if (((*b)->next->index == (*data)->index)
		&& ((*b)->index == (*data)->index + 1))
	{
		(*b)->step = -1;
		pa(a, b, 1);
		(*b)->step = -1;
		pa(a, b, 1);
		ra(a, 1);
		ra(a, 1);
		(*data)->index += 2;
	}
	else
		rb(b, 1);
}

void sort_b(t_stack **a, t_stack **b, t_data **data)
{
	int mid;

	mid = stack_mid(b);
	while (stack_length(b))
	{
		if ((*b)->value < mid)
			sort_b_helper(a, b, data);
		else
		{
			(*b)->step += 1;
			pa(a, b, 1);
		}
	}
	if (stack_length(b))
		sort_b(a, b, data);
	sort_a(a, b, data);
}

void ft_sort_large(t_stack **a, t_stack **b, t_data **data)
{
	int mid;

	mid = stack_mid(a);
	while (stack_length(a) - stack_length(b) > 1)
	{
		if ((*a)->value < mid)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	sort_b(a, b);
}


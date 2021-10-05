/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:16:17 by pkari             #+#    #+#             */
/*   Updated: 2021/10/05 15:16:22 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	part_to_b(t_stack **a, t_stack **b, t_data **data, int first)
{
	if (first != (*data)->main_min && first <= stack_last(*a)->value)
		return ;
	while ((*a)->value != first)
	{
		if ((*a)->index == stack_last(*a)->index + 1)
			ra(a, 1);
		else if (((*a)->next->index == stack_last(*a)->index + 1)
			&& ((*a)->index == (*a)->next->index + 1))
			sa(a, 1);
		else
			pb(a, b, 1);
	}
	stack_mid(b, data);
	if (find_next_index_in_b(a, b))
		recursion(a, b, data);
}

void	part_to_a(t_stack **a, t_stack **b, t_data **data)
{
	int		i;

	stack_mid(b, data);
	i = stack_length(b);
	while (i >= 0 && (*b))
	{
		if ((*b)->value >= (*data)->mid)
			pa(a, b, 1);
		else if (((*b)->index == stack_last(*a)->index + 1) || (*b)->index == 0)
		{
			pa(a, b, 1);
			ra(a, 1);
		}
		else if ((stack_last(*b)->index == stack_last(*a)->index + 1)
			|| stack_last(*b)->index == 0)
		{
			rrb(b, 1);
			pa(a, b, 1);
			ra(a, 1);
		}
		else
			rb(b, 1);
		i--;
	}
}

void	recursion(t_stack **a, t_stack **b, t_data **data)
{
	int	first;

	if (stack_length(b) == 0)
		return ;
	first = (*a)->value;
	part_to_a(a, b, data);
	while ((((*a)->index == stack_last(*a)->index + 1)
			|| (*a)->index == 0) && !stack_sorted(a))
		ra(a, 1);
	recursion(a, b, data);
	part_to_b(a, b, data, first);
}

void	ft_sort_large(t_stack **a, t_stack **b, t_data **data)
{
	stack_mid(a, data);
	while (stack_length(a) - stack_length(b) > 1)
	{
		if ((*a)->value < (*data)->mid)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	recursion(a, b, data);
	part_to_b(a, b, data, (*data)->main_min);
}

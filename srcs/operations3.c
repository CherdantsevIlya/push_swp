/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:28:09 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:28:12 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_stack **a, t_stack **b, int n)
{
	if (stack_length(a) > 1)
		rra(a, 0);
	if (stack_length(b) > 1)
		rrb(b, 0);
	if (n == 1)
		write(1, "rrr\n", 4);
}

int	stack_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_length(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	stack_mid(t_stack **stack, t_data **data)
{
	t_stack	*temp;
	int		i;
	int		*array;

	i = stack_length(stack);
	array = (int *)malloc(sizeof(int) * (i));
	temp = *stack;
	i = 0;
	while (temp)
	{
		array[i] = temp->value;
		temp = temp->next;
		i++;
	}
	ft_quicksort(array, 0, stack_length(stack) - 1);
	(*data)->min = array[0];
	(*data)->max = array[stack_length(stack) - 1];
	(*data)->mid = array[stack_length(stack) / 2];
	free(array);
}

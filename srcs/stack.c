/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:12:44 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:12:49 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_clear(t_stack **stack)
{
	t_stack	*temp;

	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (*stack != NULL)
		new->next = *stack;
	*stack = new;
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*q;

	if (!stack)
		return (0);
	q = stack;
	while (q->next)
		q = q->next;
	return (q);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (stack)
	{
		if (!(*stack))
			*stack = new;
		else
			stack_last(*stack)->next = new;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:31:21 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:31:23 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a, int n)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	(*a) = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (n == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int n)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	(*b)->next = temp;
	if (n == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int n)
{
	sa(a, 0);
	sb(b, 0);
	if (n == 1)
		write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b, int n)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (n == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int n)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (n == 1)
		write(1, "pb\n", 3);
}

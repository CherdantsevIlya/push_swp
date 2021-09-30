/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:29:48 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:29:51 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a, int n)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	while ((*a)->next != NULL)
		*a = (*a)->next;
	(*a)->next = temp;
	temp = temp->next;
	*a = (*a)->next;
	(*a)->next = NULL;
	*a = temp;
	if (n == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int n)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	while ((*b)->next != NULL)
		*b = (*b)->next;
	(*b)->next = temp;
	temp = temp->next;
	*b = (*b)->next;
	(*b)->next = NULL;
	*b = temp;
	if (n == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int n)
{
	ra(a, 0);
	rb(b, 0);
	if (n == 1)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, int n)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL)
		return ;
	tmp = *a;
	last = *a;
	while (last->next->next != NULL)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->next = tmp;
	*a = first;
	if (n == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int n)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*last;

	if (*b == NULL)
		return ;
	tmp = *b;
	last = *b;
	while (last->next->next != NULL)
		last = last->next;
	first = last->next;
	last->next = NULL;
	first->next = tmp;
	*b = first;
	if (n == 1)
		write(1, "rrb\n", 4);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:19:39 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:19:42 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_duplicate(int *index, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (index[i] == index[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_quicksort(int *array, int start, int end)
{
	int	n;

	if (start < end)
	{
		n = ft_qs_main(array, start, end);
		ft_quicksort(array, start, n - 1);
		ft_quicksort(array, n + 1, end);
	}
}

int	ft_qs_main(int *array, int start, int end)
{
	int	temp;
	int	mid;
	int	i;
	int	j;

	mid = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= mid)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = temp;
	return (i + 1);
}

void	ft_index_position(t_stack **stack, int *index)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	while (temp)
	{
		i = 0;
		while (index[i] != temp->value)
			i++;
		temp->index = i;
		temp = temp->next;
	}
}

void	ft_index(t_stack **a, t_stack **b, t_data **data)
{
	t_stack	*temp;
	int		i;
	int		*index;

	i = stack_length(a);
	index = (int *)malloc(i * sizeof(int));
	temp = *a;
	i = 0;
	while (temp)
	{
		index[i] = temp->value;
		temp = temp->next;
		i++;
	}
	ft_quicksort(index, 0, stack_length(a) - 1);
	if (!ft_duplicate(index, stack_length(a) - 1))
		ft_error(*a, *b, *data, 1);
	ft_index_position(a, index);
	free(index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:32:22 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:32:26 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	*ft_init(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	data->main_min = 0;
	data->mid = 0;
	data->max = 0;
	data->min = 0;
	data->index = 0;
	data->step = 0;
	return (data);
}

t_stack	*create_stack(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->value = 0;
	first->index = 0;
	first->step = 0;
	first->next = NULL;
	return (first);
}

t_stack	*copy_to_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = create_stack();
	tmp = first;
	while (i < argc)
	{
		tmp->value = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp->next = create_stack();
			tmp = tmp->next;
		}
		i++;
	}
	return (first);
}

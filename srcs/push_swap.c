/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:18:19 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:18:23 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_stack *a, t_stack *b, t_data *data, int argc)
{
	stack_mid(&a, &data);
	if (argc <= 4)
		ft_sort_three(&a);
	else if (argc <= 5)
		ft_sort_four(&a, &b, &data);
	else if (argc <= 6)
		ft_sort_five(&a, &b, &data);
	else
		ft_sort_large(&a, &b, &data);
}

void	ft_main_helper(t_stack *a, t_stack *b, t_data *data, int argc)
{
	if (!ft_index(&a))
		ft_error(a, b, data, 1);
	if (argc == 2 || stack_sorted(&a))
		ft_error(a, b, data, 0);
	ft_sort(a, b, data, argc);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;

	if (argc < 2)
		exit(1);
	if (!ft_parsing(argc, argv))
	{
		ft_putendl("\x1b[31mError\x1b[0m");
		return (0);
	}
	if (!ft_integer(argc, argv))
		return (0);
	b = NULL;
	a = copy_to_stack(argc, argv);
	data = ft_init();
	ft_main_helper(a, b, data, argc);
	ft_error(a, b, data, 0);
	return (0);
}

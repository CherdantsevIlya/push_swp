/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:12:16 by pkari             #+#    #+#             */
/*   Updated: 2021/10/06 18:12:22 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_read_operations(char *line, t_stack **a, t_stack **b, t_data **data)
{
	if (ft_strcmp(line, "sa") == 0)
		sa(a, 0);
	else if (ft_strcmp(line, "sb") == 0)
		sb(b, 0);
	else if (ft_strcmp(line, "ss") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(line, "pa") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(line, "pb") == 0)
		pb(a, b, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ra(a, 0);
	else if (ft_strcmp(line, "rb") == 0)
		rb(b, 0);
	else if (ft_strcmp(line, "rr") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(line, "rra") == 0)
		rra(a, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(b, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(a, b, 0);
	else
		ft_error(*a, *b, *data, 1);
}

void	ft_read_lines(t_stack **a, t_stack **b, t_data **data)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		ft_read_operations(line, a, b, data);
		free(line);
		line = NULL;
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

int	check_stack_sorted(t_stack **a, t_stack **b)
{
	int	n;

	if ((*b) != NULL || (*a) == NULL)
		return (0);
	n = (*a)->value;
	while (*a)
	{
		if (n > (*a)->value)
			return (0);
		n = (*a)->value;
		*a = (*a)->next;
	}
	return (1);
}

void	ft_checker_helper(t_stack **a, t_stack **b, t_data **data, int argc)
{
	if (!ft_index(a))
		ft_error(*a, *b, *data, 1);
	if (argc == 2)
		ft_error(*a, *b, *data, 0);
	ft_read_lines(a, b, data);
	if (check_stack_sorted(a, b))
		ft_putendl("\x1b[32mOK\x1b[0m");
	else
		ft_putendl("\x1b[31mKO\x1b[0m");
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
	ft_checker_helper(&a, &b, &data, argc);
	ft_error(a, b, data, 0);
	return (0);
}

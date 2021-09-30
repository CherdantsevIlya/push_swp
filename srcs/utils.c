/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:11:42 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:11:52 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(t_stack *a, t_stack *b, t_data *data, int i)
{
	stack_clear(&a);
	stack_clear(&b);
	free(data);
	if (i == 1)
		ft_putendl("\x1b[31mError\x1b[0m");
	exit(1);
}

int64_t	ft_big_atoi(const char *str)
{
	int			i;
	int			count;
	int64_t		nbr;

	i = 0;
	count = 1;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		count = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr = (str[i] - '0') + (nbr * 10);
		i++;
	}
	return (nbr * count);
}

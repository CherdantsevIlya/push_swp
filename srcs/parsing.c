/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:21:40 by pkari             #+#    #+#             */
/*   Updated: 2021/09/30 16:21:42 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_valid(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = -1;
	nbr = 0;
	sign = 0;
	while (str[++i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (nbr != 0 && sign != 0)
				return (0);
			nbr = 0;
			sign = 0;
		}
		else if ((str[i] == '+' || str[i] == '-') && (sign == 0 && nbr == 0)
			&& ft_isdigit(str[i + 1]))
			sign++;
		else
			return (0);
	}
	return (1);
}

int	ft_isnumber(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_spaceX(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_parsing(int argc, char **argv)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		if (ft_spaceX(argv[i]))
		{
			if (ft_isnumber(argv[i]))
			{
				if (ft_valid(argv[i]))
					n = 1;
				else
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (n);
}

int	ft_integer(int argc, char **argv)
{
	int		i;
	int64_t	nbr;

	i = 1;
	while (i < argc)
	{
		nbr = ft_big_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
		{
			ft_putendl("\x1b[31mError\x1b[0m");
			return (0);
		}
		i++;
	}
	return (1);
}

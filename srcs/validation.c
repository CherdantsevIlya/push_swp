#include "../includes/push_swap.h"

t_data *ft_init(void)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	data->mid = 0;
	data->max = 0;
	data->min = 0;
	data->index = 0;
	data->step = 0;
	return (data);
}

int ft_valid(const char *str)
{
	int i;
	int nbr;
	int sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i])
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
		i++;
	}
	return (1);
}

int ft_isnumber(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
	}
	return (0);
}

int ft_spaceX(const char *str)
{
	int i;

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

int ft_parsing(int argc, char **argv)
{
	int i;
	int n;

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
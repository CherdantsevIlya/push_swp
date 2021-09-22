#include "../includes/push_swap.h"

void ft_init(t_stack *a, t_stack *b, t_data *data)
{
	b = NULL;
	data->index = 0;
	a->mid = 0;
	a->min = 0;
	a->max = 0;
	a->step = 0;
}

//int	ft_valid_atoi(const char *str)
//{
//	int			i;
//	int			count;
//	long int	nbr;
//
//	i = 0;
//	count = 1;
//	nbr = 0;
//	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
//		   || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
//		i++;
//	if (str[i] == '-' && ft_isdigit(str[i + 1]))
//	{
//		count = -1;
//		i++;
//	}
//	else if (!ft_isdigit(str[i]))
//		return (0);
//	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
//	{
//		nbr = (str[i] - '0') + (nbr * 10);
//		if ((nbr > 2147483647 && count == 1)
//			|| (nbr > 2147483648 && count == -1))
//			return (0);
//		i++;
//	}
//	return (nbr * count);
//}

int	ft_empty_line(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		   || str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int ft_parsing(int argc, char **argv, t_stack *a)
{
	int i;
	int j;
	int count;
	long int nbr;

	i = 1;
	j = 0;
	while (i < argc)
	{
		count = 1;
		nbr = 0;
		while (argv[i][j] == '\n' || argv[i][j] == '\r' || argv[i][j] == '\t'
			   || argv[i][j] == '\v' || argv[i][j] == '\f' || argv[i][j] == ' ')
			j++;
		if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& (ft_isdigit(argv[i][j + 1])))
		{
			if (argv[i][j] == '-')
				count = -1;
			j++;
		}
		while (argv[i][j] >= '0' && argv[i][j] <= '9' && argv[i][j] != '\0')
		{
			nbr = (argv[i][j] - '0') + (nbr * 10);
			j++;
		}
		nbr = (nbr * count);
		if ((nbr > 2147483647 || nbr < -2147483648)
			|| (argv[i][j] != '\0' && !ft_isdigit(argv[i][j])))
			return (1);
		else if (ft_empty_line(argv[i]))
			return (2);
		stack_add_back(&a, stack_new(nbr));
		i++;
	}
	return (0);
}


#include "../includes/push_swap.h"

int ft_push_stack(int argc, char **argv, t_stack **a)
{
	long int nbr;
	int i;

	i = 1;
	while (argc--)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
		stack_add_back(a, stack_new(nbr));
		i++;
	}
	return (1);
}


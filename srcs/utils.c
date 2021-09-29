#include "../includes/push_swap.h"

void	ft_error(t_stack *a, t_stack *b, t_data *data, int i)
{
	stack_clear(&a);
	stack_clear(&b);
	free(data);
	if (i == 1)
		ft_putstr("\x1b[31mError\x1b[0m\n");
	exit(1);
}

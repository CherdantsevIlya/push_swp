#include "../includes/push_swap.h"

void	ft_error(t_stack *a, t_stack *b, t_data *data, int i)
{
	stack_clear(&a);
	stack_clear(&b);
	free(data->index);
	free(data->step);
	*data = NULL;
	if (i == 1)
		ft_putstr("\x1b[31mError\x1b[0m\n");
	else if (i == 0)
		ft_putstr("\x1b[31mMalloc Error\x1b[0m\n");
	exit(1);
}

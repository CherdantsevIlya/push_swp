#include "push_swap.h"

void ft_error(t_stack **a, t_stack **b)
{
	stack_clear(a);
	stack_clear(b);
	write(1, "\x1b[31mError\x1b[0m\n", 6);
	exit(1);
}

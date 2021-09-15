#include "push_swap.h"

void ft_sort(t_stack *a, t_stack *b, int argc)
{
	if (argc <= 4)
		ft_sort_three(&a);
	else if (argc <= 5)
		ft_sort_four(&a, &b);
	else if (argc <= 6)
		ft_sort_five(&a, &b);
	else if (argc <= 101)
		ft_sort_hundred(&a, &b);
	else if (argc <= 501)
		ft_sort_fhundred(&a, &b);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	if (argc < 2)
	{

		ft_sort(a, b, argc);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

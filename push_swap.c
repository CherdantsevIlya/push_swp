#include "push_swap.h"

void ft_sort(t_stack *a, t_stack *b, t_data *data, int argc)
{
	if (argc <= 4)
		ft_sort_three(&a);
	else if (argc <= 5)
		ft_sort_four(&a, &b);
	else if (argc <= 6)
		ft_sort_five(&a, &b);
	else
		ft_sort_large(&a, &b, &data);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_data *data;

	if (argc < 2)
	{

		ft_sort(a, b, data, argc);
	}
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}

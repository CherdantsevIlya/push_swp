#include "../includes/push_swap.h"

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
	int i;
	t_stack *a;
	t_stack *b;
	t_data *data;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	data = (t_data *)malloc(sizeof(t_data));
	if (!a || !b || !data)
		ft_error(a, b, data, 0);
	ft_init(a, b, data);
	if (argc > 1)
	{
		i = ft_parsing(argc, argv, a);
		if (i == 1)
			ft_error(a, b, data, 1);
		else if (i == 2)
			ft_error(a, b, data, 2);
		i = ft_index(&a);
		if (i == 0)
			ft_error(a, b, data, 0);
		else if (i == -1)
			ft_error(a, b, data, 1);
		else
			ft_sort(a, b, data, argc);
	}
	ft_error(a, b, data, 2);
	return (0);
}

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

void ft_main_helper(t_stack *a, t_stack *b, t_data *data, int argc)
{
	int i;

	i = ft_index(&a);
	if (i == 0)
		ft_error(a, b, data, 0);
	else if (i == -1)
		ft_error(a, b, data, 1);
	if (argc == 2)
		ft_error(a, b, data, 2);
	ft_sort(a, b, data, argc);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_data *data;

	if (argc < 2)
		exit(1);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	data = (t_data *)malloc(sizeof(t_data));
	if (!a || !b || !data)
		ft_error(a, b, data, 0);
	ft_init(a, b, data);
	if (ft_parsing(argc, argv) == 1)
	{
		if// проверить инты на макс и мин и засунуть в стек А
		ft_main_helper(a, b, data, argc);
	}
	else if (ft_parsing(argc, argv) == -1)
		ft_error(a, b, data, 1);
	ft_error(a, b, data, 2);
	return (0);
}

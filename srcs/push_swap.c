#include "../includes/push_swap.h"

void ft_sort(t_stack *a, t_stack *b, t_data *data, int argc)
{
	stack_mid(&a, &data);
	if (argc <= 4)
		ft_sort_three(&a);
	else if (argc <= 5)
		ft_sort_four(&a, &b, &data);
	else if (argc <= 6)
		ft_sort_five(&a, &b, &data);
	else
		ft_sort_large(&a, &b, &data);
}

void ft_main_helper(t_stack *a, t_stack *b, t_data *data, int argc)
{
	if (!ft_index(&a))
		ft_error(a, b, data, 1);
	if (argc == 2 || stack_sorted(&a))
		ft_error(a, b, data, 0);
	ft_sort(a, b, data, argc);
}

t_stack	*create_new_node(void)
{
	t_stack	*first;

	first = (t_stack *)malloc(sizeof(t_stack));
	first->value = 0;
	first->index = 0;
	first->step = 0;
	first->next = NULL;
	return (first);
}

t_stack	*copy_args_in_stack(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	first = create_new_node();
	tmp = first;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (NULL);
		tmp->value = ft_atoi(argv[i]);
		if (i < argc - 1)
		{
			tmp->next = create_new_node();
			tmp = tmp->next;
		}
		i++;
	}
	return (first);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_data *data;

	if (argc < 2)
		exit(1);
	if (!ft_parsing(argc, argv))
	{
		ft_putstr("\x1b[31mError\x1b[0m\n");
		return (0);
	}
	b = NULL;
	data = ft_init();
	if (!(a = copy_args_in_stack(argc, argv)))
		ft_error(a, b, data, 1);
	ft_main_helper(a, b, data, argc);
	ft_error(a, b, data, 0);
	return (0);
}

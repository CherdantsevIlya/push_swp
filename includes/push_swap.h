#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_stack
{
	int 			step;
	int				mid;
	int				min;
	int 			max;
	int 			index;
	int 			value;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_data
{
	int				step;
	int 			index;
}					t_data;

/*
**		operations123.c
*/

void	sa(t_stack **a, int n);
void	sb(t_stack **b, int n);
void	ss(t_stack **a, t_stack **b, int n);
void	pa(t_stack **a, t_stack **b, int n);
void	pb(t_stack **a, t_stack **b, int n);
void	ra(t_stack **a, int n);
void	rb(t_stack **b, int n);
void	rr(t_stack **a, t_stack **b, int n);
void	rra(t_stack **a, int n);
void	rrb(t_stack **b, int n);
void	rrr(t_stack **a, t_stack **b, int n);
void	stack_mid(t_stack **stack);
int	stack_sorted(t_stack **stack);
int	stack_length(t_stack **stack);

/*
**		push_swap.c
*/

void	ft_sort(t_stack *a, t_stack *b, t_data *data, int argc);
void	ft_main_helper(t_stack *a, t_stack *b, t_data *data, int argc);

/*
**		ft_sort_small.c
*/

void	ft_sort_three(t_stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);

/*
**		ft_sort_large.c
*/

void	ft_sort_large(t_stack **a, t_stack **b, t_data **data);
void	sort_b(t_stack **a, t_stack **b, t_data **data);
void	sort_b_helper(t_stack **a, t_stack **b, t_data **data);
void	sort_a(t_stack **a, t_stack **b, t_data **data);
void	sort_a_helper(t_stack **a, t_stack **b, t_data **data);

/*
**		stack.c
*/

void	stack_clear(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *new);
t_stack *stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new(long int new);

/*
**		utils.c
*/

void	ft_error(t_stack *a, t_stack *b, t_data *data, int i);

/*
**		position.c
*/

int	ft_index(t_stack **stack);
void	ft_index_position(t_stack **stack, int *index);
void	ft_quicksort(int *array, int start, int end);
int	ft_qs_main(int *array, int start, int end);

/*
**		validation.c
*/

void	ft_init(t_stack *a, t_stack *b, t_data *data);
int	ft_parsing(int argc, char **argv);
int	ft_spaceX(const char *str);
int	ft_isnumber(const char *str);
int	ft_valid(const char *str);

#endif

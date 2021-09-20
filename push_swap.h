#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

typedef struct		s_stack
{
	int 			step;
	int 			flag;
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

void sa(t_stack **a, int n);
void sb(t_stack **b, int n);
void ss(t_stack **a, t_stack **b, int n);
void pa(t_stack **a, t_stack **b, int n);
void pb(t_stack **a, t_stack **b, int n);
void ra(t_stack **a, int n);
void rb(t_stack **b, int n);
void rr(t_stack **a, t_stack **b, int n);
void rra(t_stack **a, int n);
void rrb(t_stack **b, int n);
void rrr(t_stack **a, t_stack **b, int n);
int stack_sorted(t_stack **stack);
int stack_length(t_stack **stack);

//int stack_max(t_stack **stack);
//int stack_min(t_stack **stack);

void ft_sort(t_stack *a, t_stack *b, t_data *data, int argc);

void ft_sort_three(t_stack **a);
void ft_sort_four(t_stack **a, t_stack **b);
void ft_sort_five(t_stack **a, t_stack **b);

void ft_sort_large(t_stack **a, t_stack **b, t_data **data);
void sort_b(t_stack **a, t_stack **b, t_data **data);
void sort_b_helper(t_stack **a, t_stack **b, t_data **data);
void sort_a(t_stack **a, t_stack **b, t_data **data);
void sort_a_helper(t_stack **a, t_stack **b, t_data **data);

void stack_clear(t_stack **stack);
void stack_add_front(t_stack **stack, t_stack *new);
void stack_add_back(t_stack **stack, t_stack *new);

#endif

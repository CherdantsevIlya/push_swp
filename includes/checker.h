/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:13:50 by pkari             #+#    #+#             */
/*   Updated: 2021/10/06 18:13:53 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define BUFFER_SIZE 1000

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				step;
	int				index;
	int				value;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	int				main_min;
	int				mid;
	int				min;
	int				max;
	int				step;
	int				index;
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
void	stack_mid(t_stack **stack, t_data **data);
int		stack_sorted(t_stack **stack);
int		stack_length(t_stack **stack);

/*
 **		checker.c
 */

void	ft_checker_helper(t_stack **a, t_stack **b, t_data **data, int argc);
int		check_stack_sorted(t_stack **a, t_stack **b);
void	ft_read_lines(t_stack **a, t_stack **b, t_data **data);
void	ft_read_operations(char *line, t_stack **a, t_stack **b, t_data **data);

/*
 **		utils.c
 */

void	ft_error(t_stack *a, t_stack *b, t_data *data, int i);
int		find_next_index_in_b(t_stack **a, t_stack **b);
int64_t	ft_big_atoi(const char *str);

/*
 **		position.c
 */

void	ft_index_position(t_stack **stack, int *index);
void	ft_quicksort(int *array, int start, int end);
int		ft_qs_main(int *array, int start, int end);
int		ft_index(t_stack **stack);
int		ft_duplicate(int *index);

/*
 **		parsing.c
 */

int		ft_parsing(int argc, char **argv);
int		ft_spaceX(const char *str);
int		ft_isnumber(const char *str);
int		ft_valid(const char *str);
int		ft_integer(int argc, char **argv);

/*
 **		init.c
 */

t_data	*ft_init(void);
t_stack	*create_stack(void);
t_stack	*copy_to_stack(int argc, char **argv);

/*
 **		stack.c
 */

void	stack_clear(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);
t_stack	*stack_new(long int new);
t_stack	*stack_last(t_stack *stack);

/*
 **		get_next_line.c
 */

int		get_next_line(int fd, char **line);
int		ft_eof(char **line, int br);
int		ft_find_i(const char *reminder, int c);
int		ft_check_reminder(char *reminder, char **line, int i);

#endif

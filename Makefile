#CC				= gcc -fsanitize=address
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

PUSH_SWAP		= push_swap
CHECKER			= checker

INCFLAGS		= -I./includes -I./libft

LIB_DIR			= ./libft
LINK_LIBFT		= -Llibft -lft

SRCS_DIR		= ./srcs/
SRCS_NAME		=	push_swap.c \
					ft_sort_large.c \
					ft_sort_small.c \
					operations1.c \
					operations2.c \
					operations3.c \
					position.c \
					stack.c \
					utils.c \
					init.c \
					parsing.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_NAME))
OBJS			= $(SRCS:.c=.o)

all				: $(PUSH_SWAP)

$(PUSH_SWAP) 	: $(OBJS)
				$(MAKE) all -C $(LIB_DIR)
				$(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@

.c.o			:
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean			:
				$(MAKE) -C $(LIB_DIR) clean
				rm -fv $(OBJS)

fclean			: clean
				$(MAKE) -C $(LIB_DIR) fclean
				rm -fv $(PUSH_SWAP)

re				: fclean all

.PHONY			: all clean fclean re
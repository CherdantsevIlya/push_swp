CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

PUSH_SWAP		= push_swap
CHECKER			= checker

INCFLAGS		= -I./includes -I./libft

LIB_DIR			= ./libft
LINK_LIBFT		= -Llibft -lft

SRCS_DIR		= ./srcs/

SRCS_NAME1		=	push_swap.c \
					ft_sort_large.c \
					ft_sort_small.c \
					operations1.c \
					operations2.c \
					operations3.c \
					position.c \
					stack.c \
					utils.c \
					init.c \
					parsing.c

SRCS_NAME2		=	checker.c \
					operations1.c \
					operations2.c \
					operations3.c \
					position.c \
					stack.c \
					utils.c \
					init.c \
					parsing.c \
					get_next_line.c

SRCS1			= $(addprefix $(SRCS_DIR), $(SRCS_NAME1))
SRCS2			= $(addprefix $(SRCS_DIR), $(SRCS_NAME2))
LIB				= $(LIB_DIR)/libft.a
OBJS1			= $(SRCS1:.c=.o)
OBJS2			= $(SRCS2:.c=.o)

all				: $(PUSH_SWAP) $(CHECKER)

$(LIB)			:
				 @ make -C $(LIB_DIR)

$(PUSH_SWAP) 	: $(OBJS1) $(LIB)
				@ $(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@
				@printf "\x1b[42mPush_swap done 💚 \x1b[0m\n"

$(CHECKER)	 	: $(OBJS2) $(LIB)
				@ $(CC) $(CFLAGS) $(INCFLAGS) $^ $(LINK_LIBFT) -o $@
				@printf "\x1b[42mChecker done 🍀 \x1b[0m\n"

.c.o			:
				 @ $(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

clean			:
				@ $(MAKE) -C $(LIB_DIR) clean
				@ rm -f $(OBJS1) $(OBJS2)
				@printf "\x1b[41mObj deleted 🗑 \x1b[0m\n"

fclean			: clean
				@ $(MAKE) -C $(LIB_DIR) fclean
				@ rm -f $(PUSH_SWAP) $(CHECKER)
				@printf "\x1b[41mBin deleted 🚽 \x1b[0m\n"

re				: fclean all

.PHONY			: all clean fclean re
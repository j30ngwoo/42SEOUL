CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
NAME = push_swap
BONUS_NAME = checker
GNL_NAME = get_next_line

GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_DIR = gnl
GNL_HEADER = $(GNL_DIR)/get_next_line.h
GNL = $(patsubst %.c, $(GNL_DIR)/%.c, $(GNL_SRCS))

OPERS_SRCS = oper_push.c oper_reverse_rotate.c oper_rotate.c oper_swap.c
OPERS_DIR = opers
OPERS_HEADER = $(OPERS_DIR)/opers.h
OPERS = $(patsubst %.c, $(OPERS_DIR)/%.c, $(OPERS_SRCS))

UTILS_SRCS = availability.c control_index.c control_stack.c init.c termination.c
UTILS_DIR = utils
UTILS_HEADER = $(UTILS_DIR)/utils.h
UTILS = $(patsubst %.c, $(UTILS_DIR)/%.c, $(UTILS_SRCS))

MAND_SRCS = main.c proc_min_opers.c proc_over_six.c proc_pivot.c proc_under_six.c sort_little_num.c
MAND_DIR = mandatory
MAND_HEADER = $(MAND_DIR)/push_swap.h $(OPERS_HEADER) $(UTILS_HEADER)
MAND = $(patsubst %.c, $(MAND_DIR)/%.c, $(MAND_SRCS))
MAND_GCC_SRCS = $(MAND) $(OPERS) $(UTILS)

BONUS_SRCS = main_bonus.c exec_oper_bonus.c
BONUS_DIR = bonus
BONUS_HEADER = $(BONUS_DIR)/checker_bonus.h $(GNL_HEADER) $(OPERS_HEADER) $(UTILS_HEADER)
BONUS = $(patsubst %.c, $(BONUS_DIR)/%.c, $(BONUS_SRCS))
BONUS_GCC_SRCS = $(BONUS) $(OPERS) $(UTILS) $(GNL)

.PHONY: clean fclean re

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(LIBFT) $(MAND_GCC_SRCS) $(MAND_HEADER)
	$(CC) $(CFLAGS) $(MAND_GCC_SRCS) -lft -L ./libft -o $@

$(BONUS_NAME): $(LIBFT) $(BONUS_GCC_SRCS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) $(BONUS_GCC_SRCS) -lft -L ./libft -o $@

clean:
	make clean -C libft/
	rm -f $(LIBFT)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

$(LIBFT):
	make -C libft/

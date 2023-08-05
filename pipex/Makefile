CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
NAME = pipex

GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_DIR = gnl
GNL_HEADER = $(GNL_DIR)/get_next_line.h
GNL_DIR_SRCS = $(patsubst %.c, $(GNL_DIR)/%.c, $(GNL_SRCS))

COMMON_SRCS = child_process.c fork_process.c heredoc.c init.c open_file.c protected_funcs1.c protected_funcs2.c protected_funcs3.c termination.c
COMMON_DIR = srcs
COMMON_HEADER = $(COMMON_DIR)/pipex.h $(GNL_HEADER)
COMMON_DIR_SRCS = $(patsubst %.c, $(COMMON_DIR)/%.c, $(COMMON_SRCS)) $(GNL_DIR_SRCS)

MAND_DIR_SRCS = $(COMMON_DIR)/main.c $(COMMON_DIR_SRCS)

BONUS_DIR_SRCS = $(COMMON_DIR)/main_bonus.c $(COMMON_DIR_SRCS) 

.PHONY: clean fclean re

$(NAME): all

all: $(LIBFT) $(MAND_DIR_SRCS) $(COMMON_HEADER)
	$(CC) $(CFLAGS) $(MAND_DIR_SRCS) -Llibft -lft -o $(NAME)
	rm -f bonus
	touch $@

bonus: $(LIBFT) $(BONUS_DIR_SRCS) $(COMMON_HEADER)
	$(CC) $(CFLAGS) $(BONUS_DIR_SRCS) -Llibft -lft -o $(NAME)
	rm -f all
	touch $@

$(NAME): all

clean:
	make clean -C libft
	rm -f $(LIBFT) all bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C libft
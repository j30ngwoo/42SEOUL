CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
MLX = libmlx.dylib
NAME = so_long

GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_DIR = gnl
GNL_HEADER = $(GNL_DIR)/get_next_line.h
GNL_DIR_SRCS = $(patsubst %.c, $(GNL_DIR)/%.c, $(GNL_SRCS))

MAND_SRCS = check_valid.c check_with_dfs.c init_game.c init_map.c key_input_proc.c protected_func.c render_game.c termination.c utils.c 
MAND_DIR = mandatory_srcs
MAND_HEADERS = $(MAND_DIR)/so_long.h $(GNL_HEADER)
MAND_DIR_SRCS = $(patsubst %.c, $(MAND_DIR)/%.c, $(MAND_SRCS)) $(GNL_DIR_SRCS)

BONUS_SRCS = enemy_bonus.c termination_bonus.c
BONUS_DIR = bonus_srcs
BONUS_HEADERS = $(BONUS_DIR)/so_long_bonus.h $(MAND_HEADERS)
BONUS_DIR_SRCS = $(patsubst %.c, $(BONUS_DIR)/%.c, $(BONUS_SRCS)) $(MAND_DIR_SRCS)

.PHONY: clean fclean re

$(NAME): all

all: $(LIBFT) $(MLX) $(MAND_DIR_SRCS) $(MAND_DIR)/so_long.c $(MAND_HEADERS)
	$(CC) $(CFLAGS) $(MAND_DIR_SRCS) $(MAND_DIR)/so_long.c -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	rm -f bonus
	touch $@

bonus: $(LIBFT) $(MLX) $(BONUS_DIR_SRCS) $(BONUS_DIR)/so_long_bonus.c $(BONUS_HEADERS)
	$(CC) $(CFLAGS) $(BONUS_DIR_SRCS) $(BONUS_DIR)/so_long_bonus.c -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	rm -f all
	touch $@

clean:
	make clean -C libft/
	make clean -C mlx/
	rm -f $(LIBFT) $(MLX) all bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C libft/

$(MLX):
	make -C mlx/
	mv mlx/$(MLX) $(MLX)
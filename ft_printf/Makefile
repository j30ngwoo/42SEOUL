CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
DIR_LIBFT = libft/libft.a
NAME = libftprintf.a

SRCS = ft_printf.c print_chars.c print_hex.c print_int.c print_ptr.c
DIR = mandatory_srcs
HEADER = $(DIR)/ft_printf.h
OBJS = $(patsubst %.o, $(DIR)/%.o, $(SRCS:.c=.o))

SRCS_BONUS = ft_printf_bonus.c print_chars_bonus.c print_hex_bonus.c print_int_bonus.c print_ptr_bonus.c print_space_bonus.c print_uint_bonus.c setting_bonus.c utility_bonus.c
DIR_BONUS = bonus_srcs
HEADER_BONUS = $(DIR_BONUS)/ft_printf_bonus.h
OBJS_BONUS = $(patsubst %.o, $(DIR_BONUS)/%.o, $(SRCS_BONUS:.c=.o))

.PHONY: clean fclean re

all: $(DIR_LIBFT) $(OBJS) $(HEADER)
	@rm -rf bonus $(NAME)
	@touch $@
	@cp $(DIR_LIBFT) $(LIBFT)
	ar rc $(LIBFT) $(OBJS)
	@mv $(LIBFT) $(NAME)

bonus: $(DIR_LIBFT) $(OBJS_BONUS) $(HEADER_BONUS)
	@rm -rf all $(NAME)
	@touch $@
	@cp $(DIR_LIBFT) $(LIBFT)
	ar rc $(LIBFT) $(OBJS_BONUS)
	@mv $(LIBFT) $(NAME)

clean:
	rm -f */*.o $(LIBFT) $(DIR_LIBFT) all bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): all

$(DIR_LIBFT):
	make -C libft/
	cp $(DIR_LIBFT) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# tests/bonus/Makefile

NAME = test_printf_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../../include -I../../libft/include

SRC = main_bonus.c
OBJ = $(SRC:.c=.o)

SRC_PRINTF_BONUS = \
	../../src_bonus/ft_printf_bonus.c \
	../../src_bonus/ft_parse_flags_bonus.c \
	../../src_bonus/ft_print_int_bonus.c \
	../../src_bonus/ft_print_utils_bonus.c \
	../../src_bonus/ft_parse_format_bonus.c

LIBFT_DIR = ../../libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(SRC_PRINTF_BONUS) $(LIBFT) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean $(NAME)

.PHONY: run clean fclean re

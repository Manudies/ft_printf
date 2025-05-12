# tests/Makefile

NAME = test_printf
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include -I../libft/include

SRC = main.c
OBJ = $(SRC:.c=.o)

SRC_PRINTF = ../src/ft_printf.c ../src/ft_print_char.c ../src/ft_print_str.c \
			../src/ft_print_int.c ../src/ft_print_unsigned.c ../src/ft_utoa.c \
			../src/ft_itoa_base.c ../src/ft_print_hex.c ../src/ft_print_ptr.c
LIBFT = ../libft/libft.a

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(OBJ) $(SRC_PRINTF) $(LIBFT) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ) $(NAME)

.PHONY: run clean

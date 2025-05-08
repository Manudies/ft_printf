# tests/Makefile

NAME = tester
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include -I../libft

SRC = main.c
OBJ = $(SRC:.c=.o)

SRC_PRINTF = ../src/ft_printf.c ../src/print_char.c
LIBFT = ../libft/libft.a

$(NAME): $(OBJ)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(OBJ) $(SRC_PRINTF) $(LIBFT) -o $(NAME)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ) $(NAME)

.PHONY: run clean

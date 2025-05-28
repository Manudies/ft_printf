# tests/Makefile

NAME		= test_printf
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I../../include -I../../libft/include

SRC			= main.c
OBJS		= $(SRC:.c=.o)

SRCS_DIR	= ../../src
LIBFT_DIR	= ../../libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC_FILES	= ft_printf.c ft_print_char.c ft_print_str.c ft_print_int.c \
			  ft_print_unsigned.c ft_utoa.c ft_itoa_base.c \
			  ft_print_hex.c ft_print_ptr.c

SRC_PATHS	= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(SRC_PATHS) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

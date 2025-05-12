# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/08 13:46:53 by mdiestre          #+#    #+#              #
#    Updated: 2025/05/12 14:06:00 by mdiestre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INCLUDES	= -Iinclude -Ilibft/include
SRCS_DIR	= src
OBJS_DIR	= obj
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC_FILES	= ft_printf.c ft_print_char.c ft_print_str.c ft_print_int.c \
			  ft_print_unsigned.c ft_utoa.c ft_itoa_base.c ft_print_hex.c \
			  ft_print_ptr.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR)
	$(AR) $(NAME) $(OBJS) $(LIBFT_A)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

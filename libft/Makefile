# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiestre <mdiestre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/05 10:41:07 by mdiestre          #+#    #+#              #
#    Updated: 2025/05/12 14:11:05 by mdiestre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

INCLUDES	= -Iinclude
SRCS_DIR	= src
OBJS_DIR	= obj

SRC_FILES	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
			  ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
			  ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			  ft_putendl_fd.c ft_putnbr_fd.c

BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			  ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			  ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

SRCS		= $(addprefix $(SRCS_DIR)/, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

BONUS_SRCS	= $(addprefix $(SRCS_DIR)/, $(BONUS_FILES))
BONUS_OBJS	= $(addprefix $(OBJS_DIR)/, $(BONUS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME) $(BONUS_OBJS)
	$(AR) $(NAME) $(BONUS_OBJS)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

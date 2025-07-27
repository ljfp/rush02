# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 13:00:50 by nponcin           #+#    #+#              #
#    Updated: 2025/07/27 17:08:25 by egalindo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES =	srcs/ft_putchar.c \
			srcs/check_args.c \
			srcs/convert_args.c \
			srcs/extract_word.c \
			srcs/main.c \
			srcs/print_big_unit.c \
			srcs/print_num.c \
			srcs/translate_arg.c \

HEADFILES =	includes/ft.h \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS += -Wall -Wextra -Werror -Iincludes

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean: 
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nponcin <nponcin@student.42barcelona.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 13:00:50 by nponcin           #+#    #+#              #
#    Updated: 2025/07/27 20:42:26 by lauferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = rush-02
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -fsanitize=address
SRCS_DIR= srcs
SRCS    = $(wildcard $(SRCS_DIR)/*.c)
OBJS    = $(patsubst $(SRCS_DIR)/%.c, %.o, $(SRCS))
RM      = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: $(SRCS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

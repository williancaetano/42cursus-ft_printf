# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wcaetano <wcaetano@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/06 20:23:44 by wcaetano          #+#    #+#              #
#    Updated: 2022/07/30 18:40:15 by wcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_printf.c ft_printf_utils.c

BONUS_SRCS := 

OBJS := $(SRCS:.c=.o)

BONUS_OBJS := $(BONUS_SRCS:.c=.o)

NAME := libftprintf.a

CFLAGS := -g -Wall -Wextra -Werror

CC := cc

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS) 
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

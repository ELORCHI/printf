# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 18:22:19 by eel-orch          #+#    #+#              #
#    Updated: 2020/03/03 05:29:05 by eel-orch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_find_flags.c ft_print_char.c ft_printf.c ft_print_hex.c ft_printf_u.c ft_printf_utils2.c \
	   ft_print_decimal.c ft_double_percent.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra -c $(SRCS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arlee <arlee@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 23:39:41 by aaaaaran          #+#    #+#              #
#    Updated: 2023/09/07 17:10:29 by arlee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
RM = rm -f 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
LIBFT		= libft

SRCS = \
		ft_printf.c \
		ft_printf_n.c \
		ft_printf_p.c \
		ft_printf_s.c \
		ft_printf_u.c \
		ft_printf_hex.c


OBJS =	$(SRCS:%.c=%.o)

OBJ_FILES =	$(OBJS)

all:	$(NAME)


$(NAME):	$(OBJ_FILES)
	$(AR) $@ $^



clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re:	fclean all

.PHONY :	all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaaaaran <aaaaaran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 23:39:41 by aaaaaran          #+#    #+#              #
#    Updated: 2023/08/29 00:46:46 by aaaaaran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
RM = rm -f 
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = 

OBJS =	$(SRCS:%.c=%.o)

OBJ_FILES =	$(OBJS)

all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	ar rcs $@ $^
//ar은 파일을 모아 라이브러리로 압축하는 명령어, rcs는 플래그
//$@ Target NAME
//$^ 현재 타겟이 의존하는 대상들의 전체 목록 (A complete list of audiences that the current target depends on)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)


re:	fclean all

.PHONY :	all clean fclean re

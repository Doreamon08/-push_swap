# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 20:57:13 by rabbie            #+#    #+#              #
#    Updated: 2022/02/15 21:53:25 by rabbie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c\
       init.c\
       radix_sorter.c\
       operations.c\
       helpers_for_operations.c\
       sorting_for_three.c\
       printer.c
              
HEADER = header.h

OBJ = $(SRCS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)\
       $(CC) $(CFLAGS) $(OBJ) $(NAME)

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all	
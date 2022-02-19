# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 20:57:13 by rabbie            #+#    #+#              #
#    Updated: 2022/02/20 00:14:58 by rabbie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRCS = push_swap.c\
       init.c\
       radix_sorter.c\
       operations.c\
       helpers_for_operations.c\
       sorting_for_three_or_five.c\
       inits_and_errors.c\
       ft_split.c\
       utils.c

SRCS_B = checker.c\
		init.c\
       	radix_sorter.c\
       	operations.c\
       	helpers_for_operations.c\
       	sorting_for_three_or_five.c\
       	inits_and_errors.c\
       	ft_split.c\
       	radix_sorter.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		gnl/get_nextline.h\
       	utils.c
              
HEADER = header.h

OBJ = $(SRCS:%.c=%.o)

OBJ_B $(SRCS_B:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)\
       $(CC) $(CFLAGS) $(OBJ) $(NAME)

bonus : $(NAME_BONUS)
		$(CC) $(CFLAGS) $(OBJ_B) $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re : fclean all	
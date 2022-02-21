# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabbie <rabbie@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/15 20:57:13 by rabbie            #+#    #+#              #
#    Updated: 2022/02/21 17:36:09 by rabbie           ###   ########.fr        #
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
	   gnl/get_next_line_utils.c\
       ft_split.c\
       utils.c

SRCS_B = checker.c\
		init.c\
       	operations.c\
       	helpers_for_operations.c\
       	sorting_for_three_or_five.c\
       	inits_and_errors.c\
       	ft_split.c\
       	radix_sorter.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		checker_utils.c\
       	utils.c
              
HEADER = header.h

OBJ = $(SRCS:.c=.o)

OBJ_B = $(SRCS_B:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJ_B)
	$(CC) $(CFLAGS) $(OBJ_B) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ) $(OBJ_B)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all
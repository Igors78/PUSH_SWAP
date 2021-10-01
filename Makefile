# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 08:09:21 by ioleinik          #+#    #+#              #
#    Updated: 2021/06/29 17:46:52 by ioleinik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

NAME		= push_swap
LIB_PATH	= ./libft
INCL_PATH	= /includes

LIBRARY		= libft.a

MAKE		= make

SRC			= main.c check_contract.c initialize.c fill_deck.c swap.c push.c \
				rotate.c reverse_rotate.c dispatch_sort.c sort_big.c \
				median.c

OBJ			= ${SRC:.c=.o}

all:		$(NAME)

$(LIBRARY):
			$(MAKE) -C $(LIB_PATH)

$(NAME):	$(OBJ) $(LIBRARY)
			$(CC) -I $(INCL_PATH) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft

push:		$(OBJ)
			$(CC) -I $(INCL_PATH) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIB_PATH) -lft

clean:		
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re push $(LIBRARY)
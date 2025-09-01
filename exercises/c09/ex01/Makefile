#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mklouf@student.hive.fi>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 13:50:23 by mkhlouf           #+#    #+#              #
#    Updated: 2024/08/22 13:50:49 by mkhlouf          ###   ########.fr        #
#                                                                              #
#******************************************************************************#
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
SRCS_FILLES =	srcs/ft_putchar.c \
	srcs/ft_swap.c \
	srcs/ft_putstr.c \
	srcs/ft_strlen.c \
	srcs/ft_strcmp.c \
OBJFILLES = $(SRCS_FILLES:.c=.o)
RM = rm -f
LIBFT = libft.a
all: $(LIBFT)
$(LIBFT): $(OBJFILLES)
	ar rcs $(LIBFT) $(OBJFILLES)
clean:
	$(RM) $(OBJFILLES)
fclean: clean
	$(RM) $(LIBFT)
re: fclean all

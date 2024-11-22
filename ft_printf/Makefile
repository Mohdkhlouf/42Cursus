# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:09:22 by mkhlouf           #+#    #+#              #
#    Updated: 2024/11/21 10:48:20 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
AR = ar rcs


# Files
NAME    = libftprintf.a
SRC     = ft_printf.c	ft_putchar.c	ft_putnbr_hex.c	ft_putptr.c	ft_putnbr.c	ft_putnbr_unsigned.c	ft_putstr.c
OBJ     = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Create static library
$(NAME): $(OBJ)
	$(AR) $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files only
clean:
	$(RM) *.o

# Clean all generated files
fclean: clean
	$(RM) $(NAME)

# it will delete and make again -Rebuild everything
re: fclean all

# Delete the rest - Declare that these targets are not files
.PHONY: all clean fclean re
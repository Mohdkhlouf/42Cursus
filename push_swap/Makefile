# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 10:36:17 by mkhlouf           #+#    #+#              #
#    Updated: 2025/01/23 14:22:40 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
AR      = ar rcs

# Subdirectories
PRINTF  := ./ft_printf
LIBFT   := ./libft

# Files
NAME    = push_swap
SRC     = stacka_funs.c validations.c arg_string.c push_swap.c \
          stackb_funs.c multi_args.c utils.c push_swap_utils.c \
		  more_than_3.c radix_utils.c push_swap_main_functions.c \
		  up_to_10.c

OBJS    = $(SRC:.c=.o)
LIBFT_A = $(LIBFT)/libft.a
PRINTF_A = $(PRINTF)/libftprintf.a

# Default target
all: $(NAME)

# Create executable
$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -o $(NAME)

# Build libft
$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

# Build ft_printf
$(PRINTF_A):
	$(MAKE) -C $(PRINTF)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files only
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(PRINTF) clean
	$(MAKE) -C $(LIBFT) clean

# Clean all generated files
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(PRINTF) fclean
	$(MAKE) -C $(LIBFT) fclean

# Rebuild everything
re: fclean all

# Declare that these targets are not files
.PHONY: all clean fclean re
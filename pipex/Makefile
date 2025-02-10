# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 10:36:17 by mkhlouf           #+#    #+#              #
#    Updated: 2025/02/10 09:53:54 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
AR      = ar rcs

# Subdirectories
LIBFT   := ./libft

# Files
NAME    = pipex
SRC     = pipex.c check_files.c check_command.c utils.c pipex_utils.c

OBJS    = $(SRC:.c=.o)
LIBFT_A = $(LIBFT)/libft.a

# Default target
all: $(NAME)

# Create executable
$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

# Build libft
$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files only
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT) clean

# Clean all generated files
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT) fclean

# Rebuild everything
re: fclean all

# Declare that these targets are not files
.PHONY: all clean fclean re
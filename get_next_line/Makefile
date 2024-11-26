# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 15:12:53 by mkhlouf           #+#    #+#              #
#    Updated: 2024/11/26 15:13:59 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
AR = ar rcs


# Files
NAME    = get_next_line.a
SRC     = get_next_line.c	get_next_line_utils.c
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
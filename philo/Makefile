# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 10:36:17 by mkhlouf           #+#    #+#              #
#    Updated: 2025/02/20 00:41:05 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f
AR      = ar rcs


# Files
NAME    = philo
SRC     = philo.c philo_utils.c monitor.c philo_fork_fns.c philo_routine.c 

OBJS    = $(SRC:.c=.o)

# Default target
all: $(NAME)

# Create executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files only
clean:
	$(RM) $(OBJS)

# Clean all generated files
fclean: clean
	$(RM) $(NAME)

# Rebuild everything
re: fclean all

# Declare that these targets are not files
.PHONY: all clean fclean re
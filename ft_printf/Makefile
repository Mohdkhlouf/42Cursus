# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 15:09:22 by mkhlouf           #+#    #+#              #
#    Updated: 2024/11/19 16:14:10 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME		= libftprintf.a
INCLUDE		= include
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I$(INCLUDE)
RM			= rm -f
AR			= ar rcs

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Source Files (including .c extension)
SRC_FILES	= ft_printf.c ft_putchar.c ft_putnbr_hex.c ft_putptr.c ft_strlen.c \
             ft_putnbr.c ft_putnbr_unsigned.c ft_putstr.c

# Create object and source paths
SRC 		= 	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

# Targets
OBJF		=	.cache_exists

# Default Target
all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

# Compile object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -c $< -o $@

# Create object directory if it doesn't exist
$(OBJF):
			@mkdir -p $(OBJ_DIR)

# Clean object files
clean:
			@$(RM) -rf $(OBJ_DIR)
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

# Full Clean (remove library and object files)
fclean:		clean
			@$(RM) -f $(NAME)
			@echo "$(CYAN)ft_printf library cleaned!$(DEF_COLOR)"

# Rebuild everything (clean and compile again)
re:			fclean all
			@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

# Check for code style with norminette
norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

# Declare all targets as phony (not actual files)
.PHONY:		all clean fclean re norm

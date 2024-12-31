# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhlouf <mkhlouf@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/31 19:40:47 by mkhlouf           #+#    #+#              #
#    Updated: 2024/12/31 19:59:04 by mkhlouf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
CC := cc
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast -fPIC \
	-I ./include -I ./mlx/include
LIBMLX := ./mlx
HEADERS = -I $(LIBMLX)/include/mlx
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS := draw_map.c game_utils.c map_validation.c path_validation.c \
	read_map.c read_map_utils2.c read_map_utils.c solong.c solong_utils.c \
	utils.c

OBJS := ${SRCS:.c=.o}
REPO_URL=https://github.com/codam-coding-college/MLX42.git
REPO_DIR=mlx

# Default target
all: clone libmlx $(NAME)

# Clone MLX42 repository if not already present
clone:
	@if [ ! -d "$(REPO_DIR)" ]; then \
		git clone $(REPO_URL) $(REPO_DIR); \
	else \
		echo "$(REPO_DIR) already exists."; \
	fi

# Build MLX42 library using cmake
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

# Rule to compile .c files to .o files
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

# Link the object files and create the executable
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)

# Clean object files and build directory
clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

# Clean everything (including executable)
fclean: clean
	@rm -rf $(NAME)

# Rebuild everything (clean and then build)
re: fclean all

# Phony targets to avoid filename conflicts
.PHONY: all clean fclean re clone libmlx
# Compiler
CC = gcc

# Flags
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iinclude -IMLX42/include
LFLAGS = -ldl -lglfw -pthread -lm

# MLX42
MLX42 = MLX42/build/libmlx42.a

# Target
NAME = minirt

# Source files
SRCS = main.c
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Build MLX if missing
$(MLX42):
	@echo "Compiling MLX42..."
	@if [ ! -d "MLX42" ]; then git clone https://github.com/codam-coding-college/MLX42.git; fi
	@(cd MLX42/ && cmake -B build && cmake --build build -j4)

# Link target
$(NAME): $(MLX42) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(MLX42) $(LFLAGS) -o $(NAME)

# Compile .c to .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re

# Compiler
CXX = c++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror

# NAME binary name
NAME = Scalar

# Source files
SRC = main.cpp ScalarConverter.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default NAME
all: $(NAME)

# Build the NAME from object files
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

# Compile each .cpp file to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(NAME)
	./$(NAME)

# Remove object files
clean:
	rm -f $(OBJ)

# Full clean: object files + binary
fclean: clean
	rm -f $(NAME) $(OBJ)

# Rebuild everything from scratch
re: fclean all

# Phony NAMEs
.PHONY: all run clean fclean re
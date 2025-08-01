# Compiler
CXX = c++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror

# Target binary name
NAME = Animal

# Source files
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp  WrongCat.cpp 

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(NAME)

# Build the target from object files
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

# Phony targets
.PHONY: all run clean fclean re
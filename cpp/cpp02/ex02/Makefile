# Compiler
CXX = c++

# Compilation flags
CXXFLAGS = -Wall -Wextra -Werror

# Target binary name
TARGET = Fixed

# Source files
SRC = main.cpp Fixed.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Build the target from object files
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile each .cpp file to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Remove object files
clean:
	rm -f $(OBJ)

# Full clean: object files + binary
fclean: clean
	rm -f $(TARGET) $(OBJ)

# Rebuild everything from scratch
re: fclean all

# Phony targets
.PHONY: all run clean fclean re
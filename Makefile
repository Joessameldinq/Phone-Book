## Variables

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = PhoneBookApp

CC = gcc 
CFLAGS = -Wall -Wextra  -std=c99

# Find all *.c files in the src directory
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Generate object files from source files
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SOURCES))

# Default target
all: dir $(BIN_DIR)/$(TARGET)

# Create directories
dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

# Link object files 
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo "Build complete: $(BIN_DIR)/$(TARGET)"

# Compile source file to object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean Build Files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@echo "Cleaned build artifacts"

# Run the program
run: all
	./$(BIN_DIR)/$(TARGET)

# Rebuild from scratch
rebuild: clean all

# Show help
help:
	@echo "Available targets"
	@echo "----------------------"
	@echo "  Phone Book Builder  "
	@echo "----------------------"
	@echo "  all      - Build the project (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run the program"
	@echo "  rebuild  - Clean and rebuild"
	@echo "  help     - Show this help message"

.PHONY: all dir clean run rebuild help
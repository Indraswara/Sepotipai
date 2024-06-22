# Recursive wildcard function definition
rwildcard=$(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

# Variables
CC := gcc
CFLAGS := -Wall -Wextra -g  # Adjust your desired compiler flags here

# Directories
SRC_BASE_DIR := ./src/code  # Adjust your base source directory
HEADER_BASE_DIR := ./src/header  # Adjust your base header directory
BIN_DIR := ./bin

# Targets
TARGET := main

# Find all source files recursively in SRC_BASE_DIR
SRC := $(call rwildcard,$(SRC_BASE_DIR),*.c)
# Generate object file paths in BIN_DIR
OBJ := $(patsubst $(SRC_BASE_DIR)/%.c,$(BIN_DIR)/%.o,$(SRC))

# Find all header files recursively in HEADER_BASE_DIR
HEADERS := $(call rwildcard,$(HEADER_BASE_DIR),*.h)

# Phony targets
.PHONY: all clean run

# Default target
all: $(BIN_DIR)/$(TARGET)

# Run target
run: $(BIN_DIR)/$(TARGET)
	$(BIN_DIR)/$(TARGET)

# Rule to compile object files
$(BIN_DIR)/%.o: $(SRC_BASE_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the main executable
$(BIN_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Clean target
clean:
	rm -rf $(BIN_DIR)/*


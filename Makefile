# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Directories
SRC_DIR = src
BUILD_DIR = build

# Use pkg-config to get SFML flags
PKG_CONFIG = pkg-config
SFML_CFLAGS = $(shell $(PKG_CONFIG) --cflags sfml-window sfml-graphics sfml-system sfml-audio sfml-network)
SFML_LIBS = $(shell $(PKG_CONFIG) --libs sfml-window sfml-graphics sfml-system sfml-audio sfml-network)

# Source files and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SOURCES))

# Executable
EXECUTABLE = $(BUILD_DIR)/basktlo.o

# Default target
all: $(EXECUTABLE)

# Link the object files and create the executable
$(EXECUTABLE): $(OBJECTS) | $(BUILD_DIR)
	$(CXX) $(OBJECTS) -o $@ $(SFML_LIBS)

# Compile the source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SFML_CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean the build directory
clean:
	rm -rf $(BUILD_DIR)


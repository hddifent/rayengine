LIB_NAME = rayengine

# Target for static library
STATIC_LIB = lib$(LIB_NAME).a

# Directories
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = headers
RAYLIB_PATH = C:/raylib/raylib

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -O2 -I$(INC_DIR) -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/external

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(STATIC_LIB)

# Build static library
$(STATIC_LIB): $(OBJS)
	ar rcs $@ $^
	ranlib $@

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(STATIC_LIB)

# Phony targets
.PHONY: all clean
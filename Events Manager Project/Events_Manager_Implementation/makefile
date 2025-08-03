# Target name
TARGET_EXEC := final_program

# Directory paths
BUILD_DIR := build
SRC_DIR := src
INC_DIR := inc

# Find all .cpp source files recursively in the src directory
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')

# Generate object files in the build directory, mirroring the src structure
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Generate dependency files
DEPS := $(OBJS:.o=.d)

# Include flags (for -I)
INC_FLAGS := -I$(INC_DIR)

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -O2
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# Link all object files into the final executable
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

# Compile each .cpp file to a .o object in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# Clean target
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

# Include dependency files
-include $(DEPS)

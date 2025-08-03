TARGET_EXEC := final_program

BUILD_DIR := ./build
SRC_DIRS := .

# Windows-friendly source detection
SRCS := $(wildcard *.cpp)

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := .
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CXX := g++
CXXFLAGS := -Wall -Wextra -O2
CPPFLAGS := $(INC_FLAGS) -MMD -MP

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)

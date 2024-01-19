# compilation implicit rules
CXX         := g++
CXXFLAGS    := -Wall -Wextra -std=c++17

# build instructions: where to compile the final binary and its name
BUILD_DIR   := ./bin
BUILD_FILE  := to-do

# source (.cpp) files and header files
SRC_DIR     := ./src
SRCS        := $(shell find $(SRC_DIR) -name '*.cpp')
INCLUDE_DIR := ./include

# run all rules
.PHONY: all
all: clean $(BUILD_DIR)/$(BUILD_FILE)

# task to delete all target outputs
.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/*

# compiling the source code
$(BUILD_DIR)/$(BUILD_FILE): $(SRCS)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) $^ -o $@

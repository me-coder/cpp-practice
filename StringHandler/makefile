# Makefile for CStringHandler project on Alpine Linux
MKDIR_P = mkdir -p

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -std=c++14 -I./headers -fPIC

# Debug flag (can be enabled/disabled)
DEBUG_FLAGS := -g

# Source and object files
SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=obj/%.o)

# Executable name
TARGET := bin/string_handler
DEBUG_TARGET := $(TARGET)

# Default target
all: run

prepare:
	${MKDIR_P} bin
	${MKDIR_P} obj

#Release build
release: clean prepare build_release

build_release: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

#Debug build
debug: clean prepare build_debug

build_debug: $(DEBUG_TARGET)

$(DEBUG_TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -o $(DEBUG_TARGET) $(OBJS)

# Compile source files to object files
obj/%.o: src/%.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -rf $(OBJS) $(TARGET) $(DEBUG_TARGET) bin obj

# Phony targets
.PHONY: all clean build debug release run run_debug

# Example run targets
run: release
	./$(TARGET)

run_debug: debug
	./$(DEBUG_TARGET)

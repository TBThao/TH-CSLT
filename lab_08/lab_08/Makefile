# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -g -I linked_list_helper -I double_linked_list_helper -I stack_queue_helper

# Name of execution file
TARGET = main

# List of source files
SRC = main.cpp linked_list_helper/linked_list.cpp double_linked_list_helper/double_linked_list.cpp stack_queue_helper/stack_queue.cpp

# Default command
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean command
clean:
	rm -f $(TARGET)

# Compile and run command
run: all
	./$(TARGET)

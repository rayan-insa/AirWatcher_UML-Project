# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -Wall -Werror -std=c++17

# Libraries
LIBS = -lm

# Executable name
TARGET = AirWatcher

# Source directories
SRC_DIRS = metier controller model view

# Source files
SRCS = $(wildcard $(addsuffix /*.cpp,$(SRC_DIRS))) main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)
	@echo "Compilation successful. Executable $(TARGET) created."
	@$(MAKE) clean_o

# Rule to link object files and create the executable
$(TARGET): $(OBJS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Pattern rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(addprefix -I,$(SRC_DIRS))

# Rule to clean up object files
clean_o:
ifeq ($(OS),Windows_NT)
	del /f /q *.o
else
	rm -f *.o
endif

# Phony targets
.PHONY: all clean_o

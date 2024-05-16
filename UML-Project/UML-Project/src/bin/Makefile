# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -Wall -Werror -std=c++17

# Executable name
TARGET = AirWatcher

# Source files
SRCS = Attribut.cpp Capteur.cpp Fournisseur.cpp Gouvernement.cpp Mesure.cpp main.cpp \
       Model.cpp View.cpp Particulier.cpp Controller.cpp Cleaner.cpp Utilisateur.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)
	@echo "Compilation successful. Executable $(TARGET) created."
	@$(MAKE) clean_o

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Pattern rule to compile source files into object files
%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Special rule for main.o
main.o: main.cpp $(wildcard *.h)
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Rule to clean up object files
clean_o:
ifeq ($(OS),Windows_NT)
	del /f /q *.o
else
	rm -f *.o
endif


# Phony targets
.PHONY: all clean_o

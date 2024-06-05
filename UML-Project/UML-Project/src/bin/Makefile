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
SRCS = main.cpp \
          ./metier/Attribut.cpp \
          ./metier/Capteur.cpp \
          ./metier/Cleaner.cpp \
          ./metier/Fournisseur.cpp \
          ./metier/Gouvernement.cpp \
          ./metier/Mesure.cpp \
          ./metier/Particulier.cpp \
          ./metier/Utilisateur.cpp \
          ./controller/Controller.cpp \
          ./model/Model.cpp \
          ./view/View.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)
	@echo "Compilation successful. Executable $(TARGET) created."
	@$(MAKE) clean_o

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Pattern rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(addprefix -I,$(SRC_DIRS))

# Rule to clean object files
clean_o:
ifeq ($(OS),Windows_NT)
	del /f /q metier\Attribut.o metier\Capteur.o metier\Cleaner.o metier\Fournisseur.o metier\Gouvernement.o metier\Mesure.o metier\Particulier.o metier\Utilisateur.o controller\Controller.o model\Model.o view\View.o main.o
else
	rm -f $(OBJS) main.o
endif

# Rule to clean everything
clean: clean_o
ifeq ($(OS),Windows_NT)
	del /f /q $(TARGET)
else
	rm -f $(TARGET)
endif

# Phony targets
.PHONY: all clean_o clean

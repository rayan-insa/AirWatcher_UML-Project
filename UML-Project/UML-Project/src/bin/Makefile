# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -Wall -Werror

# Executable name
TARGET = AirWatcher

# Source files
SRCS = Attribut.cpp Capteur.cpp Fournisseur.cpp Gouvernement.cpp Mesure.cpp main.cpp \
       Model.cpp View.cpp Particulier.cpp Controller.cpp Cleaner.cpp Utilisateur.cpp

# Header files
HDRS = Attribut.h Capteur.h Fournisseur.h Gouvernement.h Mesure.h \
       Model.h View.h Particulier.h Controller.h Cleaner.h Utilisateur.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)
	@echo "Compilation successful. Executable $(TARGET) created."

# Rule to link object files and create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rules to compile source files into object files with dependencies on headers
Attribut.o: Attribut.cpp Attribut.h
	$(CXX) $(CXXFLAGS) -c Attribut.cpp -o Attribut.o

Capteur.o: Capteur.cpp Capteur.h
	$(CXX) $(CXXFLAGS) -c Capteur.cpp -o Capteur.o

Fournisseur.o: Fournisseur.cpp Fournisseur.h
	$(CXX) $(CXXFLAGS) -c Fournisseur.cpp -o Fournisseur.o

Gouvernement.o: Gouvernement.cpp Gouvernement.h Utilisateur.h
	$(CXX) $(CXXFLAGS) -c Gouvernement.cpp -o Gouvernement.o

Mesure.o: Mesure.cpp Mesure.h
	$(CXX) $(CXXFLAGS) -c Mesure.cpp -o Mesure.o

Model.o: Model.cpp Model.h Gouvernement.h Particulier.h Capteur.h Cleaner.h Fournisseur.h Controller.h
	$(CXX) $(CXXFLAGS) -c Model.cpp -o Model.o

View.o: View.cpp View.h Controller.h
	$(CXX) $(CXXFLAGS) -c View.cpp -o View.o

Particulier.o: Particulier.cpp Particulier.h Utilisateur.h
	$(CXX) $(CXXFLAGS) -c Particulier.cpp -o Particulier.o

Controller.o: Controller.cpp Controller.h View.h Model.h
	$(CXX) $(CXXFLAGS) -c Controller.cpp -o Controller.o

Cleaner.o: Cleaner.cpp Cleaner.h
	$(CXX) $(CXXFLAGS) -c Cleaner.cpp -o Cleaner.o

Utilisateur.o: Utilisateur.cpp Utilisateur.h
	$(CXX) $(CXXFLAGS) -c Utilisateur.cpp -o Utilisateur.o

main.o: main.cpp Attribut.h Capteur.h Fournisseur.h Gouvernement.h Mesure.h \
                 Model.h View.h Particulier.h Controller.h Cleaner.h Utilisateur.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o


# Phony targets
.PHONY: all clean_o

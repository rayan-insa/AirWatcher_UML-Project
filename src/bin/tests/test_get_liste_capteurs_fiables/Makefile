CXX = g++
CXXFLAGS = -I../../metier -I../../model -I../../controller -I../../view -I../ -std=c++11 

# Liste des fichiers sources
SOURCES = un_capteur_defaillant.cpp \
          ../../metier/Attribut.cpp \
          ../../metier/Capteur.cpp \
          ../../metier/Cleaner.cpp \
          ../../metier/Fournisseur.cpp \
          ../../metier/Gouvernement.cpp \
          ../../metier/Mesure.cpp \
          ../../metier/Particulier.cpp \
          ../../metier/Utilisateur.cpp \
          ../../controller/Controller.cpp \
          ../../model/Model.cpp \
          ../../view/View.cpp

# Liste des fichiers objets
OBJECTS = $(SOURCES:.cpp=.o)

# Nom de l'exécutable
TARGET = test_capteur_defaillant

# Règle par défaut
all: $(TARGET)
	@echo "Compilation successful. Executable $(TARGET) created."

# Règle pour créer l'exécutable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Règle pour compiler les fichiers sources en fichiers objets
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


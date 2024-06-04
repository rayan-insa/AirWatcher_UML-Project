CXX = g++
CXXFLAGS = -I../../metier -I../../model -I../ -std=c++11

TARGETS = aucun_capteur_defaillant un_capteur_defaillant

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

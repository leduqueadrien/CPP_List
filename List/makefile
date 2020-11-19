
SRC=$(wildcard src/*.cpp) $(wildcard src/testsUnitaire/*.cpp) $(wildcard src/Exception/*.cpp)

CXX = c++

OBJTests = $(addprefix build/, $(SRC:.cpp=.o))
DEP = $(addprefix build/, $(SRC:.cpp=.d))

# options de compilation et d'edition des liens
CXXFLAGS = -Wall -Wextra -MMD -g -O2
LDFLAGS = #-lSDL

#.PHONY: all
all: exc
	@echo " executable disponible"

# edition des liens, executable tests
exc: $(OBJTests)
	@mkdir -p $(@D) #creer le dossier bin, sil nexiste pas
	$(CXX) -o $@ $^ $(LDFLAGS)

# genere les fichiers .o (dans build) a partir des fichiers .cpp (dans src) du meme nom
# compilation
build/%.o: %.cpp
	@mkdir -p $(@D)  #creer le dossier build sil nexiste pas
	$(CXX) -c $< $(CXXFLAGS) -o $@

.PHONY: clean
clean:
	rm -rf build core *.gch
	rm -rf bin

-include $(DEP)
CXX		  := g++
CXX_FLAGS := -std=c++14 -ggdb #-Wall -Wextra

all: maquina bin/teste

clean:
	rm -rf bin/*

run: bin/main
	clear
	./bin/main

maquina: bin/main.o bin/display.o bin/query.o bin/term.o bin/coord.o bin/doc.o bin/index.o bin/files.o bin/searchEngine.o 
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/main.o: src/main.cpp 
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/query.o: src/query.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/term.o: src/term.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/coord.o: src/coord.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/doc.o: src/doc.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/index.o: src/index.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/files.o: src/files.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/searchEngine.o: src/searchEngine.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/display.o: src/display.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/teste: bin/display.o bin/query.o bin/term.o bin/coord.o bin/doc.o bin/index.o bin/files.o bin/searchEngine.o src/app.teste.cpp
	${CXX} ${CXX_FLAGS} -I src/ $^ -o $@
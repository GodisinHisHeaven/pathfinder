CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++11 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)


all: bin/exec
exec: bin/exec
tests: bin/tests

bin/exec: ./src/Graph.cpp ./src/GraphReader.cpp ./src/Visualize.cpp ./src/main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: ./tests/test_BFS.cpp obj/catch.o ./src/Graph.cpp ./src/GraphReader.cpp ./src/Visualize.cpp ./tests/test_visualization.cpp ./cs225/PNG.cpp ./cs225/HSLAPixel.cpp ./cs225/lodepng/lodepng.cpp ./tests/test_data_parsing.cpp ./tests/test_Dijkstra.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/catch.o: catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.DEFAULT_GOAL := tests
.PHONY: clean tests exec

clean:
	rm -fr bin/* obj/*

CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++11 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)


all: bin/exec
exec: bin/exec
tests: bin/tests

bin/exec: ./src/Graph.cpp ./src/GraphReader.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

bin/tests: ./tests/test_data_parsing.cpp obj/catch.o ./src/Graph.cpp ./src/GraphReader.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

obj/catch.o: catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.DEFAULT_GOAL := tests
.PHONY: clean tests exec

clean:
	rm -fr bin/* obj/*

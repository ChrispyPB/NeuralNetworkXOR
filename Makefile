.PHONY: build

build:
	clang++-5.0 -o build/neuralxor -std=c++17 -g -lboost_program_options src/*.cpp
run:
	./build/neuralxor -v

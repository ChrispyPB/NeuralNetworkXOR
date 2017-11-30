.PHONY: build
build17:
	g++ -o build/nnxor17 -std=c++17 -g *.cpp

build14:
	g++ -o build/nnxor14 -std=c++14 -g *.cpp

run:
	# $(MAKE) build
	./build/nnxor

# runo:
# 	[ -f build/nnxor ] && ./build/nnxor

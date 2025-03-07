CXX = g++
CXXFLAGS = -Wall -std=c++98
CXXDEBUGFLAGS = = -ggdb -fsanitize=address -fsanitize=undefined
CXXFILES = main.cpp

TARGETS = debug main

.PHONY: all fresh clean

main:
	$(info Building $@)
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)

debug:
	$(info Building debug $@)
	$(CXX) $(CXXFLAGS) $(CXXDEBUGFLAGS) -ggdb -o $@.out $(CXXFILES)

clean: 
	rm -f ./glitch-and-glory.out ./debug.out
	$(info Cleaned project)


fresh:
	clean all


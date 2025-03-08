CXX = g++
CXXFLAGS = -Wall -std=c++11
CXXDEBUGFLAGS = -ggdb -fsanitize=address -fsanitize=undefined
# CXXFILES = main.cpp
CXXFILES = main.cpp LogicLayer/BattleLogic.cpp LogicLayer/LogicWrapper.cpp UILayer/UIHandler.cpp UILayer/IOHandler.cpp


TARGETS = debug main

.PHONY: all fresh clean

main:
	$(info Building $@)
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)

debug:clean
	$(info Building debug $@)
	$(CXX) $(CXXFLAGS) $(CXXDEBUGFLAGS) -ggdb -o $@.out $(CXXFILES)
	gdb ./debug.out

run:clean
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)
	./glitch-and-glory.out

clean: 
	rm -f ./glitch-and-glory.out ./debug.out
	$(info Cleaned project)


fresh:
	clean all


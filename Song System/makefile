CXX = g++
CXXFLAGS = -g -Wall -Wextra

.PHONY : all clean
all : songSystem test

songSystem : hashTable.o list.o node.o track.o songSystem.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

test : hashTable.o list.o node.o track.o testCases.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

hashTable.o : hashTable.cpp hashTable.hpp
	$(CXX) $(CXXFLAGS) -c $<

list.o : list.cpp list.hpp
	$(CXX) $(CXXFLAGS) -c $<

node.o : node.cpp node.hpp
	$(CXX) $(CXXFLAGS) -c $<

track.o : track.cpp track.hpp
	$(CXX) $(CXXFLAGS) -c $<

clean :
	rm *.o
	rm *.exe
# Variables to control Makefile operation
CXX = g++
CXXFLAGS = -Wall -g
RM = rm -f

# ****************************************************
# Targets needed to bring the executable up to date
main: main.o figures.o chess.o
	$(CXX) $(CXXFLAGS) -o main main.o figures.o chess.o

# The main.o target can be written more simply
main.o: main.cpp figures.h chess.h
	$(CXX) $(CXXFLAGS) -c main.cpp

figures.o: figures.h

chess.o: chess.h figures.h

clean: 
	$(RM) main test *.o

test: test.o figures.o chess.o
	$(CXX) $(CXXFLAGS) -o test test.o figures.o chess.o -L/opt/gtest/lib -lgtest -lgtest_main -lpthread

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -I/opt/gtest/include
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
	$(RM) main *.o
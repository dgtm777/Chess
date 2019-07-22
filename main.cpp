#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

// Testing

class Figure {
public:
	Figure() {}
	virtual bool check_turn() { return true; }
};

class Pawn : public Figure {
public:
	bool check_turn() {
		// ...
	}
	void become_new_figure() {}
};

class Horse : public Figure {
public:
	bool check_turn() {
		// ...
	}
};

class Chess {
	void make_turn();
	void print_field();
	Figure* field[8][8];
public:
	void start_game();
	Chess() {
		Figure* pb1 = new Pawn();
		Figure* pb2 = new Horse();
		field[0][0] = pb1;
		field[0][1] = pb2;
	}
};

int main()
{

	return 0;
}
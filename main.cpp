#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Figure {
public:
	string color;
	int line;
	int column;
//	Figure() {}
	virtual bool check_turn(Figure* next) { return true; }
	bool check_turn_general(int, int, Figure*);
	string name;
};
Figure* field[8][8];
bool Figure::check_turn_general(int col, int lin, Figure* next) {
	if (next->column < column) col = -col;
	if (next->line < line) lin = -lin;
	for (int i = col, j = lin; column + i < next->column; i += col, j += lin) {
		if (field[line + j][column + i]->name != "0") return 0;
	}
	return 1;
}
class Pawn : public Figure {
public:
	Pawn() {
		name = "P";
	}
	bool check_turn(Figure* next) {
		if (column == next->column && line == next->line) { cout << "You do not move"; return 0; }
		if (color == next->color) {
			cout << "There are your figure" << endl;
			return 0;
		}
		if (color == "black") {
			if (!(next->column < 7 && column >= 0 && next->line < 8 && line >= 0)) {
				return false;
			}
			if (column == next->column) {
				if (next -> line - line == 1) {
					if (next->line == 0) become_new_figure();
					return true;
				}
				if (line == 1 && next -> line == 3) {
					if (field[2][column]->color == "empty") {
						if (next->line == 0) become_new_figure();
						return true;
					}
				}
			}
			if (abs(next->column - column) == 1 && next->line - line == 1) {
				return true;
			}
		}
		if (color == "white") {
			if (!(next->column < 8 && column > 0 && next->line < 8 && line > 0)) {
				return false;
			}
			if (column == next->column) {
				if (line - next->line == 1) {
					if (next->line == 7) become_new_figure();
					return true;
				}
				if (line == 6 && next->line == 4) {
					if (field[5][column]->color == "empty") {
						if (next->line == 7) become_new_figure();
						return true;
					}
				}
			}
			if (abs(next->column - column) == 1 && line - next->line == 1) {
				return true;
			}
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	void become_new_figure() { //why is not working?
		string figure;
		cout << "choose your new figure" << endl;
		cin >> figure;
		string color = field[line][column]->color;
		string name;
		delete field[line][column];
		if (figure == "Rook") { field[line][column] = new Rook(); name = "R"; }
		else if (figure == "Horse") { field[line][column] = new Horse(); name = "H"; }
		else if (figure == "Elephant") { field[line][column] = new Elephant(); name = "E"; }
		else if (figure == "Queen") { field[line][column] = new Queen(); name = "Q"; }
		else cout << "you can not choose this one";
		field[line][column]-> name = name;
		field[line][column]-> color = color;
		field[line][column]-> line = line;
		field[line][column]-> column = column;
	}
};

class Rook : public Figure {
public:
	Rook() {
		name = "R";
	}
	bool check_turn(Figure* next) {
		if (column == next->column && line == next->line) { cout << "You do not move"; return 0; }
		if (color == next->color) {cout << "There are your figure" << endl; return 0;}
		if (!(next->column < 8 && column >= 0 && next->line < 8 && line >= 0)) {
			cout << "the move is not correct" << endl;
			return false;
		}
		if (column == next->column) {
			if (check_turn_general(0, 1, next)) return 1;
		}
		if (line == next->line) {
			if (check_turn_general(1, 0, next)) return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
};
class Horse : public Figure {
public:
	Horse() {
		name = "H";
	}
	bool check_turn(Figure* next) {
		if (column == next->column && line == next->line) { cout << "You do not move"; return 0; }
		if (color == next->color) { cout << "There are your figure" << endl; return 0; }
		if (!(next->column < 8 && column >= 0 && next->line < 8 && line >= 0)) {
			cout << "the move is not correct" << endl;
			return false;
		}
		if ((abs(column - next->column) == 2 && abs(line-next->line) == 1) ||
			(abs(column - next->column) == 1 && abs(line - next->line) == 2)) {
				return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
};
class Elephant : public Figure {
public:
	Elephant() {
		name = "E";
	}
	bool check_turn(Figure* next) {
		if (column == next->column && line == next->line) { cout << "You do not move"; return 0; }
		if (color == next->color) { cout << "There are your figure" << endl; return 0; }
		if (!(next->column < 8 && column >= 0 && next->line < 8 && line >= 0)) {
			cout << "the move is not correct" << endl;
			return false;
		}
		if (abs(column - next->column) == abs(line - next->line)) {
			if (check_turn_general(1, 1, next)) return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
};
class King : public Figure {
public:
	King(){
		name = "K";
	}
	bool check_turn(Figure* next) {
		if (column == next->column && line == next->line) { cout << "You do not move"; return 0; }
		if (color == next->color) { cout << "There are your figure" << endl; return 0; }
		if (!(next->column < 8 && column >= 0 && next->line < 8 && line >= 0)) {
			cout << "the move is not correct" << endl;
			return 0;
		}
		if (abs(column - next->column) < 2 && abs(line - next->line) < 2) {
			return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
};
class Queen : public Figure {
public:
	Queen(){
		name = "Q";
	}
	bool check_turn(Figure* next) {
		if (column == next->column && line == next->line) { cout << "You do not move"; return 0; }
		if (color == next->color) { cout << "There are your figure" << endl; return 0; }
		if (!(next->column <= 8 && column > 0 && next->line < 8 && line >= 0)) {
			cout << "the move is not correct" << endl;
			return 0;
		}
		if (column == next->column) {
			if (check_turn_general(0, 1, next)) return 1;
		}
		if (line == next->line) {
			if (check_turn_general(1, 0, next)) return 1;
		}
		if (abs(column - next->column) == abs(line - next->line)) {
			if (check_turn_general(1, 1, next)) return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
};
class Empty : public Figure {
public:
	Empty() {
		name = "0";
	}
	bool check_turn(Figure* next) {
		cout << "the cell is empty";
		return 0;
	}
};
class Chess {
//	void make_turn();
	void print_field();
public:
	void start_game();
	Chess() {
		for (int i = 0; i < 8; i++) {
			field[6][i] = new Pawn();
			field[6][i]-> line = 6;
			field[6][i]-> column = i;
			field[6][i]-> color = "white";
			field[1][i] = new Pawn();
			field[1][i]-> line = 1;
			field[1][i]-> column = i;
			field[1][i]-> color = "black";
		}
		field[7][0] = new Rook();
		field[7][1] = new Horse();
		field[7][2] = new Elephant();
		field[7][3] = new Queen();
		field[7][4] = new King();
		field[7][5] = new Elephant();
		field[7][6] = new Horse();
		field[7][7] = new Rook();
		field[0][0] = new Rook();
		field[0][1] = new Horse();
		field[0][2] = new Elephant();
		field[0][3] = new Queen();
		field[0][4] = new King();
		field[0][5] = new Elephant();
		field[0][6] = new Horse();
		field[0][7] = new Rook();
		for (int i = 0; i < 8; i++) {
			field[7][i] -> color = "white";
			field[7][i] -> line = 7;
			field[7][i] -> column = i;
			field[0][i] -> color = "black";
			field[0][i] -> line = 0;
			field[0][i] -> column = i;
		}
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < 8; j++) {
				field[i][j] = new Empty();
				field[i][j] -> line = i;
				field[i][j] -> column = j;
				field[i][j] -> color = "empty";
			}
		}
	}
};

//void Chess::make_turn() {
//}
void Chess::start_game() {
	int linet, linen;
	int columnt, columnn;
	string check = "white";
	string keep = "black";
	while (true) {
		print_field();
		cin >> linet >> columnt >> linen >> columnn;
		if (check == field[linet][columnt]->color) {
			if (field[linet][columnt]->check_turn(field[linen][columnn])) {
				delete field[linen][columnn];
				field[linen][columnn] = field[linet][columnt];
				field[linen][columnn]->line = linen;
				field[linen][columnn]->column = columnn;

				field[linet][columnt] = new Empty();
				field[linet][columnt]->line = linet;
				field[linet][columnt]->column = columnt;
				field[linet][columnt]->name = "0";
				field[linet][columnt]->color = "empty";
				swap(check, keep);
			}
		}
		else cout << "It is not your turn" << endl;
	}
}
void Chess::print_field() {
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
		for (int j = 0; j < 8; j++) {
			cout << field[i][j]->name;
			if (field[i][j]->color == "white") cout << "w";
			else if(field[i][j]->color == "black") cout << "b";
			else cout << 0;
			cout << " ";
		}
		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < 8; i++) cout << i << "  ";
	cout << endl;
}
int main()
{
	Chess a;
	a.start_game();
	system("pause");
	return 0;
}
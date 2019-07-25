#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Figure {
	int row, col;
	int row_turn, col_turn;
	char color;
public:	
	Figure(int st_row, int st_col, char st_color) {
		row = st_row;
		col = st_col;
		color = st_color;
		row_turn = col_turn = 0;
	}
	virtual bool check_turn(int dst_row, int dst_col, char dst_color) {
	/*	if (dst_row < col) col_turn = -col_turn;
		if (dst_row < row) row_turn = -row_turn;
		for (int i = col_turn, j = row_turn; col_turn + i < dst_col; i += col_turn, j += row_turn) {
			if (field[row + j][col + i]->name != "0") return 0;
		}
		return 1;*/
		return true;
		// TODO: make check based on row_turn, col_turn
	}
	char get_color() const {
		return color;
	}
	char get_row() const {
		return row;
	}
	char get_col() const {
		return col;
	}
	void change_row(int row_n) {
		row = row_n;
	}
	void change_col(int col_n)  {
		col = col_n;
	}
	virtual char to_char() const = 0;
};

class Pawn : public Figure {
public:
	Pawn(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {
		// TODO: define row_turn, col_turn
	}
	bool check_turn(int dst_row, int dst_col, char dst_color) {
		if (get_col() == dst_col && get_row() == dst_row) { cout << "You do not move" << endl; return 0; }
		if (get_color() == dst_color) {cout << "There are your figure" << endl; return 0;}
		if (get_color() == 'b') {
			if (!(dst_col < 7 && get_col() >= 0 && dst_row < 8 && get_row() >= 0)) {
				return false;
			}
			if (get_col() == dst_col) {
				if (dst_row - get_row() == 1) {
//					if (dst_row == 0) become_new_figure();
					return true;
				}
				if (get_row() == 1 && dst_row == 3) {
//					if (field[2][col]->color == "empty") {
//						if (dst_row == 0) become_new_figure();
						return true;
	//				}
				}
			}
			if (abs(dst_col - get_col()) == 1 && dst_row - get_row() == 1 && dst_color == 'w') {
				return true;
			}
		}
		if (get_color() == 'w') {
			if (!(dst_col < 8 && get_col() > 0 && dst_row < 8 && get_row() > 0)) {
				return false;
			}
			if (get_col() == dst_col) {
				if (get_row() - dst_row == 1) {
	//				if (dst_row == 7) become_new_figure();
					return true;
				}
				if (get_row() == 6 && dst_row == 4) {
	//				if (field[5][col]->get_color() == "empty") {
	//					if (dst_row == 7) become_new_figure();
						return true;
//					}
				}
			}
			if (abs(dst_col - get_col()) == 1 && get_row() - dst_row == 1 && dst_color == 'b') {
				return true;
			}
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	char to_char() const {
		return 'P';
	}
};
class Rook : public Figure {
public:
	Rook(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}
	bool check_turn(int dst_row, int dst_col, char dst_color) const {
		if (get_col() == dst_col && get_row() == dst_row) { cout << "You do not move"; return 0; }
		if (get_color() == dst_color) { cout << "There are your figure" << endl; return 0; }
		if (!(dst_col < 8 && get_col() >= 0 && dst_row < 8 && get_row() >= 0)) {
			cout << "the move is not correct" << endl;
			return false;
		}
		if (get_col() == dst_col) {
//			if (check_turn_general(0, 1, next)) 
			return 1;
		}
		if (get_row() == dst_row) {
//			if (check_turn_general(1, 0, next)) 
			return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	char to_char() const {
		return 'R';
	}
};
class Horse : public Figure {
public:
	Horse(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}
	bool check_turn(int dst_row, int dst_col, char dst_color) const {
		if (get_col() == dst_col && get_row() == dst_row) { cout << "You do not move"; return 0; }
		if (get_color() == dst_color) { cout << "There are your figure" << endl; return 0; }
		if (!(dst_col < 8 && get_col() >= 0 && dst_row < 8 && get_row() >= 0)) {
			cout << "the move is not correct" << endl;
			return false;
		}
		if ((abs(get_col() - dst_col) == 2 && abs(get_row() - dst_row) == 1) ||
			(abs(get_col() - dst_col) == 1 && abs(get_row() - dst_row) == 2)) {
			return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	char to_char() const {
		return 'H';
	}
};
class Elephant : public Figure {
public:
	Elephant(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}
	bool check_turn(int dst_row, int dst_col, char dst_color) const {
		if (get_col() == dst_col && get_row() == dst_row) { cout << "You do not move"; return 0; }
		if (get_color() == dst_color) { cout << "There are your figure" << endl; return 0; }
		if (!(dst_col < 8 && get_col() >= 0 && dst_row < 8 && get_row() >= 0)) {
			cout << "the move is not correct" << endl;
			return false;
		}
		if (get_col() == dst_col) {
			//			if (check_turn_general(0, 1, next)) 
			return 1;
		}
		if (get_row() == dst_row) {
			//			if (check_turn_general(1, 0, next)) 
			return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	char to_char() const {
		return 'E';
	}
};
class Queen : public Figure {
public:
	Queen(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}
	bool check_turn(int dst_row, int dst_col, char dst_color) const {
		if (get_col() == dst_col && get_row() == dst_row) { cout << "You do not move"; return 0; }
		if (get_color() == dst_color) { cout << "There are your figure" << endl; return 0; }
		if (!(dst_col <= 8 && get_col() > 0 && dst_row < 8 && get_row() >= 0)) {
			cout << "the move is not correct" << endl;
			return 0;
		}
		if (get_col() == dst_col) {
//			if (check_turn_general(0, 1, next)) 
				return 1;
		}
		if (get_row() == dst_row) {
//			if (check_turn_general(1, 0, next)) 
			return 1;
		}
		if (abs(get_col() - dst_col) == abs(get_row() - dst_row)) {
//			if (check_turn_general(1, 1, next)) 
			return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	char to_char() const {
		return 'Q';
	}
};
class King : public Figure {
public:
	King(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}
	bool check_turn(int dst_row, int dst_col, char dst_color) const {
		if (get_col() == dst_col && get_row() == dst_row) { cout << "You do not move"; return 0; }
		if (get_color() == dst_color) { cout << "There are your figure" << endl; return 0; }
		if (!(dst_col < 8 && get_col() >= 0 && dst_row < 8 && get_row() >= 0)) {
			cout << "the move is not correct" << endl;
			return 0;
		}
		if (abs(get_col() - dst_col) < 2 && abs(get_row() - dst_row) < 2) {
			return 1;
		}
		cout << "the move is not correct" << endl;
		return 0;
	}
	char to_char() const {
		return 'K';
	}
};


class Chess {
	bool make_turn(char cur_color);
	void print_field();
	Figure* field[8][8] = { nullptr };
public:
	void start_game();
	Chess() {
		char color = 'b';
		int l = 1;
		for (int i = 0; i < 8; i += 7) {
			field[i][0] = new Rook(i, 0, color);
			field[i][1] = new Horse(i, 1, color);
			field[i][2] = new Elephant(i, 2, color);
			field[i][3] = new Queen(i, 3, color);
			field[i][4] = new King(i, 4, color);
			field[i][5] = new Elephant(i, 5, color);
			field[i][6] = new Horse(i, 6, color);
			field[i][7] = new Rook(i, 7, color);
			for (int j = 0; j < 8; j++) {
				field[i+l][j] = new Pawn(i+l, j, color);
			}
			l = -1;
			color = 'w';
		}
	}
};

bool Chess::make_turn(char cur_color) {
	while (true) {
		int col_t, row_t, col_n, row_n;
		char color_next;
		cin >> row_t >> col_t >> row_n >> col_n;
		if (field[row_n][col_n] == nullptr) color_next = '0';
		else color_next = field[row_n][col_n]->get_color();
		if (cur_color == field[row_t][col_t]->get_color()) {

			if (field[row_t][col_t] == nullptr) {
				cout << "there is no Figure" << endl;
				continue;
			}
			if (field[row_t][col_t]->get_color() != cur_color) {
				cout << "it's not your figure" << endl;
				continue;
			}
			if (!(field[row_t][col_t]->check_turn(row_n, col_n, color_next))) {
//				cout << "figure can't make this turn" << endl;
				continue;
			}
			int col, row, k = 0;
			if (field[row_t][col_t]->to_char() == 'P') {
				if (field[row_t][col_t]->get_color() == 'w') {
					if (row_t == 6 && row_n == 4) {
						if (!(field[5][col_t] == nullptr)) {
							//				if (next->line == 7) become_new_figure();
							cout << "figure can't make this turn" << endl;
							continue;
						}
					}
				}
				if (field[row_t][col_t]->get_color() == 'b') {
					if (row_t == 1 && row_n == 3) {
						if (!(field[2][col_t] == nullptr)) {
							//				if (next->line == 7) become_new_figure();
							cout << "figure can't make this turn" << endl;
							continue;
						}
					}
				}
				if (field[row_n][col_n] == nullptr && col_n == col_t) { 
				}
				else if(abs(col_t-col_n) && abs(row_n - row_t)){}
				else {
					cout << "figure can't make this turn" << endl;
					continue;
				}
			}
			else if (field[row_t][col_t]->to_char() == 'H') {}
			else if (field[row_t][col_t]->to_char() == 'K') {}
			else {
				if (abs(col_t - col_n) == abs(row_t - row_n)) {
					col = 1;
					row = 1;
				}
				if (col_t == col_n) {
					col = 0;
					row = 1;
				}
				if (row_t == row_n) {
					col = 1;
					row = 0;
				}
				if (col_n < col_t) col = -col;
				if (row_n < row_t) row = -row;
				for (int i = col, j = row; col_t + i < col_n; i += col, j += row) {
					if (field[row_t + j][col_t + i] != nullptr) continue;
				}
			}
			if (field[col_n][row_n] != nullptr) {
				delete field[row_n][col_n];
			}
			field[row_n][col_n] = field[row_t][col_t];
			field[row_n][col_n]->change_col(col_n);
			field[row_n][col_n]->change_row(row_n);
			field[row_t][col_t] = nullptr;
			break;
			return true;
		}
		else cout << "It is not your turn" << endl;
	}
}

void Chess::print_field() {
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
		for (int j = 0; j < 8; j++) {
			if (field[i][j] == nullptr) {
				cout << "00";
			}
			else {
				cout << field[i][j]->to_char() << field[i][j]->get_color();
			}
			cout << " ";
		}
		cout << endl;
	}
	cout << "  ";
	for (int i = 0; i < 8; i++) cout << i << "  ";
	cout << endl;
}

void Chess::start_game() {
	int linet, linen;
	int columnt, columnn;
	char cur_color = 'w';
	char prev_color = 'b';
	while (true) {
		print_field();
//		cin >> linet >> columnt >> linen >> columnn;
//		if (cur_color == field[linet][columnt]->get_color()) {
			if (make_turn(cur_color)) {
				swap(cur_color, prev_color);
			}
//		}
//		else cout << "It is not your turn" << endl;
	}
}

int main()
{
	Chess chess = Chess();
	chess.start_game();
	return 0;
}
#pragma once

#include "figures.h"


class Chess {
	bool make_turn(char);
	bool pre_check_shah(int, int, int, int, char);
	void print_field();
	int king_col_white, king_row_white, king_col_black, king_row_black;
	bool check_shah(int, int);
	Figure* field[8][8] = { nullptr };
public:
	void start_game();
	Chess();
	void set_row(int row_n, char color);
	void set_col(int col_n, char color);
	char get_row(char color);
	char get_col(char color);
};

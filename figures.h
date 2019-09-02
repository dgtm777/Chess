#pragma once

class Figure {
	int row, col;
	bool move;
	char color;
public:	
	Figure(int st_row, int st_col, char st_color);
	bool check_turn_for_everyone(int dst_row, int dst_col, char dst_color) const;
	virtual bool check_turn(int dst_row, int dst_col, char dst_color);
	char get_color() const;
	char get_row() const;
	char get_move() const;
	char get_col() const;
	void set_row(int row_n);
	void set_col(int col_n);
	void set_move(int move_n);
	virtual char to_char() const = 0;
};


class Pawn : public Figure {
public:
	Pawn(int st_row, int st_col, char st_color);
	bool check_turn(int dst_row, int dst_col, char dst_color);
	char to_char() const;
};

class Rook : public Figure {
public:
	Rook(int st_row, int st_col, char st_color);
	bool check_turn(int dst_row, int dst_col, char dst_color);
    char to_char() const;
};

class Horse : public Figure {
public:
	Horse(int st_row, int st_col, char st_color);
	bool check_turn(int dst_row, int dst_col, char dst_color);
	char to_char() const;
};
class Elephant : public Figure {
public:
	Elephant(int st_row, int st_col, char st_color);
    bool check_turn(int dst_row, int dst_col, char dst_color);
	char to_char() const;
};

class Queen : public Figure {
public:
	Queen(int st_row, int st_col, char st_color);
	bool check_turn(int dst_row, int dst_col, char dst_color);
	char to_char() const;
};

class King : public Figure {
public:
	King(int st_row, int st_col, char st_color);
	bool check_turn(int dst_row, int dst_col, char dst_color);
	char to_char() const;
};
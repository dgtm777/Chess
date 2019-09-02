#include <iostream>
#include "chess.h"
using namespace std;


Chess::Chess() {
    char color = 'b';
    int l = 1;
    for (int i = 0; i < 8; i += 7) {
        field[i][0] = new Rook(i, 0, color);
        field[i][1] = new Horse(i, 1, color);
        field[i][2] = new Elephant(i, 2, color);
        field[i][3] = new Queen(i, 3, color);
        field[i][4] = new King(i, 4, color);
        set_row(0, 'b');
        set_col(4, 'b');
        set_row(7, 'w');
        set_col(4, 'w');
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

void Chess::set_row(int row_n, char color) {
    if (color == 'w') {
        king_row_white = row_n;
    }
    else {
        king_row_black = row_n;
    }
}

void Chess::set_col(int col_n, char color) {
    if (color == 'w') {
        king_col_white = col_n;
    }
    else {
        king_col_black = col_n;
    }
}

char Chess::get_row(char color) {
    if (color == 'w') {
        return king_row_white;
    }
    else {
        return king_row_black;
    }
}

char Chess::get_col(char color) {
    if (color == 'w') {
        return king_col_white;
    }
    else {
        return king_col_black;
    }
}

bool Chess::pre_check_shah(int row_t, int col_t, int row_n, int col_n, char cur_color) {
	if (col_t == col_n && row_t == row_n) {
		return check_shah(get_row(cur_color), get_col(cur_color));
	}
	Figure* keep = field[row_n][col_n];
	if (field[row_t][col_t]->to_char() == 'K') {
		set_col(col_n, cur_color);
		set_row(row_n, cur_color);
	}
	field[row_n][col_n] = field[row_t][col_t];
	field[row_n][col_n]->set_col(col_n);
	field[row_n][col_n]->set_row(row_n);
	field[row_t][col_t] = nullptr;
	if (check_shah(get_row(cur_color), get_col(cur_color))) {
		if (field[row_n][col_n] != nullptr) delete keep;
		field[row_n][col_n]->set_move(1);
		return true;
	}
	else {//backup
		field[row_t][col_t] = field[row_n][col_n];
		field[row_t][col_t]->set_col(col_t);
		field[row_t][col_t]->set_row(row_t);
		field[row_n][col_n] = keep;
		if (field[row_t][col_t]->to_char() == 'K') {
			set_col(col_t, cur_color);
			set_row(row_t, cur_color);
		}
	}
	return false;
}

bool Chess::check_shah(int get_row, int get_col) { //I move king anyways and then check it is ok or not
	for (int i = get_col+1; i < 8; i++) //check rook and queen attack from the regth side
	{
		if (field[get_row][i] == nullptr) {
			continue;
		}
		if (field[get_row][i]->get_color() == field[get_row][get_col]->get_color()) { //they can't attack throw your figure
			break;
		}
		if (field[get_row][i]->to_char() == 'R' || field[get_row][i]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;
		}
	}
	for (int i = get_col-1; i > -1; i--)//check rook and queen attack from the left side
	{
		if (field[get_row][i] == nullptr) {
			continue;
		}
		if (field[get_row][i]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[get_row][i]->to_char() == 'R' || field[get_row][i]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;

		}
	}
	for (int i = get_row+1; i < 8; i++)//check rook and queen attack from the bottom
	{
		if (field[i][get_col] == nullptr) {
			continue;
		}
		if (field[i][get_col]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[i][get_col]->to_char() == 'R' || field[i][get_col]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;

		}
	}
	for (int i = get_row-1; i > -1; i--)//check rook and queen attack from the left
	{
		if (field[i][get_col] == nullptr) {
			continue;
		}
		if (field[i][get_col]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[i][get_col]->to_char() == 'R' || field[i][get_col]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;

		}
	}
	for (int i = get_row+1, j = get_col+1; i < 8 && j < 8; i++, j++) {//check elephant and queen attack from the botton right
		if (field[i][j] == nullptr) {
			continue;
		}
		if (field[i][j]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[i][j]->to_char() == 'E' || field[i][j]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;
		}
	}
	for (int i = get_row-1, j = get_col-1; i > -1 && j > -1; i--, j--) {//check elephant and queen attack from the top left
		if (field[i][j] == nullptr) {
			continue;
		}
		if (field[i][j]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[i][j]->to_char() == 'E' || field[i][j]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;
		}
	}
	for (int i = get_row+1, j = get_col-1; i < 8 && j > -1; i++, j--) {//check elephant and queen attack from the botton left
		if (field[i][j] == nullptr) {
			continue;
		}
		if (field[i][j]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[i][j]->to_char() == 'E' || field[i][j]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;
		}
	}
	for (int i = get_row-1, j = get_col+1; i > -1 && j < 8; i--, j++) {//check elephant and queen attack from the top right
		if (field[i][j] == nullptr) {
			continue;
		}
		if (field[i][j]->get_color() == field[get_row][get_col]->get_color()) {//they can't attack throw your figure
			break;
		}
		if (field[i][j]->to_char() == 'E' || field[i][j]->to_char() == 'Q') {
			cout << "your king is under attack" << endl;
			return false;
		}
	}
	if ((get_col + 1 < 8 && ((get_row + 2 < 8 && field[get_row + 2][get_col + 1] != nullptr && field[get_row + 2][get_col + 1]->to_char() == 'H' && field[get_row + 2][get_col + 1]->get_color() != field[get_row][get_col]->get_color()) ||
	                         (get_row - 2 > -1 && field[get_row - 2][get_col + 1] != nullptr && field[get_row - 2][get_col + 1]->to_char() == 'H' && field[get_row - 2][get_col + 1]->get_color() != field[get_row][get_col]->get_color()))) ||
	   (get_col - 1 > -1 && ((get_row + 2 < 8 && field[get_row + 2][get_col - 1] != nullptr && field[get_row + 2][get_col - 1]->to_char() == 'H' && field[get_row + 2][get_col - 1]->get_color() != field[get_row][get_col]->get_color()) ||
		                     (get_row - 2 > -1 && field[get_row - 2][get_col - 1] != nullptr && field[get_row - 2][get_col - 1]->to_char() == 'H' && field[get_row - 2][get_col - 1]->get_color() != field[get_row][get_col]->get_color())))){
		cout << "your king is under attack" << endl;
		return false;
	}//check a horse attack
	if((get_col + 1 < 8 && ((get_row + 1 < 8 && field[get_row + 1][get_col + 1] != nullptr && field[get_row + 1][get_col + 1]->to_char() == 'K') ||
		                      (get_row - 1 > -1 && field[get_row - 1][get_col + 1] != nullptr && field[get_row - 1][get_col + 1]->to_char() == 'K')))||
	   (get_col - 1 > -1 && ((get_row + 1 < 8 && field[get_row + 1][get_col - 1] != nullptr && field[get_row + 1][get_col - 1]->to_char() == 'K') ||
	                          (get_row - 1 > -1 && field[get_row - 1][get_col - 1] != nullptr && field[get_row - 1][get_col - 1]->to_char() == 'K')))){
		cout << "your king is under attack" << endl;
		return false;
	}//check king attack
	return true;
}

bool Chess::make_turn(char cur_color) {
	while (true) {
		cout << "input the cell where your figure is" << endl;
		string s;
		getline(cin, s);
		int it;
		for (it=0; s[it] == ' ' && s[it] != '/n'; it++) {
		}
		if (s[it] == '/n') {
			continue;
		}
		if (!(s[it] >= 'a' && s[it] <= 'z')) {
			continue;
		}
		int col_t;
		col_t = s[it] - 'a';
		for(it++; s[it] ==' ' && s[it] != '/n'; it++){
		}
		if (s[it] == '/n') {
			continue;
		}
		if (!(s[it] >= '1' && s[it] <= '8')) {
			continue;
		}
		int row_t;
		row_t = 7 - s[it] + '0' + 1;
		cout << "input the cell where your figure will move" << endl;
		getline(cin, s);
		for (it=0; s[it] == ' ' && s[it] != '/n'; it++) {}
		if (s[it] == '/n') {
			continue;
		}
		if (!(s[it] >= 'a' && s[it] <= 'z')) {
			continue;
		}
		int col_n;
		col_n = s[it] - 'a';
		for (it++; s[it] == ' ' && s[it] != '/0'; it++) {}
		if (s[it] == '/n') {
			continue;
		}
		if (!(s[it] >= '1' && s[it] <= '8')) {
			continue;
		}
		int row_n;
		row_n = 7 - s[it] + '0' + 1;
		if (!(col_n < 8 && col_n >= 0 && col_t >= 0 && col_t < 8 && row_n < 8 && row_n >= 0 && row_t >= 0 && row_t < 8)) {
			cout << "the move is not correct" << endl;
			continue;
		}
		char color_next;
		if (field[row_n][col_n] == nullptr) {
			color_next = '0';
		}
		else {
			color_next = field[row_n][col_n]->get_color();
		}
		if (field[row_t][col_t] == nullptr) {
			cout << "there is no Figure" << endl;
			continue;
		}
		if (cur_color == field[row_t][col_t]->get_color()) {
			int f = 0;
			int row_tr, col_tr, row_nr, col_nr;
			if (!(field[row_t][col_t]->check_turn(row_n, col_n, color_next))) {
				continue;
			}
			if (field[row_t][col_t]->to_char() == 'P') {
				if (field[row_t][col_t]->get_color() == 'w') {
					if (row_t == 6 && row_n == 4) {
						if (!(field[5][col_t] == nullptr)) {
							cout << "figure can't make this turn" << endl;
							continue;
						}
					}
				}
				if (field[row_t][col_t]->get_color() == 'b') {
					if (row_t == 1 && row_n == 3) {
						if (!(field[2][col_t] == nullptr)) {
							cout << "figure can't make this turn" << endl;
							continue;
						}
					}
				}
				if (field[row_n][col_n] == nullptr && col_n == col_t) {}
				else if(abs(col_t-col_n) == abs(row_n - row_t)){}
				else {
					cout << "figure can't make this turn" << endl;
					continue;
				}//if we do not attack any figure our destination cell shoul be empty
			}
			else if (field[row_t][col_t]->to_char() == 'H') {}// it way will check in another place
			else if (field[row_t][col_t]->to_char() == 'K') {
				if (abs(col_t - col_n) == 2) {
					if (field[row_t][min(col_t, col_n) + 1] == nullptr) {
						if (pre_check_shah(row_t, col_t, row_t, col_t, cur_color))
						{
							if (col_t < col_n) {
								if (field[row_t][col_t + 3]->get_move() == 0) {
									if (pre_check_shah(row_t, col_t, row_n, col_t + 1, cur_color)) {
										row_tr = row_t;
										col_tr = 7;
										row_nr = row_n;
										col_nr = 5;
										pre_check_shah(row_t, col_t + 1, row_n, col_t, cur_color);
										f = 1;
									}
									else {
										continue;
									}
								}
								else {
									continue;
								}
							}
							else {
								if (field[row_t][col_t - 4]->get_move() == 0) {
									if (pre_check_shah(row_t, col_t, row_n, col_t - 1, cur_color)) {
										row_tr = row_t;
										col_tr = 0;
										row_nr = row_n;
										col_nr = 3;
										pre_check_shah(row_t, col_t - 1, row_n, col_t, cur_color);
										f = 1;
									}
									else {
										continue;
									}
								}
								else {
									continue;
								}
							}
						}
					}
				}
			}// it way will check in another place
			else {
				int col, row, k = 0;
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
				for (int i = col, j = row; col_t + i != col_n || row_t + j != row_n; i += col, j += row) {//checking that you are not jumping
					if (field[row_t + j][col_t + i] != nullptr) {
						k = 1;
						break;
					}
				}
				if (k == 1) {
					cout << "you can't make the turn" << endl;
					continue; 
				}
			}
			if (f == 1) {
				f = 0;
				pre_check_shah(row_tr, col_tr, row_nr, col_nr, cur_color);
			}
			if (pre_check_shah(row_t, col_t, row_n, col_n, cur_color)) {
				return true;
			}
		}
		else cout << "It is not your turn" << endl;
	}
}

void Chess::print_field() {
	for (int i = 0; i < 8; i++) {
		cout << 8-i << " ";
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
	for (char i = 'a'; i < 'i'; i++) {
		cout << i << "  ";
	}
	cout << endl;
}

void Chess::start_game() {
	char cur_color = 'w';
	char prev_color = 'b';
	while (true) {
		print_field();
			if (make_turn(cur_color)) {
				swap(cur_color, prev_color);
			}
	}
}
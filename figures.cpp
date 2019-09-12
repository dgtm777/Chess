#include <iostream>
#include "figures.h"
using namespace std;


Figure::Figure(int st_row, int st_col, char st_color) {
    row = st_row;
    col = st_col;
    color = st_color;
    move = 0;
}

bool Figure::check_turn_for_everyone(int dst_row, int dst_col, char dst_color) const {
    if (get_col() == dst_col && get_row() == dst_row) { 
        cout << "You do not move" << endl; 
        return false; 
    }
    if (get_color() == dst_color) { 
        cout << "There are your figure" << endl; 
        return false; 
    }
    return true;
}

bool Figure::check_turn(int dst_row, int dst_col, char dst_color) {
    return true;
}

char Figure::get_color() const {
    return color;
}

char Figure::get_row() const {
    return row;
}

char Figure::get_move() const {
    return move;
}

char Figure::get_col() const {
    return col;
}

void Figure::set_row(int row_n) {
    row = row_n;
}

void Figure::set_col(int col_n)  {
    col = col_n;
}

void Figure::set_move(int move_n) {
    move = move_n;
}

Pawn::Pawn(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {

}

bool Pawn::check_turn(int dst_row, int dst_col, char dst_color) {
    if (!(check_turn_for_everyone(dst_row, dst_col, dst_color))) {
        return false;
    }
    if (get_color() == 'b') {
        if (!(dst_row > 0)) {// black pawn can't be in a 7th row 
            return false;
        }
        if (get_col() == dst_col) {
            if (dst_row - get_row() == 1) {
//					if (dst_row == 7) become_new_figure(); TODO
                return true;
            }
            if (get_row() == 1 && dst_row == 3) {
//					if (field[2][col]->color == "empty") { TODO
//						if (dst_row == 7) become_new_figure();
                    return true;
//				}
            }
        }
        if (abs(dst_col - get_col()) == 1 && dst_row - get_row() == 1 && dst_color == 'w') {
            return true;
        }
    }
    if (get_color() == 'w') {
        if (!(get_row() < 7)) {// white pawn can't be in a 0 row
            return false;
        }
        if (get_col() == dst_col) {
            if (get_row() - dst_row == 1) {
//				if (dst_row == 0) become_new_figure(); TODO
                return true;
            }
            if (get_row() == 6 && dst_row == 4) {
//				if (field[5][col]->get_color() == "empty") { TODO
//					if (dst_row == 0) become_new_figure();
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

char Pawn::to_char() const {
    return 'P';
}

Rook::Rook(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}

bool Rook::check_turn(int dst_row, int dst_col, char dst_color) {
    if (!(check_turn_for_everyone(dst_row, dst_col, dst_color))) {
        return false;
    }
    if (get_col() == dst_col) {
        return true;
    }
    if (get_row() == dst_row) {
        return true;
    }
    cout << "the move is not correct" << endl;
    return false;
}

char Rook::to_char() const {
    return 'R';
}

Horse::Horse(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}

bool Horse::check_turn(int dst_row, int dst_col, char dst_color) {
    if (!(check_turn_for_everyone(dst_row, dst_col, dst_color))) {
        return false;
    }
    if ((abs(get_col() - dst_col) == 2 && abs(get_row() - dst_row) == 1) ||
        (abs(get_col() - dst_col) == 1 && abs(get_row() - dst_row) == 2)) {
        return true;
    }
    cout << "the move is not correct" << endl;
    return false;
}

char Horse::to_char() const {
    return 'H';
}

Elephant::Elephant(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}

bool Elephant::check_turn(int dst_row, int dst_col, char dst_color) {
    if (!(check_turn_for_everyone(dst_row, dst_col, dst_color))) {
        return false;
    }
    if (abs(get_col() - dst_col) == abs(get_row() - dst_row)) {
        return true;
    }
    cout << "the move is not correct" << endl;
    return false;
}

char Elephant::to_char() const {
    return 'E';
}

Queen::Queen(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}

bool Queen::check_turn(int dst_row, int dst_col, char dst_color) {
    if (!(check_turn_for_everyone(dst_row, dst_col, dst_color))) {
        return false;
    }
    if (get_col() == dst_col) {
            return true;
    }
    if (get_row() == dst_row) {
        return true;
    }
    if (abs(get_col() - dst_col) == abs(get_row() - dst_row)) {
        return true;
    }
    cout << "the move is not correct" << endl;
    return false;
}

char Queen::to_char() const {
    return 'Q';
}

King::King(int st_row, int st_col, char st_color) : Figure(st_row, st_col, st_color) {}

bool King::check_turn(int dst_row, int dst_col, char dst_color) {
    if (!(check_turn_for_everyone(dst_row, dst_col, dst_color))) {
        return false;
    }
    if (abs(get_col() - dst_col) < 2 && abs(get_row() - dst_row) < 2) {
        return true;
    }
    if (abs(get_col() - dst_col) == 2 && abs(get_row() - dst_row) == 0 && get_move() == 0){
        return true;
    }
    cout << "the move is not correct" << endl;
    return false;
}

char King::to_char() const {
    return 'K';
}

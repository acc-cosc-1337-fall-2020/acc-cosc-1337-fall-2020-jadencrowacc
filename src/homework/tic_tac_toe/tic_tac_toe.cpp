//cpp

#include <iostream>
#include <string>
#include "tic_tac_toe.h"

using std::string;

using std::cout;

bool tic_tac_toe::game_over() {
    if (check_column_win() || check_row_win() || check_diagonal_win()) {
        set_winner();
        return true;
    }
    if (check_board_full()) {
        winner = "C";
        return true;
    }
    return false;
}

void tic_tac_toe::start_game(string first_player) {
    clear_board();
    player = first_player;
}

bool tic_tac_toe::mark_board(int position) {
    if (board[position - 1] != " " || position < 1 || position > 9)
        return false;
    board[position - 1] = player;
    set_next_player();
    return true;
}

string tic_tac_toe::get_player() {
    return player;
}

void tic_tac_toe::set_next_player() {
    if (player == "X")
        player = "O";
    else
        player = "X";
}

bool tic_tac_toe::check_board_full() {
    for (string peg : board)
        if (peg == " ")
            return false;
    return true;
}

void tic_tac_toe::clear_board() {
    for (auto &i : board)
        i = " ";
}

string tic_tac_toe::get_winner() {
    return winner;
}

void tic_tac_toe::set_winner() {
    set_next_player();
    winner = player;
}

std::ostream &operator<<(std::ostream &out, const tic_tac_toe &game) {
    out << "\n===\n";
    for (int i = 1; i <= game.board.size(); i++) {
        out << game.board[i - 1];
        if (i % 3 == 0) {
            out << "\n";
        }
    }
    out << "===\n";
    return out;
}

std::istream &operator>>(std::istream &in, tic_tac_toe &game) {
    cout << game.get_player() << " it is your turn, type a number 1-9 to place you peg: ";
    int position = 0;
    in >> position;
    while (!game.mark_board(position)) {
        cout << "Invalid input, please type a number 1-9: ";
        in >> position;
    }
    return in;
}
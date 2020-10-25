//cpp

#include "tic_tac_toe.h"
#include <iostream>
#include <string>

using std::string;

using std::cout;

bool tic_tac_toe::game_over() {
    for (int i = 0; i <= 6; i += 3)
        if (board[0 + i] != " " && board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
            return true;
    return false;
}

void tic_tac_toe::start_game(string first_player) {
    player = first_player;
}

bool tic_tac_toe::mark_board(int position) {
    if(board[position-1] != " " || position < 1 || position > 9)
        return false;
    board[position - 1] = player;
    set_next_player();
    return true;
}

string tic_tac_toe::get_player() {
    return player;
}

void tic_tac_toe::display_board() {
    for (int i = 1; i <= board.size(); i++) {
        cout << board[i - 1];
        if (i % 3 == 0)
            cout << "\n";
    }
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
    for (int i = 0; i < board.size(); i++)
        board[i] = " ";
}

//cpp

#include "tic_tac_toe_manager.h"
#include <string>

std::ostream &operator<<(std::ostream &out, const tic_tac_toe_manager &manager) {
    for (const tic_tac_toe &game : manager.games)
        out << game;
    return out;
}

void tic_tac_toe_manager::save_game(tic_tac_toe game) {
    games.push_back(game);
    switch (game.get_winner()[0]) {
        case 'O':
            o_wins++;
            break;
        case 'X':
            x_wins++;
            break;
        case 'C':
            ties++;
            break;
    }
}

void tic_tac_toe_manager::get_winner_total(int &o, int &x, int &t) {
    o = o_wins;
    x = x_wins;
    t = ties;
}
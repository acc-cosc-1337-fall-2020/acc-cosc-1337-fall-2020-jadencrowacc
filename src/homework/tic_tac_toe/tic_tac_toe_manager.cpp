//cpp

#include "tic_tac_toe_manager.h"
#include <string>
std::ostream &operator<<(std::ostream &out, const tic_tac_toe_manager &manager) {
    for (auto &game : manager.games)
        out << *game;
    return out;
}

void tic_tac_toe_manager::save_game(std::unique_ptr<tic_tac_toe> game) {
    switch (game->get_winner()[0]) {
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
    games.push_back(std::move(game));
}

void tic_tac_toe_manager::get_winner_total(int &o, int &x, int &t) {
    o = o_wins;
    x = x_wins;
    t = ties;
}

tic_tac_toe_manager::~tic_tac_toe_manager() {
    data.save_games(games);
}

tic_tac_toe_manager::tic_tac_toe_manager() {
    games = data.get_games();
    for (std::unique_ptr<tic_tac_toe> &game : games) {
        switch (game->get_winner()[0]) {
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
}

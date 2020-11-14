#include <iostream>
#include <string>
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

using std::cout;
using std::cin;
using std::string;

int main() {
    tic_tac_toe_manager manager;
    std::unique_ptr<tic_tac_toe> game;
    string play_again = "Y";
    while (play_again == "Y") {

        string game_type;
        while (game_type != "3" && game_type != "4") {
            cout << "Please type 3 or 4 to select game type: ";
            cin >> game_type;
        }

        if (game_type == "3")
            game = std::make_unique<tic_tac_toe_3>();
        else
            game = std::make_unique<tic_tac_toe_4>();

        string first_player;
        while (first_player != "X" && first_player != "O") {
            cout << "Please type X or O to determine who will go first: ";
            cin >> first_player;
        }

        game->start_game(first_player);

        while (!game->game_over()) {
            cin >> *game;
            cout << *game;
        }
        if (game->get_winner() == "C")
            cout << "Tie.\n";
        else
            cout << game->get_winner() << " wins!\n";

        manager.save_game(std::move(game));

        int x_wins, o_wins, ties;
        manager.get_winner_total(o_wins, x_wins, ties);
        cout << "X wins: " << x_wins << ", O wins: " << o_wins << ", Ties: " << ties << "\n\n";

        do {
            cout << "Would you like to play again? (Y/N): ";
            cin >> play_again;
        } while (play_again != "Y" && play_again != "N");
    }

    cout << manager;
}
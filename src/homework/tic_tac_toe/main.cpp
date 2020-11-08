#include <iostream>
#include <string>
#include <tic_tac_toe_manager.h>

using std::cout;
using std::cin;
using std::string;

int main() {
    tic_tac_toe_manager manager;
    tic_tac_toe game;
    string play_again = "Y";
    while (play_again == "Y") {

        string first_player;
        while (first_player != "X" && first_player != "O") {
            cout << "Please type X or O to determine who will go first: ";
            cin >> first_player;
        }

        game.start_game(first_player);

        while (!game.game_over()) {
            cin >> game;
            cout << game;
        }
        if (game.get_winner() == "C")
            cout << "Tie.\n";
        else
            cout << game.get_winner() << " wins!\n";

        manager.save_game(game);

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
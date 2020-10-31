#include <tic_tac_toe.h>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

int main() {
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
            cout << game.get_player() << " it is your turn, type a number 1-9 to place you peg: ";

            int position = 0;

            cin >> position;
            while (!game.mark_board(position)) {
                cout << "Invalid input, please type a number 1-9: ";
                cin >> position;
            }
            cout << "\n===\n";
            game.display_board();
            cout << "===\n\n";
        }
        if (game.get_winner() == "C")
            cout << "Tie.\n\n";
        else
            cout << game.get_winner() << " wins!\n\n";

        do {
            cout << "Would you like to play again? (Y/N): ";
            cin >> play_again;
        } while (play_again != "Y" && play_again != "N");
    }
}
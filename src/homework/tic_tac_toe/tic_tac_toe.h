#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class tic_tac_toe {
public:

    bool game_over();

    void start_game(string first_player);

    bool mark_board(int position);

    string get_player();

    void display_board();

    string get_winner();

private:

    string winner;
    string player;
    vector<string> board = {" ", " ", " ",
                            " ", " ", " ",
                            " ", " ", " ",};

    void clear_board();

    bool check_board_full();

    void set_next_player();

    bool check_column_win();

    bool check_row_win();

    bool check_diagonal_win();

    void set_winner();


};
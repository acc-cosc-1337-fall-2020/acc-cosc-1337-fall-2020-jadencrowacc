#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class tic_tac_toe
{
public:

    bool game_over();

    void start_game(string first_player);

    bool mark_board(int position);

    string get_player();

    void display_board();

    void set_next_player();

    bool check_board_full();

    void clear_board();

private:

    string player;
    vector<string> board = {" "," "," ",
                            " "," "," ",
                            " "," "," ",};
};
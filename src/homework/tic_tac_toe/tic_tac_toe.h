#ifndef tictactoe_h
#define tictactoe_h

#include <iostream>
#include <string>
#include <vector>
#include <bits/unique_ptr.h>

using std::string;
using std::vector;

class tic_tac_toe {
public:
    explicit tic_tac_toe(int s) : board(s * s, " ") {}

    tic_tac_toe(std::vector<string> p, string win);

    bool game_over();

    void start_game(string first_player);

    bool mark_board(int position);

    string get_player();

    string get_winner();

    friend std::ostream &operator<<(std::ostream &out, const tic_tac_toe &game);

    friend std::istream &operator>>(std::istream &in, tic_tac_toe &game);

    friend std::ofstream &operator<<(std::ofstream &file, const tic_tac_toe &game);

private:

    string winner;
    string player;

    void clear_board();

    bool check_board_full();

    void set_next_player();

    void set_winner();

protected:

    virtual bool check_column_win() = 0;

    virtual bool check_row_win() = 0;

    virtual bool check_diagonal_win() = 0;

    vector<string> board;
};

#endif
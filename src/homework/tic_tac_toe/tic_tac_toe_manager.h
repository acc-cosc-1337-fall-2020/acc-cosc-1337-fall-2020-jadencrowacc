//h
#include <vector>
#include <bits/unique_ptr.h>
#include "tic_tac_toe.h"

class tic_tac_toe_manager {
private:
    std::vector<std::unique_ptr<tic_tac_toe>> games;
    int x_wins = 0;
    int o_wins = 0;
    int ties = 0;
public:
    friend std::ostream &operator<<(std::ostream &out, const tic_tac_toe_manager &manager);

    void save_game(std::unique_ptr<tic_tac_toe> game);

    void get_winner_total(int &o, int &x, int &t);
};
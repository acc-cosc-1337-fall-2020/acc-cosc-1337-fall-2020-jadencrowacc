//h

#include <bits/unique_ptr.h>
#include <vector>
#include <tic_tac_toe.h>

class tic_tac_toe_data {
public:
    void save_games(const std::vector<std::unique_ptr<tic_tac_toe>> &games);

    std::vector<std::unique_ptr<tic_tac_toe>> get_games();
};
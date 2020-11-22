//h
#include <tic_tac_toe.h>

#include <utility>

class tic_tac_toe_3 : public tic_tac_toe { ;

    bool check_diagonal_win() override;

    bool check_column_win() override;

    bool check_row_win() override;

public:
    tic_tac_toe_3() : tic_tac_toe(3) {}

    tic_tac_toe_3(std::vector<string> p, string win) : tic_tac_toe(std::move(p), std::move(win)) {}
};

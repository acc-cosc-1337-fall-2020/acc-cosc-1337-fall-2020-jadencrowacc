#include "tic_tac_toe.h"

class tic_tac_toe_4 : public tic_tac_toe { ;

    bool check_diagonal_win() override;

    bool check_column_win() override;

    bool check_row_win() override;

public:
    tic_tac_toe_4() : tic_tac_toe(4) {}
};
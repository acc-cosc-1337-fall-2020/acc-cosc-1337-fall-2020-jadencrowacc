#include "tic_tac_toe_3.h"

bool tic_tac_toe_3::check_row_win() {
    for (int i = 0; i <= 6; i += 3)
        if (board[0 + i] != " " && board[0 + i] == board[1 + i] && board[1 + i] == board[2 + i])
            return true;
    return false;
}

bool tic_tac_toe_3::check_column_win() {
    for (int i = 0; i < 3; i += 1)
        if (board[0 + i] != " " && board[0 + i] == board[3 + i] && board[3 + i] == board[6 + i])
            return true;
    return false;
}

bool tic_tac_toe_3::check_diagonal_win() {
    return (board[4] != " " && board[2] == board[4] && board[4] == board[6]) ||
           (board[4] != " " && board[0] == board[4] && board[4] == board[8]);
}
